////////////////////////////////////////////////////////////////////////////////
// Filename: game.h
////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_H_
#define GAME_H_

/////////////////
// My INCLUDES //
/////////////////
#include "systemincludes.h"
#include "playerstruct.h"
#include "aStarstruct.h"
#include "controls.h"
//ASM Functions
//extern void addSprites(int* start, int* Finish, int* characterAddress, int *spriteData);
extern void addSprites(int* start, int* Finish, unsigned int* characterAddress, const unsigned int *spriteData);
extern void forLoop(int* start, int* Finish, int* result);
extern void subNumber(int* answer);
extern void addNumber(int* answer);
extern void add1Number(int* answer, int* addition);
extern void timer(int *time);
extern void sub1Number(int* answer, int* subtraction);
extern void ifAlive(bool * alive, int * enable);
extern void multiplyNumbers(int* x, int* y, int* total);
extern void statMath(int *first, int *second, int *third);
extern void addToTotal(int* x, int* y, int* total);
//Functions
void pathfindSetup();
void pathFind();
void myObj_function(int obj_ref,
	int yCoor, int rotation_scaling_flag, int object_disable, int ignore0, int shape_lookup,//yCoor (0 - 255),int rotation_scaling_flag (0-1) off/on, int object_disable (0-1) or double size flag (0-1) normal/double, int ignore0, int shape_lookup (0-3),
	int xCoor, int ignore1, int horizontal_flip, int vertical_flip, int size_lookup, //
	int tile_number, int priority, int palette,
	int rotation_scaling);
int getxPos(int object);
int getyPos(int object);
void moveUp(int object, int yPos);
void moveDown(int object, int yPos);
void moveLeft(int object, int xPos);
void moveRight(int object, int xPos);
void moveCheck();
void updateOffset(int xPos, int yPos);
void playerStart();
void calcStats();
void setPlayerStartStats();
void levelCheck();
int damageCalc(int currentHP, int damage, int defence);
void move_function(int trigger, int object);
void setupLevel(int levelNumber);
void runGame();
void draw_function(int x, int y, int baseblock, int palette, int character);
void drawOtherfunction(int x, int y, int baseblock, int palette, int character);
void clear_function(int x, int y, int baseblock);
void battlePosFunction(int numberInGroup);
void clearObjects();
void setupFunction();
void playerStart();
void playersetup(int levelNumber);
void keyUsed();
void drawSplash();
void drawMenu();
void drawDeadScreen(int lives);
void drawGameOver(int score);
void drawPause();
void drawExit();
void drawOptions();
void enemyStart();
void enemySetup(int levelNumber);
void enemySetupBattle(int levelNumber, int groupNumber);
void enemySetupMap(int levelNumber);
void playersetupBattle(int levelNumber);
void enemyBattleStart();
void drawMenuBG(int startXPos, int startYPos, int endXPos, int endYPos, int baseblock);
void drawMainMenu();
void drawInventoryMenu();
void drawAbiliesMenu();
void drawEquipmentMenu();
void drawStatusMenu();
void drawPartyMenu();
void drawOptionsMenu();
void displayEnemyHP();
bool music;
void playSFX(int effect);
void runAnimation(int object, int spriteRef, int action, bool step);
void drawBG();
//current gamestate
enum gameStates
{
	splash,
	menu,
	setup,
	playing,
	gameOver,
	pause,
	options,
	dead,
	exit,
	inGameMenu,
	setupStressTest,
	stressTest,
}gameState;
//the state of play
enum playStates
{
	map,
	battle,
	battleEnd,
	setupEnd,
	battleSetup,
}playState;
//position in battle menu
enum BattleMenuPos
{
	attack,
	abilityMenuPos,
	run,
	itemMenuPos,
}battleMenuPos;
//position in the battle
enum BattleState
{
	playerTurn,
	playerAttack,
	enemyAttack,
	abilityMenu,
	itemMenu,
	running,
	playerAttacking,
	enemyAttacking,
}battleState;
//enemies position on screen
enum EnemyBattlePos
{
	top,
	bottom,
	middle
}enemyBattlePos;
//inventory (outisde of battle) position
enum PlayerMenuPos
{
	inventoryPos,
	abilitiesPos,
	equipmentPos,
	statusPos,
	partyPos,
	optionsMenuPos,
}playerMenuPos;
//sets the current page the player is on inside the inventory
enum PlayerMenu
{
	mainMenu,
	inventory,
	abilities,
	equipment,
	status,
	party,
	optionsMenu,
}playerMenu;
//current inventory position
enum ItemPos
{
	item1,
	item2,
	item3,
	item4,
	item5,
	item6,
}itemPos;
//current equipment position
enum EquipPos
{
	equip1,
	equip2,
	equip3,
	equip4,
	equip5,
	equip6,
}equipPos;
//main menu positions
enum menuPos
{
	nG,
	menuOptions,
	menuStressTest,
	hidden,
}menuP;
//option positions
enum optionPos
{
	option1,
	option2,
}optionP;
//exit menu positions
enum exitMenu
{
	yes,
	no,
}exitM;
//menu stuct containing info on the keypressed (used for navigation in menu)
typedef struct MenuStruct
{
	bool arrow;
	
	bool upPressed;
	bool downPressed;
	bool aPressed;
	bool bPressed;
	bool startPressed;
	bool selectPressed;
	
} menuStruct;
menuStruct Menu;
//battle info, the enemy currently battling the player and the current frame
typedef struct BattleStruct
{
	int enemyRef;
	int frame;
}battleStruct;
battleStruct Battle;
#endif