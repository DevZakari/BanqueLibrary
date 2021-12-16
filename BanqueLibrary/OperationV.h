#pragma once
#include "Operation.h"
using namespace Banque;
namespace Banque {
	class OperationV :public Operation
	{
	private:
	public:
		OperationV(Date* d, Devise* s);
	};
};
