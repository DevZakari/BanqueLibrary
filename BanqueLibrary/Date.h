#pragma once
#include <iostream>
namespace Banque {
	class Date
	{
	private:
		int h, m, s, j, mo, a;
	public:
		Date();
		void AfficherDate()const;
	};
};
