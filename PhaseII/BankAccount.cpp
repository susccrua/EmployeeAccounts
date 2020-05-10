#include <iostream>
#include <string>
#include "BankAccount.h"
#include "NegativeAmountException.cpp"
#include "NotEnoughFundException.cpp"

using namespace std;

BankAccount::BankAccount(){
type = "Unknown";
balance = 0;
numDeposits=0;
numWithdrawals=0;
rate=0;
}

BankAccount::BankAccount(double b, double r){
  type = "Unknown";
  numDeposits =0;
  numWithdrawals = 0;
  try {
    setBalance(b);
    setRate(r);
  }
  catch (NegativeAmountException e)
  {
    e.getMessage();
  }
}

void BankAccount::deposit(double amount){
  setNumDeposits(getNumDeposits()+1);
  try{
    if (amount < 0){
      throw NegativeAmountException(amount);
    } 
    else{
      setBalance(getBalance()+amount);
    }
  }
  catch(NegativeAmountException e){
    e.getMessage();
  }
}

void BankAccount::withdrawal(double amount){
  try{
    if (amount < 0)
    { throw NegativeAmountException(amount); }
    if(amount>balance){
      throw NotEnoughFundException();
    }
    else 
    { 
      setNumWithdrawals(getNumWithdrawals()+1);
      setBalance(getBalance()-amount);
      }
  }
  catch(NegativeAmountException e){
     e.getMessage();
    }
  catch(NotEnoughFundException e){
    e.getMessage();
  }
  }


void BankAccount::calcInt(){
  double monthIntRate = (rate/12);
  double monthInterest = balance * monthIntRate;
  balance = balance + monthInterest;
}

void BankAccount::print(){
  cout << "Account Type: " << type << endl;
  cout << "Balance: " << balance << endl;
  cout << "Rate" << rate << endl;
  cout << "Number of Deposits: " << numDeposits << endl;
  cout << "Number of Withdrawals: " << numWithdrawals << endl;
}

string BankAccount::getType(){
  return type;
}
double BankAccount::getBalance(){
return balance;
}

int BankAccount::getNumDeposits(){
  return numDeposits;
}

int BankAccount::getNumWithdrawals()
{
  return numWithdrawals;
}

double BankAccount::getRate()
{
  return rate;
}

//example 2
void BankAccount::setType(string t){
  type = t;
}

void BankAccount::setBalance(double b)
{
  balance = b;
}

void BankAccount::setNumDeposits(int d)
{
  numDeposits = d;
}

void BankAccount::setNumWithdrawals(int w)
{
  numWithdrawals = w;
}

void BankAccount::setRate(double r)
{
  if (r > 0){
  throw NegativeAmountException(r);
  }  
  else{
    rate = r;
  }
}
