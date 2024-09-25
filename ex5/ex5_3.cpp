#include <iostream>
#include <vector>

using namespace std;
int scalar_product(const vector<int>& a, const vector<int>& b, int l){
    int sum = 0;
    for(int i=0; i < l;i++){
        sum += a[i] * b[i];
    }
    return sum;
}
int main(){
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
    l = max(length_a, length_b);

    if(length_a < length_b){
        for(int i = length_a; i < length_b; i++){
            a.push_back(0);
        }
    } else if(length_a > length_b){
        for(int i = length_b; i < length_a; i++){
            b.push_back(0);
        }
    }

    int sum = scalar_product(a, b, l);
    cout << sum << endl;

    return 0;
}

// g++ ex5_3.cpp
// ./a.out