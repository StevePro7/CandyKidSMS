cd ..
cd gfx

:: Tiles
bmp2tile.exe raw\font_tiles.bmp -savetiles "font_tiles (tiles).psgcompr" -noremovedupes -planar -tileoffset 0  -savetilemap "font_tiles (tilemap).bin" -savepalette "font_tiles (palette).bin" -fullpalette -exit
bmp2tile.exe raw\game_tiles.png -savetiles "game_tiles (tiles).psgcompr" -noremovedupes -planar -tileoffset 64 -savetilemap "game_tiles (tilemap).bin" -savepalette "game_tiles (palette).bin" -fullpalette -exit

:: Sprites
:: https://github.com/maxim-zhao/bmp2tile
bmp2tile.exe raw\sprites.png -savetiles "sprites (tiles).psgcompr" -noremovedupes -nomirror -planar -tileoffset 0 -savepalette "sprites (palette).bin" -fullpalette  -spritepalette -exit

cd ..
cd dev