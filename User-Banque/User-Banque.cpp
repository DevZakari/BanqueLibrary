// User-Banque.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Client.h"
#include "Compte.h"
#include "CompteCourant.h"
#include "CompteEpargne.h"
#include "ComptePayant.h"
#include "Devise.h"
#include "Euros.h"
#include "MAD.h"
#include "Dollars.h"
using namespace Banque;
using namespace std;


int main()
{
    Client* cli1 = new Client("Machtor", "Zakaria", "Hay El Amal");
    Devise* scli1 = new MAD(20000);
    Devise* scli_p = new MAD(20000);
    Devise* dec = new MAD(200);

    Devise* s1 = new MAD(400);
    Devise* s2 = new MAD(1200);
    Devise* s3 = new MAD(0);


    Compte* cmp1 = new CompteCourant(cli1, scli1,'M',dec);
    Compte* cmpp = new ComptePayant(cli1, scli_p,'M');
    CompteEpargne* cmpE = new CompteEpargne(cli1, s3, 'M',5);

    cli1->AjouterCompte(cmp1);
    cli1->AjouterCompte(cmpp);
    cli1->AjouterCompte(cmpE);

    cmp1->Crediter(s1);
    cmpp->Debiter(s2);
    cmp1->verser(s2, *cmpE);
    cli1->AfficherDetailsClient();

   
    system("pause>0");
}

