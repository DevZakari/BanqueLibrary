#include "pch.h"
#include "Date.h"
#include <ctime>
using namespace Banque;
using namespace std;

Banque::Date::Date()
{
	time_t t = time(0);
	tm* now = new tm();
	localtime_s(now, &t);
	this->h = now->tm_hour;
	this->m = now->tm_min;
	this->s = now->tm_sec;
	this->j = now->tm_mday;
	this->mo = now->tm_mon;
	this->a = now->tm_year;
}

void Banque::Date::AfficherDate() const
{
	cout << " Date : ";
	cout << this->h << ":" << this->m << ":" << this->s << " ";
	cout << this->j << "/" << this->mo << "/" << this->a << " || ";
}
