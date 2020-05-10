#include <iostream>
#include <string>

using namespace std;

class NegativeAmountException {
  private:
  double amount;
  public:
  NegativeAmountException(double am){
    amount = am;
  }
  string getMessage(){
    string msg = "Amount " + to_string(amount) + " is negative";
    return msg;
  }

};