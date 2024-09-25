#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int main(){
    int n = 0;
    map<int, int> frequency;

    while(true) {
        cin >> n;

        if(n == 0) {
            break;
        }else if(1 <= n && n <= 1000){
            frequency[n]++;
            cout << frequency[n] - 1 << endl;
        }
    }

    return 0;
}