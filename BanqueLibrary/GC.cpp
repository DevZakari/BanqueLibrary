#include "pch.h"
#include "GC.h"
using namespace Banque;

Banque::GC::GC(int x)
{
    this->compt = x;
}

void Banque::GC::incre()
{
    this->compt++;
}

int Banque::GC::decre()
{
    this->compt--;
    return this->compt;
}
