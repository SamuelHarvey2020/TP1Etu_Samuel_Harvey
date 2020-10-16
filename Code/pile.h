#pragma once
#include "Noeud.h"
#include "Block.h"

using namespace std;

class Pile
{
public:
	Pile();
	~Pile();
	void push(Block* _block);
	Block* pop();
	void affiche();
	Noeud* getPremierNoeud();

private:
	Noeud* premierNoeud;
};


