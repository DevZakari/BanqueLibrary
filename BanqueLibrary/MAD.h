#pragma once
#include "Devise.h"
using namespace Banque;
namespace Banque {
	class MAD :public Devise
	{
	private:
		static double Mad_to_Dollars;
		static double Mad_to_Euros;
	public:
		MAD(double s);
		Devise& Convert(Devise* s, char type)override;
	};
};
