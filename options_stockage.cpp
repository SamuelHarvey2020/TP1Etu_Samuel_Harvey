//Voici 2 options pour stocker le cube, ce code va dans le constructeur de Cube qui a été fourni

//OPTION 1 : 3 For Imbriqués
ifstream streamInput;
streamInput.open(cubePath);
string currentLine;

if (!streamInput)
{
	string exceptionCaption = "Le fichier " + cubePath + " n'existe pas.";
	throw invalid_argument(exceptionCaption);
}

for //todo : Boucle du z à compléter
{
	//on "brule" le caractère "+" ici, ceci ne fait que passer par dessus.
	getline(streamInput, currentLine);

	for //todo : Boucle du y à compléter
	{
		getline(streamInput, currentLine);

		for //todo : Boucle du x à compléter
		{
			//todo : Allocation des blocs dans le tableau 3D
			//todo : Logique des chaînages
		}			
	}
}

streamInput.close();


//OPTION 2 : Utilisation du caractère "+":
ifstream streamInput;
streamInput.open(cubePath);
string currentLine;

if (!streamInput)
{
	string exceptionCaption = "Le fichier " + cubePath + " n'existe pas.";
	throw invalid_argument(exceptionCaption);
}

//todo : préparation des variables i et j

while (getline(streamInput, currentLine))
{
	if (currentLine == "+")
	{
		//todo : On change de niveau
		//todo : On replace le compteur j
	}

	else
	{
		for //todo : Boucle du i à compléter
		{
			//todo : Allocation des blocs dans le tableau 3D
			//todo : Logique des chaînages				
		}

		//todo : on vient de traiter une ligne donc ...
	}

}
streamInput.close();
