////////////////////////////////////////////////////////////////////////////////
// Filename: pointerstruct.c
////////////////////////////////////////////////////////////////////////////////

/////////////////
// My INCLUDES //
/////////////////
#include "pointerstruct.h"

void pointersFunc()//this function runs and sets up the memory addresses
{//creates a pointer to the memory address given
	//new for COPRE
	point.SystemRom = (unsigned short *)0x00000000;//BIOS - System ROM         (16 KBytes)
	point.EWRAM = (unsigned short *)0x02000000;//WRAM - On-board Work RAM  (256 KBytes) 2 Wait
	point.IWRAM = (unsigned short *)0x03000000;//WRAM - On-board Work RAM  (32 KBytes)

	//LCD I/O Registers
	point.DISPCNT = (unsigned short *)0x04000000;//LCD control		(1 Kbyte)

	point.DISPTSTAT = (unsigned short*)0x4000004;// General LCD Status (STAT,LYC)
	point.VCOUNT = (volatile unsigned short*)0x4000006;//Vertical Counter (LY)
	//old
	point.BGCNT = (unsigned short *)0x04000008;// BG0-3 Control		(1 Kbyte)
	point.BGHOFS = (unsigned short*)0x04000010;
	point.BGVOFS = (unsigned short*)0x04000012;
	point.mapArray = (unsigned short*)0x06005800;
	//BG/OBJ Palette RAM
	point.bg_palette = (unsigned short *)0x05000000;// BG Palette RAM        (1 Kbyte)
	point.obj_palette = (unsigned short *)0x05000200;//OBJ Palette RAM        (1 Kbyte)

	//VRAM - Video RAM(96 KBytes)
	point.characterAddressFirst = (unsigned int *)0x06000000; //first sprite in tile view


	
	point.base_block4 = (unsigned short *)0x6002000;
	point.base_block8 = (unsigned short *)0x6004000;
	point.base_block9 = (unsigned short *)0x6004800;
	point.base_block10 = (unsigned short *)0x6005000;
	point.base_block11 = (unsigned short *)0x6005800;

	point.characterAddress = (unsigned int *)0x06008000;

	point.base_block20 = (unsigned short *)0x600a000;
	point.base_block24 = (unsigned short *)0x600c000;
	point.base_block25 = (unsigned short *)0x600c800;
	point.base_block26 = (unsigned short *)0x600d000;
	point.base_block27 = (unsigned short *)0x600d800;
	point.base_block24a = (unsigned int *)0x600a000;
	point.spriteAddress = (unsigned int *)0x06010000;

	point.obj_holderAddress = (unsigned short *)0x07000000;//OAM - OBJ Attributes      (1 Kbyte)
	//new for COPRE
	point.PAKROM = (unsigned short *)0x08000000;//Game Pak ROM/FlashROM (max 32MB)
	point.CARTRAM = (unsigned short *)0x0E000000;//Cart ram (64kb)
	
}

