#pragma once
#include "Compte.h"
namespace Banque {
	class CompteEpargne : public Compte
	{
	private:
		double tauxI;
	public:
		CompteEpargne(Client* cli, Devise* s,char type,double taux);
		void CalculInteret();
		void AfficherDetailsCompte()const ;
	};
};
