#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    char c;
    vector<int> a;
    vector<int> b;
    int length_a;
    int length_b;
    int l = 0;

    while(cin >> c){
        if(c == 'a'){
            cin >> n;
            a.push_back(n);
        } else if(c == 'b'){
            cin >> n;
            b.push_back(n);
        } else break;
    }

    length_a = a.size();
    length_b = b.size();

    if(length_a < length_b){
        l = length_a;
    } else l = length_b;

    for(int i = 0; i < l; i++){
        if(a[i]){
            cout << a[i] << " ";
        }
        if(b[i]){
            cout << b[i] << " ";
        }
    }

    for(int i = l; i < length_a; i++){
        cout << a[i] << " ";
    }
    for(int i = l; i < length_b; i++){
        cout << b[i] << " ";
    }
    
    cout << endl;

    return 0;
}

// g++ ex5_2.cpp
// ./a.out