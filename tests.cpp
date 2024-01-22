#define CATCH_CONFIG_MAIN   
#include "catch.hpp"
#include "Untitled-1.cpp"


TEST_CASE("Can be constructed", "[Complex]") {
    Complex<double> c1;
    REQUIRE(c1.getReal() == 0);
    REQUIRE(c1.getImag() == 0);

    Complex<double> c2(5);
    REQUIRE(c2.getReal() == 5);
    REQUIRE(c2.getImag() == 0);

    Complex<double> c3(2, 1);
    REQUIRE(c3.getReal() == 2);
    REQUIRE(c3.getImag() == 1);

    Complex<double> c4(c3);
    REQUIRE(c4.getReal() == 2);
    REQUIRE(c4.getImag() == 1);
}

TEST_CASE("Can be copped", "[Complex]") {
    Complex<double> c1;

    Complex<double> c2 = c1;

    REQUIRE(c2.getReal() == c1.getReal());
    REQUIRE(c2.getImag() == c1.getImag());
}

TEST_CASE("Can be changed", "[Complex]") {
    Complex<double> c1;

    c1.setReal(5);
    c1.setImag(2);

    REQUIRE(c1.getReal() == 5);
    REQUIRE(c1.getImag() == 2);
}

TEST_CASE("Conj can be getted", "[Complex]") {
    Complex<double> c1(3, 8);

    Complex<double> c2 = c1.conj();

    REQUIRE(c2.getReal() == c1.getReal());
    REQUIRE(c2.getImag() == -c1.getImag());
}

TEST_CASE("Can sum complex numbers", "[Complex]") {
    Complex<double> c1(3, 8), c2(3, 4);

    Complex<double> c3 = (c1 + c2);

    REQUIRE(c3.getReal() == c1.getReal()+c2.getReal());
    REQUIRE(c3.getImag() == c1.getImag()+c2.getImag());

    Complex<double> c4(-3, -15);

    Complex<double> c5 = (c4 + c1);

    REQUIRE(c5.getReal() == c1.getReal()+c4.getReal());
    REQUIRE(c5.getImag() == c1.getImag()+c4.getImag());
}

TEST_CASE("Can sum complex numbers and num", "[Complex]") {
    double add_d = 3;
    int add_i = 3;
    float add_f = 3;
    Complex<double> c1(3, 8);

    Complex<double> c2 = c1 + add_d;

    REQUIRE(c2.getReal() == c1.getReal()+add_d);
    REQUIRE(c2.getImag() == c1.getImag());

    Complex<double> c3 = add_d + c1;

    REQUIRE(c3.getReal() == c1.getReal()+add_d);
    REQUIRE(c3.getImag() == c1.getImag());

    c2 = c1 + add_i;

    REQUIRE(c2.getReal() == c1.getReal()+add_d);
    REQUIRE(c2.getImag() == c1.getImag());

    c3 = add_i + c1;

    REQUIRE(c3.getReal() == c1.getReal()+add_d);
    REQUIRE(c3.getImag() == c1.getImag());

    c2 = c1 + add_f;

    REQUIRE(c2.getReal() == c1.getReal()+add_d);
    REQUIRE(c2.getImag() == c1.getImag());

    c3 = add_f + c1;

    REQUIRE(c3.getReal() == c1.getReal()+add_d);
    REQUIRE(c3.getImag() == c1.getImag());
}

TEST_CASE("ComplexNum can be +=", "[Complex]") {
    Complex<double> c1(3, 8), c2(3, 4);

    c1 += c2;

    REQUIRE(c1.getReal() == 6);
    REQUIRE(c1.getImag() == 12);
}

TEST_CASE("ComplexNum and num can be +=", "[Complex]") {
    double add_d = 3;
    int add_i = 3;
    float add_f = 3;
    Complex<double> c1(3, 8);

    c1 += add_d;

    REQUIRE(c1.getReal() == 6);
    REQUIRE(c1.getImag() == 8);

    c1.setReal(3);
    c1 += add_i;

    REQUIRE(c1.getReal() == 6);
    REQUIRE(c1.getImag() == 8);

    c1.setReal(3);
    c1 += add_f;

    REQUIRE(c1.getReal() == 6);
    REQUIRE(c1.getImag() == 8);
}

TEST_CASE("Apply unary minus", "[Complex]") {
    Complex<double> c1(3, 8);

    Complex<double> c2 = -c1;

    REQUIRE(c2.getReal() == -c1.getReal());
    REQUIRE(c2.getImag() == -c1.getImag());
}

TEST_CASE("Can sub complex numbers", "[Complex]") {
    Complex<double> c1(3, 8), c2(3, 4);

    Complex<double> c3 = (c1 - c2);

    REQUIRE(c3.getReal() == c1.getReal()-c2.getReal());
    REQUIRE(c3.getImag() == c1.getImag()-c2.getImag());

    Complex<double> c4(-3, -15);

    Complex<double> c5 = (c4 - c1);

    REQUIRE(c5.getReal() == c4.getReal()-c1.getReal());
    REQUIRE(c5.getImag() == c4.getImag()-c1.getImag());
}

