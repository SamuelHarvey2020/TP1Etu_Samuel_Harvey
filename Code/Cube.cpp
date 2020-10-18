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
		//Cette exception doit �tre g�r�e
		throw invalid_argument(exceptionCaption);
	}

	Block * cube = new Block[CUBE_SIZE * CUBE_SIZE * CUBE_SIZE];

	while (getline(streamInput, currentLine))
	{
		
		for (int i = 0; i < CUBE_SIZE - 1; i++) //todo : Boucle du z � compl�ter
		{
			//on "brule" le caract�re "+" ici, ceci ne fait que passer par dessus.
			getline(streamInput, currentLine);

			for(int ii = CUBE_SIZE - 1; ii > 0; ii--) //todo : Boucle du y � compl�ter
			{
				getline(streamInput, currentLine);

				for(int iii = 0; iii < CUBE_SIZE - 1; iii++) //todo : Boucle du x � compl�ter
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

					if (newBlock.value == 'U') {
						
					}
					if (newBlock.value == 'D') {

					}
					

					//todo : Allocation des blocs dans le tableau 3D
					//todo : Logique des cha�nages
				}
			}
		}
		//RAPPELS
		//1) Le symbole "+" indique qu'on passe au prochain level 
		//2) Le premier level rencontr� dans le fichier texte est celui le plus bas (niveau 0) et on monte jusqu'au dernier (niveau CUBE_SIZE - 1)
		//3) Tous les blocs doivent �tre allou�s dynamiquement dans le tableau 3D
		//4) Utilisez un algo simple bas� sur les indices de tableau pour attribuer les pointeurs vers les blocs voisins
        //5) N'oubliez pas d'attribuer le bloc de d�part
		//6) 2 cubes sont donn�s avec ce TP, commencez avec celui de dimension 5 (plus facile � d�boguer)
	}
	streamInput.close();
	
}

Cube::~Cube()
{
	
}

