#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Cube.h"
#include "pile.h"
#include "Block.h"

using namespace std;


class ROB
{
public:
	ROB(Cube* cube);
	~ROB();
	void solvePathToExit();
	string getSolutionPathToExit();

private:
	Cube* cube;
	Pile pathToExit;
	bool solved = false;
	Block* currentBlock;
};


