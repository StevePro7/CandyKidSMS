@echo off

:: https://stackoverflow.com/questions/673523/how-do-i-measure-execution-time-of-a-command-on-the-windows-command-line
:: Calculate the start timestamp
set _time=%time: =0%
set /a _hours=100%_time:~0,2%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
set /a _started=_hours*60*60*100+_min*60*100+_sec*100+_cs


cd angame
:: sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 _sms_manager.c
:: sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 _snd_manager.c
cd ..

:: echo Build main
sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 main.c



:: Calculate the difference in cSeconds
set _time=%time: =0%
set /a _hours=100%_time:~0,2%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
set /a _duration=_hours*60*60*100+_min*60*100+_sec*100+_cs-_started

:: Populate variables for rendering (100+ needed for padding)
set /a _hours=_duration/60/60/100,_min=100+_duration/60/100%%60,_sec=100+(_duration/100%%60%%60),_cs=100+_duration%%100

echo.
echo Time taken: %_sec:~-2%.%_cs:~-2% secs
echo.


:: echo Linking
sdcc -o output.ihx -mz80 --no-std-crt0 --data-loc 0xC000  ^
..\crt0\crt0_sms.rel main.rel ^
..\lib\SMSlib.lib ^
..\lib\PSGlib.rel ^
angame\_sms_manager.rel ^
angame\_snd_manager.rel

if %errorlevel% NEQ 0 goto :EOF

:: echo Binary output
ihx2sms output.ihx output.sms


:: echo Delete
if exist "*.asm" del "*.asm" > nul
if exist "*.ihx" del "*.ihx" > nul
if exist "*.lk" del "*.lk" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.noi" del "*.noi" > nul
if exist "*.sym" del "*.sym" > nul

C:\SEGA\Fusion\Fusion.exe output.sms
::C:\SEGA\meka\mekaw.exe output.sms
::java -jar C:\SEGA\Emulicious\Emulicious.jar output.sms