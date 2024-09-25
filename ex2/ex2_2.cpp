#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int main(){
    int n = 0;
    vector<int> v;

    cin >> n;
    
    while(n % 2 == 0) {
        v.push_back(2);
        n = n / 2;
    }   // This happens when the value is even

    for(int i = 3; i <= sqrt(n); i = i +2) {
        while(n % i == 0) {
            v.push_back(i);
            n = n / i;
        }   // Dealing with odd
    }

    if (n > 2) {
        v.push_back(n);
    }
    cout << v[0] << " *";
    for(int i = 1; i < v.size()-1; i++) {
        cout << " " << v[i] << " *";
    }
    cout << " " << v[v.size()-1] << endl;

    return 0;
}