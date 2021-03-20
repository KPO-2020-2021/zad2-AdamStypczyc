#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"

using namespace std;




int main(int argc, char **argv)
{
  /*******************************************************/
  LZespolona x,y,z, o1, o2, po1, po2;
  WyrazenieZesp aaa,odp1,odp2;
  Statystyka odpowiedzi;
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
  cin >> aaa;
  cout << aaa;
  cout << "\n***** ***\n";
  /*********************************************************/
  odp1.Arg1.re=1;
  odp1.Arg1.im=-2;
  odp1.Op=Op_Mnoz;
  odp1.Arg2.re=2;
  odp1.Arg2.im=3;
  po1.re=8;
  po1.im=-1;
  cout << "Oblicz: " << odp1 << "\n";
  cout << "Twoja odpowiedź to: ";
  cin >> o1;
  odpowiedzi.Odpowiedzi++;
  if(o1==po1)
  {
    cout << "Gitara!!!\nDobra odpowiedź!!!";
    odpowiedzi.Dobre++;
  }
  else
  {
    cout << "Źle!!!\nZła odpowiedź!!!\nPoprawna opowiedź to: "<< po1 << endl;
    odpowiedzi.Zle++;
  }
  odp2.Arg1.re=3;
  odp2.Arg1.im=4;
  odp2.Op=Op_Dodaj;
  odp2.Arg2.re=8;
  odp2.Arg2.im=7;
  po2.re=11;
  po2.im=11;
  cout << "Oblicz: " << odp2 << "\n";
  cout << "Twoja odpowiedź to: ";
  cin >> o2;
  odpowiedzi.Odpowiedzi++;
  if(o2==po2)
  {
    cout << "Gitara!!!\nDobra odpowiedź!!!";
    odpowiedzi.Dobre++;
  }
  else
  {
    cout << "Źle!!!\nZła odpowiedź!!!\nPoprawna opowiedź to: "<< po2 << endl;
    odpowiedzi.Zle++;
  }
  Procenty(odpowiedzi);
  cout << "\n***** ***\n";
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
