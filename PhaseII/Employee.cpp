// Employee.cpp
#include "Employee.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;



Employee::Employee()
{
	name = "0";
	id = "0";
}

// Parameterized constructor

Employee::Employee(string name, string id)

{

	this->name = name;

	this->id = id;

}

// Setters and getters

string Employee::getName()

{

	return name;

}

void Employee::setName(string name)

{

	this->name = name;

}

string Employee::getID()

{

	return id;

}

void Employee::setID(string id)

{

	this->id = id;

}

void Employee::addAccount(BankAccount *acc){
    accounts.push_back(acc);
}

BankAccount* Employee::getAccount(int i){
    return accounts[i];
}

void Employee::print(){
    cout << "Name: " << getName() << endl;
	cout << "ID: " << getID() << endl;

}

//
