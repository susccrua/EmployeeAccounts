#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include <iostream>
#include <string>
#include "BankAccount.h"
using namespace std;

class CheckingAccount : public BankAccount{
public:
    CheckingAccount();
    
    CheckingAccount(double, double);
    
    void withdraw(double);
};


#endif
