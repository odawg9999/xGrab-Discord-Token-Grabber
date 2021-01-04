# xGrab - Discord Token Grabber

Important: This is meant to be a PoC (proof of concept) and to spread awareness of this issue since I consider it as a vulnerability (although Discord seems to have a different opinion). You're not allowed to modify this code for real world usage. You may use it if you want to recover your own account.

PoC for grabbing Discord tokens. File works on Windows XP-10, having no dependencies except the OS itself. Written in C using pure WinAPI (no C runtime library) - Filesize: ~11kb; Format: Win32 PE.
Token is delivered via Discord webhook (but can easily be changed to custom web panels for example).
Executable is non-resident and will remove itself after searching and transfering data. If the internet connection fails, the executable will try to connect 2 more times over the next 10 minutes before it removes itself. The executable uses Anti-Debug and Anti-VM techniques. Real-world malware would use encrypted strings, however, this is not the point of this project.

Demonstration video: https://www.youtube.com/watch?v=MbF7JA2nArE

How to use a token to log into an account: https://www.youtube.com/watch?v=FmXMGCRpw50

Example output of the tool:

![alt text](https://i.imgur.com/8pRQxlp.png)

C/C++ Flags (Visual Studio):
/permissive- /ifcOutput "Release\" /GS- /analyze- /W3 /Gy /Zc:wchar_t /Zi /Gm- /O1 /sdl- /Fd"Release\vc142.pdb" /Zc:inline /fp:precise /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /Gd /Oy- /MT /FC /Fa"Release\" /EHsc /nologo /Fo"Release\" /Os /Fp"Release\TokenGrabber.pch" /diagnostics:column /Gs100000000 /utf-8 /arch:SSE 

Linker flags:
/OUT:"C:\Users\User\IT\Coding\C\TokenGrabber\Release\TokenGrabber.exe" /MANIFEST /NXCOMPAT /PDB:"C:\Users\User\IT\Coding\C\TokenGrabber\Release\TokenGrabber.pdb" /DYNAMICBASE "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" /DEBUG /MACHINE:X86 /OPT:REF /SAFESEH /INCREMENTAL:NO /PGD:"C:\Users\User\IT\Coding\C\TokenGrabber\Release\TokenGrabber.pgd" /SUBSYSTEM:WINDOWS /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /ManifestFile:"Release\TokenGrabber.exe.intermediate.manifest" /OPT:ICF /ERRORREPORT:PROMPT /NOLOGO /TLBID:1 /NODEFAULTLIB /ENTRY:wWinMain 
