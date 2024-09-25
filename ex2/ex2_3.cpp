#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int main(){
    int n;
    double pi_4 = 0;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        pi_4 +=  pow(-1, i) / (2 * i + 1);
    }
    double pi = pi_4 * 4;

    cout << pi << endl;

    return 0;
}