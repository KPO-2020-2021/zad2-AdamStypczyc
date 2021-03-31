#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

/**********************************
*Moje wcześniejsze wyświetlanie   *
*i wczytywanie,                   *
*nowe wyświetlanie i wczytywanie  *
*zostało przetestowane            *
*w pliku main                     *
***********************************

UPDATE
aktualnie testowane w test 1

void Wyswietl(WyrazenieZesp  WyrZ)
{
    Wyswietl(WyrZ.Arg1);
    switch (WyrZ.Op)
    {
        case Op_Dodaj:
        cout<<"+";
        break;
        case Op_Odejmij:
        cout<<"-";
        break;
        case Op_Mnoz:
        cout<<"*";
        break;
        case Op_Dziel:
        cout<<"/";
        break;
    }
    Wyswietl(WyrZ.Arg2);
}
void Wczytaj(WyrazenieZesp &WyrZ)
{
    char znak;
    Wczytaj(WyrZ.Arg1);
    cin>>znak;
    switch (znak)
    {
        case '+':
        WyrZ.Op=Op_Dodaj;
        break;
        case '-':
        WyrZ.Op=Op_Odejmij;
        break;
        case '*':
        WyrZ.Op=Op_Mnoz;
        break;
        case '/':
        WyrZ.Op=Op_Dziel;
        break;
    }
    Wczytaj(WyrZ.Arg2);
}*/
//wczytywanie i wyświetlanie zrobione analogicznie 
//do wczytywania i wyświetlania wyżej
//to niżej wykorzytuje przeciążenia
void WyrazenieZesp::Wyswietl()
{
    cout << this->Arg1; 
    switch (this->Op)
    {
        case Op_Dodaj:
        cout<<"+";
        break;
        case Op_Odejmij:
        cout<<"-";
        break;
        case Op_Mnoz:
        cout<<"*";
        break;
        case Op_Dziel:
        cout<<"/";
        break;
    }
    cout << this->Arg2;
}
LZespolona WyrazenieZesp::Oblicz()
//Oblicznie wyrażenia zespolonego i zaokrąglenie go do dwóch miejsc po przecinku
{
    LZespolona Wynik;
    switch (this->Op)
    {
        case Op_Dodaj:
        Wynik=this->Arg1+this->Arg2;
        break;
        case Op_Odejmij:
        Wynik=this->Arg1-this->Arg2;
        break;
        case Op_Mnoz:
        Wynik=this->Arg1*this->Arg2;
        break;
        case Op_Dziel:
        Wynik=this->Arg1/this->Arg2;
        break;
    }   
    Wynik.zaokraglij();
    return Wynik; 
}
void WyrazenieZesp::Wczytaj()
{
    char znak;
    cin >> this->Arg1;
    cin>>znak;
    switch (znak)
    {
        case '+':
        this->Op=Op_Dodaj;
        break;
        case '-':
        this->Op=Op_Odejmij;
        break;
        case '*':
        this->Op=Op_Mnoz;
        break;
        case '/':
        this->Op=Op_Dziel;
        break;
    }
    cin >> this->Arg2;
}
//Przeciążenia operatorów dla wyrażeń zespolonych wykonałem póżniej
//Głupio było usuwać to co jest wyżej, dlatego zostawiłem
//wątpię czy będę jeszcze używał

//przeciążenie dla cout
ostream &operator << (ostream &StrmWyj, WyrazenieZesp Skl1)
{
    StrmWyj << Skl1.Arg1; 
    switch (Skl1.Op)
    {
        case Op_Dodaj:
        StrmWyj<<"+";
        break;
        case Op_Odejmij:
        StrmWyj<<"-";
        break;
        case Op_Mnoz:
        StrmWyj<<"*";
        break;
        case Op_Dziel:
        StrmWyj<<"/";
        break;
    }
    StrmWyj << Skl1.Arg2;
    return StrmWyj;
}

//przeciążenie dla cin
istream &operator >> (istream &StrmWej, WyrazenieZesp &Skl1)
{
    char znak;
    StrmWej >> Skl1.Arg1;
    if (StrmWej.fail())
    {
        cerr << "Błąd!!!";
        return StrmWej;
    }
    StrmWej >> znak;
    if (StrmWej.fail())
    {
        cerr << "Błąd!!!";
        return StrmWej;
    }
    switch (znak)
    {
        case '+':
        Skl1.Op=Op_Dodaj;
        break;
        case '-':
        Skl1.Op=Op_Odejmij;
        break;
        case '*':
        Skl1.Op=Op_Mnoz;
        break;
        case '/':
        Skl1.Op=Op_Dziel;
        break;
    }
    StrmWej >> Skl1.Arg2;
    if (StrmWej.fail())
    {
        cerr << "Błąd!!!";
        return StrmWej;
    }
    return StrmWej;
}