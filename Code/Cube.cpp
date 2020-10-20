#include "stdafx.h"
#include "Cube.h"
#include "Block.h"

Cube::Cube(string cubePath)
{
	ifstream streamInput;
	streamInput.open(cubePath);
	string currentLine;

	if (!streamInput)
	{
		string exceptionCaption = "Le fichier " + cubePath + " n'existe pas.";
		throw invalid_argument(exceptionCaption);
	}

	this->cube = new Block[CUBE_SIZE * CUBE_SIZE * CUBE_SIZE];

	while (getline(streamInput, currentLine))
	{
		
		for (int i = 0; i <= CUBE_SIZE - 1; i++)
		{
			//on "brule" le caractère "+" ici, ceci ne fait que passer par dessus.
			getline(streamInput, currentLine);

			for(int ii = CUBE_SIZE - 1; ii >= 0; ii--)
			{
				
				for(int iii = 0; iii <= CUBE_SIZE - 1; iii++)
				{
					Block newBlock = Block();

					newBlock.x = iii;
					newBlock.y = ii;
					newBlock.z = i;

					newBlock.value = currentLine[iii];

					if (newBlock.value == '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9') {

						//ici pour mettre la valeur en int je soustrait le code ascii de 0
						newBlock.points = newBlock.value - '0';
					}
					else { newBlock.points = 0; }	

					cube[i, ii, iii] = newBlock;
				}

				getline(streamInput, currentLine);
			}
		}
	}

	streamInput.close();

	// ici je fais une boucle afin de parcourir mon tableau une deuxiemme fois pour effectuer le chainage.
	// Malheureusement, une erreur inconnue m'empêche de bien effectuer le chainae car mon z reste a 4. 
	for (int i = 0; i <= CUBE_SIZE - 1; i++)
	{

		for (int ii = CUBE_SIZE - 1; ii >= 0; ii--)
		{

			for (int iii = 0; iii <= CUBE_SIZE - 1; iii++)
			{
				Block actualBlock = this->cube[i, ii, iii];

				//StartBlock
				if (actualBlock.value == 'S') {
					this->startBlock = &actualBlock;
				}

				//Bloc au dessus si le bloc est un bloc de lvlUP
				if (actualBlock.value == 'U') {
					actualBlock.upBlock = &cube[i+1, ii, iii];
				}
				else {
					actualBlock.upBlock = NULL;
				}

				//Bloc en dessous si le bloc est un bloc de lvlDOWN
				if (actualBlock.value == 'D') {
					actualBlock.downBlock = &cube[i - 1, ii, iii];
				}
				else {
					actualBlock.downBlock = NULL;
				}

				//Bloc a gauche si le bloc ne fait pas partie du mur de gauche
				if (actualBlock.x > 0) {
					actualBlock.leftBlock = &cube[i, ii, iii - 1];
				}
				else {
					actualBlock.leftBlock = NULL;
				}

				//Bloc a droite si le bloc ne fait pas partie du mur de droite
				if (actualBlock.x < 4) {
					actualBlock.rightBlock = &cube[i, ii, iii + 1];
				}
				else {
					actualBlock.rightBlock = NULL;
				}

				//Bloc en face si le bloc ne fait pas partie du mur de face
				if (actualBlock.y < 4) {
					actualBlock.frontBlock = &cube[i, ii + 1, iii];
				}
				else {
					actualBlock.frontBlock = NULL;
				}

				//Bloc derriere si le bloc ne fait pas partie du mur de derriere
				if (actualBlock.y > 0) {
					actualBlock.behindBlock = &cube[i, ii - 1, iii];
				}
				else {
					actualBlock.behindBlock = NULL;
				}

				cube[i, ii, iii] = actualBlock;
			}
		}
	}
}

Cube::~Cube()
{
	delete this->cube;
}

Block* Cube::getStartBlock()
{
	return this->startBlock;
}




