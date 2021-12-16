#include "pch.h"
#include "Compte.h"
#include "OperationV.h"
#include "OperationR.h"
#include "assert.h"
#include "MAD.h"
using namespace std;
using namespace Banque;

int Compte::compt = 0;
Devise* Compte::plafond = new MAD(2000);

Banque::Compte::Compte(Client* c, Devise* m,char type):numCompte{compt++}
{
    this->titulaire = c;
    // initialisation du GC : 
    ref = new GC(1);
    this->solde = m;
    assert(type == 'D' || type == 'M' || type == 'E');
    this->type = type;
    this->historique = vector<Operation*>();
}

Banque::Compte::Compte(const Compte& c):numCompte{c.numCompte}
{
    this->titulaire = c.titulaire;
    // augmentation du ref : 
    this->ref->incre();
    this->solde = c.solde;
    this->historique = c.historique;
}

void Banque::Compte::Crediter(Devise* s)
{
    Devise* nv_s= &s->Convert(s, this->type);
    *this->solde = *this->solde + *nv_s;
    Date* d = new Date();
    Operation* op = new OperationV(d,s);
    this->historique.push_back(op);
}

bool Banque::Compte::Debiter(Devise* s)
{
    Devise* nv_s = &s->Convert(s, this->type);
    Devise* nv_p = &s->Convert(plafond, this->type);

    if (*nv_s >= *nv_p)
    {
        cout << " **  Sorry ! you cannot take a somme grather than the PLAFOND !" << endl;
        return false;
    }
    else if (*this->solde < *nv_s) {
        cout << " ** Sorry ! the balance that you have is insuffisant !" << endl;
        return false;
    }
    else {
        *this->solde = *this->solde - *nv_s;
        Date* d = new Date();
        Operation* op = new OperationR(d,s);
        this->historique.push_back(op);
        return true;
    }
}

bool Banque::Compte::verser(Devise* s, Compte& c)
{
    if (this->Debiter(s))
    {
        c.Crediter(s);
        return true;
    }
    return false;
}

void Banque::Compte::AfficherDetailsCompte() const
{
    cout << "Num Compte : " << this->numCompte;
    cout << " Solde : ";
    this->solde->AfficherSolde();
    cout << endl << "   Les Operations :    " << endl;
    for (int i = 0; i < this->historique.size(); i++)
    {
        this->historique[i]->AfficherOperation();
        cout << endl;
    }
}

Banque::Compte::~Compte()
{
    if (this->titulaire && this->ref && this->ref->decre() == 0)
    {
        delete this->titulaire;
        this->titulaire = 0;
    }
}

bool Banque::Compte::CheckSolde(Devise* m, Devise* dec) const
{
    if (*this->solde - *m > *dec) {
        return true;
    }
    return false;
}

Devise& Banque::Compte::Interet_A_ajouter(Devise* t) const
{
    return (*this->solde * *t);
}
