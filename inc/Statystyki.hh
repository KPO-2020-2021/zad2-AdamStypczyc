#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH


#include <iostream>
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

/*
 * Tu nalezy zdefiniowac funkcje, ktore definiuja model statystyki 
 */
using namespace std;
/*************
 * struktura odpowiedzialna
 * za statystyke
 * **************/
struct Statystyka
{
    int Odpowiedzi=0;
    int Dobre=0;
    int Zle=0;
    void Procenty();
};
#endif //STATYSTYKI_HH
