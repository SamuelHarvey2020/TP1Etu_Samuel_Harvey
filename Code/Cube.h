#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Block.h"

using namespace std;

class Cube
{
public:
	Cube(string cubePath);

	void resetAllVisitedBlockstoFalse();

	~Cube();

	Block* getStartBlock();

private:
	const int CUBE_SIZE = 5;

	Block* tabBlocks[5][5][5];
	
	Block* startBlock;
};

