#pragma once
#include "Compte.h"
namespace Banque {
	class ComptePayant :public Compte
	{
	private:
		static double cout_operation;
	public:
		ComptePayant(Client* cli, Devise* s,char type);
		bool Debiter(Devise* s) override;
		bool verser(Devise* s, Compte& c) override;
		void AfficherDetailsCompte()const ;
	};
};
