//SavingsAccount.cpp

#include <iostream>
#include <string>

using namespace std;

#include "SavingsAccount.h"
#include "BankAccount.cpp"
#include "Employee.h"

SavingsAccount::SavingsAccount():BankAccount(){
  status = false;
  setType("Savings");
}
SavingsAccount::SavingsAccount(double b, double r):BankAccount(b, r){
  setType("Savings");
  if(b <= 25){
    status = true;
  }
  else{
    status = false;
  }
}

SavingsAccount::~SavingsAccount()
{

}


void SavingsAccount::withdrawal(double amount){
  if (status){
    BankAccount::withdrawal(amount);
  }
  if(getBalance() < 25){
    status = false;
  }
}

void SavingsAccount::deposit(double amount){
  if (!status){
    BankAccount::deposit(amount);
    if(getBalance() >= 25){
      status = true;
    }
  }
  else{
    BankAccount::deposit(amount);
  }
}

bool SavingsAccount::getStatus(double){
  return status;
}

void SavingsAccount::print(){
    
  BankAccount::print();
    
  cout << "Status: " << to_string(status) << endl;
}
