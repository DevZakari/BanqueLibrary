#include "pch.h"
#include "CompteEpargne.h"
#include "MAD.h"
#include "assert.h"
using namespace Banque;

Banque::CompteEpargne::CompteEpargne(Client* cli, Devise* s,char type, double taux):Compte(cli,s,type)
{
	assert(taux > 0 && taux <= 100);
	this->tauxI = taux;
}

void Banque::CompteEpargne::CalculInteret()
{
	Devise* a = new MAD(this->tauxI / 100);
	this->Compte::Crediter(&this->Interet_A_ajouter(a));
}

void Banque::CompteEpargne::AfficherDetailsCompte() const
{
	this->Compte::AfficherDetailsCompte();
}

