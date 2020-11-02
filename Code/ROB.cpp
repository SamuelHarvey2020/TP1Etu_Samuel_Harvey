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
	delete this;
}

// la méthode de solution qui pile toute les bonnes cases dans la pile.
// Elle semble bien codée mais évidemment mon app ne fonctionne pas jusque la.
void ROB::solvePathToExit()
{
	this->pathToExit.push(cube->getStartBlock());
	this->currentBlock = cube->getStartBlock();

	while (this->currentBlock->value != 'E') {

		this->currentBlock->visited = true;
	
		if(this->currentBlock->value == 'U'){
			this->currentBlock = this->currentBlock->upBlock;
			this->pathToExit.push(currentBlock);
		}
		else if (this->currentBlock->value == 'D') {
			this->currentBlock = this->currentBlock->downBlock;
			this->pathToExit.push(currentBlock);
		}
		else if (this->currentBlock->leftBlock->value != '*' && this->currentBlock->leftBlock->visited == false) {
			this->currentBlock = this->currentBlock->leftBlock;
			this->pathToExit.push(currentBlock);
		}
		else if (this->currentBlock->rightBlock->value != '*' && this->currentBlock->rightBlock->visited == false) {
			this->currentBlock = this->currentBlock->rightBlock;
			this->pathToExit.push(currentBlock);
		}
		else if (this->currentBlock->frontBlock->value != '*' && this->currentBlock->frontBlock->visited == false) {
			this->currentBlock = this->currentBlock->frontBlock;
			this->pathToExit.push(currentBlock);
		}
		else if (this->currentBlock->behindBlock->value != '*' && this->currentBlock->behindBlock->visited == false) {
			this->currentBlock = this->currentBlock->behindBlock;
			this->pathToExit.push(currentBlock);
		}
		else if (this->currentBlock->leftBlock->value != '*') {
			this->pathToExit.pop();
			this->currentBlock = this->currentBlock->leftBlock;
		}
		else if (this->currentBlock->rightBlock->value != '*') {
			this->pathToExit.pop();
			this->currentBlock = this->currentBlock->rightBlock;
		}
		else if (this->currentBlock->frontBlock->value != '*') {
			this->pathToExit.pop();
			this->currentBlock = this->currentBlock->frontBlock;
		}
		else if (this->currentBlock->behindBlock->value != '*') {
			this->pathToExit.pop();
			this->currentBlock = this->currentBlock->behindBlock;
		}

	}

	if (this->currentBlock->value == 'E') {
		this->pathToExit.push(currentBlock);
	}
	
}
//=================================================================================================================================

void ROB::solveAllPoints(Block* startingBlock) {

	startingBlock->visited == true;
	int count = 0;

	if (startingBlock->points != 0) {
		this->allPoints.ajouter(startingBlock);
	}

	if (startingBlock->leftBlock->value != '*' && startingBlock->leftBlock->visited == false) {
		count++;
	}
	if (startingBlock->rightBlock->value != '*' && startingBlock->rightBlock->visited == false) {
		count++;
	}
	if (startingBlock->frontBlock->value != '*' && startingBlock->frontBlock->visited == false) {
		count++;
	}
	if (startingBlock->value != 'S' && startingBlock->behindBlock->value != '*' && startingBlock->behindBlock->visited == false) {
		count++;
	}
	if (startingBlock->value == 'U' && startingBlock->upBlock->visited == false) {
		count++;
	}
	else if (startingBlock->value == 'D' && startingBlock->downBlock->visited == false) {
		count++;
	}

	if (count == 1) {

		if (startingBlock->leftBlock->value != '*' && startingBlock->leftBlock->visited == false) {
			startingBlock = startingBlock->leftBlock;
		}
		else if (startingBlock->rightBlock->value != '*' && startingBlock->rightBlock->visited == false) {
			startingBlock = startingBlock->rightBlock;
		}
		else if (startingBlock->frontBlock->value != '*' && startingBlock->frontBlock->visited == false) {
			startingBlock = startingBlock->frontBlock;
		}	
		else if (startingBlock->value != 'S' && startingBlock->behindBlock->value != '*' && startingBlock->behindBlock->visited == false) {
			startingBlock = startingBlock->behindBlock;
		}
		else if (startingBlock->value == 'U' && startingBlock->upBlock->visited == false) {
			startingBlock = startingBlock->upBlock;
		}
		else if (startingBlock->value == 'D' && startingBlock->downBlock->visited == false) {
			startingBlock = startingBlock->downBlock;
		}

		solveAllPoints(startingBlock);
	}

	if (count > 2) {
		if (startingBlock->leftBlock->value != '*' && startingBlock->leftBlock->visited == false) {
			solveAllPoints (startingBlock->leftBlock);
		}
		if (startingBlock->rightBlock->value != '*' && startingBlock->rightBlock->visited == false) {
			solveAllPoints (startingBlock->rightBlock);
		}
		if (startingBlock->frontBlock->value != '*' && startingBlock->frontBlock->visited == false) {
			solveAllPoints(startingBlock->frontBlock);
		}
		if (startingBlock->value != 'S' && startingBlock->behindBlock->value != '*' && startingBlock->behindBlock->visited == false) {
			solveAllPoints(startingBlock->behindBlock);
		}
		if (startingBlock->value == 'U' && startingBlock->upBlock->visited == false) {
			solveAllPoints(startingBlock->upBlock);
		}
		if (startingBlock->value == 'D' && startingBlock->downBlock->visited == false) {
			solveAllPoints(startingBlock->downBlock);
		}
	}

}

// ici j'affiche le résultat de ma pile de solution
string ROB::getSolutionPathToExit()
{
	cout << "Le chemin de sortie est :" << endl;
	this->pathToExit.affiche();
	return "";
}

string ROB::getSolutionAllPoints() {
	cout << "Les points sont : " << endl;
	this->allPoints.allBlocksAndPoints_toString();
	return "";
}
