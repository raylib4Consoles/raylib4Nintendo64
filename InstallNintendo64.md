# Install for Nintendo 64
- Install last libdragon using the unstable branch https://github.com/DragonMinded/libdragon/tree/unstable follow steps from https://github.com/DragonMinded/libdragon/wiki/Installing-libdragon#compile-and-install-the-toolchain-from-sources
- clone this repository and execute if you are in Unix like environtment including wsl2:
```
./nintendo64build.sh
```

# Samples
- in each sample use make to build
```
% cd samples
% ls
models  shapes
% cd shapes
% ls
basic_shapes logo_raylib_anim
% cd logo_raylib_anim
% ls
Makefile  main.c  assets
% make
    [CC] main.c
    [LD] build/raylib.elf
      text       data        bss      total filename
    229432     113588      36716     379736 build/raylib.elf
    [SPRITE] filesystem/shape.sprite
    [DFS] build/raylib.dfs
    [Z64] raylib.z64
```
- If you have a flash cartridge with UNFLoader support for example using windows 
```
%  .\UNFLoader.exe -f 3 -r PATHTOYOURSAMPLEZ64 -d 
```
- If you are using an emulator for example Ares in windows
```
.\ares.exe --system nintendo64 PATHTOYOURSAMPLEZ64
```
You can use wsl2 for all your compiling work and use path to your samples like:
```
\\wsl.localhost\Ubuntu\usr\local\n64dev\git\raylib4Nintendo64\samples\shapes\logo_raylib_anim\raylib.z64
```
Enjoy!!!!

