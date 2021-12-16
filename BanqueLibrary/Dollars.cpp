#include "pch.h"
#include "Dollars.h"
#include "Euros.h"
#include "MAD.h"

double Banque::Dollars::Dollars_to_Euros = 0.89;
double Banque::Dollars::Dollars_to_Mad =9.26 ;

Banque::Dollars::Dollars(double s):Devise(s)
{
}

Devise& Banque::Dollars::Convert(Devise* m, char type)
{
	if (type == 'M')
	{
		Devise* nv = new Dollars(Dollars_to_Mad);
		*nv = *nv * *m;
		return *nv;
	}
	else if (type == 'E')
	{
		Devise* nv = new Euros(Dollars_to_Euros);
		*nv = *nv * *m;
		return *nv;
	}
	else {
		return *m;
	}
}
