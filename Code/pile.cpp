#include "stdafx.h"
#include "Pile.h"
#include <iostream>
#include <string>

using namespace std;

Pile::Pile()
{
	this->premierNoeud = NULL;
}


Pile::~Pile()
{
	while (this->premierNoeud != NULL) {
		Noeud* noeudTemporaire = this->premierNoeud->getSuivant();
		delete this->premierNoeud;
		this->premierNoeud = noeudTemporaire;
	}
}

void Pile::push(Block* _block)
{
	Noeud* nouveauNoeud = new Noeud;
	nouveauNoeud->setBlock(_block);
	nouveauNoeud->setSuivant(this->premierNoeud);
	this->premierNoeud = nouveauNoeud;
}

Block* Pile::pop()
{
	if (this->premierNoeud != NULL) {
		Block* block = this->premierNoeud->getBlock();
		Noeud* noeudTemporaire = this->premierNoeud;
		this->premierNoeud = noeudTemporaire->getSuivant();
		delete noeudTemporaire;

		return block;
	}
	else {
		return NULL;
	}
}

void Pile::affiche()
{
	if (this->premierNoeud != NULL) {

		Pile* pileTemporaire = new Pile;
		do {
			pileTemporaire->push(this->pop());
			int x = pileTemporaire->premierNoeud->getBlock()->x;
			int y = pileTemporaire->premierNoeud->getBlock()->y;
			int z = pileTemporaire->premierNoeud->getBlock()->z;
			cout << "[" + to_string(x) + "," + to_string(y) + "," + to_string(z) + "]" << endl << endl;
		} while (this->premierNoeud != NULL);

		do {
			this->push(pileTemporaire->pop());

		} while (pileTemporaire->premierNoeud != NULL);

		delete pileTemporaire;
	}
	else {
		cout << "la pile est vide." << endl << endl;
	}
}

Noeud* Pile::getPremierNoeud()
{
	return this->premierNoeud;
}