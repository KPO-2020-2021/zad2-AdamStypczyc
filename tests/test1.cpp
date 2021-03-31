#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test LZespolona Suma 1"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x+y == z);
}
TEST_CASE("test LZespolona Suma 2"){
    LZespolona x, y, z;

    x.re = 6;
    x.im = 6;

    y.re = 2;
    y.im = -3;

    z.re = 8;
    z.im = 3;
    
    CHECK(x+y == z);
}
TEST_CASE("test LZespolona Suma 3"){
    LZespolona x, y, z;

    x.re = 6;
    x.im = 6;

    y.re = 0;
    y.im = 0;

    z.re = 6;
    z.im = 6;
    
    CHECK(x+y == z);
}
TEST_CASE("test LZespolona Suma 4"){
    LZespolona x, y, z;

    x.re = 6;
    x.im = 6;

    y.re = 0.0;
    y.im = 0.0;

    z.re = 6;
    z.im = 6;
    
    CHECK(x+y == z);
}
TEST_CASE("test LZespolona Suma 5"){
    LZespolona x, y, z;

    x.re = 6;
    x.im = 6;

    y.re = 0.0001;
    y.im = 0.0001;

    z.re = 6;
    z.im = 6;
    
    CHECK(x+y == z);
}
TEST_CASE("test LZespolona Suma 6"){
    LZespolona x, y, z;

    x.re = 6;
    x.im = 6;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 6;
    z.im = 6;
    
    CHECK(x+y == z);
}
TEST_CASE("test LZespolona Suma 7"){
    LZespolona x, y, z;

    x.re = 6;
    x.im = 6;

    y.re = 0.00009;
    y.im = 0.00009;

    z.re = 6;
    z.im = 6;
    
    CHECK(x+y == z);
}
TEST_CASE("test LZespolona Suma 8"){
    LZespolona x, y, z;

    x.re = 6;
    x.im = 6;

    y.re = 0.001;
    y.im = 0.001;

    z.re = 6;
    z.im = 6;
    
    CHECK(x+y != z);
}
TEST_CASE("test LZespolona Różnica 1"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 0;
    z.im = 4;
    
    CHECK(x-y == z);
}
TEST_CASE("test LZespolona Różnica 2"){
    LZespolona x, y, z;

    x.re = 5;
    x.im = 6;

    y.re = 2;
    y.im = 3;

    z.re = 3;
    z.im = 3;
    
    CHECK(x-y == z);
}
TEST_CASE("test LZespolona Różnica 3"){
    LZespolona x, y, z;

    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 0;

    z.re = 2;
    z.im = 2;
    
    CHECK(x-y == z);
}
TEST_CASE("test LZespolona Różnica 4"){
    LZespolona x, y, z;

    x.re = 2;
    x.im = 2;

    y.re = 0.0;
    y.im = 0.0;

    z.re = 2;
    z.im = 2;
    
    CHECK(x-y == z);
}
TEST_CASE("test LZespolona Różnica 5"){
    LZespolona x, y, z;

    x.re = 2;
    x.im = 2;

    y.re = 0.0001;
    y.im = 0.0001;

    z.re = 2;
    z.im = 2;
    
    CHECK(x-y == z);
}
TEST_CASE("test LZespolona Różnica 6"){
    LZespolona x, y, z;

    x.re = 2;
    x.im = 2;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 2;
    z.im = 2;
    
    CHECK(x-y == z);
}
TEST_CASE("test LZespolona Różnica 7"){
    LZespolona x, y, z;

    x.re = 2;
    x.im = 2;

    y.re = 0.00009;
    y.im = 0.00009;

    z.re = 2;
    z.im = 2;
    
    CHECK(x-y == z);
}
TEST_CASE("test wyświetlanie standard"){
    LZespolona x;

    x.re = 2.00;
    x.im = 2.00;
    ostringstream out;
    out << x;
    cout << out.str() << endl;
    CHECK("(2+2i)" == out.str());
}
TEST_CASE("test wyświetlanie zaokrąglanie"){
    LZespolona x;

    x.re = 2.0/3.0;
    x.im = 2.0/3.0;
    x.zaokraglij();
    ostringstream out;
    out << x;
    cout << out.str() << endl;
    CHECK("(0.67+0.67i)" == out.str());
}
TEST_CASE("test wczytywanie standard"){
    LZespolona x;

    istringstream in("(10+10.101i)");
    in >> x;
    ostringstream out;
    out << x;
    
    CHECK("(10+10.101i)"== out.str());
}
TEST_CASE("test += 1"){
    LZespolona x,y,z;
    x.re=1;
    x.im=1;
    y.re=2;
    y.im=2;
    z.re=3;
    z.im=3;
    x+=y;
    CHECK(x==z);
}
TEST_CASE("test += 2"){
    LZespolona x,y,z;
    x.re=2;
    x.im=12;
    y.re=23;
    y.im=-21;
    z.re=25;
    z.im=-9;
    x+=y;
    CHECK(x==z);
}
TEST_CASE("test += 3"){
    LZespolona x,y,z;
    x.re=4;
    x.im=8;
    y.re=8;
    y.im=-12;
    z.re=12;
    z.im=-4;
    x+=y;
    CHECK(x==z);
}
TEST_CASE("test += 4"){
    LZespolona x,y,z;
    x.re=10;
    x.im=54;
    y.re=11;
    y.im=-17;
    z.re=21;
    z.im=37;
    x+=y;
    CHECK(x==z);
}

TEST_CASE("test argument"){
    LZespolona x,y,z,a,b;
    x.re=5;
    x.im=2;

    y.re=0;
    y.im=0;
    
    z.re=1;
    z.im=1;
    
    a.re=0;
    a.im=-67;
    
    b.re=8;
    b.im=-6;
    
    x.arg();
    y.arg();
    z.arg();
    a.arg();
    b.arg();
}
