#pragma once
#include "Noeud.h"
class File
{

public :
	File();
	~File();
	void ajouter(Block* _block);
	Block* retirer();
	Noeud* getPremierNoeud();
	Noeud* getDernierNoeud();
private :
	Noeud* premierNoeud;
	Noeud* dernierNoeud;
};

