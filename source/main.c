////////////////////////////////////////////////////////////////////////////////
// Filename: main.c
////////////////////////////////////////////////////////////////////////////////
/////////////////
// My INCLUDES //
/////////////////
#include "systemincludes.h"
#include "playerstruct.h"
#include "game.h"

void runGame();
asm("mov r0,r0");
//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------

	// the vblank interrupt must be enabled for VBlankIntrWait() to work
	irqInit();
	irqSet(IRQ_VBLANK, mmVBlank);
	irqEnable(IRQ_VBLANK);
	
	// generic setup function
	consoleDemoInit();
	mmInitDefault((mm_addr)soundbank_bin, 8);
	gameState = splash; // sets the initial gamestate

	// main loop
	while (1) 
	{

		runGame(); // runs the runGame function (game.c - L5)
		VBlankIntrWait();
		player.frame = player.frame + 1; //this is used in animations
		Battle.frame = Battle.frame + 1;//this is used in animations
		int i;
		for (i = 0; i < NUMBER_OF_ENEMIES; i++)
		{
			enemyai[i].frame = enemyai[i].frame + 1;
			if (enemyai[i].frame >= (FRAMETIME + 5))
			{
				enemyai[i].frame = 0;
			}
		}
		if (currentState != IDLE && player.frame >= (FRAMETIME+5))
		{
			player.frame = 0;
		}
		if (currentState != attacking && Battle.frame >= (FRAMETIME + 5))
		{
			Battle.frame = 0;
		}
		if (currentState != enemyAnimation && Battle.frame >= (FRAMETIME*2 + 5))
		{
			Battle.frame = 0;
		}
		mmFrame();
	}
}
