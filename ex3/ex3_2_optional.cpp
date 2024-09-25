#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int largest_number(vector<int>& numbers){
    int highest = numbers[0];
    bool highlited = false;
    for(size_t i = 0; i < numbers.size(); i++){
        if(numbers[i] > highest){
            highest = numbers[i];
        }
    }
    for(size_t i = 0; i < numbers.size(); i++){
        if(numbers[i] == highest && !highlited){
            cout << "*" << numbers[i] << "* ";
            highlited = true;
        }
        else{
            cout << numbers[i] << " ";
        }
    }
    cout << endl;
    return highest;
}

int main(){
    int n=0;
    vector<int> numbers;

    cin >> n;

    for(int i = 0; i < n ; i++){
        int var;
        cin >> var;
        numbers.push_back(var);
    }

    largest_number(numbers);
    return 0;
}