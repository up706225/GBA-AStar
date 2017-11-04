////////////////////////////////////////////////////////////////////////////////
// Filename: controls.c
////////////////////////////////////////////////////////////////////////////////
#include "controls.h"




void heldKey()//CHECKS IF KEYS ARE HELD, NOT USED AS I FOUND THIS DIDNT WORK TOO WELL
{
	scanKeys();
	u16 keyHeld = keysHeld();

	if (keyHeld == KEY_UP)
	{
		player.upPressed = true;
	}
	else if (keyHeld != KEY_UP)
	{
		player.upPressed = false;
	}
	if (keyHeld == KEY_DOWN)
	{
		player.downPressed = true;
	}
	else if (keyHeld != KEY_DOWN)
	{
		player.downPressed = false;
	}
	if (keyHeld == KEY_LEFT)
	{
		player.leftPressed = true;
	}
	else if (keyHeld != KEY_LEFT)
	{
		player.leftPressed = false;
	}
	if (keyHeld == KEY_RIGHT)
	{
		player.rightPressed = true;
	}
	else if (keyHeld != KEY_RIGHT)
	{
		player.rightPressed = false;
	}
	if (keyHeld == KEY_A)
	{
		
	}
	if (keyHeld == KEY_B)
	{

	}
	if (keyHeld == KEY_START)
	{

	}
	if (keyHeld == KEY_SELECT)
	{

	}
}
void keyUsed()//CHECKS IF KEYS ARE BEING USED
{
	//---------------------------------- SOUND EFFECTS ----------------------------------

	scanKeys();
	u16 keyDown = keysDown();
	u16 keyUp = keysUp();

	if (keyUp == KEY_UP)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY UP - UP
	{
		player.upPressed = false;
		Menu.upPressed = false;
		currentState = IDLE;
	}
	if (keyUp == KEY_DOWN)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY DOWN - UP
	{
		player.downPressed = false;
		Menu.downPressed = false;
		currentState = IDLE;

	}
	if (keyUp == KEY_LEFT)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY LEFT - UP
	{
		player.leftPressed = false;
		currentState = IDLE;
	}
	if (keyUp == KEY_RIGHT)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY RIGHT - UP
	{
		player.rightPressed = false;
		currentState = IDLE;
	}
	if (keyUp == KEY_A)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY A - UP
	{
		Menu.aPressed = false;
		player.aPressed = false;
	}
	if (keyUp == KEY_B)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY B - UP
	{
		Menu.bPressed = false;
		player.bPressed = false;
	}
	if (keyUp == KEY_START)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY START - UP
	{
		Menu.startPressed = false;
		player.startPressed = false;
	}
	if (keyUp == KEY_SELECT)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY SELECT - UP
	{
		Menu.selectPressed = false;
		player.selectPressed = false;
	}
	if (keyDown == KEY_UP)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY UP - DOWN
	{


		//----------------------------------THE UP KEY IS USED IN THE MENU FOR NAVIGATION----------------------------------
		if (gameState == menu)//---------------------------------- MENU SCREEN ----------------------------------
		{

			if (menuP == nG && Menu.upPressed == false)
			{
				Menu.upPressed = true;
				clear_function(MENUX - 1, MENUY, 9);
				draw_function(MENUX - 1, MENUY + 2, 9, 0, ARROW);
				menuP = menuStressTest;
			}
			if (menuP == menuOptions && Menu.upPressed == false)	//CHANGES THE CURRENT MENU POSITION BASED ON ITS CURRENT POSITION AND THE MENU ITEM ABOVE IT
			{
				Menu.upPressed = true;
				clear_function(MENUX - 1, MENUY + 1, 9);
				draw_function(MENUX - 1, MENUY, 9, 0, ARROW);
				menuP = nG;
			}
			if (menuP == menuStressTest && Menu.upPressed == false)
			{
				Menu.upPressed = true;
				clear_function(MENUX - 1, MENUY + 2, 9);
				draw_function(MENUX - 1, MENUY + 1, 9, 0, ARROW);
				menuP = menuOptions;
			}
		}
		if (gameState == exit)//---------------------------------- EXIT SCREEN ----------------------------------
		{
			if (exitM == yes && Menu.upPressed == false)
			{
				Menu.upPressed = true;
				clear_function(MENUX - 1, MENUY + 2, 9);
				draw_function(MENUX - 1, MENUY + 1, 9, 0, ARROW);
				exitM = no;
			}
			if (exitM == no && Menu.upPressed == false)
			{
				Menu.upPressed = true;
				clear_function(MENUX - 1, MENUY + 1, 9);
				draw_function(MENUX - 1, MENUY + 2, 9, 0, ARROW);
				exitM = yes;
			}
		}
	
		if (gameState == stressTest)
		{
			currentState = UP;
			player.spriteRef = 40;
			player.frame = 0;
			player.upPressed = true;		//SETS THE PLAYERS UPPRESSED BOOL TO TRUE (FOR USE MOVING THE PLAYER)	
		}
	}
	if (keyDown == KEY_DOWN)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY DOWN - DOWN
	{

	
		if (gameState == menu)
		{
			if (menuP == nG && Menu.downPressed == false)
			{
				Menu.downPressed = true;
				clear_function(MENUX - 1, MENUY, 9);
				draw_function(MENUX - 1, MENUY + 1, 9, 0, ARROW);
				menuP = menuOptions;
			}
			if (menuP == menuOptions && Menu.downPressed == false)
			{
				Menu.downPressed = true;
				clear_function(MENUX - 1, MENUY+1, 9);
				draw_function(MENUX - 1, MENUY + 2, 9, 0, ARROW);
				menuP = menuStressTest;
			}
			if (menuP == menuStressTest && Menu.downPressed == false)
			{
				Menu.upPressed = true;
				clear_function(MENUX - 1, MENUY + 2, 9);
				draw_function(MENUX - 1, MENUY, 9, 0, ARROW);
				menuP = nG;
			}
		}
		if (gameState == exit)
		{
			if (exitM == no && Menu.downPressed == false)
			{
				Menu.downPressed = true;
				clear_function(MENUX - 1, MENUY + 1, 9);
				draw_function(MENUX - 1, MENUY + 2, 9, 0, ARROW);
				exitM = yes;
			}
			if (exitM == yes && Menu.downPressed == false)
			{
				Menu.downPressed = true;
				clear_function(MENUX - 1, MENUY + 2, 9);
				draw_function(MENUX - 1, MENUY + 1, 9, 0, ARROW);
				exitM = no;
			}
		}
		if (gameState == options)
		{
			if (optionP == option1 && Menu.downPressed == false)
			{
				Menu.downPressed = true;
				clear_function(MENUX - 1, MENUY, 9);
				draw_function(MENUX - 1, MENUY + 1, 9, 0, ARROW);
				optionP = option2;
			}
			if (optionP == option2 && Menu.downPressed == false)
			{
				Menu.downPressed = true;
				clear_function(MENUX - 1, MENUY + 1, 9);
				draw_function(MENUX - 1, MENUY, 9, 0, ARROW);
				optionP = option1;
			}
		}
		if (gameState == stressTest)
		{
			player.spriteRef = 32;
			player.frame = 0;
			currentState = DOWN;
			player.downPressed = true;
		}
		
	}
	if (keyDown == KEY_LEFT)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY LEFT - DOWN
	{
		if (gameState == stressTest)
		{
			player.spriteRef = 52;
			player.frame = 0;
			currentState = LEFT;
			player.leftPressed = true;
		}
	}
	if (keyDown == KEY_RIGHT) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY RIGHT - DOWN
	{
		if (gameState == stressTest)
		{
			player.spriteRef = 46;
			player.frame = 0;
			currentState = RIGHT;
			player.rightPressed = true;
		}
	}
	if (keyDown == KEY_A) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY A - DOWN
	{
		if (gameState == menu)
		{
			clearCharacters();//CLEARS CHARACTERS

			if (menuP == nG)
			{
				playSFX(33);
				mmStop();
				music = false;
				clearObjects();
				player.lives = PLAYER_MAX_LIVES;
				gameState = setup;
				Menu.arrow = false;
				setupLevel(player.levelNumber);
				//asm("mov r0,r0");
			}
			if (menuP == menuOptions)
			{
				playSFX(33);
				clearObjects();
				Menu.arrow = false;
				optionP = option1;
				gameState = options;
				//asm("mov r0,r0");
			}
			if (menuP == menuStressTest)
			{
				playSFX(33);
				clearObjects();
				Menu.arrow = false;
				gameState = setupStressTest;
				//asm("mov r0,r0");
			}
		}
		
		if (gameState == stressTest)
		{
			switch (player.drawBG)
			{
				case true: player.drawBG = false;
					break;
				case false: player.drawBG = true;
					break;
			}
			if (player.drawBG == false)
			{
				int x, y;
				for (x = 0; x < 32; x++)
				{
					for (y = 0; y < 32; y++)
					{
						clear_function(y, x, 4);
					}
				}
			}

		}		
		if (gameState == pause)
		{
			mmResume();
			playerStart();
			clearCharacters();
			gameState = playing;
		}
		if (gameState == exit)
		{
			if (exitM == no)
			{
				playSFX(33);
				Menu.arrow = false;
				clearCharacters();
				gameState = pause;

			}
			if (exitM == yes)
			{
				playSFX(31);
				clearCharacters();
				clearObjects();
				Menu.arrow = false;
				gameState = splash;
			}
		}
		if (gameState == options)
		{
			if (optionP == option1)
			{
				playSFX(33);
				clearObjects();
				Menu.arrow = false;
				player.levelNumber = 1;
				player.level = 1;
			}
			if (optionP == option2)
			{
				playSFX(33);
				clearObjects();
				Menu.arrow = false;
				player.levelNumber = 2;
				player.level = 2;
			}
		}
	}
	if (keyDown == KEY_B)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY B - DOWN
	{
		
		if (gameState == pause && Menu.bPressed == false)
		{
			playSFX(31);
			clearCharacters();
			Menu.bPressed = true;
			Menu.arrow = false;
			exitM = no;
			gameState = exit;
		}
		if (gameState == exit  && Menu.bPressed == false)
		{
			playSFX(31);
			clearCharacters();
			Menu.bPressed = true;
			gameState = pause;
		}
		if (gameState == options)
		{
			clearObjects();
			clearCharacters();
			Menu.arrow = false;
			menuP = nG;
			gameState = menu;
		}
		
	}
	if (keyDown == KEY_START)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY START - DOWN
	{
		if (gameState == splash)
		{
			playSFX(33);
			mmStop();
			music = false;
			clearCharacters();
			Menu.arrow = false;
			menuP = nG;
			gameState = menu;
		}
		if (gameState == pause && Menu.startPressed == false)
		{
			mmResume();
			Menu.startPressed = true;
			clearCharacters();
			playerStart();
			gameState = playing;
		}
	}
	if (keyDown == KEY_SELECT) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY SELECT - DOWN
	{
	
	}

	moveCheck();

}
