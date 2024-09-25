#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int a = 0;
    vector<int> v;
    while(!cin.fail()){
        cin >> a;
        if(!cin.fail()){
            v.push_back(a);
        }
    }
    reverse(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
    return 0;
}

// g++ ex9_1.cpp
// ./a.out