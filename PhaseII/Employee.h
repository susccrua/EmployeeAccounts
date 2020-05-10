// Employee.h

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "BankAccount.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee
{

private:
    vector<BankAccount*> accounts;
	string name;
	string id;

public:

	Employee();

	// Parameterized constructor

	Employee(string, string);

	// Setters and getters

	string getName();

	void setName(string);

	string getID();

	void setID(string);

    virtual double earnings();
    
    void addAccount(BankAccount *);
    
    BankAccount * getAccount(int);

    void print();


};

#endif

//
