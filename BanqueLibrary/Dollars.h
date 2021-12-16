#pragma once
#include "Devise.h"
using namespace Banque;
namespace Banque {
	class Dollars :public Devise
	{
	private:
		static double Dollars_to_Mad;
		static double Dollars_to_Euros;
	public:
		Dollars(double s);
		Devise& Convert(Devise* m, char type)override;
	};
};
