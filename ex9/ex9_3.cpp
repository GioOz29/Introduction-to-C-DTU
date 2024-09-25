#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool palindrome(vector<int> v){
    int left  = 0;
    int right = v.size()-1;
    while(left<right){
        if(v[left] != v[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main(){
    int n;
    vector<int> v;

    while(!cin.fail()){
        cin >> n;
        if(!cin.fail()){
            v.push_back(n);
        }
    }
    bool pal = palindrome(v);

    cout << (pal ? "yes" : "no");

    cout << endl;

    return 0;
}
// g++ ex9_3.cpp
// ./a.out