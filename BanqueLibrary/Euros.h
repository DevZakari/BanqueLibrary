#pragma once
#include "Devise.h"
using namespace Banque;
namespace Banque {
	class Euros :public Devise
	{
	private:
		static double Euros_to_Mad;
		static double Euros_to_Dollars;
	public:
		Euros(double s);
		Devise& Convert(Devise* m, char type) override;
	};
};
