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
*/
/*void Wyswietl(WyrazenieZesp  WyrZ)
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
void Wyswietl(WyrazenieZesp  WyrZ)
{
    cout << WyrZ.Arg1; 
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
    cout << WyrZ.Arg2;
}
LZespolona Oblicz(WyrazenieZesp  WyrZ)
//Oblicznie wyrażenia zespolonego
{
    LZespolona Wynik;
    switch (WyrZ.Op)
    {
        case Op_Dodaj:
        Wynik=WyrZ.Arg1+WyrZ.Arg2;
        break;
        case Op_Odejmij:
        Wynik=WyrZ.Arg1-WyrZ.Arg2;
        break;
        case Op_Mnoz:
        Wynik=WyrZ.Arg1*WyrZ.Arg2;
        break;
        case Op_Dziel:
        Wynik=WyrZ.Arg1/WyrZ.Arg2;
        break;
    }   
    return Wynik; 
}
void Wczytaj(WyrazenieZesp &WyrZ)
{
    char znak;
    cin >> WyrZ.Arg1;
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
    cin >> WyrZ.Arg2;
}