TEST_CASE("Can sub complex numbers and num", "[Complex]") {
    double add_d = 3;
    int add_i = 3;
    float add_f = 3;
    Complex<double> c1(3, 8);

    Complex<double> c2 = c1 - add_d;

    REQUIRE(c2.getReal() == c1.getReal()-add_d);
    REQUIRE(c2.getImag() == c1.getImag());

    Complex<double> c3 = add_d - c1;

    REQUIRE(c3.getReal() == c1.getReal()-add_d);
    REQUIRE(c3.getImag() == -c1.getImag());

    c2 = c1 - add_i;

    REQUIRE(c2.getReal() == c1.getReal()-add_d);
    REQUIRE(c2.getImag() == c1.getImag());

    c3 = add_i - c1;

    REQUIRE(c3.getReal() == c1.getReal()-add_d);
    REQUIRE(c3.getImag() == -c1.getImag());

    c2 = c1 - add_f;

    REQUIRE(c2.getReal() == c1.getReal()-add_d);
    REQUIRE(c2.getImag() == c1.getImag());

    c3 = add_f - c1;

    REQUIRE(c3.getReal() == c1.getReal()-add_d);
    REQUIRE(c3.getImag() == -c1.getImag());
}

TEST_CASE("ComplexNum can be -=", "[Complex]") {
    Complex<double> c1(3, 8), c2(3, 4);

    c1 -= c2;

    REQUIRE(c1.getReal() == 0);
    REQUIRE(c1.getImag() == 4);
}

TEST_CASE("ComplexNum and num can be -=", "[Complex]") {
    double add_d = 3;
    int add_i = 3;
    float add_f = 3;
    Complex<double> c1(3, 8);

    c1 -= add_d;

    REQUIRE(c1.getReal() == 0);
    REQUIRE(c1.getImag() == 8);

    c1.setReal(3);
    c1 -= add_i;

    REQUIRE(c1.getReal() == 0);
    REQUIRE(c1.getImag() == 8);

    c1.setReal(3);
    c1 -= add_f;

    REQUIRE(c1.getReal() == 0);
    REQUIRE(c1.getImag() == 8);
}

//------multiplication----------

TEST_CASE("Can mul complex numbers", "[Complex]") {
    Complex<double> c1(3, 8), c2(3, 4);

    Complex<double> c3 = (c1 * c2);

    REQUIRE(c3.getReal() == -23);
    REQUIRE(c3.getImag() == 36);
}

TEST_CASE("Can mul complex numbers and num", "[Complex]") {
    double add_d = 3;
    int add_i = 3;
    float add_f = 3;
    Complex<double> c1(3, 8);

    Complex<double> c2 = c1 * add_d;

    REQUIRE(c2.getReal() == 9);
    REQUIRE(c2.getImag() == 24);

    Complex<double> c3 = add_d * c1;

    REQUIRE(c3.getReal() == 9);
    REQUIRE(c3.getImag() == 24);

    c2 = c1 * add_i;

    REQUIRE(c2.getReal() == 9);
    REQUIRE(c2.getImag() == 24);

    c3 = add_i * c1;

    REQUIRE(c3.getReal() == 9);
    REQUIRE(c3.getImag() == 24);

    c2 = c1 * add_f;

    REQUIRE(c2.getReal() == 9);
    REQUIRE(c2.getImag() == 24);

    c3 = add_f * c1;

    REQUIRE(c3.getReal() == 9);
    REQUIRE(c3.getImag() == 24);
}

TEST_CASE("ComplexNum can be *=", "[Complex]") {
    Complex<double> c1(1, -3), c2(-3, 2);

    c1 *= c2;

    REQUIRE(c1.getReal() == 3);
    REQUIRE(c1.getImag() == 11);
}

TEST_CASE("ComplexNum and num can be *=", "[Complex]") {
    double add_d = 3;
    int add_i = 3;
    float add_f = 3;
    Complex<double> c1(1, -2);

    c1 *= add_d;

    REQUIRE(c1.getReal() == 3);
    REQUIRE(c1.getImag() == -6);

    c1.setReal(1);
    c1.setImag(-2);

    c1 *= add_i;

    REQUIRE(c1.getReal() == 3);
    REQUIRE(c1.getImag() == -6);

    c1.setReal(1);
    c1.setImag(-2);

    c1 *= add_f;

    REQUIRE(c1.getReal() == 3);
    REQUIRE(c1.getImag() == -6);
}

//----------division------------

TEST_CASE("Can div complex numbers", "[Complex]") {
    Complex<double> c1(3, 8), c2(3, 4);

    Complex<double> c3 = (c1 / c2);

    REQUIRE(c3.getReal() == 1.64);
    REQUIRE(c3.getImag() == 0.48);
}

