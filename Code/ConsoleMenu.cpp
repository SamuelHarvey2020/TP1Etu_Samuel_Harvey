#include "stdafx.h"
#include "ConsoleMenu.h"
#include "Cube.h"
#include "ROB.h"


ConsoleMenu::ConsoleMenu()
{
	
}


ConsoleMenu::~ConsoleMenu()
{

}

void ConsoleMenu::Run()
{
    char input;
	//Les entr�es support�es
    char tabValidInputs[] = { '1', '2', 'q' };
    const int NB_ELEMENTS = 3;

    //Tant qu'il ne quitte pas, on demande � l'utilisateur ce qu'il veut faire.
    do
    { 
		DisplayCredits();
		input = ReadValidInput(tabValidInputs, NB_ELEMENTS);
		
		
    } while (ManageSelection(input));
	
}

char ConsoleMenu::ReadValidInput(char tabValidInputs[], int nbElements)
{
	
    DisplayMenu();
    string userEntry;
    cin >> userEntry;
	
    if (userEntry.size() == 1)
    {
        //Pour tous les caract�res valides,
        for (int i = 0; i < nbElements; i++)
        {
            //Si notre entr�e y est pr�sente,
            if (tabValidInputs[i] == userEntry[0])
                //on retourne ce caract�re.
                return userEntry[0];
        }
    }

	 cout << "Votre entree doit etre une seule lettre correspondante au menu ci-dessus." << endl;
     system("pause");
	 system("cls");
  
	 return NULL;
}


void ConsoleMenu::DisplayMenu()
{
    cout << "Que voulez-vous faire ? " << endl;
    cout << "Appuyez sur 1 pour solutionner l'algorithme du chemin de sortie" << endl;
    cout << "Appuyez sur 2 pour solutionner l'algorithme de tous les points" << endl;
    cout << "Appuyez sur q pour quitter le programme." << endl;
}


void ConsoleMenu::DisplayCredits()
{
	cout << "-------------------------------------------------------------------" << endl;
    cout << "|                       TRAVAIL PRATIQUE 1                        |" << endl;
    cout << "|                              R.O.B                              |" << endl;
    cout << "|                                                                 |" << endl;
    cout << "|                     AUTEUR  : SAMUEL HARVEY                     |" << endl;
    cout << "|                                                                 |" << endl;
    cout << "------------------------------------------------------------------|" << endl;
    cout << endl;
	cout << endl;
}


bool ConsoleMenu::ManageSelection(char entry)
{
	
    bool toContinue = true;
    
    switch (entry)
    {
		//Si l'utilisateur veut r�soudre l'Algo #1
		case '1':
		{  
            Cube cube("cube5.txt");
			ROB rob(&cube);
			cube.resetAllVisitedBlockstoFalse();
			rob.solvePathToExit();
			rob.getSolutionPathToExit();
       		system("pause");
			system("cls");
			break;
		}

		//Si l'utilisateur veut r�soudre la partie 2
		case '2':
		{
			Cube cube("cube5.txt");
			ROB rob(&cube);
			cube.resetAllVisitedBlockstoFalse();
			rob.solveAllPoints(cube.getStartBlock());
			rob.getSolutionAllPoints();
			system("pause");
			system("cls");
			break;
		}
		
		//Si l'utilisateur veut quitter le programme,
		case 'q':
			//on quitte le programme.
			toContinue = false;
			break;

    }
	
	return toContinue;
}
