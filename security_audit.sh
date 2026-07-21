#!/usr/bin/env bash

set -uo pipefail

# Setup


TIMESTAMP=$(date +"%Y-%m-%d_%H-%M-%S")
DEFAULT_OUTDIR="/var/log/security_audits"
OUTDIR="${1:-$DEFAULT_OUTDIR}"

# Fall back to a local directory if we can't write to the default location
if ! mkdir -p "$OUTDIR" 2>/dev/null || [ ! -w "$OUTDIR" ]; then
    OUTDIR="./audit_logs"
    mkdir -p "$OUTDIR"
fi

LOGFILE="${OUTDIR}/security_audit_${TIMESTAMP}.log"

# Colors for terminal output (stripped when writing to file)
RED='\033[0;31m'
YELLOW='\033[1;33m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m'

# Track whether we're root (some checks need it)
IS_ROOT=false
if [ "$(id -u)" -eq 0 ]; then
    IS_ROOT=true
fi


# Print a section header to both terminal and log
section() {
    local title="$1"
    {
        echo ""
        echo "================================================================"
        echo " $title"
        echo "================================================================"
    } | tee -a "$LOGFILE"
}

log() {
    echo "$1" | tee -a "$LOGFILE"
}

warn() {
    echo -e "${YELLOW}[!] $1${NC}"
    echo "[!] $1" >> "$LOGFILE"
}

info() {
    echo -e "${CYAN}[*] $1${NC}"
    echo "[*] $1" >> "$LOGFILE"
}

require_root_notice() {
    if [ "$IS_ROOT" = false ]; then
        warn "Not running as root — some checks (e.g. shadow file, some ports/services) may be incomplete."
        warn "Re-run with sudo for a full audit."
    fi
}

# Report header

{
    echo "############################################################"
    echo "# Linux Security Audit Report"
    echo "# Host: $(hostname)"
    echo "# Date: $(date)"
    echo "# Run by: $(whoami) (root: $IS_ROOT)"
    echo "############################################################"
} | tee "$LOGFILE"

require_root_notice

# 1. World-writable files
section "1. World-Writable Files"
info "Scanning common system directories for world-writable files (this may take a moment)..."

# Limit scope to avoid scanning huge/irrelevant trees like /proc, /sys, /dev, network mounts
WW_DIRS="/etc /bin /sbin /usr /opt /var /home /root"

WW_COUNT=0
while IFS= read -r -d '' f; do
    echo "$f" >> "$LOGFILE"
    WW_COUNT=$((WW_COUNT + 1))
done < <(find $WW_DIRS -xdev -type f -perm -0002 -not -path "*/proc/*" -print0 2>/dev/null)

if [ "$WW_COUNT" -eq 0 ]; then
    log "No world-writable files found in scanned directories."
else
    warn "$WW_COUNT world-writable file(s) found. See list above in log."
fi

# 2. Failed SSH login attempts
section "2. Failed SSH Login Attempts"

AUTHLOG=""
for candidate in /var/log/auth.log /var/log/secure; do
    if [ -f "$candidate" ]; then
        AUTHLOG="$candidate"
        break
    fi
done

if [ -n "$AUTHLOG" ]; then
    info "Reading from $AUTHLOG"
    FAILED_COUNT=$(grep -c "Failed password" "$AUTHLOG" 2>/dev/null || echo 0)
    log "Total failed password attempts logged: $FAILED_COUNT"

    log ""
    log "Top offending IPs (failed attempts):"
    grep "Failed password" "$AUTHLOG" 2>/dev/null \
        | grep -oE "from [0-9]{1,3}(\.[0-9]{1,3}){3}" \
        | awk '{print $2}' \
        | sort | uniq -c | sort -rn | head -10 >> "$LOGFILE"
    grep "Failed password" "$AUTHLOG" 2>/dev/null \
        | grep -oE "from [0-9]{1,3}(\.[0-9]{1,3}){3}" \
        | awk '{print $2}' \
        | sort | uniq -c | sort -rn | head -10
elif command -v journalctl >/dev/null 2>&1; then
    info "No auth.log/secure found — trying journalctl (systemd journal)"
    FAILED_COUNT=$(journalctl -u ssh -u sshd 2>/dev/null | grep -c "Failed password" || echo 0)
    log "Total failed password attempts logged (journal): $FAILED_COUNT"
    journalctl -u ssh -u sshd 2>/dev/null \
        | grep "Failed password" \
        | grep -oE "from [0-9]{1,3}(\.[0-9]{1,3}){3}" \
        | awk '{print $2}' \
        | sort | uniq -c | sort -rn | head -10 | tee -a "$LOGFILE"
else
    warn "Could not locate SSH auth logs (no auth.log, secure, or journalctl available)."
fi

# 3. Open ports
section "3. Open Ports / Listening Services"

if command -v ss >/dev/null 2>&1; then
    info "Using ss to list listening ports"
    {
        echo "Proto  Local Address:Port      Process"
        ss -tulnp 2>/dev/null | tail -n +2
    } | tee -a "$LOGFILE"
elif command -v netstat >/dev/null 2>&1; then
    info "Using netstat to list listening ports"
    netstat -tulnp 2>/dev/null | tee -a "$LOGFILE"
else
    warn "Neither 'ss' nor 'netstat' found — cannot list open ports."
fi

# 4. Running services
section "4. Running Services"

if command -v systemctl >/dev/null 2>&1; then
    info "Using systemctl to list active services"
    systemctl list-units --type=service --state=running --no-pager --no-legend 2>/dev/null \
        | awk '{print $1}' | tee -a "$LOGFILE"
elif command -v service >/dev/null 2>&1; then
    info "Using service --status-all"
    service --status-all 2>/dev/null | tee -a "$LOGFILE"
else
    warn "No systemctl or service command found — cannot list running services."
fi

# 5. Users with no password
section "5. Accounts With No Password Set"

if [ "$IS_ROOT" = true ] && [ -r /etc/shadow ]; then
    NOPASS_USERS=$(awk -F: '($2 == "" ) {print $1}' /etc/shadow)
    if [ -z "$NOPASS_USERS" ]; then
        log "No accounts with empty passwords found."
    else
        warn "The following accounts have NO password set:"
        echo "$NOPASS_USERS" | tee -a "$LOGFILE"
    fi

    log ""
    info "Accounts with locked passwords (for reference, not a finding):"
    awk -F: '($2 ~ /^!/ || $2 ~ /^\*/) {print $1}' /etc/shadow >> "$LOGFILE"
else
    warn "Cannot read /etc/shadow (requires root). Skipping empty-password check."
fi

# 6. SUID binaries
section "6. SUID Binaries"

info "Scanning for SUID binaries (this may take a moment)..."
SUID_DIRS="/usr /bin /sbin /opt /home /root"

SUID_COUNT=0
while IFS= read -r -d '' f; do
    echo "$f" >> "$LOGFILE"
    SUID_COUNT=$((SUID_COUNT + 1))
done < <(find $SUID_DIRS -xdev -type f -perm -4000 -not -path "*/proc/*" -print0 2>/dev/null)

log "Total SUID binaries found: $SUID_COUNT"
log "(Review this list for anything unexpected or not matching your distro's known-good baseline.)"

# Summary
section "Summary"
{
    echo "World-writable files found: $WW_COUNT"
    echo "SUID binaries found:        $SUID_COUNT"
    echo "Report saved to:            $LOGFILE"
} | tee -a "$LOGFILE"

echo ""
echo -e "${GREEN}Audit complete. Full report saved to: $LOGFILE${NC}"
