#pragma once
#include <iostream>
#include "Client.h"
#include "Devise.h"
#include "Operation.h"
#include "GC.h"
using namespace Banque;
namespace Banque {

	class Client;
	class Compte
	{
	private:
		const int numCompte;
		static int compt;
		Client* titulaire;
		static Devise *plafond;
		Devise *solde;
		char type;
		// operation sur les comptes : 
		vector<Operation*> historique;
		// Garbage Collector : 
		GC* ref;

	public:
		Compte(Client* c, Devise* m,char type);
		Compte(const Compte& c);
		void Crediter(Devise *s );
		virtual bool Debiter(Devise* s);
		virtual bool verser(Devise* s, Compte& c);
		 void AfficherDetailsCompte()const;
		~Compte();
	protected:
		bool CheckSolde(Devise* m, Devise* dec)const;
		Devise& Interet_A_ajouter(Devise* t)const;
	};
};
