////////////////////////////////////////////////////////////////////////////////
// Filename: system.c
////////////////////////////////////////////////////////////////////////////////

/////////////////
// My INCLUDES //
/////////////////
#include "system.h"
//---------------------------------------------------------------------------------
// SETUP
//---------------------------------------------------------------------------------
//This is the main setup function, this sets up pointers, the graphical settings, sprites and characters
void setupFunction()
{
	pointersFunc();
	
	//---------------------------------------------------------------------------------
	// FONT/SPRITE SETUP - OLD MANUAL METHOD 
	//---------------------------------------------------------------------------------
	// *****************
	// Character (font) 
	// *****************
	//tile ref, pixels
	//--- Adds the custom characters to the character list
	//myChar_function(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0); //character tile 0 (blank)
	//myChar_function(1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0); //character tile 1 (backwards L) 
	//myChar_function(2,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0); //character tile 2 (backwards L)
	//myChar_function(3,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0); //character tile 3 (backwards L)
	//
	//// *****************
	//// Sprite
	//// *****************
	////tile ref, pixels
	////--- Adds the custom characters to the sprite list
	//mySprite_function(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0); //sprite tile 0 (blank)
	//mySprite_function(1,0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0); //sprite tile 1
	//mySprite_function(2,0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0); //sprite tile 1
	//mySprite_function(3,0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0); //sprite tile 1
	//mySprite_function(4,0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0); //sprite tile 1
	
	//---------------------------------------------------------------------------------
	// FONT/SPRITE SETUP - OLD AUTOMATED METHOD 
	//---------------------------------------------------------------------------------
	//int i;
	//for (i = 0; i < 256; i++)
	//{
	//	point.characterAddress[i] = spriteData[i];
	//}
	//auto adds sprites to tile list
	//for (i = 0; i < 2048; i++)
	//{
	//	point.spriteAddress[i] = spriteData[i];
	//}

	//---------------------------------------------------------------------------------
	// FONT/SPRITE SETUP - NEW ASM METHOD
	//---------------------------------------------------------------------------------
	int start = 0;
	int finish = 256;
	addSprites(&start, &finish, &point.characterAddressFirst[0], &spriteData[0]); //Adds charactres to tile list
	finish = 2048;
	addSprites(&start, &finish, &point.characterAddress[0], &spriteData[0]); //Adds charactres to tile list
	addSprites(&start, &finish, &point.spriteAddress[0], &spriteData[0]);	//Adds sprites to sprite list
	//---------------------------------------------------------------------------------
	// GRAPHICS SETUP
	//---------------------------------------------------------------------------------
	// *****************
	// Display
	// *****************
	//graphics_mode (0 - 5), obj_data_mode (0 - 1), bg0 off/on (0 - 1), bg1 off/on (0 - 1), bg2 bg1 off/on (0 - 1), bg3 bg1 off/on (0 - 1), obj bg1 off/on (0 - 1))
	//myDisplay_function(0, 1, 1, 1, 1, 1, 1);
	//(int graphics_mode (0-5), int pageSelect (0 - 1) (modes4/5 only), int hBlank (0 - 1), int obj_data_mode (0 - 1), int bg0 (0 - 1), int bg1 (0 - 1), int bg2 (0 - 1), int bg3 (0 - 1), int obj (0 - 1), int window0 (0 - 1), int window1 (0 - 1), int objectWindow (0 - 1))
	myDisplayNew_function(0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0);
	// *****************
	// Backgroundz
	// *****************
	//bg_layer (0 - 3), layer_priority (0 - 3), char_base_block (0 - 3), colour_mode (0 - 16), screen_base_block (0 - 31), screen_size (0 - 3)
	mybg_function(0, 1, 0, 0, 8, 0);
	mybg_function(1, 3, 0, 0, 11, 1);
	mybg_function(2, 2, 0, 0, 9, 0);
	mybg_function(3, 0, 0, 0, 4, 0);


	//---------------------------------------------------------------------------------
	// PALETTE SETUP
	//---------------------------------------------------------------------------------
	// *****************
	// Background palette
	// *****************
	//palette (0 - 16), palette tile (0 - 16) , red (0 - 31), green (0 - 31), blue (0 - 31)
	bgPalette_function(0, 0, 0, 15, 15);//BG colour
	bgPalette_function(0, 1, 0, 0, 0);//Black
	bgPalette_function(0, 2, 31, 0, 0);//Red
	bgPalette_function(0, 3, 0, 31, 0); //green
	bgPalette_function(0, 4, 0, 0, 31); //blue
	bgPalette_function(0, 5, 31, 31, 0); //Yellow
	bgPalette_function(0, 6, 31, 31, 31); //white
	bgPalette_function(0, 7, 31, 0, 31); //purple
	bgPalette_function(0, 8, 0, 31, 31); //light blue
	bgPalette_function(0, 9, 13, 8, 5); //brown
	bgPalette_function(0, 10, 0, 14, 0); //dark green
	bgPalette_function(0, 11, 14, 14, 14); //grey
	bgPalette_function(0, 12, 9, 9, 8); //dark grey
	bgPalette_function(0, 13, 27, 0, 0);//RED
	bgPalette_function(0, 14, 31, 22, 25);//Pink

	bgPalette_function(1, 0, 0, 0, 31);//BG colour
	bgPalette_function(1, 1, 0, 0, 0);//Black
	bgPalette_function(1, 2, 31, 0, 0);//Red
	bgPalette_function(1, 3, 0, 31, 0); //green
	bgPalette_function(1, 4, 0, 0, 31); //blue
	bgPalette_function(1, 5, 31, 31, 0); //Yellow
	bgPalette_function(1, 6, 31, 31, 31); //white
	bgPalette_function(1, 7, 31, 0, 31); //purple
	bgPalette_function(1, 8, 0, 31, 31); //light blue
	bgPalette_function(1, 9, 13, 8, 5); //brown
	bgPalette_function(1, 10, 0, 14, 0); //dark green
	bgPalette_function(1, 11, 14, 14, 14); //grey
	bgPalette_function(1, 12, 9, 9, 8); //dark grey
	bgPalette_function(1, 13, 27, 0, 0);//RED
	bgPalette_function(1, 14, 31, 22, 25);//Pink
	// *****************
	// Object palette 
	// *****************
	//palette (0 - 16), palette tile (0 - 16) , red (0 - 31), green (0 - 31), blue (0 - 31)
	objPalette_function(0, 0, 31, 0, 0);//Blank (BG) colour - Yellow
	objPalette_function(0, 1, 0, 0, 0);//Black
	objPalette_function(0, 2, 31, 0, 0);//Red
	objPalette_function(0, 3, 0, 31, 0); //green
	objPalette_function(0, 4, 0, 0, 31); //blue
	objPalette_function(0, 5, 31, 31, 0); //Yellow
	objPalette_function(0, 6, 31, 31, 31); //white
	objPalette_function(0, 7, 31, 0, 31); //purple
	objPalette_function(0, 8, 0, 31, 31); //light blue
	objPalette_function(0, 9, 13, 8, 5); //brown
	objPalette_function(0, 10, 0, 14, 0); //dark green
	objPalette_function(0, 11, 14, 14, 14); //grey	
	objPalette_function(0, 12, 9, 9, 8);//dark grey
	objPalette_function(0, 13, 27, 0, 0);//RED
	objPalette_function(0, 14, 31, 22, 25);//Pink


}
void updateOffset(int xPos, int yPos)
{
	//if (xPos > 31 && xPos < 200)
	//{
	//	player.screenPosX = xPos;
	//}
	//if (yPos > 31 && yPos < 122)
	//{
	//	player.screenPosY = yPos;
	//}
	point.BGHOFS[2] = player.screenPosX;
	point.BGVOFS[2] = player.screenPosY;
	point.BGHOFS[6] = player.screenPosX;
	point.BGVOFS[6] = player.screenPosY;
}

// *****************
// Display
// *****************
//sets up the display, selecting graphics mode, turning objects on/off and turning on the backgrounds - 
void myDisplay_function(int graphics_mode, int obj_data_mode, int bg0, int bg1, int bg2, int bg3, int obj)
{
	point.DISPCNT[0] = ((obj << 12) | (bg3 << 11) | (bg2 << 10) | (bg1 << 9) | (bg0 << 8) | (obj_data_mode << 6) | (graphics_mode << 0));
}
void myDisplayNew_function(int graphics_mode, int pageSelect, int hBlank, int obj_data_mode, int bg0, int bg1, int bg2, int bg3, int obj, int window0, int window1, int objectWindow)
{
	point.DISPCNT[0] = ((objectWindow << 15) | (window1 << 14) | (window0 << 13) | (obj << 12) | (bg3 << 11) | (bg2 << 10) | (bg1 << 9) | (bg0 << 8) | (obj_data_mode << 6) | (hBlank << 5) | (pageSelect << 4) | (graphics_mode << 0));
}

