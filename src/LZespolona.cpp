#include "LZespolona.hh"



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
//dodawanie zespolonych
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
//odejmowanie zespolonych
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}
//mnozenie zespolonych
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}
//mnozenie zespolonej razy skalar
LZespolona  operator * (LZespolona  Skl1,  double  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re*Skl2;
  Wynik.im = Skl1.im*Skl2;
  return Wynik;
}
//dzielenie zespolonej przez skalar

LZespolona  operator / (LZespolona  Skl1,  double  Skl2)
{
  LZespolona  Wynik;
  if(Skl2==0)
  {
    throw "Pamiętaj cholero nie dziel przez 0";
  }
  else
  {
    Wynik.re = Skl1.re/Skl2;
    Wynik.im = Skl1.im/Skl2;
    return Wynik;
  }
}
//dzielenie skalaru przez zespolona
LZespolona  operator / (double  Skl2, LZespolona  Skl1)
{
  LZespolona Licznik, Wynik;
  if(Modul2(Skl1)==0)
  {
    throw "Pamiętaj cholero nie dziel przez 0";
  }
  Licznik=Skl2*Sprzezenie(Skl1);
  Wynik=Licznik/Modul2(Skl1);
  return Wynik;

}
//mnozenie zespolonej
LZespolona  operator * (double  Skl2, LZespolona  Skl1)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re*Skl2;
  Wynik.im = Skl1.im*Skl2;
  return Wynik;
}
//sprzezenia
LZespolona Sprzezenie(LZespolona Skl1)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re;
  Wynik.im = -Skl1.im;
  return Wynik;
}

//moduł
double Modul2(LZespolona Skl1)
{
  double Wynik;
  Wynik = Skl1.re*Skl1.re + Skl1.im*Skl1.im;
  return Wynik;
}

//dzielenie zespolonej
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  if(Modul2(Skl2)==0)
  {
    throw "Pamiętaj cholero nie dziel przez 0";
  }
  else
  {
    Wynik = Skl1*Sprzezenie(Skl2)/Modul2(Skl2);
    return Wynik;
  }
}

/**********************
 * funkcje wczytywania 
 * i wyświetlania liczby;
 * zespolonej, funkcje wykonane przed 
 * przeciążeniami bitowymi
***********************/

//funkcja wczytywania zespolonej
void Wyswietl(LZespolona Skl1)
{                                                             
  cout<<"("<<Skl1.re<<showpos<<Skl1.im<<noshowpos<<"i)";    
}
//wczytywanie zespolonej
void Wczytaj(LZespolona &Skl1)
{
  char znak;
  cin>>znak;
  if(znak!='(')
  {
    cerr<<"Błąd zły znak, zacznij od (";
  }
  cin>>Skl1.re;
  cin>>Skl1.im;
  cin>>znak;
  if(znak!='i')
  {
    cerr<<"Błąd zły znak, po części urojonej jest i";
  }
  cin>>znak;
  if(znak!=')')
  {
    cerr<<"Błąd zły znak, skończ znakiem )";
  }
}
//operator porównania
bool operator == (LZespolona  Skl1,  LZespolona  Skl2)
{
  if(abs(Skl1.re-Skl2.re)<=MIN_DIFF && abs(Skl1.im-Skl2.im)<=MIN_DIFF)
  {
    return true;
  }
  else
  {
    return false;
  }
}
//operator negacji
bool operator != (LZespolona  Skl1,  LZespolona  Skl2)
{
  if(abs(Skl1.re-Skl2.re)<=MIN_DIFF && abs(Skl1.im-Skl2.im)<=MIN_DIFF)
  {
    return false;
  }
  else
  {
    return true;
  }
}
/*************************
 * przy przeciążeniu bitowym
 * wzorowałem się na przeciążeniu pokazanym w trakcie 
 * godzin projektowych
 * */

/**********************
 * przeciążenie operatora bitowego
 * dla cout
***********************/
ostream &operator << (ostream &StrmWyj, LZespolona Skl1)
{
  StrmWyj << "(" << Skl1.re << showpos << Skl1.im << noshowpos << "i)";
  return StrmWyj;
}

/**********************
 * przeciążenie operatora bitowego
 * dla cin
***********************/

istream &operator >> (istream &StrmWej, LZespolona &Skl1)
{
    char Nawias, Litera;
    StrmWej >> Nawias;
    if(StrmWej.fail())
    {
      cerr << "Błąd!!!";
      return StrmWej;
    }
    if( Nawias != '(')
    {
      StrmWej.setstate(ios::failbit);
      return StrmWej;
    }
    StrmWej >> Skl1.re;
    if(StrmWej.fail())
    {
      cerr << "Błąd!!!";
      return StrmWej;
    }
    StrmWej >> Skl1.im;
    if(StrmWej.fail())
    {
      cerr << "Błąd!!!";
      return StrmWej;
    }
    StrmWej >> Litera;
    if(StrmWej.fail())
    {
      cerr << "Błąd!!!";
      return StrmWej;
    }
    if( Litera != 'i')
    {
      StrmWej.setstate(ios::failbit);
      return StrmWej;
    } 
    StrmWej >> Nawias;
    if(StrmWej.fail())
    {
      cerr << "Błąd!!!";
      return StrmWej;
    }
    if( Nawias != ')')
    {
      StrmWej.setstate(ios::failbit);
      return StrmWej;
    } 
    return StrmWej;      
}
/**********************
 * zaokrąglanie do
 * dwóch miejsc po 
 * przecinku
***********************/
LZespolona zaokraglij(LZespolona &x)
{
    x.re*=100;
    x.re=round(x.re);
    x.re/=100;
    x.im*=100;
    x.im=round(x.im);
    x.im/=100;
    return x;
}
