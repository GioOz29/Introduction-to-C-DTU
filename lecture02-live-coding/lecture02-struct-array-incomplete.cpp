// Example showing how to use 'struct'ures
#include <iostream>
#include <string>

#define MAX_SIZE 3

using namespace std;

struct employee {
    string name;
    string surname;
    unsigned int salary;
};

void displayEmployee(employee e[], int n) {
	//TODO: display the contents of e
}

void raiseSalary(employee e[], int n, int increment){
    //TODO: raise the salary of e
}

int main() {
    
	employee employees[MAX_SIZE];
	
	
	employees[0] = {"Bjarne", "Stroustrup", 100000};
	employees[1] = {"John", "Doe", 50000};
    
    employees[2].name = "Margaret";
    employees[2].surname = "Hamilton";
    employees[2].salary = 500000;
	
    string action; // Will contain the user-supplied command
    int increment;
    unsigned int n;

	while (true)
    {
        cout << "What operation would you like to perform?" << endl;
        cout << "Choose between: display, raise, quit" << endl;
        cin >> action;

        if (action == "raise")
        {
            cout << "Specify employee number and increment" << endl;
            cin >> n;
            cin >> increment;
            if (n < MAX_SIZE) {
                raiseSalary(employees, n, increment);
            } else {
                cout << "Invalid employee number" << endl;
            }
        }
        else if (action == "display")
        {
            cout << "Specify employee number" << endl;
            cin >> n;
            if (n < MAX_SIZE) {
                displayEmployee(employees, n);
            } else {
                cout << "Invalid employee number" << endl;
            }
        }
        else if (action == "quit")
        {
            return 0;
        }
        else
        {
            cout << "ERROR: invalid command" << endl;
            return 1;
        }
    }

    return 0;
}
