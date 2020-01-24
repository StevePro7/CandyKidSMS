REM bank5
@echo off

cd ..
cd banks
cd bank5

:: Tiles
bmp2tile.exe raw\main_tiles.png -savetiles "main_tiles (tiles).psgcompr" -noremovedupes -planar -tileoffset 64 -savetilemap "main_tiles (tilemap).bin" -savepalette "main_tiles (palette).bin" -fullpalette -exit

:: Tiles
bmp2tile.exe raw\splash.bmp -savetiles "splash (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "splash (tilemap).stmcompr" -savepalette "splash (palette).bin" -fullpalette -exit

cd ..
folder2c bank5 bank5 5
sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK5 bank5.c

del *.asm > nul
del *.lst > nul
del *.sym > nul

cd ..
cd scripts