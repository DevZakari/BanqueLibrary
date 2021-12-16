#include "pch.h"
#include "Operation.h"
using namespace std;
using namespace Banque;

int Operation::compt = 0;

Banque::Operation::Operation(Date* t, Devise* m, string lib):num{++compt}
{
	this->d = t;
	this->montant = m;
	this->libelle = lib;
}

void Banque::Operation::AfficherOperation() const
{
	cout << "Operation :  " << this->num << " " << "|| " << this->libelle << " ||  ";
	this->d->AfficherDate();
	this->montant->AfficherSolde();
	cout << endl;
}
