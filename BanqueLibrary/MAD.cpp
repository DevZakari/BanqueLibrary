#include "pch.h"
#include "MAD.h"
#include "Dollars.h"
#include "Euros.h"
using namespace Banque;

double Banque::MAD::Mad_to_Dollars = 0.11;
double Banque::MAD::Mad_to_Euros = 0.096;
Banque::MAD::MAD(double s) :Devise(s)
{
}

Devise& Banque::MAD::Convert(Devise* s, char type)
{
	if (type == 'D')
	{
		Devise* nv = new Dollars(Mad_to_Dollars);
		*nv = *nv * *s;
		return *nv;
	}
	else if (type == 'E')
	{
		Devise* nv = new Euros(Mad_to_Euros);
		*nv = *nv * *s;
		return *nv;
	}
	else {
		return *s;
	}
	
}
