#include "stdafx.h"
#include "Cube.h"

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
	
	while (getline(streamInput, currentLine))
	{
		
		for (int i = 0; i < CUBE_SIZE - 1; i++) //todo : Boucle du z � compl�ter
		{
			//on "brule" le caract�re "+" ici, ceci ne fait que passer par dessus.
			getline(streamInput, currentLine);

			for(int ii = 0; ii < CUBE_SIZE - 1; ii++) //todo : Boucle du y � compl�ter
			{
				getline(streamInput, currentLine);

				for(int iii = 0; iii < CUBE_SIZE - 1; iii++) //todo : Boucle du x � compl�ter
				{

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

