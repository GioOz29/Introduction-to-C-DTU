#include<iostream>

using namespace std;

int main(){
    int n = 0;
    double d = 0;
    double sum = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> d;
        sum += d;
    }
    cout << sum << endl;

    return 0;
}