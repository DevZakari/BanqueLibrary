#include "pch.h"
#include "Devise.h"
using namespace Banque;
using namespace std;

Banque::Devise::Devise(double s)
{
	this->solde = s;
}

void Banque::Devise::AfficherSolde() const
{
	cout << this->solde << " ";
}

Devise& Banque::Devise::operator+(const Devise& s)
{
	this->solde = this->solde + s.solde;
	return *this;
}

Devise& Banque::Devise::operator-(const Devise& s)
{
	this->solde = this->solde - s.solde;
	return *this;
}

Devise& Banque::Devise::operator*(const Devise& s)
{
	this->solde = this->solde * s.solde;
	return *this;
}

Devise& Banque::Devise::operator*(double s)
{
	this->solde = this->solde * s;
	return *this;
}

bool Banque::Devise::operator>=(const Devise& s)const
{
	return this->solde >= s.solde;
}

bool Banque::Devise::operator<=(const Devise& s)const
{
	return !(this->operator>=(s));
}

bool Banque::Devise::operator>(const Devise& s)const
{
	return this->solde > s.solde;
}

bool Banque::Devise::operator<(const Devise& s) const
{
	return !(this->operator>(s));
}

