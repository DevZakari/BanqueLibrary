#pragma once
#include "Operation.h"
using namespace Banque;
namespace Banque {
	class OperationR :public Operation
	{
	private:
	public:
		OperationR(Date* d, Devise* s);
	};
};
