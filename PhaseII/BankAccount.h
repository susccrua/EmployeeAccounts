#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class BankAccount {
  
private:
string type;
double balance;
int numDeposits;
int numWithdrawals;
double rate;

public:

BankAccount();
BankAccount(double, double);
virtual void deposit(double);
virtual void withdrawal(double);
void calcInt();
virtual void print();

//get and set methods
string getType();
double getBalance();
int getNumDeposits();
int getNumWithdrawals();
double getRate();

void setType(string);
void setBalance(double);
void setNumDeposits(int);
void setNumWithdrawals(int);
void setRate(double);

};


#endif