#include <iostream>
#include <set>
#include <string>

using namespace std;

void bbags(multiset<int> bbag){
    while (true) {
        string command;
        cin >> command;

        if (command == "add") {
            int x;
            cin >> x;
            bbag.insert(x);
        } else if (command == "del") {
            int x;
            cin >> x;
            multiset<int>::iterator it = bbag.find(x);
            if (it != bbag.end()) {
                bbag.erase(it);
            }
        } else if (command == "qry") {
            int x;
            cin >> x;
            if (bbag.find(x) != bbag.end()) {
                cout << "T";
            } else {
                cout << "F";
            }
        } else if (command == "quit") {
            break;
        }
    }
}

int main(){
    multiset<int> bbag;
    bbags(bbag);
    return 0;
}