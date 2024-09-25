#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void dot_product(int n){
    vector<double> first;
    vector<double> second;
    vector<double> product;

    for(size_t i = 0; i < n ; i++){
        int var = 0;
        cin >> var;
        first.push_back(var);
    }
    for(size_t i = 0; i < n ; i++){
        int var;
        cin >> var;
        second.push_back(var);
    }
    for(size_t i = 0; i < n ; i++){
        double prod = 0;
        prod = first[i] * second[i];
        product.push_back(prod);
        cout << product[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    dot_product(n);
    return 0;
}