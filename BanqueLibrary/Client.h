#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Compte.h"
using namespace std;
namespace Banque {
	class Compte;
	class Client
	{
	private:
		string nom;
		string prenom;
		string adress;
		// une liste des compte : 
		vector<Compte*> mes_comptes;
	public:
		Client(string n, string p, string a);
		void AfficherDetailsClient()const;
		// ajouter un compte pour un client :
		void AjouterCompte(Compte* c);
	};
};
