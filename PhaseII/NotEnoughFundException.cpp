#include <iostream>
#include <string>
using namespace std;

class NotEnoughFundException {
  public:
  NotEnoughFundException()
  {
    
  }

  string getMessage()
  {
    return "Not enough funds.";
  }
};
