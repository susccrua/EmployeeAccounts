#include "BankAccount.h"
#include "CheckingAccount.h"

#include <iostream>
#include <string>
using namespace std;

CheckingAccount::CheckingAccount() : BankAccount(){
}

CheckingAccount::CheckingAccount(double initBalance, double rate) : BankAccount(initBalance, rate)
{
}


//void CheckingAccount::deposit(double amount)
//{
//		BankAccount::deposit(amount);
//}



void CheckingAccount::withdraw(double amount)
{
  if(getBalance() - amount < 0){
    BankAccount::setBalance(getBalance()-15);
  }
  else{
    BankAccount::withdrawal(amount);
  }
}

