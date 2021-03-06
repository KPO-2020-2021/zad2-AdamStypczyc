#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 2") {
    LZespolona x, y;
    double t = 3;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.666666666666666667;
    y.im = 0.666666666666666667;
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}
TEST_CASE("Test LZespolona mnożenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 4;
    y.im = 4;
   
    CHECK(x*t == y);
}
TEST_CASE("Test LZespolona mnożenie przez skalar 2") {
    LZespolona x, y;
    double t = 7;
    
    x.re = 3;
    x.im = 2;

    y.re = 21;
    y.im = 14;
   
    CHECK(x*t == y);
}
TEST_CASE("Test LZespolona mnożenie przez skalar 3") {
    LZespolona x, y;
    double t = 0;
    
    x.re = 3;
    x.im = 2;

    y.re = 0;
    y.im = 0;
   
    CHECK(x*t == y);
}

TEST_CASE("Test LZespolona mnożenie przez skalar 4") {
    LZespolona x, y;
    double t = 0;
    
    x.re = 3;
    x.im = 2;

    y.re = 0;
    y.im = 0;
   
    CHECK(t*x == y);//mnożenie w innej kolejności niż wcześniej
}

TEST_CASE("Test LZespolona mnożenie zespolonych 1") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 3;
    y.im = 3;
   
    z.re =0;
    z.im =12;

    CHECK(x*y == z);
}
TEST_CASE("Test LZespolona mnożenie zespolonych 2") {
    LZespolona x, y, z;
    
    x.re = 3;
    x.im = 3;

    y.re = 3;
    y.im = 3;
   
    z.re =0;
    z.im =18;

    CHECK(x*y == z);
}
TEST_CASE("Test LZespolona mnożenie zespolonych 3") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 0;
   
    z.re =0;
    z.im =0;

    CHECK(x*y == z);
}
TEST_CASE("Test LZespolona mnożenie zespolonych 4") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.0;
    y.im = 0.0;
   
    z.re =0;
    z.im =0;

    CHECK(x*y == z);
}
TEST_CASE("Test LZespolona mnożenie zespolonych 5") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.00001;
    y.im = 0.00001;
   
    z.re =0;
    z.im =0;

    CHECK(x*y == z);
}
TEST_CASE("Test LZespolona mnożenie zespolonych 6") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 0;
   
    z.re =2;
    z.im =2;

    CHECK(x*y == z);
}
TEST_CASE("Test LZespolona mnożenie zespolonych 7") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 1;
   
    z.re =-2;
    z.im =2;

    CHECK(x*y == z);
}
TEST_CASE("Test LZespolona mnożenie zespolonych 8") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    z.re =0;
    z.im =4;

    CHECK(x*y == z);
}

TEST_CASE("Test Skalar przez zespolona 1") {
    double x;
    LZespolona y,z;
    
    x = 8;

    y.re = 4;
    y.im = -4;
   
    z.re =1;
    z.im =1;

    CHECK(x/y == z);
}

TEST_CASE("Test LZespolona dzielenie zespolonych 1") {
    LZespolona x, y, z;
    
    x.re = 8;
    x.im = 8;

    y.re = 4;
    y.im = -4;
   
    z.re =0;
    z.im =2;

    CHECK(x/y == z);
}

TEST_CASE("Test LZespolona dzielenie zespolonych 2") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 4;
    y.im = 4;
   
    z.re =0.5;
    z.im =0;

    CHECK(x/y == z);
}
TEST_CASE("Test LZespolona dzielenie zespolonych 3") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 0;

    WARN_THROWS(x/y);
}
TEST_CASE("Test Sprzerzenie 1") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 2;
    y.im = -2;
    z=x.Sprzezenie();
    CHECK(z==y);
}
TEST_CASE("Test Sprzerzenie 2") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 0;

    y.re = 2;
    y.im = 0;
    z=x.Sprzezenie();
    CHECK(z==y);
}
TEST_CASE("Test Modul2 1") {
    LZespolona x;
    double y,z;
    x.re = 2;
    x.im = 2;
    z=8;
    y=x.Modul2();
    CHECK(y==z);
}
TEST_CASE("test /= 1"){
    LZespolona x,y,z;
    x.re=2;
    x.im=2;
    y.re=4;
    y.im=4;
    z.re=0.5;
    z.im=0;
    x/=y;

    CHECK(x==z);
}
TEST_CASE("test /= 2"){
    LZespolona x,y,z;
    x.re=8;
    x.im=8;
    y.re=4;
    y.im=-4;
    z.re=0;
    z.im=2;
    x/=y;

    CHECK(x==z);
}
TEST_CASE("test /= 3"){
    LZespolona x,y,z;
    x.re=0;
    x.im=9;
    y.re=6;
    y.im=6;
    z.re=0.75;
    z.im=0.75;
    x/=y;

    CHECK(x==z);
}
TEST_CASE("test /= 4"){
    LZespolona x,y,z;
    x.re=5;
    x.im=10;
    y.re=10;
    y.im=5;
    z.re=0.8;
    z.im=0.6;
    x/=y;

    CHECK(x==z);
}
TEST_CASE("test /= przez 0"){
    LZespolona x,y;
    x.re=2;
    x.im=2;
    y.re=0;
    y.im=0;

    WARN_THROWS(x/y);
}
