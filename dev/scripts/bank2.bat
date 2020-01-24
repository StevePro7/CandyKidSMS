@echo off
REM echo Generate levels

REM cd ..
cd banks

folder2c bank2 bank2 2
sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK2 bank2.c

del *.asm > nul
del *.lst > nul
del *.sym > nul

REM cd ..
REM cd scripts