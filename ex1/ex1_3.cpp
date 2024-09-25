#include<iostream>

using namespace std;


int main(){

    int num1 = 0, num2 = 0;
    cin >> num1 >> num2;

    if(num1 == num2){
        cout << num1 << " is equal to " << num2 << endl;
    }
    else if(num1 > num2){
        cout << num1 << " is bigger than " << num2 << endl;
    }
    else {
        cout << num1 << " is smaller than " << num2 << endl;
    }

    return 0;
}