// *****************
// Background
// *****************
//sets up the background, configuring (BG0CNT - BG3CNT) automatically - BGCNT number (0 - 3), layers priority, characters base block, the colour mode, screen baseblock, screen size
void mybg_function(int bg_layer, int layer_priority, int char_base_block, int colour_mode, int screen_base_block, int screen_size)
{
	point.BGCNT[bg_layer] = ((screen_size << 14) | (screen_base_block << 8) | (colour_mode << 7) | (char_base_block << 2) | (layer_priority << 0));
}

// *****************
// Background palette
// *****************
//creates the background pallete - palette number, tile number, RED, GREEN, BLUE - adjust to change the colours
void bgPalette_function(int palette, int palette_tile, int red, int green, int blue)
{
	int i = palette * 16; //Works out the palette number
	unsigned short *palette_address = (unsigned short *)&point.bg_palette[i]; //creates a pointer to the palette using the palette number

	palette_address[palette_tile] = ((blue << 10) | (green << 5) | (red << 0)); //uses the pointer created above and the tile number to apply the colour to a tile
}

// *****************
// Object palette
// *****************
//creates the objects pallete - palette number, tile number, RED, GREEN, BLUE - adjust to change the colours
void objPalette_function(int palette, int palette_tile, int red, int green, int blue)
{
	int i = palette * 16;//Works out the palette number
	unsigned short *palette_address = (unsigned short *)&point.obj_palette[i]; //creates a pointer to the palette using the palette number

	palette_address[palette_tile] = ((blue << 10) | (green << 5) | (red << 0));//uses the pointer created above and the tile number to apply the colour to a tile
}

// *****************
// Character (font) 
// *****************
//manually add characters to the character library
void myChar_function(int tile_ref,
	int a1, int b1, int c1, int d1, int e1, int f1, int g1, int h1,
	int a2, int b2, int c2, int d2, int e2, int f2, int g2, int h2,
	int a3, int b3, int c3, int d3, int e3, int f3, int g3, int h3,
	int a4, int b4, int c4, int d4, int e4, int f4, int g4, int h4,
	int a5, int b5, int c5, int d5, int e5, int f5, int g5, int h5,
	int a6, int b6, int c6, int d6, int e6, int f6, int g6, int h6,
	int a7, int b7, int c7, int d7, int e7, int f7, int g7, int h7,
	int a8, int b8, int c8, int d8, int e8, int f8, int g8, int h8)
{
	int i = tile_ref * 8;//Works out the tile number 
	unsigned int *character = (unsigned int *)&point.characterAddress[i];//creates a pointer to the character location

	character[0] = ((h1 << 28) | (g1 << 24) | (f1 << 20) | (e1 << 16) | (d1 << 12) | (c1 << 8) | (b1 << 4) | (a1 << 0)); //uses the pointer to set each row of the character
	character[1] = ((h2 << 28) | (g2 << 24) | (f2 << 20) | (e2 << 16) | (d2 << 12) | (c2 << 8) | (b2 << 4) | (a2 << 0));
	character[2] = ((h3 << 28) | (g3 << 24) | (f3 << 20) | (e3 << 16) | (d3 << 12) | (c3 << 8) | (b3 << 4) | (a3 << 0));
	character[3] = ((h4 << 28) | (g4 << 24) | (f4 << 20) | (e4 << 16) | (d4 << 12) | (c4 << 8) | (b4 << 4) | (a4 << 0));
	character[4] = ((h5 << 28) | (g5 << 24) | (f5 << 20) | (e5 << 16) | (d5 << 12) | (c5 << 8) | (b5 << 4) | (a5 << 0));
	character[5] = ((h6 << 28) | (g6 << 24) | (f6 << 20) | (e6 << 16) | (d6 << 12) | (c6 << 8) | (b6 << 4) | (a6 << 0));
	character[6] = ((h7 << 28) | (g7 << 24) | (f7 << 20) | (e7 << 16) | (d7 << 12) | (c7 << 8) | (b7 << 4) | (a7 << 0));
	character[7] = ((h8 << 28) | (g8 << 24) | (f8 << 20) | (e8 << 16) | (d8 << 12) | (c8 << 8) | (b8 << 4) | (a8 << 0));
}

// *****************
// Sprite
// *****************
//manually add sprites to the sprite library
void mySprite_function(int tile_ref,
	int a1, int b1, int c1, int d1, int e1, int f1, int g1, int h1,
	int a2, int b2, int c2, int d2, int e2, int f2, int g2, int h2,
	int a3, int b3, int c3, int d3, int e3, int f3, int g3, int h3,
	int a4, int b4, int c4, int d4, int e4, int f4, int g4, int h4,
	int a5, int b5, int c5, int d5, int e5, int f5, int g5, int h5,
	int a6, int b6, int c6, int d6, int e6, int f6, int g6, int h6,
	int a7, int b7, int c7, int d7, int e7, int f7, int g7, int h7,
	int a8, int b8, int c8, int d8, int e8, int f8, int g8, int h8)
{
	int i = tile_ref * 8;//Works out the tile number 
	unsigned int *sprite = (unsigned int *)&point.spriteAddress[i];//creates a pointer to the sprite location

	sprite[0] = ((h1 << 28) | (g1 << 24) | (f1 << 20) | (e1 << 16) | (d1 << 12) | (c1 << 8) | (b1 << 4) | (a1 << 0)); //uses the pointer to set each row of the sprite
	sprite[1] = ((h2 << 28) | (g2 << 24) | (f2 << 20) | (e2 << 16) | (d2 << 12) | (c2 << 8) | (b2 << 4) | (a2 << 0));
	sprite[2] = ((h3 << 28) | (g3 << 24) | (f3 << 20) | (e3 << 16) | (d3 << 12) | (c3 << 8) | (b3 << 4) | (a3 << 0));
	sprite[3] = ((h4 << 28) | (g4 << 24) | (f4 << 20) | (e4 << 16) | (d4 << 12) | (c4 << 8) | (b4 << 4) | (a4 << 0));
	sprite[4] = ((h5 << 28) | (g5 << 24) | (f5 << 20) | (e5 << 16) | (d5 << 12) | (c5 << 8) | (b5 << 4) | (a5 << 0));
	sprite[5] = ((h6 << 28) | (g6 << 24) | (f6 << 20) | (e6 << 16) | (d6 << 12) | (c6 << 8) | (b6 << 4) | (a6 << 0));
	sprite[6] = ((h7 << 28) | (g7 << 24) | (f7 << 20) | (e7 << 16) | (d7 << 12) | (c7 << 8) | (b7 << 4) | (a7 << 0));
	sprite[7] = ((h8 << 28) | (g8 << 24) | (f8 << 20) | (e8 << 16) | (d8 << 12) | (c8 << 8) | (b8 << 4) | (a8 << 0));
}

// *****************
// Object list 
// ****************
//obj ref, 

//xCoor (0 - 511), ignore1, horizontal_flip (0 - 1), vertical_flip (0 - 1), size_lookup  (0 - 3), 
//sprite tile_number (0 - 1023), priority (0 - 3), palette (0 - 15),
//rotation and scaling

//adds sprite to the object list to be displayed
void myObj_function(int obj_ref,
	int yCoor, int rotation_scaling_flag, int object_disable, int ignore0, int shape_lookup,//yCoor (0 - 255),int rotation_scaling_flag (0-1) off/on, int object_disable (0-1) or double size flag (0-1) normal/double, int ignore0, int shape_lookup (0-3),
	int xCoor, int ignore1, int horizontal_flip, int vertical_flip, int size_lookup, //
	int tile_number, int priority, int palette,
	int rotation_scaling)
{
	int i = obj_ref * 4;//Works out the object tile number 
	unsigned short *obj = (unsigned short *)&point.obj_holderAddress[i];//sets the pointer to the object location

	obj[0] = ((shape_lookup << 14) | (ignore0 << 10) | (object_disable << 9) | (rotation_scaling_flag << 8) | (yCoor << 0)); //uses the pointer to set the values of the object 
	obj[1] = ((size_lookup << 14) | (vertical_flip << 13) | (horizontal_flip << 12) | (ignore1 << 9) | (xCoor << 0)); //xCoor (0 - 511), ignore if rotation/scaling not used, if it is, (0-31), horizontal_flip (0 - 1), vertical_flip (0 - 1), size_lookup  (0 - 3), 
	obj[2] = ((palette << 12) | (priority << 10) | (tile_number << 0));
	obj[3] = ((rotation_scaling << 0));
}


