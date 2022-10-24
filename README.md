# CandyKidSMS
Candy Kid for the Sega Master System

22/03/2021
One thing that I noticed is that on boss screen if you lose all lives then you are prompted to continue
If you choose No then game over but when you continue you have to repeat the world / round before boss
e.g. W01 R02 or W03 R10
But I will leave this as a game design decision because if I auto skip then potentially you may not see
the Beat screen on W10 R10 and Continue No


01/02/2020
Here is the out outline for SRAM
0000
0010	frames		256 * 2 bytes	512
0210	commands	256 * 1 bytes	256
0310	args		256 * 1 bytes	256
0410	F7

If I open the save files in HxD then they do seem to refresh after re-save


E:\GitHub\StevePro7\CandyKidSMS\dev
C:\SEGA\meka\Saves
E:\Fusion


29/01/2020
Here is the link to the "SpriteClippingWindow"
C:\Bitbucket\SteveProXNA\actionstuff\Personal\Presentations\_CodeAFTER\60_SpriteClippingWindow\dev
_sm_sManager.c


OK - I finally sorted out the command pattern:
unsigned int frame
unsigned char command
unsigned char args

command will be mover or speed
args will be:
mover	direction
speed	slower or faster


The gamer will have slow / fast for easy / hard
i.e.
EASY	HARD
1,0		2,0		SLOW
2,0		4,0		FAST

I will have a predetermined list of the speeds for each enemy
for each world on both easy + hard and will cycle thru array
when Kid eats more than X candy then each actor goes faster

NB: the enemy hands will be random delays per actor - this doesn't matter across tiles


Game will store 256 commands
if >= 256 then will wrap = 0
First command on frame = 0 will be start command

Will have max 65535 frames to play 1x level
that is 65535 / 60 = 1093 seconds or ~ 18mins
if go beyond 65535 for 1x level then time over