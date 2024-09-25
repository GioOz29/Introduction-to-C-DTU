#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Enumeration type for actions on the bag
enum action {add, del, readFile, none};

// Translate a strings into an action
action str2action(string s) {
    if (s == "add") return add;
    if (s == "del") return del;
    if (s == "readFile") return readFile;
    cout << "WARNING: converting '" << s << "' into action 'none'" << endl;
    return none;
}

void display(const vector<unsigned int> &bag){
    vector<unsigned int>::iterator it;
    cout << "The content of the bag is: ";
    // for(it = bag.begin(); it != bag.end(); it++){
    //     cout << *it << " ";
    // }
    for (auto e : bag) {
        cout << e << " ";
    }
    cout << endl;

}

void performAction(vector<unsigned int> &bag, action act, string arg){
    switch (act)
    {
    case add:{
        unsigned int value = stoi(arg); // from a string to an integer value
        bag.push_back(value);
        break;
    }
    case del:{
        unsigned int value = stoi(arg);
        for(int i = bag.size()-1; i >= 0; i--){
            if(bag[i] == value){
                vector<unsigned int>::iterator it = bag.begin();
                bag.erase(it+i);    // remove the element at index it so the beginning of the bag + the i index
            }
        }
        break;
    }
    case readFile:{
        ifstream f(arg);
        if(f.fail()){
            cout << "file could not exist";
            break;
        }
        while(true){
            f >> arg;
            if(f.fail()){
                break;
            }
            performAction(bag,add, arg);
        }
    }
    default:
        break;
    }
}

int main() {
    vector<unsigned int> myBag;
    string actStr;
    action act;
    string arg;

    while (true) {
		//TODO: implement a function to display the contents of the vector
        display(myBag);

        cout << "Enter an action between: add <x> | del <x> | readFile <filename>" << endl;
        cout << "To terminate, press Ctrl+D (on Linux and Mac) or Ctrl+Z then <Return> (on Windows)" << endl;
        cin >> actStr;

        if (cin.fail()) {
            cout << "Goodbye!" << endl;
            return 0;
        }

		act = str2action(actStr);

        cin >> arg;

        //TODO: implement a function to modify the contents of the vector according to what has been specified by the user
        performAction(myBag, act, arg);
        cout << endl;
    }

    return 0;
}

