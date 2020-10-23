#include "stdafx.h"
#include "File.h"
#include <iostream>
#include <string>

using namespace std;

File::File()
{
	this->premierNoeud = NULL;
	this->dernierNoeud = NULL;
}

File::~File()
{

}

void File::ajouter(Block* _block)
{
	Noeud* nouveauNoeud = new Noeud;
	nouveauNoeud->setBlock(_block);

	if (this->premierNoeud == NULL) {
		this->premierNoeud = nouveauNoeud;
		this->premierNoeud->setSuivant(NULL);
	}
	else {
		this->dernierNoeud->setSuivant(nouveauNoeud);
	}
	this->dernierNoeud = nouveauNoeud;
}

Block* File::retirer()
{
	return nullptr;
}

Noeud* File::getPremierNoeud()
{
	return this->premierNoeud;
}

Noeud* File::getDernierNoeud()
{
	this->getDernierNoeud;
}
