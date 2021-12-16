#include "pch.h"
#include "CompteCourant.h"
using namespace Banque;

Banque::CompteCourant::CompteCourant(Client* cli, Devise* s,char type, Devise* dec):Compte(cli,s,type)
{
    this->decouvert = dec;
}

bool Banque::CompteCourant::Debiter(Devise* m)
{
    if (this->CheckSolde(m, this->decouvert))
    {
        return this->Compte::Debiter(m);
    }
    return false;
}

void Banque::CompteCourant::AfficherDetailsCompte() const
{
    this->Compte::AfficherDetailsCompte();
}
