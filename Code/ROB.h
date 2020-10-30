#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Cube.h"
#include "pile.h"
#include "Block.h"
#include "File.h"

using namespace std;


class ROB
{
public:
	ROB(Cube* cube);
	~ROB();
	
	void solvePathToExit();
	void solveAllPoints(Block* startingBlock);

	string getSolutionPathToExit();
	string getSolutionAllPoints();

	Block* currentBlock;
	bool solved = false;

private:
	Cube* cube;
	Pile pathToExit;
	File allPoints;
};


