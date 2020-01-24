#include "main.h"

void main (void)
{
	devkit_SMS_setSpritePaletteColor( 0, 1, 2, 3 );
	devkit_SMS_displayOn();

	for( ;;)
	{
		devkit_SMS_waitForVBlank();
	}
}