// *****************
// Draw 
// *****************
//draw - x, y, baseblock, pallet, character
//--- Draws one of the custom (font) characters added above (testing purposes)
//draws a character to the location specified 
void draw_function(int x, int y, int baseblock, int palette, int character)
{
	mybg_function(0, 1, 0, 0, 8, 0);
	mybg_function(1, 3, 2, 0, 11, 3);
	mybg_function(2, 2, 0, 0, 9, 0);
	mybg_function(3, 0, 0, 0, 4, 3);

	if (baseblock == 8)
	{
		point.base_block8[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
	else if (baseblock == 9)
	{
		point.base_block9[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
	else if (baseblock == 10)
	{
		point.base_block10[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
	else if (baseblock == 11)
	{
		point.base_block11[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
	else if (baseblock == 4)
	{
		point.base_block4[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
}
void drawOtherfunction(int x, int y, int baseblock, int palette, int character) //this is the same as draw_function, accept it uses character block 2, I wanted to be able to have another tile set for the backgrounds
{
	mybg_function(0, 0, 2, 0, 20, 0);
	mybg_function(1, 1, 2, 0, 24, 0);
	mybg_function(2, 2, 2, 0, 25, 0);
	mybg_function(3, 3, 2, 0, 27, 0);

	if (baseblock == 20)
	{
		point.base_block20[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
	else if (baseblock == 24)
	{
		point.base_block24[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
	else if (baseblock == 25)
	{
		point.base_block25[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
	else if (baseblock == 26)
	{
		point.base_block26[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
	else if (baseblock == 27)
	{
		point.base_block27[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
}
//// *****************
//// Clear 
//// *****************
////clear - x, y, baseblock
//clears any character at location specified
void clear_function(int x, int y, int baseblock)
{
	if (baseblock == 8)
	{
		point.base_block8[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
	else if (baseblock == 9)
	{
		point.base_block9[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
	else if (baseblock == 10)
	{
		point.base_block10[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
	else if (baseblock == 11)
	{
		point.base_block11[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
	else if (baseblock == 4)
	{
		point.base_block4[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
	if (baseblock == 20)
	{
		point.base_block20[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
	else if (baseblock == 24)
	{
		point.base_block24[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
	else if (baseblock == 25)
	{
		point.base_block25[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
	else if (baseblock == 26)
	{
		point.base_block26[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
	else if (baseblock == 27)
	{
		point.base_block27[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
}
//CLEARS ALL CHARACTERS FROM SCREEN
void clearCharacters()
{
	int y;
	int x;
	int b;
	for (b = 8; b < 12; b++)
	{
		for (y = 0; y < 32; y++)
		{
			for (x = 0; x < 32; x++)
			{
				clear_function(x, y, 4);
				clear_function(x, y, b);
			}
		}
	}
}
//CLEARS ALL OBJECTS FROM SCREEN AND STOPS PLAYERS/ENEMIES FROM CONTINUING TO MOVE
void  clearObjects()
{

	playerClear();
	int i;
	for (i = 0; i < 128; i++)
	{
		myObj_function(i, 0, 0, 0, 0, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0);
	}
}

void setupLevel(int levelNumber) //sets up the level with default info
{
	player.positionX = XSTART;
	player.positionY = YSTART;
	setPlayerStartStats();
	playersetup(levelNumber);
	playerStart();
	int t;
	for (t = 0; t < 128; t++)
	{
		point.obj_holderAddress[(t * 4) + 1] = 240;//SETS ALL OBJECTS TO BE OFSCREEN BEFORE ACTUALLY SETTING THINGS UP
	}
	playersetup(levelNumber);
	playerStart();
}

int getxPos(int object) //gets the current xpos
{
	int maskR = 255;
	int xPos = point.obj_holderAddress[(object * 4) + 1] & maskR;
	return xPos;
}
int getyPos(int object) //gets the current ypos
{
	int maskR = 255;
	int yPos = point.obj_holderAddress[(object * 4)] & maskR;
	return yPos;
}
//following functions move the player
void moveUp(int object, int yPos) //moves player
{
	int maskL = 65280;
	if (collision(object, UP) != UP && borderCollision(object, UP) != UP)
	{
		point.obj_holderAddress[(object * 4)] &= maskL;
		point.obj_holderAddress[(object * 4)] |= (yPos - MOVE_SPEED);
		if (player.frame == FRAMETIME && (player.spriteRef != 40 || player.spriteRef != 42 || player.spriteRef != 44))
		{
			currentState = UP;
			player.spriteRef = 40;
			player.frame = 0;
		}
	}
	else if (borderCollision(object, UP) == UP && player.screenPosY > 0)
	{
		player.screenPosY = player.screenPosY - MOVE_SPEED;
		if (player.frame == FRAMETIME && (player.spriteRef != 40 || player.spriteRef != 42 || player.spriteRef != 44))
		{
			currentState = UP;
			player.spriteRef = 40;
			player.frame = 0;
		}
	}
	
}
void moveDown(int object, int yPos)
{
	int maskL = 65280;
	if (collision(object, DOWN) != DOWN && borderCollision(object, DOWN) != DOWN)
	{
		point.obj_holderAddress[(object * 4)] &= maskL;
		point.obj_holderAddress[(object * 4)] |= (yPos + MOVE_SPEED);
		if (player.frame == FRAMETIME && (player.spriteRef != 32 || player.spriteRef != 34 || player.spriteRef != 36 || player.spriteRef != 38))
		{
			currentState = DOWN;
			player.spriteRef = 32;
			player.frame = 0;
		}
	}
	else if (borderCollision(object, DOWN) == DOWN && player.screenPosY < 352)
	{
		player.screenPosY = player.screenPosY + MOVE_SPEED;
		if (player.frame == FRAMETIME && (player.spriteRef != 32 || player.spriteRef != 34 || player.spriteRef != 36 || player.spriteRef != 38))
		{
			currentState = DOWN;
			player.spriteRef = 32;
			player.frame = 0;
		}
	}
	
}
void moveLeft(int object, int xPos)
{
	int maskL = 65280;
	if (collision(object, LEFT) != LEFT && borderCollision(object, LEFT) != LEFT)
	{
		point.obj_holderAddress[(object * 4 + 1)] &= maskL;
		point.obj_holderAddress[(object * 4 + 1)] |= (xPos - MOVE_SPEED);
		if (player.frame == FRAMETIME && (player.spriteRef != 52 || player.spriteRef != 54 || player.spriteRef != 56))
		{
			currentState = LEFT;
			player.spriteRef = 52;
			player.frame = 0;
		}

	}
	else if (borderCollision(object, LEFT) == LEFT && player.screenPosX > 0)
	{
		player.screenPosX = player.screenPosX - MOVE_SPEED;
		if (player.frame == FRAMETIME && (player.spriteRef != 52 || player.spriteRef != 54 || player.spriteRef != 56))
		{
			currentState = LEFT;
			player.spriteRef = 52;
			player.frame = 0;
		}
	}
}
void moveRight(int object, int xPos)
{
	int maskL = 65280;
	if (collision(object, RIGHT) != RIGHT && borderCollision(object, RIGHT) != RIGHT)
	{
		point.obj_holderAddress[(object * 4 + 1)] &= maskL;
		point.obj_holderAddress[(object * 4 + 1)] |= (xPos + MOVE_SPEED);
		if (player.frame == FRAMETIME && (player.spriteRef != 46 || player.spriteRef != 48 || player.spriteRef != 50))
		{
			currentState = RIGHT;
			player.spriteRef = 46;
			player.frame = 0;
		}
	}
	else if (borderCollision(object, RIGHT) == RIGHT && player.screenPosX < 272)
	{
		player.screenPosX = player.screenPosX + MOVE_SPEED;
		if (player.frame == FRAMETIME && (player.spriteRef != 46 || player.spriteRef != 48 || player.spriteRef != 50))
		{
			currentState = RIGHT;
			player.spriteRef = 46;
			player.frame = 0;
		}
	}
}
//sets enemy up for battle

//SETS UP THE PLAYERES X/Y POSITION AND THAT THE PLAYER WILL BE ALIVE - USED BELOW IN SETUP FUNCTION
void playerStart()
{

	point.obj_holderAddress[(player.objectRef * 4) + 1] = player.positionX;
	point.obj_holderAddress[(player.objectRef * 4)] = player.positionY;

	player.xPos = (unsigned short *)&point.obj_holderAddress[(player.objectRef * 4) + 1];
	player.yPos = (unsigned short *)&point.obj_holderAddress[(player.objectRef * 4)];
	player.alive = true;
	player.enable = 0;
	Menu.startPressed = false;
	Menu.selectPressed = false;
	Menu.aPressed = false;
	Menu.bPressed = false;
	player.score = player.score;
	player.time = 0;
}
	
//this checks to see if the object passed is colliding
int collision(int object, int direction)
{
	int i = 1;
	int mask = 255;

	int object1x = point.obj_holderAddress[(object * 4) + 1] & mask; //sets the moving objects x
	int object1y = point.obj_holderAddress[(object * 4)] & mask; //sets the moving objects y

	for (i = 0; i < 128; i++) //checks every object against the current moving object
	{
		if (i != object)
		{
			int object2x = point.obj_holderAddress[(i * 4) + 1] & mask; //creates a temp x poistion to check against
			int object2y = point.obj_holderAddress[(i * 4)] & mask; //creates a temp y poistion to check against

			switch (direction)
			{
			case UP:
				if ((object1y <= (object2y + 8)) && (object1y >= object2y) && ((object1x + 7) >= object2x) && (object1x <= (object2x + 7)))
				{
					//doorCollision(i, object, player.level);
					//pickupCollision(i, object);
					return UP;
				}
				break;
			case DOWN:
				if (object == player.objectRef)
				{
					if ((((object1y + 12) >= object2y) && (object1y <= object2y) && ((object1x + 7) >= object2x) && (object1x <= (object2x + 7))))
					{
						//doorCollision(i, object, player.level);
						//pickupCollision(i, object);
						return DOWN;
					}
				}
				else
				{
					if ((((object1y + 8) >= object2y) && (object1y <= object2y) && ((object1x + 7) >= object2x) && (object1x <= (object2x + 7))))
					{
						//doorCollision(i, object, player.level);
						//pickupCollision(i, object);
						return DOWN;
					}
				}
				break;
			case LEFT:
				if (object == player.objectRef)
				{
					if (object1x >= (object2x + 8) && object1x <= (object2x + 8) && ((object1y + 11) >= object2y) && (object1y <= (object2y + 7)))
					{
						//doorCollision(i, object, player.level);
						//pickupCollision(i, object);
						return LEFT;
					}
				}
				else
				{
					if (object1x >= (object2x + 8) && object1x <= (object2x + 8) && ((object1y + 7) >= object2y) && (object1y <= (object2y + 7)))
					{
						//doorCollision(i, object, player.level);

						//pickupCollision(i, object);
						return LEFT;
					}
				}
			
				break;
			case RIGHT:
				if (object == player.objectRef)
				{
					if (((object1x + 8) >= object2x) && object1x <= (object2x) && ((object1y + 11) >= object2y) && (object1y <= (object2y + 7)))
					{
						//doorCollision(i, object, player.level);
						//pickupCollision(i, object);
						return RIGHT;
					}
				}
				else
				{
					if (((object1x + 8) >= object2x) && object1x <= (object2x) && ((object1y + 7) >= object2y) && (object1y <= (object2y + 7)))
					{
						//doorCollision(i, object, player.level);
						//pickupCollision(i, object);
						return RIGHT;
					}
				}
				break;
			}
		}
	}

	return 0;
}
// *****************
// BORDER COLLISION detection
// *****************
//border collision detection (checks the collisions against the border) - object ref, direction to check
int borderCollision(int object, int direction)
{
	int mask = 255;

	int objectX = point.obj_holderAddress[(object * 4) + 1] & mask; //sets the moving objects x
	int objectY = point.obj_holderAddress[(object * 4)] & mask; //sets the moving objects y
	switch (direction)
	{

	case UP:
		if (objectY == 0)
		{
			return UP;

		}
		break;
	case DOWN:
		if (object == player.objectRef)
		{
			if (objectY+5 == HEIGHT)
			{
				return DOWN;
			}
		}
		else
		{
			if (objectY == HEIGHT)
			{
				return DOWN;
			}
		}
		break;
	case LEFT:
		if (objectX == 0)
		{
			return LEFT;
		}
		break;
	case RIGHT:
		if (objectX == WIDTH)
		{
			return RIGHT;
		}
		break;

	}
	return 0;
}
//sets the enemies locations in battle
//calculates the actual damage done vs defence
int damageCalc(int currentHP, int damage, int defence)
{
	float fDamage = (float)damage;
	float fDefence = (float)defence;
	currentHP = currentHP - (fDamage - ((fDamage / fDefence) * 10));
	return currentHP;
}
//sets initial player stats
void setPlayerStartStats()
{
	player.xP = 400;
	levelCheck();
}
//checks to see if the player has leveled
void levelCheck()
{
	if (player.xP >= player.nextLevel)
	{
		player.currentLevel = player.currentLevel + 1;
		statCheck();
		player.currentHP = player.maxHP;
		player.currentMP = player.maxMP;
		if (player.xP >= player.nextLevel)
		{
			levelCheck();
		}
	}
}
//if the player levels, it will run this updating their HP,MP and XP required
void statCheck()
{
	int first, second, third, number;
	// ASM FUNCTION for calculating the required XP until next level, see below for the math breakdown (it works the same as in old, but using ASM)
	first = 20;
	second = player.currentLevel;
	third = 150;
	statMath(&first, &second, &third); 
	player.nextLevel = third;

	first = 3;
	second = player.endurance;
	third = player.currentLevel;
	statMath(&first, &second, &third);
	player.maxHP = third;

	first = 2;
	second = player.intelligence;
	third = player.currentLevel;
	statMath(&first, &second, &third);
	player.maxMP = third;

	//ASM Add function used to give the players stat values
	number = 3;
	addToTotal(&number, &player.currentLevel, &player.strength);
	addToTotal(&number, &player.currentLevel, &player.endurance);
	number = 2;
	addToTotal(&number, &player.currentLevel, &player.agility);
	addToTotal(&number, &player.currentLevel, &player.intelligence);

	//old code, I have basically rewritten this section completely with ASM
	/*player.nextLevel = (20 * (player.currentLevel * player.currentLevel) + 100 + 50);
	player.strength = (3 + player.currentLevel);
	player.agility = (2 + player.currentLevel);
	player.intelligence = (2 + player.currentLevel);
	player.endurance = (3 + player.currentLevel);
	player.maxHP = (3 * (player.endurance * player.endurance) + player.currentLevel);
	player.maxMP = (2 * (player.intelligence * player.intelligence) + player.currentLevel);*/
	if (player.currentHP > player.maxHP)
	{
		player.currentHP = player.maxHP;
	}
	if (player.maxHP > player.totalMaxHP)
	{
		player.maxHP = player.totalMaxHP;
	}
	if (player.currentMP > player.maxMP)
	{
		player.currentMP = player.maxMP;
	}
	if (player.maxMP > player.totalMaxMP)
	{
		player.maxMP = player.totalMaxMP;
	}
}
//calculates the stats from weapons/armour
void calcStats(int number)
{
	if (items[number].inUse == true)
	{
		player.armourDefence += items[number].defence;
		player.weaponDamage += items[number].damage;
	}
	else
	{
		player.armourDefence -= items[number].defence;
		player.weaponDamage -= items[number].damage;
	}
	calcDamDef();
}
//basically makes sure that the damage of the player does not exceed the max damage
void calcDamDef()
{
	player.damage = player.strength + player.weaponDamage;
	if (player.damage > player.MaxDamage)
	{
		player.damage = player.MaxDamage;
	}
	player.defence = player.endurance + player.baseDefence + player.armourDefence;
	if (player.defence > player.MaxDefence)
	{
		player.defence = player.MaxDefence;
	}
}
//stops the player from moving
void playerClear()
{
	player.upPressed = false;
	player.downPressed = false;
	player.leftPressed = false;
	player.rightPressed = false;
}
//runs all the movement functions from above
void move_function(int trigger, int object)
{
	int xPos = getxPos(object);
	int yPos = getyPos(object);

	if (trigger == UP)
	{
		moveUp(object, yPos);
	}
	if (trigger == DOWN)
	{
		moveDown(object, yPos);
	}
	if (trigger == LEFT)
	{
		moveLeft(object, xPos);
	}
	if (trigger == RIGHT)
	{
		moveRight(object, xPos);
	}
}
//checks to see if the player is moving
void moveCheck()
{
	if (player.upPressed)
	{

		move_function(UP, player.objectRef);
	}
	if (player.downPressed)
	{
		move_function(DOWN, player.objectRef);
	}
	if (player.leftPressed)
	{
		move_function(LEFT, player.objectRef);
	}
	if (player.rightPressed)
	{
		move_function(RIGHT, player.objectRef);
	}
}
//runs my animations
void runAnimation(int object, int spriteRef, int state, bool step)
{
	if (playState == map)
	{
		if (state == IDLE && object == player.objectRef)
		{
			if (player.frame == 300 && player.spriteRef == 32)
			{
				player.spriteRef = 34;
				player.frame = 0;
			}
			if (player.frame == 300 && player.spriteRef == 34)
			{
				player.spriteRef = 32;
				player.frame = 0;
			}
			if (player.frame == 600)
			{
				player.horFlip = 0;
				player.spriteRef = 32;
				player.frame = 0;
			}
		}
		if (state == RIGHT && object == player.objectRef)
		{
			if (player.frame == FRAMETIME && player.spriteRef == 46 && step == false)
			{
				player.spriteRef = 48;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 48)
			{
				player.spriteRef = 46;
				player.step = true;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 46 && step == true)
			{
				player.spriteRef = 50;
				player.step = false;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 50)
			{
				player.spriteRef = 46;
				player.frame = 0;
			}
			if (player.frame == 5 && player.rightPressed == false)
			{
				player.spriteRef = 46;
				player.step = false;
				player.frame = 0;
			}
		}

		if (state == LEFT && object == player.objectRef)
		{
			if (player.frame == FRAMETIME && player.spriteRef == 52 && step == false)
			{
				player.spriteRef = 54;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 54)
			{
				player.spriteRef = 52;
				player.step = true;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 52 && step == true)
			{
				player.spriteRef = 56;
				player.step = false;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 56)
			{
				player.spriteRef = 52;
				player.frame = 0;
			}
			if (player.frame == 5 && player.leftPressed == false)
			{
				player.spriteRef = 52;
				player.step = false;
				player.frame = 0;
			}
		}

		if (state == UP && object == player.objectRef)
		{
			if (player.frame == FRAMETIME && player.spriteRef == 40 && step == false)
			{
				player.spriteRef = 42;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 42)
			{
				player.spriteRef = 40;
				player.step = true;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 40 && step == true)
			{
				player.spriteRef = 44;
				player.step = false;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 44)
			{
				player.spriteRef = 40;
				player.frame = 0;
			}
			if (player.frame == 5 && player.upPressed == false)
			{
				player.spriteRef = 40;
				player.step = false;
				player.frame = 0;
			}
		}
		if (state == DOWN && object == player.objectRef)
		{

			if (player.frame == FRAMETIME && player.spriteRef == 32)
			{
				player.spriteRef = 38;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 38)
			{
				player.spriteRef = 34;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 34)
			{
				player.spriteRef = 36;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 36)
			{
				player.spriteRef = 32;
				player.frame = 0;
			}
			if (player.frame == 5 && player.downPressed == false)
			{
				player.spriteRef = 42;
				player.step = false;
				player.frame = 0;
			}
		}

	}
}
//plays my sound effects
void playSFX(int effect)
{
	if (effect == 33)
	{
		mm_sound_effect sfxKACHING = {
			{ SFX_KACHING },			// id
			(int)(1.0f * (1 << 10)),	// rate
			50,		// handle
			100,	// volume
			127,	// panning
		};
		mmEffectEx(&sfxKACHING);
	}
	if (effect == 32)
	{
		mm_sound_effect sfxHIT = {
			{ SFX_HIT },			// id
			(int)(1.0f * (1 << 10)),	// rate
			0,		// handle
			75,	// volume
			127,	// panning
		};
		mmEffectEx(&sfxHIT);
	}
	if (effect == 31)
	{
		mm_sound_effect sfxCANCEL = {
			{ SFX_CANCEL },			// id
			(int)(1.0f * (1 << 10)),	// rate
			50,		// handle
			100,	// volume
			127,	// panning
		};
		mmEffectEx(&sfxCANCEL);
	}
}


//Below are all the functions used to draw the game
void drawSplash()//DRAWS THE SPLASH SCREEN TEXT
{
	draw_function(PLAYERMENUSTARTX - 7, PLAYERMENUSTARTY - 1, 4, 0, CHARRCAPS);//R
	draw_function(PLAYERMENUSTARTX - 6, PLAYERMENUSTARTY - 1, 4, 0, CHARPCAPS);//p
	draw_function(PLAYERMENUSTARTX - 5, PLAYERMENUSTARTY - 1, 4, 0, CHARGCAPS);//g

	draw_function(PLAYERMENUSTARTX - 3, PLAYERMENUSTARTY - 1, 4, 0, CHARGCAPS);//g
	draw_function(PLAYERMENUSTARTX - 2, PLAYERMENUSTARTY - 1, 4, 0, CHARBCAPS);//b
	draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY - 1, 4, 0, CHARACAPS);//A

	draw_function(PLAYERMENUSTARTX + 1, PLAYERMENUSTARTY - 1, 4, 0, CHARCCAPS);//C
	draw_function(PLAYERMENUSTARTX + 2, PLAYERMENUSTARTY - 1, 4, 0, CHARWCAPS);//W
	draw_function(GOSTARTX, GOSTARTY, 9, 0, CHARPCAPS);//P
	draw_function(GOSTARTX + 1, GOSTARTY, 9, 0, CHARU);//U
	draw_function(GOSTARTX + 2, GOSTARTY, 9, 0, CHARS);//S
	draw_function(GOSTARTX + 3, GOSTARTY, 9, 0, CHARH);//H

	draw_function(GOSTARTX + 5, GOSTARTY, 9, 0, CHARSCAPS);//S
	draw_function(GOSTARTX + 6, GOSTARTY, 9, 0, CHART);//T
	draw_function(GOSTARTX + 7, GOSTARTY, 9, 0, CHARA);//A
	draw_function(GOSTARTX + 8, GOSTARTY, 9, 0, CHARR);//R
	draw_function(GOSTARTX + 9, GOSTARTY, 9, 0, CHART);//T
}

void drawMenu()//DRAWS THE MENU SCREEN TEXT
{
	if (Menu.arrow == false && menuP == nG)
	{
		draw_function(MENUX - 1, MENUY, 9, 0, ARROW);
		menuP = nG;
		Menu.arrow = true;
	}

	//DRAWS THE MENU (NEW GAME AND OPTIONS)
	draw_function(MENUX, MENUY, 9, 0, 78);//N
	draw_function(MENUX + 1, MENUY, 9, 0, 69);//E
	draw_function(MENUX + 2, MENUY, 9, 0, 87);//W

	draw_function(MENUX + 4, MENUY, 9, 0, 71);//G
	draw_function(MENUX + 5, MENUY, 9, 0, 65);//A
	draw_function(MENUX + 6, MENUY, 9, 0, 77);//M
	draw_function(MENUX + 7, MENUY, 9, 0, 69);//E


	draw_function(MENUX, MENUY + 1, 9, 0, 79);//O
	draw_function(MENUX + 1, MENUY + 1, 9, 0, 80);//P
	draw_function(MENUX + 2, MENUY + 1, 9, 0, 84);//T
	draw_function(MENUX + 3, MENUY + 1, 9, 0, 73);//I
	draw_function(MENUX + 4, MENUY + 1, 9, 0, 79);//O
	draw_function(MENUX + 5, MENUY + 1, 9, 0, 78);//N
	draw_function(MENUX + 6, MENUY + 1, 9, 0, 83);//S

	draw_function(MENUX, MENUY + 2, 9, 0, 83);//S
	draw_function(MENUX + 1, MENUY + 2, 9, 0, 84);//T
	draw_function(MENUX + 2, MENUY + 2, 9, 0, 82);//R
	draw_function(MENUX + 3, MENUY + 2, 9, 0, 69);//E
	draw_function(MENUX + 4, MENUY + 2, 9, 0, 83);//S
	draw_function(MENUX + 5, MENUY + 2, 9, 0, 83);//S

	draw_function(MENUX + 7, MENUY + 2, 9, 0, 84);//T
	draw_function(MENUX + 8, MENUY + 2, 9, 0, 69);//E
	draw_function(MENUX + 9, MENUY + 2, 9, 0, 83);//S
	draw_function(MENUX + 10, MENUY + 2, 9, 0, 84);//T
}
void drawDeadScreen(int lives)//DRAWS THE DEATH SCREEN TEXT
{
	int restartX = 10;
	int restartY = 8;
	draw_function(restartX, restartY, 8, 0, 65);//A
	draw_function(restartX + 2, restartY, 8, 0, 45);//-
	draw_function(restartX + 4, restartY, 8, 0, 82);//r
	draw_function(restartX + 5, restartY, 8, 0, 101);//e
	draw_function(restartX + 6, restartY, 8, 0, 115);//s
	draw_function(restartX + 7, restartY, 8, 0, 97);//a
	draw_function(restartX + 8, restartY, 8, 0, 114);//r
	draw_function(restartX + 9, restartY, 8, 0, 116);//t

	draw_function(restartX + 3, restartY + 1, 8, 0, 21);
	draw_function(restartX + 4, restartY + 1, 8, 0, 173);
	switch (lives)
	{
	case 1:
		draw_function(restartX + 5, restartY + 1, 8, 0, 49);
		break;
	case 2:
		draw_function(restartX + 5, restartY + 1, 8, 0, 50);
		break;
	case 3:
		draw_function(restartX + 5, restartY + 1, 8, 0, 51);
		break;
	}
}
void drawGameOver(int score)//DRAWS THE GAMEOVER SCREEN TEXT
{
	//DISPLAYS GAME OVER TEXT
	draw_function(GOSTARTX, GOSTARTY, 8, 0, 71);//G
	draw_function(GOSTARTX + 1, GOSTARTY, 8, 0, 65);//A
	draw_function(GOSTARTX + 2, GOSTARTY, 8, 0, 77);//M
	draw_function(GOSTARTX + 3, GOSTARTY, 8, 0, 69);//E
	draw_function(GOSTARTX + 5, GOSTARTY, 8, 0, 79);//O
	draw_function(GOSTARTX + 6, GOSTARTY, 8, 0, 86);//V
	draw_function(GOSTARTX + 7, GOSTARTY, 8, 0, 69);//E
	draw_function(GOSTARTX + 8, GOSTARTY, 8, 0, 82);//R


	//draws the start/select text so player has some idea of what to do
	draw_function(PSTARTX, PSTARTY, 8, 0, 83);//S
	draw_function(PSTARTX + 1, PSTARTY, 8, 0, 84);//T
	draw_function(PSTARTX + 2, PSTARTY, 8, 0, 65);//A
	draw_function(PSTARTX + 3, PSTARTY, 8, 0, 82);//R
	draw_function(PSTARTX + 4, PSTARTY, 8, 0, 84);//T

	draw_function(PSTARTX + 6, PSTARTY, 8, 0, 45);//-

	draw_function(PSTARTX + 8, PSTARTY, 8, 0, CHARRCAPS);//R
	draw_function(PSTARTX + 9, PSTARTY, 8, 0, CHARECAPS);//E
	draw_function(PSTARTX + 10, PSTARTY, 8, 0, CHARSCAPS);//S
	draw_function(PSTARTX + 11, PSTARTY, 8, 0, CHARTCAPS);//T
	draw_function(PSTARTX + 12, PSTARTY, 8, 0, CHARACAPS);//A
	draw_function(PSTARTX + 13, PSTARTY, 8, 0, CHARRCAPS);//R
	draw_function(PSTARTX + 14, PSTARTY, 8, 0, CHARTCAPS);//T


	draw_function(PSELECTX, PSELECTY, 8, 0, 83);//S
	draw_function(PSELECTX + 1, PSELECTY, 8, 0, 69);//E
	draw_function(PSELECTX + 2, PSELECTY, 8, 0, 76);//L
	draw_function(PSELECTX + 3, PSELECTY, 8, 0, 69);//E
	draw_function(PSELECTX + 4, PSELECTY, 8, 0, 67);//C
	draw_function(PSELECTX + 5, PSELECTY, 8, 0, 84);//T

	draw_function(PSELECTX + 7, PSELECTY, 8, 0, 45);//-

	draw_function(PSELECTX + 9, PSELECTY, 8, 0, 77);//M
	draw_function(PSELECTX + 10, PSELECTY, 8, 0, 69);//E
	draw_function(PSELECTX + 11, PSELECTY, 8, 0, 78);//N
	draw_function(PSELECTX + 12, PSELECTY, 8, 0, 85);//U
}
void drawPause()//DRAWS THE PAUSE SCREEN TEXT
{
	draw_function(PAUSEX + 2, PAUSEY, 8, 0, 80);//P
	draw_function(PAUSEX + 3, PAUSEY, 8, 0, 97);//A
	draw_function(PAUSEX + 4, PAUSEY, 8, 0, 117);//U
	draw_function(PAUSEX + 5, PAUSEY, 8, 0, 115);//S
	draw_function(PAUSEX + 6, PAUSEY, 8, 0, 101);//E
	draw_function(PAUSEX + 7, PAUSEY, 8, 0, 100);//D

	draw_function(PAUSEX, PAUSEY + 1, 8, 0, 65);//A

	draw_function(PAUSEX + 2, PAUSEY + 1, 8, 0, 45);//-

	draw_function(PAUSEX + 4, PAUSEY + 1, 8, 0, 67);//C
	draw_function(PAUSEX + 5, PAUSEY + 1, 8, 0, 111);//O
	draw_function(PAUSEX + 6, PAUSEY + 1, 8, 0, 110);//N
	draw_function(PAUSEX + 7, PAUSEY + 1, 8, 0, 116);//T
	draw_function(PAUSEX + 8, PAUSEY + 1, 8, 0, 105);//I
	draw_function(PAUSEX + 9, PAUSEY + 1, 8, 0, 110);//N
	draw_function(PAUSEX + 10, PAUSEY + 1, 8, 0, 117);//U
	draw_function(PAUSEX + 11, PAUSEY + 1, 8, 0, 101);//E

	draw_function(PAUSEX, PAUSEY + 2, 8, 0, 66);//B

	draw_function(PAUSEX + 2, PAUSEY + 2, 8, 0, 45);//-

	draw_function(PAUSEX + 4, PAUSEY + 2, 8, 0, 69);//E
	draw_function(PAUSEX + 5, PAUSEY + 2, 8, 0, 120);//x
	draw_function(PAUSEX + 6, PAUSEY + 2, 8, 0, 105);//I
	draw_function(PAUSEX + 7, PAUSEY + 2, 8, 0, 116);//T
}
void drawExit()//DRAWS THE EXIT SCREEN TEXT
{
	if (Menu.arrow == false && exitM == no)
	{
		draw_function(MENUX - 1, MENUY + 1, 9, 0, ARROW);
		exitM = no;
		Menu.arrow = true;
	}
	player.enable = 1;
	//draw text
	draw_function(MENUX, MENUY, 8, 0, 69);//E
	draw_function(MENUX + 1, MENUY, 8, 0, 120);//x
	draw_function(MENUX + 2, MENUY, 8, 0, 105);//I
	draw_function(MENUX + 3, MENUY, 8, 0, 116);//T
	draw_function(MENUX + 4, MENUY, 8, 0, 63);//?

	draw_function(MENUX, MENUY + 1, 8, 0, 78);//no
	draw_function(MENUX + 1, MENUY + 1, 8, 0, 111);//no

	draw_function(MENUX, MENUY + 2, 8, 0, 89);//yes
	draw_function(MENUX + 1, MENUY + 2, 8, 0, 101);//yes
	draw_function(MENUX + 2, MENUY + 2, 8, 0, 115);//yes
}
void drawOptions()//DRAWS THE OPTIONS SCREEN TEXT
{
	if (Menu.arrow == false && optionP == option1)
	{
		draw_function(MENUX - 1, MENUY, 9, 0, ARROW);
		optionP = option1;
		Menu.arrow = true;
	}

	draw_function(MENUX, MENUY, 9, 0, 79);//o1
	draw_function(MENUX + 1, MENUY, 9, 0, 49);//o1

	draw_function(MENUX, MENUY + 1, 9, 0, 79);//o2
	draw_function(MENUX + 1, MENUY + 1, 9, 0, 50);//o2

	int backX = 3;
	int backY = 16;
	draw_function(backX, backY, 9, 0, 80);//P
	draw_function(backX + 1, backY, 9, 0, 85);//U
	draw_function(backX + 2, backY, 9, 0, 83);//S
	draw_function(backX + 3, backY, 9, 0, 72);//H

	draw_function(backX + 5, backY, 9, 0, 66);//B

	draw_function(backX + 7, backY, 9, 0, 84);//T
	draw_function(backX + 8, backY, 9, 0, 79);//O


	draw_function(backX, backY + 1, 9, 0, 71);//G
	draw_function(backX + 1, backY + 1, 9, 0, 79);//O

	draw_function(backX + 3, backY + 1, 9, 0, 66);//B
	draw_function(backX + 4, backY + 1, 9, 0, 65);//A
	draw_function(backX + 5, backY + 1, 9, 0, 67);//C
	draw_function(backX + 6, backY + 1, 9, 0, 75);//A
}
//void drawBG()
//{
//	int i,t;
//	for (i = 0; i < 4096; i++)
//	{
//		point.mapArray[i] = testMap[i];
//		short test;
//		test = testMap[i];
//
//		if (test >> 0 == 1)
//		{
//			draw_function(i, 0, 11, 0, 4);
//		}
//	}
//
//}
void drawBG()
{

	int i;
	for (i = 0; i < 4096; i++)
	{
		enemyai[0].map = testMap;
		point.mapArray[i] = enemyai[0].map[i];
	}

}
void setUpAI(int i)
{	
		enemyai[i].enemyIteration = i;
		enemyai[i].nodeList.listCount = 0;
		enemyai[i].checkNextNode = true;
		enemyai[i].nodeList.selfNode = enemyai[i].nodeList.Start;
}
void pathfindSetup()
{
	int i, t,g;
	//for(j = 1; j <= 5;i++)
	//{}
	for (i = 0; i < 32; i++)//x
	{
		for (t = 0; t < 128; t++)//y
		{

				stateArray[i + (t * 32)] = Untested;


			short mapToCheck;//creates a short to hold the map info for current position
			mapToCheck = enemyai[0].map[i + (t * 32)];//sets the short to the value held in the current map poistion
			if ((mapToCheck >> 0) == 0)//if tile sprite = 0 (walkbable),
			{
				//draw_function(i, t, 11, 0, 2);
			}

			for (g = 0; g < NUMBER_OF_ENEMIES; g++)
			{
				if (mapToCheck == 3+g)//if tile sprite = 3, set start location as here
				{
					enemyai[g].nodeList.Start.nodeRef = i + (t * 32);
					enemyai[g].nodeList.Start.LocationX = i;
					enemyai[g].nodeList.Start.LocationY = t;
					enemyai[g].nodeList.Start.walkable = true;
					enemyai[g].nodeList.Start.g = 0;
					enemyai[g].nodeList.Start.h = getDistance(enemyai[g].nodeList.Start, enemyai[g].nodeList.End);
					stateArray[enemyai[g].nodeList.Start.nodeRef] = Open;
				}
			
				if (mapToCheck == 7)//if tile sprite = 4, set end location as here
				{
					enemyai[g].nodeList.End.nodeRef = i + (t * 32);
					enemyai[g].nodeList.End.LocationX = i;
					enemyai[g].nodeList.End.LocationY = t;
					draw_function(0, 10, 4, 0, i);
					draw_function(1, 10, 4, 0, t);
					enemyai[g].nodeList.End.walkable = true;
					enemyai[g].nodeList.End.g = 0;
					enemyai[g].nodeList.End.h = 0;
				}
			}
		}
	}
	for (g = 0; g < NUMBER_OF_ENEMIES; g++)
	{
		setUpAI(g);
	}
}
int getEnemyNumber(int level)
{
	switch (level)
	{
	case 0: 
		return 1;
	case 1:
		return 2;
	}
}
int setX(Node nodeToRef)
{
	int i, t;
	for (i = 0; i < 32; i++)//x
	{
		for (t = 0; t < 128; t++)//y
		{
			if (i + (t * 32) == nodeToRef.nodeRef)
			{
				return i;
			}
		}
	}
	return 0;
}
int setY(Node nodeToRef)
{
	int i, t;
	for (i = 0; i < 32; i++)//x
	{
		for (t = 0; t < 128; t++)//y
		{
			if (i + (t * 32) == nodeToRef.nodeRef)
			{
				return t;
			}
		}
	}
	return 0;
}
float getG(Node inputNode, Node parentNode)
{
	return parentNode.g + getDistance(inputNode, parentNode);
}
float getF(Node currentNode)
{
	return currentNode.g + currentNode.h;
}
int getScreen(Node currentnode)
{
	if (currentnode.nodeRef < 1024)
	{
		return 1;
	}
	if (currentnode.nodeRef >= 1024 && currentnode.nodeRef < 2048)
	{
		return 2;
	}
	if (currentnode.nodeRef >= 2048 && currentnode.nodeRef < 3072)
	{
		return 3;
	}
	if (currentnode.nodeRef >= 3072 && currentnode.nodeRef < 4096)
	{
		return 4;
	}
	return 0;
}
float getDistance(Node node1, Node node2)
{
	
	//if (getScreen(node1) == 2 || getScreen(node1) == 4)
	//{ tempScreenp1X, tempScreenp1Y
	//	tempScreenp1X = 32;
	//}int, tempScreenp2X, tempScreenp2Y;
	//if (getScreen(node2) == 2 || getScreen(node2) == 4)
	//{
	//	tempScreenp2X = 32;
	//}
	//if (getScreen(node1) == 3 || getScreen(node1) == 4)
	//{
	//	tempScreenp1Y= 32;+ tempScreenp2X
	//}+ tempScreenp2Y+ tempScreenp2X+ tempScreenp2Y
	//if (getScreen(node2) == 3 || getScreen(node2) == 4)
	//{
	//	tempScreenp2Y = 32;
	//}
		float deltaX = (node2.LocationX ) - (node1.LocationX);
		float deltaY = (node2.LocationY ) - (node1.LocationY);
		//if (getScreen(node1) != getScreen(node2))
		//{
		//	deltaX += 32;
		//	deltaY -= 32;
		//}
		return squareRoot(deltaX * deltaX + deltaY * deltaY);
}
float squareRoot(float input)
{
	float a = input;
	int i;
	for (i = 0; i > (input / 2); i++)
	{
		a = (a + input / a) / 2;
	}
	return a;
}
void pathFind()
{
	bool findPath;
	int i;
	for (i = 0; i < NUMBER_OF_ENEMIES; i++)
	{
		findPath = search(enemyai[i].nodeList.selfNode, enemyai[i].enemyIteration);
		if (findPath)
		{

			//while (enemyai.)
		}
		else
		{
			setUpAI(i);
		}
	}
}
int getLowestF(int iteration, Node *nodeArrayToCheck)
{
	int temp, i;
	temp = 0;
	for (i = 0; i < iteration; i++)
	{
		if (nodeArrayToCheck[i].f < nodeArrayToCheck[temp].f)
		{
			temp = i;
		}
	}
	return temp;
}
bool search(Node currentNode, int enemyIteration)
{

	stateArray[currentNode.nodeRef] = Closed;
	int i, temp;
	if (enemyai[enemyIteration].checkNextNode)
	{ 
		checkSurroundingNodes(currentNode, enemyIteration);//creates a list of walkable nodes
	}
	temp = getLowestF(enemyai[enemyIteration].iteration, enemyai[enemyIteration].tempNodeHolder);
	enemyai[enemyIteration].nodeList.nodeHolderList[enemyai[enemyIteration].nodeList.listCount-1] = enemyai[enemyIteration].tempNodeHolder[temp];
	for (i = enemyai[enemyIteration].nodeList.listCount-1; i < enemyai[enemyIteration].nodeList.listCount; i++)
	{
		if (enemyai[enemyIteration].nodeList.nodeHolderList[i].nodeRef == enemyai[enemyIteration].nodeList.End.nodeRef)
		{
			return true;
		}
		else
		{
			if (enemyai[enemyIteration].nodeList.nodeHolderList[i].nodeRef != enemyai[enemyIteration].nodeList.selfNode.nodeRef)
			{
				draw_function(enemyai[enemyIteration].nodeList.nodeHolderList[i].LocationX, enemyai[enemyIteration].nodeList.nodeHolderList[i].LocationY, 11, 0, 2);
				enemyai[enemyIteration].nodeList.selfNode = enemyai[enemyIteration].nodeList.nodeHolderList[i]; //add when working
				enemyai[enemyIteration].checkNextNode = true;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}
void checkSurroundingNodes(Node prevNode, int enemyIteration)
{
	int i;
	
	enemyai[enemyIteration].iteration = 0;
	Node walkableNodes[8];
	
	for (i = 0; i < 8; i++)
	{
		unsigned short testNode;
		walkableNodes[i].nodeRef = getLocationToCheck(prevNode, i);//creates a group of nodes that are around the current node
		walkableNodes[i].LocationX = setX(walkableNodes[i]);
		walkableNodes[i].LocationY = setY(walkableNodes[i]);
		walkableNodes[i].walkable = false;
		walkableNodes[i].g = 0;
		testNode = enemyai[0].map[walkableNodes[i].nodeRef];//gets the map info for the node
		if (testNode == 1)//checks if the square is empty, thus walkable
		{

			walkableNodes[i].walkable = false;//if walkable, set to true
		}
		if (testNode == 4)//checks if the square is empty, thus walkable
		{

			walkableNodes[i].walkable = true;//if walkable, set to true
		}
		if (testNode == 0)//checks if the square is empty, thus walkable
		{
			walkableNodes[i].walkable = true;//if walkable, set to true
		}
		if (!walkableNodes[i].walkable)//if walkable is false
			continue;//skip
		if (stateArray[walkableNodes[i].nodeRef] == Closed)//if state is 2 (closed)
			continue;//skip
		if (stateArray[walkableNodes[i].nodeRef] == Open)//if state is open
		{
			walkableNodes[i].parentNodeRef = prevNode.nodeRef;
			walkableNodes[i].g = getG(walkableNodes[i], prevNode);
			walkableNodes[i].h = getDistance(walkableNodes[i], enemyai[enemyIteration].nodeList.End);
			walkableNodes[i].f = getF(walkableNodes[i]);
			enemyai[enemyIteration].tempNodeHolder[enemyai[enemyIteration].iteration] = walkableNodes[i];
			enemyai[enemyIteration].iteration += 1;
		}
		else if(stateArray[walkableNodes[i].nodeRef] == Untested)
		{
			walkableNodes[i].parentNodeRef = prevNode.nodeRef;
			walkableNodes[i].g = getG(walkableNodes[i], prevNode);
			walkableNodes[i].h = getDistance(walkableNodes[i], enemyai[enemyIteration].nodeList.End);
			walkableNodes[i].f = getF(walkableNodes[i]);
			stateArray[walkableNodes[i].nodeRef] = Open;
			enemyai[enemyIteration].tempNodeHolder[enemyai[enemyIteration].iteration] = walkableNodes[i];
			enemyai[enemyIteration].iteration += 1;

		}

	}
	if (enemyai[enemyIteration].checkNextNode == true)
	{
		enemyai[enemyIteration].checkNextNode = false;
		enemyai[enemyIteration].nodeList.listCount += 1;
	}
}


int getLocationToCheck(Node nodeToRef, int iteration)
{
	int returnNodeRef[8];
	if (iteration == 0)
	{
		if ((nodeToRef.LocationY > 0 && nodeToRef.LocationY < 32) || (nodeToRef.LocationY > 32 && nodeToRef.LocationY < 64) || (nodeToRef.LocationY > 64 && nodeToRef.LocationY < 96) || (nodeToRef.LocationY > 96))
		{
			//outside of top row, sb1,2,3,4
			returnNodeRef[0] = (nodeToRef.nodeRef - 32);
			if (player.drawBG == true)
				draw_function(nodeToRef.nodeRef - 32, 0, 4, 0, 13);
		}
		else if (nodeToRef.LocationY == 64 || nodeToRef.LocationY == 96)
		{
			//top row - sb3/sb4
			returnNodeRef[0] = (nodeToRef.nodeRef - 1056);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef - 1056, 0, 4, 0, 13);
		}
	}
	if (iteration == 1)
	{
		if (nodeToRef.LocationX < 31)
		{
			//right if not in right column  - sb1/sb2/sb3/sb4
			returnNodeRef[1] = (nodeToRef.nodeRef + 1);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef + 1, 0, 4, 0, 14);
		}
		else if (nodeToRef.LocationX == 31 && ((nodeToRef.LocationY >= 0 && nodeToRef.LocationY < 32) || (nodeToRef.LocationY >= 64 && nodeToRef.LocationY < 96)))
		{
			returnNodeRef[1] = (nodeToRef.nodeRef + 993);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef + 993, 0, 4, 0, 14);
		}
	}

	if (iteration == 2)
	{
		if ((nodeToRef.LocationY >= 0 && nodeToRef.LocationY < 31) || (nodeToRef.LocationY >= 32 && nodeToRef.LocationY < 63) || (nodeToRef.LocationY >= 64 && nodeToRef.LocationY < 95) || (nodeToRef.LocationY >= 96 && nodeToRef.LocationY < 127))
		{
			//outside of bottom row, sb1,2,3,4
			returnNodeRef[2] = (nodeToRef.nodeRef + 32);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef + 32, 0, 4, 0, 15);
		}
		else if (nodeToRef.LocationY == 31 || nodeToRef.LocationY == 63)
		{
			//bottom row - sb3/sb4
			returnNodeRef[2] = (nodeToRef.nodeRef + 1056);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef + 1056, 0, 4, 0, 15);
		}
	}
	if (iteration == 3)
	{
		if (nodeToRef.LocationX > 0)
		{
			//left if not in left column  - sb1/sb2/sb3/sb4
			returnNodeRef[3] = (nodeToRef.nodeRef - 1);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef - 1, 0, 4, 0, 16);
		}
		else if (nodeToRef.LocationX == 0 && ((nodeToRef.LocationY >= 32 && nodeToRef.LocationY < 64) || (nodeToRef.LocationY >= 96 && nodeToRef.LocationY < 128)))
		{
			returnNodeRef[3] = (nodeToRef.nodeRef - 993);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef - 993, 0, 4, 0, 16);
		}
	}
	if (iteration == 4)
	{
		if (nodeToRef.LocationX < 31 && ((nodeToRef.LocationY > 0 && nodeToRef.LocationY < 32) || (nodeToRef.LocationY > 32 && nodeToRef.LocationY < 64) || (nodeToRef.LocationY > 64 && nodeToRef.LocationY < 96) || (nodeToRef.LocationY > 96)))
		{
			//right/up if not in right column or any top row - sb1/sb2/sb3/sb4
			returnNodeRef[4] = (nodeToRef.nodeRef - 31);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef - 31, 0, 4, 0, 10);
		}
		else if (nodeToRef.LocationX == 31 && ((nodeToRef.LocationY > 0 && nodeToRef.LocationY < 32) || (nodeToRef.LocationY > 64 && nodeToRef.LocationY < 96)))
		{
			//right/up if in right column and not in top row - sb1/sb3
			returnNodeRef[4] = (nodeToRef.nodeRef + 961);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef + 961, 0, 4, 0, 10);
		}
		else if (nodeToRef.LocationX < 31 && (nodeToRef.LocationY == 64 || nodeToRef.LocationY == 96))
		{
			//right/up if not in right coloum and in top row - sb3/sb4
			returnNodeRef[4] = (nodeToRef.nodeRef - 1055);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef - 1055, 0, 4, 0, 10);
		}
		else if (nodeToRef.LocationX == 31 && nodeToRef.LocationY == 64)
		{
			//right/up if in right colum and top row - sb3
			returnNodeRef[4] = (nodeToRef.nodeRef - 63);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef - 63, 0, 4, 0, 10);
		}
	}
	if (iteration == 5)
	{
		if (nodeToRef.LocationX < 31 && ((nodeToRef.LocationY >= 0 && nodeToRef.LocationY < 31) || (nodeToRef.LocationY >= 32 && nodeToRef.LocationY < 63) || (nodeToRef.LocationY >= 64 && nodeToRef.LocationY < 95) || (nodeToRef.LocationY >= 96 && nodeToRef.LocationY < 127)))
		{
			//right/down if not in right column or any bottom row - sb1/sb2/sb3/sb4
			returnNodeRef[5] = (nodeToRef.nodeRef + 33);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef + 33, 0, 4, 0, 11);
		}
		else if (nodeToRef.LocationX == 31 && ((nodeToRef.LocationY >= 0 && nodeToRef.LocationY < 31) || (nodeToRef.LocationY >= 64 && nodeToRef.LocationY < 95)))
		{
			//right/down if in right column and not in bottom row - sb1/sb3
			returnNodeRef[5] = (nodeToRef.nodeRef + 1025);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef + 1025, 0, 4, 0, 11);
		}
		else if (nodeToRef.LocationX < 31 && (nodeToRef.LocationY == 31 || nodeToRef.LocationY == 63))
		{
			//right/up if not in right coloum and in bottom row - sb1/sb2
			returnNodeRef[5] = (nodeToRef.nodeRef + 1057);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef + 1057, 0, 4, 0, 11);
		}
		else if (nodeToRef.LocationX == 31 && nodeToRef.LocationY == 63)
		{
			//right/up if in right colum and top row - sb3
			returnNodeRef[5] = (nodeToRef.nodeRef + 2049);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef + 2049, 0, 4, 0, 11);
		}
	}
	if (iteration == 6)
	{
		if (nodeToRef.LocationX > 0 && ((nodeToRef.LocationY >= 0 && nodeToRef.LocationY < 31) || (nodeToRef.LocationY >= 32 && nodeToRef.LocationY < 63) || (nodeToRef.LocationY >= 64 && nodeToRef.LocationY < 95) || (nodeToRef.LocationY >= 96 && nodeToRef.LocationY < 127)))
		{
			//left/down if not in left column or any bottom row - sb1/sb2/sb3/sb4
			returnNodeRef[6] = (nodeToRef.nodeRef + 31);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef + 31, 0, 4, 0, 12);
		}
		else if (nodeToRef.LocationX == 0 && ((nodeToRef.LocationY >= 32 && nodeToRef.LocationY < 63) || (nodeToRef.LocationY >= 96 && nodeToRef.LocationY < 127)))
		{
			//left/down if in left column and not in bottom row - sb2/sb4
			returnNodeRef[6] = (nodeToRef.nodeRef - 961);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef - 961, 0, 4, 0, 12);
		}
		else if (nodeToRef.LocationX > 0 && (nodeToRef.LocationY == 31 || nodeToRef.LocationY == 63))
		{
			//left/up if not in left coloum and in bottom row - sb1/sb2
			returnNodeRef[6] = (nodeToRef.nodeRef + 1055);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef + 1055, 0, 4, 0, 12);
		}
		else if (nodeToRef.LocationX == 0 && nodeToRef.LocationY == 63)
		{
			//left/up if in right colum and top row - sb3
			returnNodeRef[6] = (nodeToRef.nodeRef + 63);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef + 63, 0, 4, 0, 12);
		}

	}
	if (iteration == 7)
	{
		if (nodeToRef.LocationX > 0 && ((nodeToRef.LocationY > 0 && nodeToRef.LocationY < 32) || (nodeToRef.LocationY > 32 && nodeToRef.LocationY < 64) || (nodeToRef.LocationY > 64 && nodeToRef.LocationY < 96) || (nodeToRef.LocationY > 96)))
		{
			//left/up if not in left column or any top row - sb1/sb2/sb3/sb4
			returnNodeRef[7] = (nodeToRef.nodeRef - 33);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef - 33, 0, 4, 0, 9);
		}
		else if (nodeToRef.LocationX == 0 && ((nodeToRef.LocationY > 32 && nodeToRef.LocationY < 64) || (nodeToRef.LocationY > 96 && nodeToRef.LocationY < 128)))
		{
			//left/up if in left column and not in top row - sb2/sb4
			returnNodeRef[7] = (nodeToRef.nodeRef - 1025);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef - 1025, 0, 4, 0, 9);
		}
		else if (nodeToRef.LocationX > 0 && (nodeToRef.LocationY == 64 || nodeToRef.LocationY == 96))
		{
			//left/up if not in left coloum and in top row - sb3/sb4
			returnNodeRef[7] = (nodeToRef.nodeRef - 1057);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef - 1057, 0, 4, 0, 9);
		}
		else if (nodeToRef.LocationX == 0 && nodeToRef.LocationY == 96)
		{
			//left/up if in left colum and top row - sb4
			returnNodeRef[7] = (nodeToRef.nodeRef - 2049);
			if (player.drawBG == true)
			draw_function(nodeToRef.nodeRef - 2049, 0, 4, 0, 9);
		}
	}
	return returnNodeRef[iteration];
}
