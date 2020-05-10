#include <iostream>
#include <string>
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "NegativeAmountException.cpp"
#include "NotEnoughFundException.cpp"
using namespace std;

int main()
{
	Employee *employees[2];
	employees[0] = new ProductionWorker("Bob", "1111", 40, 30, 1);
	employees[1] = new ShiftSupervisor("Alice", "22222", 40000, 5000);

	BankAccount *checking1 = new CheckingAccount(500, 0.03);
	BankAccount *checking2 = new CheckingAccount(1000, 0.02);

	BankAccount *savings1 = new SavingsAccount(1000, 0.05);
	BankAccount *savings2 = new SavingsAccount(2000, 0.06);

	employees[0]->addAccount(checking1);
	employees[0]->addAccount(savings1);

	employees[1]->addAccount(checking2);
	employees[1]->addAccount(savings2);

	for (int i = 0; i < 2; i++)
	{
		employees[i]->print();
			cout << "\n";
	}

	cout << "\n----------------------------\n";

	cout << "\n*** Test normal deposit and withdrawal ***\n";
	try {
		employees[0]->getAccount(0)->deposit(200);
		employees[0]->getAccount(0)->withdrawal(500); //checking $200
		employees[0]->getAccount(1)->deposit(200);
		employees[0]->getAccount(1)->withdrawal(500); // savings $700

		employees[1]->getAccount(0)->deposit(300);
		employees[1]->getAccount(0)->withdrawal(600); // checking 700
		employees[1]->getAccount(1)->deposit(300);
		employees[1]->getAccount(1)->withdrawal(600); // savings $1,700
		/*
		employees[0]->accounts[0]->deposit(200);
		employees[0]->accounts[0]->withdraw(500); //checking $200
		employees[0]->accounts[1]->deposit(200);
		employees[0]->accounts[1]->withdraw(500); // savings $700

		employees[1]->accounts[0]->deposit(300);
		employees[1]->accounts[0]->withdraw(600); // checking 700
		employees[1]->accounts[1]->deposit(300);
		employees[1]->accounts[1]->withdraw(600); // savings $1,700
		*/
	}
	catch (NegativeAmountException nae)
	{
		cout << nae.getMessage() << endl;
	}
	catch (NotEnoughFundException nef)
	{
		cout << nef.getMessage() << endl;
	}
	cout << "\nAfter transactions ...\n";
	employees[0]->print();
	cout << "\n";
	employees[1]->print();


	cout << "\n----------------------------\n";

	cout << "\n*** Test not enough fund ***\n";
	cout << "Before withdraw ...\n";
	employees[0]->print();
	try {
		//employees[0]->accounts[0]->withdraw(300);
		employees[0]->getAccount(0)->withdrawal(300);
	}
	catch (NegativeAmountException nae)
	{
		cout << nae.getMessage() << endl;
	}
	catch (NotEnoughFundException nef)
	{
		cout << nef.getMessage() << endl;
	}
	cout << "After withdraw ...\n";
	employees[0]->print(); // $15 fine should be deducted from balance

	cout << "\n----------------------------\n";

	cout << "\n*** Test negative amount ***\n";
	cout << "Before withdraw ...\n";
	employees[1]->print();
	try {
		employees[1]->getAccount(0)->deposit(-200);
	}
	catch (NegativeAmountException nae)
	{
		cout << nae.getMessage() << endl;
	}
	catch (NotEnoughFundException nef)
	{
		cout << nef.getMessage() << endl;
	}
	cout << "After withdraw ...\n";
	employees[1]->print();

	cout << "\n----------------------------\n";

	cout << "\n*** Test status change to false ***\n";
	cout << "Before withdraw ...\n";
	employees[0]->print();
	cout << "\n";
	employees[1]->print();
	try {
		employees[0]->getAccount(1)->withdrawal(680);
		employees[1]->getAccount(1)->withdrawal(1690);
		/*
		employees[0]->accounts[1]->withdraw(680);
		employees[1]->accounts[1]->withdraw(1690);
		*/
	}
	catch (NegativeAmountException nae)
	{
		cout << nae.getMessage() << endl;
	}
	catch (NotEnoughFundException nef)
	{
		cout << nef.getMessage() << endl;
	}
	cout << "After withdraw ...\n";
	employees[0]->print();
	cout << "\n";
	employees[1]->print();

	cout << "\n----------------------------\n";

	cout << "\n*** Test False status not being able to withdraw ***\n";
	cout << "Before withdraw ...\n";
	employees[0]->print();
	//employees[0]->accounts[1]->withdraw(10);
	employees[0]->getAccount(1)->withdrawal(10);
	cout << "After withdraw ...\n";
	employees[0]->print(); // employee[0] after withdrawal, should be no difference

	cout << "\n----------------------------\n";

	cout << "\n***Deposit to both accounts, back to normal ***\n";
	cout << "Before deposit ...\n";
	employees[0]->print();
	cout << "\n";
	employees[1]->print();

	cout << "\nMaking deposit ...\n";
	employees[0]->getAccount(0)->deposit(500);
	employees[0]->getAccount(1)->deposit(1000);
	employees[1]->getAccount(0)->deposit(1000);
	employees[1]->getAccount(1)->deposit(2000);

	/*
	employees[0]->accounts[0].deposit(500);
	employees[0]->accounts[1].deposit(1000);
	employees[1]->accounts[0].deposit(1000);
	employees[1]->accounts[1].deposit(2000);
	*/
	cout << "\nAfter deposit ...\n";
	employees[0]->print();
	cout << "\n";
	employees[1]->print();


	return 0;
}
