#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Cube
{
public:
	Cube(string cubePath);
    ~Cube();
	Block* getStartBlock();
  
private:
	const int CUBE_SIZE = 5;
	Block* cube;
	Block* startBlock;
};

