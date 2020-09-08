#include<bits/stdc++.h>
using namespace std;

class Rational
{
public:
    Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator) {
          cout << "Constructor Called..." << endl;
    }

    ~Rational() {
          cout << "Destructor Called... n:" << n << "d:" << d << endl;
    }

    Rational(const Rational&& a){
        this->d = a.d;
        this->n = a.n;
        cout << "Move Constructor Called..." << endl;
    }

    Rational(const Rational& rhs) {
          this->d = rhs.d;
          this->n = rhs.n;
          cout << "Copy Constructor Called..." << endl;
    }

    int numerator() const { return n; }
    int denominator() const { return d; }
private:
    int n, d;
};

Rational func(){
    Rational a(1, 5);
    return a;
}

int main(int argc, char **argv)
{
    //Rational x(1, 5), y(2, 9);
    Rational z = func();
    // cout << "calc result: " << z.numerator()
    //     << "/" << z.denominator() << endl;

    return 0;
}