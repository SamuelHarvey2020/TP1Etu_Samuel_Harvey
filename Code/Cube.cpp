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
		//Cette exception doit être gérée
		throw invalid_argument(exceptionCaption);
	}
	
	while (getline(streamInput, currentLine))
	{
		//RAPPELS
		//1) Le symbole "+" indique qu'on passe au prochain level 
		//2) Le premier level rencontré dans le fichier texte est celui le plus bas (niveau 0) et on monte jusqu'au dernier (niveau CUBE_SIZE - 1)
		//3) Tous les blocs doivent être alloués dynamiquement dans le tableau 3D
		//4) Utilisez un algo simple basé sur les indices de tableau pour attribuer les pointeurs vers les blocs voisins
        //5) N'oubliez pas d'attribuer le bloc de départ
		//6) 2 cubes sont donnés avec ce TP, commencez avec celui de dimension 5 (plus facile à déboguer)
	}
	streamInput.close();
	
}

Cube::~Cube()
{
	
}

