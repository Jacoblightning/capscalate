# capscalate
A program to escalate to root privileges with many different capabilities
# Disclaimer
A few of these "exploits" cat cause temporary or permanat damage to a system if the "exploit" fails. Always have a root shell open while running these so you can fix any issues. 
## What can they do?
- The exploit for CAP_SYS_ADMIN can temporarily render your system unusable until a reboot as it overwrites /usr/lib/libpam with a bind mount. If everything goes successfully, A reboot will not be required.
- The exploit for CAP_CHOWN could render your system with a corrupted /etc/shadow. Make sure to back it up before running.
# How do I use these?
1. Clone the repo: `git clone https://github.com/Jacoblightning/capscalate && cd capscalate`'

1.5. At this point in development, there is no autodetect functionality. You will have to edit main.cpp to run the one you want.

2. Build capscalate: `mkdir build && cd build && cmake .. && cmake --build .`
3. Add the capability you want to exploit: `sudo setcap <capability>+ep capscalate`
4. Run capscalate: `./capscalate`
5. Reap the benefits of a root shell.
