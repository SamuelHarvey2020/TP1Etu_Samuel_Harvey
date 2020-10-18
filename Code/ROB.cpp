
#include "stdafx.h"
#include "ROB.h"
#include "stdafx.h"
#include "Cube.h"
#include "Block.h"
#include "Pile.h"


ROB::ROB(Cube* cube)
{
	this->cube = cube;
}

ROB::~ROB()
{
}

void ROB::solvePathToExit()
{
	this->pathToExit.push(cube->getStartBlock());
	
}

string ROB::getSolutionPathToExit()
{
	return string();
}
