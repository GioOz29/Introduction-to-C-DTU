#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n = 0;
    char c;
    vector<int> a;
    vector<int> b;

    while(cin >> c){
        if(c == 'a'){
            cin >> n;
            a.push_back(n);
        } else if(c == 'b'){
            cin >> n;
            b.push_back(n);
        } else break;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }

    for(int i = 0; i < b.size(); i++){
        cout << b[i] << " ";
    }

    return 0;
}

// g++ ex5_1.cpp
// ./a.out