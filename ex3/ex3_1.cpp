#include <iostream>
#include <set>
#include <string>

using namespace std;

void bags(set<int> bag){
    while (true) {
        string command;
        cin >> command;

        if (command == "add") {
            int x;
            cin >> x;
            bag.insert(x);
        } else if (command == "del") {
            int x;
            cin >> x;
            bag.erase(x);
        } else if (command == "qry") {
            int x;
            cin >> x;
            if (bag.find(x) != bag.end()) {
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
    set<int> bag;

    bags(bag);
    return 0;
}