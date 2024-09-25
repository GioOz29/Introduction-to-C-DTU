#include "BankAccount.h"
#include <iostream>

using namespace std;

BankAccount::BankAccount(int number, string owner, double balance) {
    this->number = number;
    this->owner = owner;
    this->balance = balance;
}

BankAccount::~BankAccount(){
    cout << "Account " << this->number << " has been deleted" << endl;
	return;
}

double BankAccount::getBalance() const {
    return this->balance;
}

int BankAccount::getNumber() const {
    return this->number;
}

const string BankAccount::getOwner() const {
    return this->owner;
}

void BankAccount::print() const {
    cout << "Account number " << this->number << " owned by " << this->owner << " contains " << this->balance << endl;
	return;
}

bool BankAccount::transferMoney(BankAccount &to, double value) {
    if(value < 0 || this->balance < value){
        cout << "Transfer failed" << endl;
        return false;
    } else {
        this->balance -= value;
        to.balance += value;
        cout << "Transfer succeeded" << endl;
        return true;
    }
}

bool BankAccount::wrongTransferMoney(BankAccount to, double value) {
    if(value < 0 ||this->balance < value){
        cout << "Transfer failed" << endl;
        return false;
    }
    else{
        this->balance-=value;
        to.balance += value;
        cout << "Transfer succeeded" << endl;
        return true;
    }
}

bool BankAccount::withdraw(double value) {
    if(value < 0 ||this->balance < value){
        return false;
    } else {
        this->balance-=value;
        return true;
    }
}

bool BankAccount::deposit(double value) {
    this->balance += value;
    return true;
}
