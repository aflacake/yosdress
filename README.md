# YosDress
Dress up game for Windows

[![Download YosDress](https://a.fsdn.com/con/app/sf-download-button)](https://sourceforge.net/projects/yosdress/files/latest/download)

## Contribution
Via MSYS2 not standalone (SourceForge/WinLibs).

### Install
In MinGW64, type this command to download SFML:
- UCRT64 example:
   `pacman -S mingw-w64-ucrt-x86_64-sfml`
- Or MINGW64:
   `pacman -S mingw-w64-x86_64-sfml`

### Compile YosDress
From the file where YosDress is located, compile it with SFML. If SFML isn't already installed, compile it.

File location: `cd /c/[USER]/[USER]/[DOCUMENTS]/[TO]/yosdress`

Compile: `g++ src/main.cpp -lsfml-graphics -lsfml-window -lsfml-system -o yosdress`
Or
```
g++ -std=c++20 src/main.cpp src/Character.cpp src/Button.cpp \
    -lsfml-graphics -lsfml-window -lsfml-system \
    -o yosdress
```

Run: `./yosdress`