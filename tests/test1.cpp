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