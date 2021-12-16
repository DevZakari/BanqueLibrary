#include "pch.h"
#include "ComptePayant.h"
#include "MAD.h"
using namespace Banque;
double Banque::ComptePayant::cout_operation = 0.05;

Banque::ComptePayant::ComptePayant(Client* cli, Devise* s,char type):Compte(cli,s,type)
{
}

bool Banque::ComptePayant::Debiter(Devise* s)
{
    Devise* nv_s = &s->Convert(s, 'M');
    Devise* nv = &(*nv_s * (1 + this->cout_operation));
    return this->Compte::Debiter(nv);
}

bool Banque::ComptePayant::verser(Devise* s, Compte& c)
{
    return this->Debiter(s);
}

void Banque::ComptePayant::AfficherDetailsCompte() const
{
    this->Compte::AfficherDetailsCompte();
}
