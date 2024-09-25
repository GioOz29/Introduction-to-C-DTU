#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Fibonacci(int v){
    int fn = 1;
    int f1 = 1;
    int temp;
    if(v == 0 || v == 1){
        return fn;
    } else {
        for(int i = 1; i < v; i++){
            temp = fn;
            fn = fn + f1;
            f1 = temp;
        }
        return fn;
    }
}

int main(){
    int n, f;
    vector<int> v;

    while(!cin.fail()){
        cin >> n;
        if(!cin.fail()){
            v.push_back(n);
        }
    }
    for(int i = 0; i< v.size(); i++){
        f = Fibonacci(v[i]);
        cout << f << " ";
    }

    cout << endl;
    return 0;
}

// g++ ex9_2.cpp
// ./a.out