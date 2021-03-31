#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
#include <cmath>
using namespace std;
#define MIN_DIFF 0.0001
#define PI 3.14159265359

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  LZespolona  operator + (LZespolona  Skl2);
  LZespolona  operator - (LZespolona  Skl2);
  LZespolona  operator * (LZespolona  Skl2);
  LZespolona  operator * (double  Skl2)const;
  LZespolona  operator / (LZespolona  Skl2)const;
  LZespolona  operator / (double  Skl2);
  bool operator == (const LZespolona  Skl2)const;
  bool operator != (const LZespolona  Skl2)const;
  LZespolona zaokraglij();
  LZespolona Sprzezenie();
  double Modul2();
  void Wyswietl();
  void Wczytaj();
  double arg();
  LZespolona operator +=(LZespolona const &Skl2);
  LZespolona operator /=(LZespolona &Skl2);
};

//te przeciążenia zostały jako funkcje, bo inaczej nie działało
//a przynajmniej ja nie wiedizałem jak je zrobić ta żeby działały
//na slajdach z wykładu też nie znalazłem
 
LZespolona operator * (double  Skl2, const LZespolona Skl1);      
LZespolona operator / (double  Skl2, LZespolona  Skl1);       

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


// LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
// LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
// LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
// LZespolona  operator * (LZespolona  Skl1,  double  Skl2);
// LZespolona  operator * (double  Skl2, LZespolona  Skl1);
// LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
// LZespolona  operator / (LZespolona  Skl1,  double  Skl2);
// LZespolona  operator / (double  Skl2, LZespolona  Skl1);
// bool operator == (LZespolona  Skl1,  LZespolona  Skl2);
// bool operator != (LZespolona  Skl1,  LZespolona  Skl2);
ostream &operator << (ostream &StrmWyj, LZespolona Skl1);
istream &operator >> (istream &StrmWej, LZespolona &Skl1);
// LZespolona zaokraglij(LZespolona &x);
// LZespolona Sprzezenie(LZespolona Skl1);
// double Modul2(LZespolona Skl1);

// void Wyswietl(LZespolona Skl1);

// void Wczytaj(LZespolona &Skl1);

#endif