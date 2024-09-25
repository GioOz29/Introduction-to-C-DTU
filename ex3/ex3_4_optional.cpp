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

void histogram(){
    int l;
    int n;
    int highest;
    double k;
    vector<int> dataset;
    cin >> l;
    cin >> n;

    for(int i = 0; i < n; i++){
        int var;
        cin >> var;
        dataset.push_back(var);
    }
    highest = largest_number(dataset);
    k = static_cast<double> (highest) / l;
    k = ceil(k);
    if (highest >= l) {
        vector<int> intervalCounts(l, 0); // Initialize interval counts with zeros
        // Count numbers in each interval
        for (size_t i = 0; i < dataset.size(); i++) {
            int num = dataset[i];
            int interval = num / k;
            intervalCounts[interval]++;
        }
        // Print the histogram
        for (int i = 0; i < l; i++) {
            int lower_bound = i * k;
            int upper_bound = (i + 1) * k - 1;
            // Adjust the upper bound if m is divisible by l
            if (i == l - 1 && highest % l == 0) {
                upper_bound = i * k + k;
            }
            cout << lower_bound << ": " << intervalCounts[i] << endl;
        }
    } else {
        cout << "The value that you inserted were wrong." << endl;
    }
}

int main(){
    histogram();
    return 0;
}