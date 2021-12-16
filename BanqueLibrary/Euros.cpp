#include "pch.h"
#include "Dollars.h"
#include "Euros.h"
#include "MAD.h"
using namespace Banque;

double Banque::Euros::Euros_to_Dollars = 1.13;
double Banque::Euros::Euros_to_Mad = 10.45;

Banque::Euros::Euros(double s):Devise(s)
{
}

Devise& Banque::Euros::Convert(Devise* m, char type)
{
	if (type == 'D')
	{
		Devise* nv = new Dollars(Euros_to_Dollars);
		*nv = *nv * *m;
		return *nv;
	}
	else if (type == 'M')
	{
		Devise* nv = new Euros(Euros_to_Mad);
		*nv = *nv * *m;
		return *nv;
	}
	else {
		return *m;
	}
}
