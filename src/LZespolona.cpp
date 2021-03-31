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
LZespolona LZespolona::operator + (LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = this->re + Skl2.re;
  Wynik.im = this->im + Skl2.im;
  return Wynik;
}
//odejmowanie zespolonych
LZespolona LZespolona::operator - (LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = this->re - Skl2.re;
  Wynik.im = this->im - Skl2.im;
  return Wynik;
}
//mnozenie zespolonych
LZespolona LZespolona::operator * (LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = this->re * Skl2.re - this->im * Skl2.im;
  Wynik.im = this->re * Skl2.im + this->im * Skl2.re;
  return Wynik;
}
//mnozenie zespolonej razy skalar
LZespolona LZespolona::operator * (double  Skl2)const
{
  LZespolona  Wynik;

  Wynik.re = this->re*Skl2;
  Wynik.im = this->im*Skl2;
  return Wynik;
}
//mnozenie zespolonej
LZespolona operator * (double  Skl2, const LZespolona Skl1)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re*Skl2;
  Wynik.im = Skl1.im*Skl2;
  return Wynik;
}
//dzielenie zespolonej przez skalar

LZespolona LZespolona::operator / (double  Skl2)
{
  LZespolona  Wynik;
  if(Skl2==0)
  {
    throw "Pamiętaj cholero nie dziel przez 0";
  }
  else
  {
    Wynik.re = this->re/Skl2;
    Wynik.im = this->im/Skl2;
    return Wynik;
  }
}
//dzielenie zespolonej
LZespolona LZespolona::operator / (LZespolona  Skl2)const
{
  LZespolona  Wynik;
  if(Skl2.Modul2()==0)
  {
    throw "Pamiętaj cholero nie dziel przez 0";
  }
  else
  {
    Wynik.re = (this->re*Skl2.re+this->im*Skl2.im)/Skl2.Modul2();
    Wynik.im = (this->im*Skl2.re-this->re*Skl2.im)/Skl2.Modul2();
    return Wynik;
  }
}
//dzielenie skalaru przez zespolona
LZespolona  operator / (double  Skl2, LZespolona  Skl1)
{
  LZespolona Licznik, Wynik;
  if(Skl1.Modul2()==0)
  {
    throw "Pamiętaj cholero nie dziel przez 0";
  }
  Licznik=Skl2*Skl1.Sprzezenie();
  Wynik=Licznik/Skl1.Modul2();
  return Wynik;

}

//sprzezenia
LZespolona LZespolona::Sprzezenie()
{
  LZespolona Wynik;
  Wynik.re = this->re;
  Wynik.im = -this->im;
  return Wynik;
}

//moduł
double LZespolona::Modul2()
{
  double Wynik;
  Wynik = this->re*this->re + this->im*this->im;
  return Wynik;
}



/**********************
 * funkcje wczytywania 
 * i wyświetlania liczby;
 * zespolonej, funkcje wykonane przed 
 * przeciążeniami bitowymi
***********************/

//funkcja wczytywania zespolonej
void LZespolona::Wyswietl()
{                                                             
  cout<<"("<<this->re<<showpos<<this->im<<noshowpos<<"i)";    
}
//wczytywanie zespolonej
void LZespolona::Wczytaj()
{
  char znak;
  cin>>znak;
  if(znak!='(')
  {
    cerr<<"Błąd zły znak, zacznij od (";
  }
  cin>>this->re;
  cin>>this->im;
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
bool LZespolona::operator == (const LZespolona  Skl2)const
{
  if(abs(this->re-Skl2.re)<=MIN_DIFF && abs(this->im-Skl2.im)<=MIN_DIFF)
  {
    return true;
  }
  else
  {
    return false;
  }
}
//operator negacji
bool LZespolona::operator != (const LZespolona  Skl2)const
{
  if(abs(this->re-Skl2.re)<=MIN_DIFF && abs(this->im-Skl2.im)<=MIN_DIFF)
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
LZespolona LZespolona::zaokraglij()
{
    this->re*=100;
    this->re=round(this->re);
    this->re/=100;
    this->im*=100;
    this->im=round(this->im);
    this->im/=100;
    return *this;
}
LZespolona LZespolona::operator +=(LZespolona const &Skl2)
{

  *this=*this+Skl2;
  return *this;
}
LZespolona LZespolona::operator /=(LZespolona &Skl2)
{
  double y;
  y=Skl2.Modul2();
  if(y==0)
  {
    throw"Pamiętaj cholero nie dziel przez 0";
  }
  else
  {
  *this=*this/Skl2;
  }
  return *this;
}
double LZespolona::arg()
{
  double radian, kat;
  if(this->re>0)
  {
    radian=atan2(this->im,this->re);
    kat=radian*180/PI;
  }
  else if(this->re<0)
  {
    radian=atan2(this->im,this->re)+PI;
    kat=radian*180/PI;
  }
  else
  {
    if(this->im>0)
    {
      radian=0.5*PI;
      kat=radian*180/PI;
    }
    else if(this->im<0)
    {
      radian=-0.5*PI;
      kat=radian*180/PI;
    }
    else
    {
      radian=0;
      kat=0;
    }
  }
  cout << "Argument liczby zespolonej wynosi: "<<endl;
  cout << "W radianach: "<<radian<<endl;
  cout << "W stopniach: "<<kat<<endl;
  cout << endl;
}
