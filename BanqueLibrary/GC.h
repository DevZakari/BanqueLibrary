#pragma once
#include <iostream>

namespace Banque {
	class GC
	{
	private:
		int compt;
	public:
		GC(int x);
		void incre();
		int decre();
	};
};
