////////////////////////////////////////////////////////////////////////////////
// Filename: aStarstruct.h
////////////////////////////////////////////////////////////////////////////////
#ifndef ASTARSTRUCT_H_
#define ASTARSTRUCT_H_
#pragma once
/////////////////
// My INCLUDES //
/////////////////
#include "systemincludes.h"
typedef enum NodeStates
{
	Untested,
	Open,
	Closed
}nodeState;
typedef struct Nodes
{

	unsigned short LocationX;
	unsigned short LocationY;
	int nodeRef;
	bool walkable;
	float g;
	float h;
	float f;
	nodeState state;
	int parentNodeRef;
	int endNodeRef;
	}Node;
Node startNode;
Node endNode;
Node node;
typedef struct NodesHolder
{
	Node selfNode;
	Node ParentNode;
	int listCount;
	
	Node Start;
	Node nodeHolderList[NUMBEROFNODES];
	//Node oldNodeHolderList[128];
	//Node nodeHolderList2[128];
	Node End;
}NodeHolder;
typedef struct EnemyAI
{
	const unsigned short *map;
	int frame;
	bool checkNextNode;
	Node tempNodeHolder[8];
	Node myNode;
	NodeHolder nodeList;
	int iteration;
	int enemyIteration;

}enemyAI;
enemyAI enemyai[NUMBER_OF_ENEMIES];
nodeState stateArray[4096];

#endif 