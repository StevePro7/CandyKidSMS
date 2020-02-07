@echo off

:: Time build START
:: Reference: https://stackoverflow.com/questions/673523/how-do-i-measure-execution-time-of-a-command-on-the-windows-command-line
set _time=%time: =0%
set /a _hours=100%_time:~0,2%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
set /a _started=_hours*60*60*100+_min*60*100+_sec*100+_cs


:: Compile
cd devkit
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 _sms_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 _snd_manager.c
cd ..


cd engine
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 asm_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 actor_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 audio_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 board_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 collision_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 command_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 content_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 delay_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 enemy_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 enum_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 font_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 frame_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 gamer_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 hack_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 global_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 input_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 level_manager.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 move_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 screen_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 sprite_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 storage_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 tile_manager.c
cd ..

cd object
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 audio_object.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 board_object.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 command_object.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 delay_object.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 enemy_object.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 frame_object.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 gamer_object.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 hack_object.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 level_object.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 move_object.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 state_object.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 savegame_object.c
cd ..

cd screen
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 none_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 splash_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 title_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 intro_screen.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 load_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 demo_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 play_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 record_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 save_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 pass_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 dead_screen.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 cont_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 over_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 beat_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 test_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 func_screen.c
cd ..


:: echo Build main
sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 main.c


:: Time build -END-
set _time=%time: =0%
set /a _hours=100%_time:~0,2%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
set /a _duration=_hours*60*60*100+_min*60*100+_sec*100+_cs-_started
set /a _hours=_duration/60/60/100,_min=100+_duration/60/100%%60,_sec=100+(_duration/100%%60%%60),_cs=100+_duration%%100
echo.
echo Time taken: %_sec:~-2%.%_cs:~-2% secs
echo.


:: Link
sdcc -o output.ihx -mz80 --no-std-crt0 --data-loc 0xC000  ^
..\crt0\crt0_sms.rel main.rel ^
-Wl-b_BANK2=0x8000 ^
-Wl-b_BANK3=0x8000 ^
-Wl-b_BANK4=0x8000 ^
-Wl-b_BANK5=0x8000 ^
-Wl-b_BANK6=0x8000 ^
-Wl-b_BANK7=0x8000 ^
..\lib\SMSlib.lib ^
..\lib\PSGlib.rel ^
banks\bank2.rel ^
banks\bank3.rel ^
banks\bank4.rel ^
banks\bank5.rel ^
banks\bank6.rel ^
banks\bank7.rel ^
devkit\_sms_manager.rel ^
devkit\_snd_manager.rel ^
engine\asm_manager.rel engine\actor_manager.rel engine\audio_manager.rel  engine\board_manager.rel ^
engine\collision_manager.rel engine\command_manager.rel engine\content_manager.rel ^
engine\delay_manager.rel engine\enemy_manager.rel engine\enum_manager.rel engine\font_manager.rel ^
engine\frame_manager.rel engine\gamer_manager.rel engine\global_manager.rel engine\hack_manager.rel engine\input_manager.rel ^
engine\level_manager.rel engine\move_manager.rel engine\screen_manager.rel engine\sprite_manager.rel ^
engine\storage_manager.rel engine\tile_manager.rel ^
object\audio_object.rel ^
object\board_object.rel object\command_object.rel object\delay_object.rel object\enemy_object.rel object\frame_object.rel ^
object\gamer_object.rel object\hack_object.rel object\level_object.rel object\move_object.rel ^
object\state_object.rel object\savegame_object.rel ^
screen\none_screen.rel screen\splash_screen.rel screen\title_screen.rel screen\intro_screen.rel screen\load_screen.rel ^
screen\demo_screen.rel screen\play_screen.rel 	screen\record_screen.rel screen\save_screen.rel screen\pass_screen.rel ^
screen\dead_screen.rel screen\cont_screen.rel 	screen\over_screen.rel 	screen\beat_screen.rel 	screen\test_screen.rel ^
screen\func_screen.rel ^
gfx.rel ^
psg.rel

:: Execute
ihx2sms output.ihx output.sms


:: Delete
cd devkit
if exist "*.asm" del "*.asm" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.sym" del "*.sym" > nul
cd ..

cd engine
if exist "*.asm" del "*.asm" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.sym" del "*.sym" > nul
cd ..

cd object
if exist "*.asm" del "*.asm" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.sym" del "*.sym" > nul
cd ..

cd screen
if exist "*.asm" del "*.asm" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.sym" del "*.sym" > nul
cd ..

if exist "*.asm" del "*.asm" > nul
if exist "*.ihx" del "*.ihx" > nul
if exist "*.lk"  del "*.lk" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.noi" del "*.noi" > nul
if exist "*.sym" del "*.sym" > nul


:: Run
::java -jar C:\SEGA\Emulicious\Emulicious.jar output.sms
::C:\SEGA\meka\mekaw.exe output.sms
output.sms