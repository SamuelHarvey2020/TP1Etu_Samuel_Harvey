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

	while (this->solved == false) {

		this->currentBlock->visited = true;

		if (this->currentBlock->value == 'E') {
			this->pathToExit.push(currentBlock);
			this->solved = true;
		}
		else if(this->currentBlock->value == 'U'){
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
	
}

void ROB::solveAllPoints(Block* startingBlock) {

}

// ici j'affiche le résultat de ma pile de solution
string ROB::getSolutionPathToExit()
{
	cout << "Le chemin de sortie est :" << endl;
	this->pathToExit.affiche();
	return "";
}

string ROB::getSolutionAllPoints() {
	return "";
}
