#include <iostream>
#include "BazaTestu.hh"

using namespace std;




int main(int argc, char **argv)
{
  /*******************************************************/
  LZespolona x,y,z;
  WyrazenieZesp aaa;
  x.re=1;
  x.im=1;
  cout << x <<"\n";
  y.re=1;
  y.im=1;
  aaa.Arg1=x;
  aaa.Arg2=y;
  aaa.Op=Op_Dodaj;
  z=Oblicz(aaa);
  cout << z<<"\n";//Wynik po dodawaniu liczb zespolonych i wyświetlanie liczby zespolonej
  Wyswietl(aaa);
  cout << "\n***** ***\n";
  /*******************************************************/
  aaa.Op=Op_Odejmij;
  z=Oblicz(aaa);
  cout << z<<"\n";//Wynik po odejmowaniu liczb zespolonych i wyświetlanie liczby zespolonej
  Wyswietl(aaa);
  cout << "\n***** ***\n";
  /*******************************************************/
  aaa.Op=Op_Mnoz;
  y.re=3;
  y.im=3;
  z=Oblicz(aaa);
  cout << z<<"\n";//Wynik po mnozeniu liczb zespolonych i wyświetlanie liczby zespolonej
  Wyswietl(aaa);
  cout << "\n***** ***\n";
  /*******************************************************/
  aaa.Op=Op_Dziel;
  x.re=3;
  x.im=3;
  z=Oblicz(aaa);
  cout << z<<"\n";//Wynik po dzieleniu liczb zespolonych i wyświetlanie liczby zespolonej
  Wyswietl(aaa);
  cout << "\n***** ***\n";
  /*******************************************************/
  cin >> x;//test wczytywania zespolonej
  cout << x<<"\n***** ***\n";
  /*******************************************************/
  Wczytaj(aaa);//test wczytywania wyrażenia
  Wyswietl(aaa);
  cout << "\n***** ***\n";
  /*********************************************************/
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
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " Czesc rzeczywista pierwszego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg1.re << endl;
  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
