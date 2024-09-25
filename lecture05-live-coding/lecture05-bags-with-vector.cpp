#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

// Here we are saying that 'bag' is an alias for a vector of unsigned ints
typedef vector<unsigned int> bag;

// Enumeration type for actions on the bag
enum action {add, del, sortIt, makeSet, readFile, flip, none};

// Here are several function prototypes; their definitions are after main()
action str2action(string s); // Translate a strings into an action
void display(const bag &b); // Display the content of a bag (used read-only)
void performAction(bag &b, action a, string arg); // Perform an action

int main() {
    bag myBag;
    string actStr;
    action act;
    string arg;

    while (true) {
        display(myBag);

        cout << "Enter an action between: add <x> | del <x> | sortIt | makeSet | readFile <filename> | flip" << endl;
        cout << "To terminate, press Ctrl+D (on Linux and Mac) or Ctrl+Z then <Return> (on Windows)" << endl;
        cin >> actStr;

        if (cin.fail()) {
            cout << "Goodbye!" << endl;
            return 0;
        }

        act = str2action(actStr);

        // Some actions require an extra argument
        if ((act == add) || (act == del) || (act == readFile)) {
            cin >> arg;
        }

        // Perform the action
        performAction(myBag, act, arg);
        cout << endl;
    }

    return 0;
}

// Translate a strings into an action
action str2action(string s) {
    if (s == "add") return add;
    if (s == "del") return del;
    if (s == "sortIt") return sortIt;
    if (s == "makeSet") return makeSet;
    if (s == "readFile") return readFile;
    if (s == "flip") return flip;
    cout << "WARNING: converting '" << s << "' into action 'none'" << endl;
    return none;
}

// Function to print the content of the bag.
// Notice that the bag is passed as a constant reference: it cannot be modified
void display(const bag &b) {
    cout << "The bag is now: [";
    // Here is a simple example of how to use modern C++ syntax
    // to go through all the elements in a vector
    for (auto e : b) {
        cout << e << " ";
    }

    // There are several ways of iterating a vector
    // For example, using iterators the above could be written as follows
    // Notice that we use 'const_iterator': this is because 'b' is a reference
    // to a const bag.  A normal iterator could be exploited to modify the bag,
    // so C++ gives an error if we try to use it (try!)
    /*
    for(bag::const_iterator i = b.begin(); i != b.end(); i++) {
        // The iterator is used like a pointer
        // *i is used to de-reference the iterator/pointer
        cout << *i << " ";
    }
    */

    cout << "]" << endl;
}

// This function perform a given action 'a' on the bag.
// 'arg' is the argument of the action (sometimes unused)
void performAction(bag &b, action a, string arg) {    
    switch (a) {
        case add: {
            unsigned int x = stoi(arg); // Translate a string into an integer
            // The following line inserts at the beginning of the bag
            b.insert(b.begin(), x);
            // The following line appends at the end of the bag
            // b.push_back(x);
            break;
        }

        case del: {
            unsigned int x = stoi(arg); // Translate a string into an integer

            // We loop backwards from the last element of the bag
            for (int i = b.size() - 1; i >= 0; i--) {
                if (b[i] == x) {
                    // We have found out that element 'i' of the bag must be
                    // removed: to use bag.erase(...) on that element, we take
                    // an iterator 'it' from the beginning of the bag...
                    bag::iterator it = b.begin();
                    // ...and add 'i' to 'it', to "point" to the i-th element
                    b.erase(it + i);
                }
            }

            // The iterator-based solution below is NOT correct.
            // Suppose we want to remove element '22' from the bag '11 22 22 33'
            // When the first '22' is erased, the 'it++' increment skips the
            // following '22' element, which remains in the bag even if it
            // should be removed.

            // for (bag::iterator it = b.begin(); it != b.end(); it++) {
            //     if (*it == x) {
            //         b.erase(it);
            //         break;
            //     }
            // }

            break;
        }

        case sortIt: {
            // Sort vector elements between its initial and final positions
            sort(b.begin(), b.end());
            break;
        }

        case makeSet: {
            // Sort vector elements between its initial and final positions
            sort(b.begin(), b.end());
            for (bag::iterator it = b.begin(); it != b.end(); it++) {
                // We now delete duplicate elements by checking whether
                // the current element is equal to the successor
                while ((it + 1 != b.end()) && (*it == *(it + 1))) {
                    b.erase(it + 1);
                }
            }
            break;
        }

        case readFile: {
            string n; // Will contain data read from a file
            // Open the file named 'arg' into the filestream f
            ifstream f(arg);
            // Check if the file exists
            if (f.fail()) {
                cout << "ERROR: could not open the file: " + arg << endl;
                break;
            }
            // Repeat until we can read whitespace-separated "words"...
            while (true) {
                f >> n;
                if (f.fail()) {
                    // We have reached the end of the file
                    break;
                }
                performAction(b, add, n);
            }
            // The following f.close() is optional:
            // the file will be closed when f exits the current scope
            // f.close();
            break;
        } // This is where f exits the scope, and the file is closed

        case flip: {
            stack<unsigned int> pile;
            // Dump the bag into a stack
            for(auto e : b){
                pile.push(e);
            }
            // Dump the stack into the bag again
            b.clear();
            while (!pile.empty()) {
                b.push_back(pile.top());
                pile.pop();
            }
            break;
        }

        case none: break;

        default:
            cout << "ERROR: invalid action: " << a << endl;
            break;
    }

    return;
}
