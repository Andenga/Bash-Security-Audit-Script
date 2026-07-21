# Linux Security Audit Script

A  bash script that runs a quick security sweep of Linux  and
saves the results to a log file. 

It performs a scan on Linux system and then tells you what it finds.

## What it checks

- **World-writable files** — files that anyone on the system can
  modify. 
- **Failed SSH login attempts** — pulls from `auth.log` / `secure` (or
  `journalctl` if those aren't around) and ranks the IPs.
- **Open ports** — what's actually listening on the network, and which
  process owns it.
- **Running services** — everything currently active via systemd 
- **Passwordless accounts** — any user account with no password set. This
  should **always** be empty.
- **SUID binaries** — programs that run with elevated privileges regardless
  of who launches them. 


## Usage
This is how you can run this script in your Linux system

```bash
chmod +x audit.sh
sudo ./audit.sh
```

Want it saved somewhere else? run the below command instead.

```bash
sudo ./audit.sh ~/reports
```

Each run produces a timestamped file


## Reading the output

The script prints everything to the terminal as it runs *and* writes the
same thing to the log file, so you can watch it work or just check the file
afterward. It closes with a short summary — counts of world-writable files
and SUID binaries found, plus the path to the full report.
