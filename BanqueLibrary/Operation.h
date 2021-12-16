#pragma once
#include <iostream>
#include <string>
#include "Devise.h"
#include "Date.h"

using namespace std;
namespace Banque {
	class Operation
	{
	private:
		const int num;
		static int compt;
		Devise* montant;
		Date* d;
		string libelle;

	public:
		Operation(Date* t, Devise* m, string lib);
		void AfficherOperation()const;
	};
};
