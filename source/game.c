////////////////////////////////////////////////////////////////////////////////
// Filename: game.h
////////////////////////////////////////////////////////////////////////////////
#include "game.h"
void runGame() //this is the main game function, this is where everything happens inside the game
{
	runAnimation(player.objectRef, player.spriteRef, currentState, player.step); //runs animations every loop
	if (gameState == splash) //---------------------------------- SPLASH SCREEN ----------------------------------
	{


		
		//if (music == false)								//checks to see if music is already running
		//{
		//	mmStart(MOD_SPLASH_SND, MM_PLAY_ONCE);	//If no music is running, it plays this on a loop
		//	music = true;								//Sets the bool music to be true, to indicate that music is currently running
		//}
								//This function checks if keys are in use (controls.c - L63)
		setupFunction();					//setup function (system.c - L14)
		player.levelNumber = 1;							//sets the current levelNumber to 1, this was used in an older iteration to distinguish between different levels
		
		drawSplash();									//function to draw the splash screen (current - L537)
		keyUsed();		
	}

	if (gameState == menu)//---------------------------------- MENU ----------------------------------
	{
		drawMenu();										//function to draw the Menu (current - L551)
		keyUsed();
	}

	

	if (gameState == pause)//---------------------------------- PAUSED ----------------------------------
	{
		player.enable = 1;
		drawPause();
		myObj_function(player.objectRef, *player.yPos, player.rotation_scaling_flag, player.enable, 0, player.shape, *player.xPos, player.rotation_scaling_paramaters, player.horFlip, player.verFlip, player.size, player.spriteRef, SPRITE_PRIORITY, 0, 0);
		//stops player from moving after pause is removed
		player.upPressed = false;
		player.downPressed = false;
		player.leftPressed = false;
		player.rightPressed = false;
		keyUsed();
	}

	if (gameState == exit)//---------------------------------- EXIT ----------------------------------
	{
		drawExit();
		keyUsed();
	}

	if (gameState == options)//---------------------------------- OPTIONS ----------------------------------
	{
		drawOptions();
		
		keyUsed();
	}
	if (gameState == setupStressTest)
	{
		player.positionX = XSTART;
		player.positionY = YSTART;
		playersetup(player.levelNumber);				//Sets the players variables to their default values (playerStruct.c - L10)
		playerStart();
		drawBG();
		pathfindSetup();
		

		
		gameState = stressTest;
	}
	if (gameState == stressTest)
	{

		ifAlive(&player.alive, &player.enable);
		myObj_function(player.objectRef, *player.yPos, player.rotation_scaling_flag, player.enable, 0, player.shape, *player.xPos, player.rotation_scaling_paramaters, player.horFlip, player.verFlip, player.size, player.spriteRef, SPRITE_PRIORITY, 0, 0);
		updateOffset(getxPos(1), getyPos(1));
		pathFind();
	}
		keyUsed();
	

}
