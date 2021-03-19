#include "LZespolona.hh"



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  double  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re*Skl2;
  Wynik.im = Skl1.im*Skl2;
  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  double  Skl2)
{
  LZespolona  Wynik;
  if(Skl2==0)
  {
    cerr<<"Pamiętaj cholero nie dziel przez 0"<<endl;
  }
  else
  {
    Wynik.re = Skl1.re/Skl2;
    Wynik.im = Skl1.im/Skl2;
    return Wynik;
  }
}

LZespolona Sprzezenie(LZespolona Skl1)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re;
  Wynik.im = -Skl1.im;
  return Wynik;
}

double Modul2(LZespolona Skl1)
{
  double Wynik;
  Wynik = Skl1.re*Skl1.re + Skl1.im*Skl1.im;
  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  if(Modul2(Skl2)==0)
  {
    cerr<<"Pamiętaj cholero nie dziel przez 0"<<endl;
  }
  else
  {
    Wynik = Skl1*Sprzezenie(Skl2)/Modul2(Skl2);
    return Wynik;
  }
}

void Wyswietl(LZespolona Skl1)
{                                                             //wykorzystanie showpos mówiącego nam o znaku liczby, 
  cout<<"("<<Skl1.re<<showpos<<Skl1.im<<noshowpos<<"i)";      //ale trzeba go zamknąć bo działa globalnie, nie dajemy znaku końca linii bo będziemy pisać całe wyrażenia 
}

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

ostream &operator << (ostream &StrmWyj, LZespolona Skl1)
{
  StrmWyj << "(" << Skl1.re << showpos << Skl1.im << noshowpos << "i)";
  return StrmWyj;
}

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
