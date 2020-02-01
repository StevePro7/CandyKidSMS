# CandyKidSMS
Candy Kid for the Sega Master System

01/02/2020
Here is the out outline for SRAM
0000
0010	frames		256 * 2 bytes	512
0210	commands	256 * 1 bytes	256
0310	args		256 * 1 bytes	256
0410	F7


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