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
	if (this->premierNoeud != NULL) {
		Block* _block = this->premierNoeud->getBlock();
		Noeud* noeudtemporaire = this->premierNoeud->getSuivant();
		this->premierNoeud = noeudtemporaire;
		delete noeudtemporaire;

		return _block;
	}
	else {
		return NULL;
	}


}

void File::allBlocksAndPoints_toString()
{
	if (this->premierNoeud != NULL) {
		
		File* fileTemporaire = new File;
		do {
			fileTemporaire->ajouter(this->retirer());
			int pts = fileTemporaire->premierNoeud->getBlock()->points;
			int x = fileTemporaire->premierNoeud->getBlock()->x;
			int y = fileTemporaire->premierNoeud->getBlock()->y;
			int z = fileTemporaire->premierNoeud->getBlock()->z;
			cout <<pts + "dans le block : [" + to_string(x) + "," + to_string(y) + "," + to_string(z) + "]" << endl << endl;

		} while (this->premierNoeud != NULL);

		do {
			this->ajouter(fileTemporaire->retirer());

		} while (fileTemporaire->premierNoeud != NULL);

		delete fileTemporaire;
	}
	else {
		cout << "la file est vide." << endl << endl;
	}
}

Noeud* File::getPremierNoeud()
{
	return this->premierNoeud;
}

Noeud* File::getTopBlock()
{
	return getPremierNoeud();
}

Noeud* File::getDernierNoeud()
{
	return this->dernierNoeud;
}
