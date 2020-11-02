#include "stdafx.h"
#include "Cube.h"
#include "Block.h"

Cube::Cube(string cubePath)
{
	std::ifstream streamInput;
	streamInput.open(cubePath);
	std::string currentLine;

	int j = CUBE_SIZE - 1;
	int level = -1;

	if (streamInput)
	{
		while (getline(streamInput, currentLine))
		{
			if (currentLine == "+")
			{
				//afin de débuter le z à 0
				level++;

				//on replace l'ordonnée en 4 (pour partir du haut)
				j = CUBE_SIZE - 1;
			}

			else
			{
				//stockage de tous les éléments du tableau 3D

				//on stocke la ligne selon l'abscisse
				for (size_t i = 0; i < CUBE_SIZE; i++)
				{
					Block* block = new Block();
					block->x = i;
					block->y = j;
					block->z = level;
					//Vérification si c'est un numérique (points)
					if (std::isdigit(currentLine[i]))
					{
						//c'est un espace circulable comme les autres
						block->value = ' ';
						block->points = currentLine[i] - '0';
					}
					else
					{
						//on stocke la valeur du caractère
						block->value = currentLine[i];
						block->points = 0;
					}

					if (block->value == 'S')
					{
						startBlock = block;
					}

					tabBlocks[i][j][level] = block;

					//On effectue les chaînages, 2 dans 1 est possible
					if (i > 0)
					{
						tabBlocks[i - 1][j][level]->rightBlock = block;
						block->leftBlock = tabBlocks[i - 1][j][level];
					}

					if (j < CUBE_SIZE - 1)
					{
						tabBlocks[i][j + 1][level]->behindBlock = block;
						block->frontBlock = tabBlocks[i][j + 1][level];
					}

					if (level > 0)
					{
						//Un labyrinthe valide a un Up qui débouche donc pas besoin de vérifier que level du haut laisse entrer
						if (tabBlocks[i][j][level - 1]->value == 'U')
						{
							tabBlocks[i][j][level - 1]->upBlock = block;
						}

						//Idem pour le down
						else if (tabBlocks[i][j][level]->value == 'D')
						{
							block->downBlock = tabBlocks[i][j][level - 1];
						}
					}
				}

				//on diminue l'ordonnée de 1
				j--;
			}

		}
		streamInput.close();
	}
}

void Cube::resetAllVisitedBlockstoFalse() {

	for (int i = 0; i< CUBE_SIZE; i++) {

		for (int ii = 0; ii < CUBE_SIZE; ii++) {

			for (int iii = 0; iii < CUBE_SIZE; iii++) {

				if (tabBlocks[i][ii][iii]->visited == true) {

					tabBlocks[i][ii][iii]->visited == false;
				}
			}
		}
	}
}

Cube::~Cube()
{
	delete this->tabBlocks;
}

Block* Cube::getStartBlock()
{
	return this->startBlock;
}




