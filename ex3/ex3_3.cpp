#include <iostream>
#include <set>
#include <string>

using namespace std;

const int MAX_PAGES = 50;

struct Contacts{
    string firstName;
    string middleName;
    string lastName;
    string phoneNumber;
    string streetAddress;
    string houseNumber;
    string zipCode;
    string region;
};

void contact_bag(){
    Contacts addressBook[MAX_PAGES];
    int page;
    while(true){
        string command;
        cin >> command;

        if(command == "add"){
            cin >> page;

            if(1 <= page && page <= MAX_PAGES){
                Contacts& contact = addressBook[page - 1];
                if(contact.firstName.empty()){
                    cin >> contact.firstName >> contact.middleName >> contact.lastName >> contact.phoneNumber 
                    >> contact.streetAddress >> contact.houseNumber >> contact.zipCode >> contact.region;
                }
            }
        }
        else if(command == "clr"){
            cin >> page;
            if (page >= 1 && page <= MAX_PAGES) {
                Contacts& contact = addressBook[page - 1];
                contact.firstName = "";
                contact.middleName = "";
                contact.lastName = "";
                contact.phoneNumber = "";
                contact.streetAddress = "";
                contact.houseNumber = "";
                contact.zipCode = "";
                contact.region = "";   // Clear the contact information
            }
        }
        else if(command == "qry"){
            cin >> page;
            if(1 <= page && page <= MAX_PAGES){
                Contacts& contact = addressBook[page - 1];
                if(!contact.firstName.empty()){
                    cout << contact.firstName << "," << contact.middleName << "," <<  contact.lastName << "," << contact.phoneNumber << ","
                    << contact.streetAddress << "," << contact.houseNumber << "," << contact.zipCode << "," << contact.region << endl;
                }
            }
        }
        else if(command == "quit"){
            break;
        }
    }
}

int main(){
    contact_bag();
    return 0;
}