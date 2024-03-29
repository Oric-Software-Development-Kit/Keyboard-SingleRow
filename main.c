// --------------------------------------
// Single Row Keyboard Read
// --------------------------------------
// (c) 2010-2020 Defence Force
// Authors: Twilighte, Chema and Dbug
// --------------------------------------
// This code is provided as-is:
// We do not assume any responsability concerning the fact this is a bug-free software !!!
// You can use this example code without any limitation, but if you do, it would be nice
// if you could mention the origin somewhere and inform us :)
// --------------------------------------
// For more information, please contact us on internet:
// e-mail: mike@defence-force.org
// URL: http://www.defence-force.org
// --------------------------------------
// Note: This text was typed with a Win32 editor. So perhaps the text will not be
// displayed correctly with other OS.


#include <stdio.h>

#include "defines.h"

// Initialization of ISR
extern void InitIRQ();
extern unsigned char gKey;         // One bit per key pressed

void main()
{
    cls();
	printf("Single Row Keyboard Read demo program\n");
    printf("Left Arrow\n");
    printf("Right Arrow\n");
    printf("Up Arrow\n");
    printf("Down Arrow\n");
    printf("Space\n");
    printf("Left Shift\n");
    printf("< ,\n");
    printf("> .\n");

    InitIRQ();
	while (1)
	{
        poke(0xbb80+40*2,(gKey & KEY_LEFT_ARROW)?16+1:16+2);
        poke(0xbb80+40*3,(gKey & KEY_RIGHT_ARROW)?16+1:16+2);
        poke(0xbb80+40*4,(gKey & KEY_UP_ARROW)?16+1:16+2);
        poke(0xbb80+40*5,(gKey & KEY_DOWN_ARROW)?16+1:16+2);
        poke(0xbb80+40*6,(gKey & KEY_SPACE)?16+1:16+2);
        poke(0xbb80+40*7,(gKey & KEY_LEFT_SHIFT)?16+1:16+2);
        poke(0xbb80+40*8,(gKey & KEY_LESS_THAN)?16+1:16+2);
        poke(0xbb80+40*9,(gKey & KEY_GREATER_THAN)?16+1:16+2);

        sprintf((char *)(0xbb80+40*10),"%c gKey=%u  ",16+4,gKey);
	}   
}

