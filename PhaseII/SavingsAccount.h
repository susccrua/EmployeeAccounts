#ifndef SAVINGS_ACCOUNT_H_
#define SAVINGS_ACCOUNT_H_

#include "BankAccount.h"

class SavingsAccount : public BankAccount
{
    private:
        bool status;

    public:
        SavingsAccount();
        SavingsAccount(double, double);

        ~SavingsAccount();

        void deposit(double) override;
        void withdrawal(double) override;
        bool getStatus(double);
        void print() override;

        
};

#endif
