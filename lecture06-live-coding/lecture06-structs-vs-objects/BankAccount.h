#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include <string>

using namespace std;

/**
 * A class representing a Bank account
 */
class BankAccount {

/**
 * Encapsulation: the private members of the class can be accessed only by the methods of the class
 */
private:
    int number;
    string owner;
    double balance;

/**
 * The public members of the class can be accessed also from outside the class. For example, by the function 'exampleWithOO' in the main file
 */
public:
    /**
     * Constructor: create an instance of BankAccount (an 'object') with given number, owner, and balance.
     */
    BankAccount(int number,	string owner, double balance);

	/**
     * Destructor: called automatically when the object is deleted or when it gets out of scope.
     */
    ~BankAccount();

    /**
     * Get the current balance, the number, and the owner of the account.
     * The keyword 'const' stresses the fact that this methods do not modify the account
     */
    double getBalance() const;
    int getNumber() const;
    const string getOwner() const;

    /**
     * Print information on the bank account.
     */
    void print() const;

    /**
     * Transfer 'value' money from 'this' bankAccount to the bankAccount 'to'.
     * Given that we pass the account 'to' by reference (using BankAccount &to),
     * any change to the account will persist in the original account passed as parameter.
     * Instead, when passing objects by value (using BankAccount to)
     * we actually create a copy of the object passed by parameter,
     * and changes done by the method will NOT persist in the original account passed as parameter.
     */
    bool transferMoney(BankAccount &to, double value);

    bool wrongTransferMoney(BankAccount to, double value);

    /**
     * Withdraw 'value' money from 'this' bankAccount
     */
    bool withdraw(double value);

    /**
     * Deposit 'value' money from 'this' bankAccount
     */
    bool deposit(double value);
};

#endif /* BANKACCOUNT_H_ */
