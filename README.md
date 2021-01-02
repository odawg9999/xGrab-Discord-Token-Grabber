# xGrab - Discord Token Grabber

Important: This is meant to be a PoC (proof of concept) and to make aware of this issue since I consider it as a vulnerability (although Discord seems to have a different opinion). You're not allowed to modify this code for real world usage. You may use it if you want to recover your own account.

PoC for grabbing Discord tokens for Windows XP-10 having no dependencies except the OS itself. Written in C using pure WinAPI (no C runtime library) - current filesize: ~11kb.
Token is delivered via Discord webhook (but can easily be changed to custom web panels for example).
Executable is non-resident and will remove itself after searching and transfering data. If the internet connection fails, the executable will try to connect 2 more times over the next 10 minutes before it removes itself. The executable uses Anti-Debug and Anti-VM techniques. Real-world malware would use encrypted strings, however, this is not the point of this project.

Demonstration video:

How to use a token to log into an account: https://www.youtube.com/watch?v=FmXMGCRpw50

Example output of the tool:

![alt text](https://i.imgur.com/8pRQxlp.png)
