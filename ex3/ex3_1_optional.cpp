#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main(){
    int n;
    vector<int> numbers;
    bool sorted = true;
    cin >> n;

    for(int i = 0; i < n ; i++){
        int var;
        cin >> var;
        numbers.push_back(var);
    }

    if(n != 0 && n != 1){
        for(size_t i = 0; i < numbers.size(); i++){
            if(numbers[i] > numbers[i+1]){
                sorted = false;
            }
        }
    }

    if(sorted){
        cout << "SORTED" << endl;
    }
    else{
        cout << "UNSORTED" << endl;
    }
    return 0;
}