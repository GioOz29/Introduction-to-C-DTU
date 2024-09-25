#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// This function is a vector that takes in input a fraction
vector<int> p_factorization(int n){
    vector<int>  factorcount(n + 1, 0);
    int divisor = 2;

    while (divisor <= n) {
        if (n % divisor == 0) {
            factorcount[divisor]++;
            n /= divisor;
        } else {
            divisor++;
        }
    }
    return factorcount;
}
long long multiply(vector<int>& factorsCount1, vector<int>& factorsCount2) {
    // Determine the maximum size of the two vectors
    int maxSize = max(factorsCount1.size(), factorsCount2.size());

    long long result = 1;

    for (int i = 2; i < maxSize; i++) {
        int count1 = (i < factorsCount1.size()) ? factorsCount1[i] : 0;
        int count2 = (i < factorsCount2.size()) ? factorsCount2[i] : 0;
        int totalCount = count1 + count2;
        
        if (totalCount > 0) {
            for (int j = 0; j < totalCount; j++) {
                result *= i;
            }
        }
    }

    return result;
}

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
    vector<int> num = p_factorization(numerator);
    vector<int> num1 = p_factorization(f.numerator);
    vector<int> den = p_factorization(denominator);
    vector<int> den1 = p_factorization(f.denominator);

    numerator = multiply(num, den1)+multiply(num1, den);
    denominator *= f.denominator;
}
void fraction::mult(fraction f){
    vector<int> num = p_factorization(numerator);
    vector<int> num1 = p_factorization(f.numerator);
    vector<int> den = p_factorization(denominator);
    vector<int> den1 = p_factorization(f.denominator);

    numerator = multiply(num, num1);
    denominator = multiply(den, den1);
}
void fraction::div(fraction f){
    vector<int> num = p_factorization(numerator);
    vector<int> num1 = p_factorization(f.numerator);
    vector<int> den = p_factorization(denominator);
    vector<int> den1 = p_factorization(f.denominator);

    numerator = multiply(num, den1);
    denominator = multiply(num1, den);
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

// g++ ex6_optional.cpp
// ./a.out