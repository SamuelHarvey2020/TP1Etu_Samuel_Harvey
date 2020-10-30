#pragma once
#include "Noeud.h"
class File
{

public :
	File();
	~File();
	void ajouter(Block* _block);
	Block* retirer();
	void allBlocksAndPoints_toString();
	Noeud* getPremierNoeud();
	Noeud* getTopBlock();
	Noeud* getDernierNoeud();
private :
	Noeud* premierNoeud;
	Noeud* dernierNoeud;
};

