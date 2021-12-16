#pragma once
#include <iostream>
namespace Banque {
	class Devise
	{
	private:
		double solde;
	public:
		Devise(double s);
		void AfficherSolde()const;
		Devise& operator + (const Devise& s);
		Devise& operator - (const Devise& s);
		Devise& operator * (const Devise& s);
		Devise& operator * (double s);
		bool operator >= (const Devise& s)const;
		bool  operator <= (const Devise& s)const;
		bool operator > (const Devise& s)const;
		bool  operator < (const Devise& s)const;
		virtual Devise& Convert(Devise* m, char type)=0;
	};
};
