////////////////////////////////////////////////////////////////////////////////
// Filename: system.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _SYSTEM_H_
#define _SYSTEM_H_

/////////////////
// My INCLUDES //
/////////////////
#include "pointerstruct.h"
#include "aStarstruct.h"
#include "spritesheet.h"
#include "systemincludes.h"
#include "game.h"

///////////////////////
// MY INCLUDES //
///////////////////////

//---------------------------------------------------------------------------------
// FUNCTION DECLERATIONS
//---------------------------------------------------------------------------------
void setUpAI(int i);
int getLocationToCheck(Node nodeToRef, int iteration);
float getDistance(Node node1, Node node2);
float squareRoot(float input);
int setX(Node nodeToRef);
int setY(Node nodeToRef);
void checkSurroundingNodes(Node prevNode, int enemyIteration);
float getG(Node inputNode, Node parentNode);
bool search(Node currentNode, int enemyIteration);
int getScreen(Node currentnode);
float getF(Node currentNode);
int getLowestF(int iteration, Node *nodeArrayToCheck);
void pathFind();
void heldKey();
void pointersFunc();
int borderCollision(int object, int direction);
int collision(int object, int direction);
void enemyCollision(int Object, int movingObject, int direction);
void playerClear();
void myDisplay_function(int graphics_mode, int obj_data_mode, int bg0, int bg1, int bg2, int bg3, int obj);
void myDisplayNew_function(int graphics_mode, int pageSelect, int hBlank, int obj_data_mode, int bg0, int bg1, int bg2, int bg3, int obj, int window0, int window1, int objectWindow);
void mybg_function(int bg_ref, int layer_priority, int char_base_block, int colour_mode, int screen_base_block, int screen_size);
void myChar_function(int tile_ref,
	int a1, int b1, int c1, int d1, int e1, int f1, int g1, int h1,
	int a2, int b2, int c2, int d2, int e2, int f2, int g2, int h2,
	int a3, int b3, int c3, int d3, int e3, int f3, int g3, int h3,
	int a4, int b4, int c4, int d4, int e4, int f4, int g4, int h4,
	int a5, int b5, int c5, int d5, int e5, int f5, int g5, int h5,
	int a6, int b6, int c6, int d6, int e6, int f6, int g6, int h6,
	int a7, int b7, int c7, int d7, int e7, int f7, int g7, int h7,
	int a8, int b8, int c8, int d8, int e8, int f8, int g8, int h8);

void mySprite_function(int tile_ref,
	int a1, int b1, int c1, int d1, int e1, int f1, int g1, int h1,
	int a2, int b2, int c2, int d2, int e2, int f2, int g2, int h2,
	int a3, int b3, int c3, int d3, int e3, int f3, int g3, int h3,
	int a4, int b4, int c4, int d4, int e4, int f4, int g4, int h4,
	int a5, int b5, int c5, int d5, int e5, int f5, int g5, int h5,
	int a6, int b6, int c6, int d6, int e6, int f6, int g6, int h6,
	int a7, int b7, int c7, int d7, int e7, int f7, int g7, int h7,
	int a8, int b8, int c8, int d8, int e8, int f8, int g8, int h8);



void bgPalette_function(int palette, int palette_tile, int red, int green, int blue);
void objPalette_function(int palette, int palette_tile, int red, int green, int blue);
void keyPushed(int button);
void enemyBattleSetup();

#endif