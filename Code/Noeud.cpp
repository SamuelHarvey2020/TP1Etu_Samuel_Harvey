#include "stdafx.h"
#include "Noeud.h"

Noeud::Noeud()
{
}


Noeud::~Noeud()
{
}

Noeud* Noeud::getSuivant()
{
	return this->suivant;
}

void Noeud::setSuivant(Noeud* _suivant)
{
	this->suivant = _suivant;
}

Block* Noeud::getBlock()
{
	return this->block;
}

void Noeud::setBlock(Block* _block)
{
	this->block = _block;
}