TEST_CASE("Can div complex numbers and num", "[Complex]") {
    double add_d = 4;
    int add_i = 4;
    float add_f = 4;
    Complex<double> c1(7, 1);

    Complex<double> c2 = c1 / add_d;

    REQUIRE(c2.getReal() == 1.75);
    REQUIRE(c2.getImag() == 0.25);

    Complex<double> c3 = add_d / c1;

    REQUIRE(c3.getReal() == 0.56);
    REQUIRE(c3.getImag() == -0.08);

    c2 = c1 / add_i;

    REQUIRE(c2.getReal() == 1.75);
    REQUIRE(c2.getImag() == 0.25);

    c3 = add_i / c1;

    REQUIRE(c3.getReal() == 0.56);
    REQUIRE(c3.getImag() == -0.08);

    c2 = c1 / add_f;

    REQUIRE(c2.getReal() == 1.75);
    REQUIRE(c2.getImag() == 0.25);

    c3 = add_f / c1;

    REQUIRE(c3.getReal() == 0.56);
    REQUIRE(c3.getImag() == -0.08);
}

TEST_CASE("ComplexNum can be /=", "[Complex]") {
    Complex<double> c1(1, -3), c2(-3, 4);

    c1 /= c2;

    REQUIRE(c1.getReal() == -0.6);
    REQUIRE(c1.getImag() == 0.2);
}

TEST_CASE("ComplexNum and num can be /=", "[Complex]") {
    double add_d = 4;
    int add_i = 4;
    float add_f = 4;
    Complex<double> c1(1, -2);

    c1 /= add_d;

    REQUIRE(c1.getReal() == 0.25);
    REQUIRE(c1.getImag() == -0.5);


    c1.setReal(1);
    c1.setImag(-2);

    c1 /= add_i;

    REQUIRE(c1.getReal() == 0.25);
    REQUIRE(c1.getImag() == -0.5);


    c1.setReal(1);
    c1.setImag(-2);

    c1 /= add_f;

    REQUIRE(c1.getReal() == 0.25);
    REQUIRE(c1.getImag() == -0.5);
}

TEST_CASE("Calculates abs", "[Complex]") {
    Complex<double> c1(4, -3), c2;

    double absc1 = c1.abs();

    REQUIRE(absc1 == 5);


    double absc2 = c2.abs();

    REQUIRE(absc2 == 0);
}

TEST_CASE("Calculates arg", "[Complex]") {
    Complex<double> c1(1, 1), c2;

    double todeg = 180/3.14159265359;

    double argc1 = c1.arg()*todeg;

    REQUIRE((argc1 - 45) < 0.0000001);

    
    c1.setImag(-1);

    argc1 = c1.arg()*todeg;

    REQUIRE((argc1 + 45) < 0.000001);


    c1.setReal(-1);
    c1.setImag(-1);

    argc1 = c1.arg()*todeg;

    REQUIRE((argc1 + 135) < 0.000001);


    c1.setReal(-1);
    c1.setImag(1);

    argc1 = c1.arg()*todeg;

    REQUIRE((argc1 - 135) < 0.0000001);

    // На оси oI
    c1.setReal(0);

    argc1 = c1.arg()*todeg;

    REQUIRE(argc1 == 90);


    c1.setImag(-1);

    argc1 = c1.arg()*todeg;

    REQUIRE(argc1 == -90);

    // На оси oR

    c1.setReal(1);
    c1.setImag(0);

    argc1 = c1.arg()*todeg;

    REQUIRE(argc1 == 0);


    c1.setReal(-1);

    argc1 = c1.arg()*todeg;

    REQUIRE(argc1 == 180);

    // (0,0)
    c1.setReal(0);

    argc1 = c1.arg();

    REQUIRE(argc1 == -1000);
}

TEST_CASE("Calculates pow", "[Complex]") {
    Complex<double> c1(4.1, -1);

    Complex<double> c2 = c1.pow(3);

    REQUIRE(abs(c2.getReal() - 56.621) < 0.00000001);
    REQUIRE(abs(c2.getImag() + 49.43) < 0.000000001);
}

TEST_CASE("Сomparison for equality", "[Complex]") {
    Complex<double> c1(4, -1);
    Complex<double> c2(4, -1);

    REQUIRE(1 == (c1 == c2));

    Complex<double> c3(2, 0);
    double eq_d = 2;
    int eq_i = 2;
    float eq_f = 2;

    REQUIRE(1 == (c3 == eq_d));
    REQUIRE(1 == (eq_d == c3));

    REQUIRE(1 == (c3 == eq_i));
    REQUIRE(1 == (eq_i == c3));

    REQUIRE(1 == (c3 == eq_f));
    REQUIRE(1 == (eq_f == c3));
}

TEST_CASE("Сomparison for inequality", "[Complex]") {
    Complex<double> c1(4, -1);
    Complex<double> c2(4, -1);

    REQUIRE(false != (c1 == c2));

    Complex<double> c3(2, 0);
    double eq_d = 2;
    int eq_i = 2;
    float eq_f = 2;

    REQUIRE(false != (c3 == eq_d));
    REQUIRE(false != (eq_d == c3));

    REQUIRE(false != (c3 == eq_i));
    REQUIRE(false != (eq_i == c3));

    REQUIRE(false != (c3 == eq_f));
    REQUIRE(false != (eq_f == c3));
}