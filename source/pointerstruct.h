////////////////////////////////////////////////////////////////////////////////
// Filename: pointerstruct.h
////////////////////////////////////////////////////////////////////////////////
#ifndef POINTERSTRUCT_H_
#define POINTERSTRUCT_H_
//Pointers struct
// *****************
// Pointers
// *****************
typedef struct Pointers
{
	//creates a pointer
	//new for COPRE
	unsigned short *SystemRom;//BIOS - System ROM         (16 KBytes)
	//BIOS memory. You can execute it, but not read it (i.o.w, touch, don't look).

	unsigned short *EWRAM;//WRAM - On-board Work RAM  (256 KBytes) 2 Wait

	unsigned short *IWRAM;//WRAM - On-chip Work RAM   (32 KBytes)

	//LCD I/O Registers
	unsigned short *DISPCNT; //LCD control

	unsigned short *DISPTSTAT;// General LCD Status (STAT,LYC)
	volatile unsigned short *VCOUNT;//Vertical Counter (LY)
	unsigned short *BGCNT;// BG0-3 Control

	//old
	unsigned short *bg_palette;// BG Palette RAM        (1 Kbyte)
	unsigned short *obj_palette;//OBJ Palette RAM        (1 Kbyte)
	unsigned short *mapArray;
	//VRAM - Video RAM(96 KBytes)
	unsigned int *characterAddressFirst;
	unsigned int *characterAddress;
	unsigned int *spriteAddress;
	unsigned short *BGHOFS;
	unsigned short *BGVOFS;
	//character block 1 base blocks
	unsigned short *base_block4;
	unsigned short *base_block8;
	unsigned short *base_block9;
	unsigned short *base_block10;
	unsigned short *base_block11;

	//character block 2 base blocks
	unsigned short *base_block20;
	unsigned short *base_block24;
	unsigned short *base_block25;
	unsigned short *base_block26;
	unsigned short *base_block27;
	unsigned int *base_block24a;
	unsigned short *obj_holderAddress;//OAM - OBJ Attributes      (1 Kbyte)
	//new for COPRE
	unsigned short *PAKROM;//Game Pak ROM/FlashROM (max 32MB)
	unsigned short *CARTRAM;//Cart ram

} Pointer;
Pointer point;

#endif