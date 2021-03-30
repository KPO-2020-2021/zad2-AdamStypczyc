#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"

using namespace std;




int main(int argc, char **argv)
{
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

  
  cout << endl;
  cout << "Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << "W razie ułamków zaokrąglaj wyniki do dwóch miejsc po przecinku." << endl;
  cout << endl;

  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona odpowiedz;       //odpowiedz użytkownika
  Statystyka statystyka;      //statystyka
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << "Oblicz wyrażenie: ";
    cout << WyrZ_PytanieTestowe<< endl;
    int i=0;                          //i potrzebne do pętli odpowiadającej za zliczanie prób poprawnego wczytania Lzespoleonej
    while(i < 3)                      //jeżeli użytkowanik poprawnie poda liczbę zespoloną to potem przerywamy pętlę
    {
      cout << "Twoja odpowiedź: ";
      cin >> odpowiedz;
      if(cin.good())
      {
        break;
      }
      else
      {
        cin.clear();                  //czyści flagę błędu
        cin.ignore(1024,'\n');        //czyści całą linię do napotkania znaku końca linii
        cout << "Zła forma liczby zespolonej" << endl;
        cout << endl;
        i++;                          //zwiększenie ilości zużytych prób
      }
    }
    statystyka.Odpowiedzi++;          //zwiększenie ilości wszystkich odpowiedzi
    if(odpowiedz==Oblicz(WyrZ_PytanieTestowe))
    {
      statystyka.Dobre++;             //w razie dobrej zwiększenie ilości dobrych odpowiedzi
      cout << "Gitara!!!"<<endl;
      cout << "Dobra odpowiedź!!!"<< endl;
      cout << endl;
    }
    else
    {
      statystyka.Zle++;               //w razie złej zwiększenie ilości złych odpowiedzi
      cout << ":("<<endl;
      cout <<"Zla odpowiedź"<< endl;
      cout <<"Poprawna odpowiedź to: "<< Oblicz(WyrZ_PytanieTestowe )<< endl;
      cout << endl;
    }
  }
  Procenty(statystyka);               //podsumowanie odpowiedzi

  
  cout << endl;
  cout << "Koniec testu" << endl;
  cout << endl;

}
