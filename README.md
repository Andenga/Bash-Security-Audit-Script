# Linux Security Audit Script

This is a bash script that runs a quick security sweep of Linux  and
saves the results to a log file. 

It performs a scan on the Linux system and then tells you what it finds.

## What it checks

- **World-writable files** — it checks and lists files that anyone on the system can
  modify. 
- **Failed SSH login attempts** — pulls from `auth.log` / `secure` (or
  `journalctl` if those aren't around) and ranks the IPs.
- **Open ports** — what is listening on the network, and which process owns it.
- **Running services** — it check evry currently active service via systemd 
- **Passwordless accounts** — any user account with no password set. This
  should **always** be empty.
- **SUID binaries** — it checks programs that run with elevated privileges regardless
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

