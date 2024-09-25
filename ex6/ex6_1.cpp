#include <iostream>
#include <string>

using namespace std;

class fraction {
    private:
    // Internal representation of a fraction as two integers
    int numerator;
    int denominator;
    public:
    // Class constructor
    fraction(int n, int d);
    // Methods to update the fraction
    void add(fraction f);
    void mult(fraction f);
    void div(fraction f);
    void semplification();
    // Display method
    void display(void);
};

fraction::fraction(int n, int d) : numerator(n), denominator(d) {}

void fraction::add(fraction f){
    numerator = (numerator*f.denominator)+(f.numerator*denominator);
    denominator *= f.denominator;
}
void fraction::mult(fraction f){
    numerator = numerator*f.numerator;
    denominator *= f.denominator;
}
void fraction::div(fraction f){
    numerator = numerator*f.denominator;
    denominator = denominator*f.numerator;
}
void fraction::display(void){
    cout << numerator << " / " << denominator << endl;
}
void fraction::semplification(){
    // Find the minimum of absNum and absDen
    int minVal = min(numerator, denominator);

    // Find the greatest common divisor (GCD)
    int gcd = 1;
    for (int i = 2; i <= minVal; i++) {
        if (numerator % i == 0 && denominator % i == 0) {
            gcd = i;
        }
    }

    // Divide both numerator and denominator by the GCD
    if (gcd > 1) {
        numerator /= gcd;
        denominator /= gcd;
    }
}

int main(int argc, const char * argv[]) {
    int n1, n2;
    int d1, d2;
    string op;
    char i;
    while (!cin.fail()) {
        cin >> n1 >> i >> d1 >> op >> n2 >> i >> d2;
        if(cin.fail()){
            break;
        }
        fraction frac1(n1,d1);
        fraction frac2(n2,d2);
        
        if(op=="+"){
            frac1.add(frac2);
        } else if (op=="*"){
            frac1.mult(frac2);
        } else if (op=="div"){
            frac1.div(frac2);
        }
        frac1.semplification();
        frac1.display();
    }
    return 0;
}

// g++ ex6_1.cpp
// ./a.out