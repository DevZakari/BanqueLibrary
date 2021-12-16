#pragma once
#include "Compte.h"

namespace Banque {
	class CompteCourant :public Compte
	{
	private:
		Devise* decouvert;
	public:
		CompteCourant(Client* cli, Devise* s,char type, Devise* dec);
		bool Debiter(Devise* m) override;
		void AfficherDetailsCompte()const ;
	};
};
