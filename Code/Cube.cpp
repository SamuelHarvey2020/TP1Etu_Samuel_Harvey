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
		//Cette exception doit être gérée
		throw invalid_argument(exceptionCaption);
	}

	cube = new Block[CUBE_SIZE * CUBE_SIZE * CUBE_SIZE];

	while (getline(streamInput, currentLine))
	{
		
		for (int i = 0; i < CUBE_SIZE - 1; i++) //todo : Boucle du z à compléter
		{
			//on "brule" le caractère "+" ici, ceci ne fait que passer par dessus.
			getline(streamInput, currentLine);

			for(int ii = CUBE_SIZE - 1; ii > 0; ii--) //todo : Boucle du y à compléter
			{
				getline(streamInput, currentLine);

				for(int iii = 0; iii < CUBE_SIZE - 1; iii++) //todo : Boucle du x à compléter
				{
					Block newBlock = Block();
					cube[i, ii, iii] = newBlock;

					newBlock.x = iii;
					newBlock.y = ii;
					newBlock.z = i;

					newBlock.value = currentLine.at(iii);

					if (newBlock.value == '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9') {

						//ici pour mettre la valeur en int je soustrait le code ascii de 0
						newBlock.points = newBlock.value - '0';
					}
					else { newBlock.points = 0; }	

					//todo : Allocation des blocs dans le tableau 3D
					//todo : Logique des chaînages
				}
			}
		}

		//RAPPELS
		//1) Le symbole "+" indique qu'on passe au prochain level 
		//2) Le premier level rencontré dans le fichier texte est celui le plus bas (niveau 0) et on monte jusqu'au dernier (niveau CUBE_SIZE - 1)
		//3) Tous les blocs doivent être alloués dynamiquement dans le tableau 3D
		//4) Utilisez un algo simple basé sur les indices de tableau pour attribuer les pointeurs vers les blocs voisins
        //5) N'oubliez pas d'attribuer le bloc de départ
		//6) 2 cubes sont donnés avec ce TP, commencez avec celui de dimension 5 (plus facile à déboguer)
	}

	streamInput.close();


	for (int i = 0; i < CUBE_SIZE - 1; i++) //todo : Boucle du z à compléter
	{

		for (int ii = CUBE_SIZE - 1; ii > 0; ii--) //todo : Boucle du y à compléter
		{

			for (int iii = 0; iii < CUBE_SIZE - 1; iii++) //todo : Boucle du x à compléter
			{
				Block actualBlock = cube[i, ii, iii];

				//StartBlock
				if (actualBlock.value = 'S') {
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

				//Bloc en face si le bloc ne fait pas partie du mur de face
				if (actualBlock.y < 4) {
					actualBlock.frontBlock = &cube[i, ii + 1, iii];
				}
				else {
					actualBlock.frontBlock = NULL;
				}

				//Bloc a droite si le bloc ne fait pas partie du mur de droite
				if (actualBlock.x < 4) {
					actualBlock.rightBlock = &cube[i, ii, iii + 1];
				}
				else {
					actualBlock.rightBlock = NULL;
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
	
}

Block* Cube::getStartBlock()
{
	return this->startBlock;
}



