#include "pch.h"
#include "Client.h"
using namespace Banque;

Banque::Client::Client(string n, string p, string a)
{
	this->nom = n;
	this->prenom = p;
	this->adress = a;
	this->mes_comptes = vector<Compte*>();
}

void Banque::Client::AfficherDetailsClient() const
{
	cout << "Nom : " << this->nom << " Prenom : " << this->prenom << " Adresse : " << this->adress << endl;
	cout << "Les Comptes : " << endl;
	for (int i = 0; i < this->mes_comptes.size(); i++)
	{
		this->mes_comptes[i]->AfficherDetailsCompte();
	}
}

void Banque::Client::AjouterCompte(Compte* c)
{
	this->mes_comptes.push_back(c);
}
