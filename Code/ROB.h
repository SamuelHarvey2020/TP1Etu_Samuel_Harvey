#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Cube.h"
#include "pile.h"

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
};


