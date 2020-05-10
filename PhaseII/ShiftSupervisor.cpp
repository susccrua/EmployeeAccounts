// ShiftSupervisor.cpp

#include <iostream>
#include <string>

using namespace std;

#include "ShiftSupervisor.h"

#include "Employee.h"

ShiftSupervisor::ShiftSupervisor() :Employee()

{

	this->bonus = 0.0;

	this->salary = 0.0;

}

ShiftSupervisor::ShiftSupervisor(string name, string id, double salary, double bonus) :Employee(name, id)

{

	this->bonus = bonus;

	this->salary = salary;

}

double ShiftSupervisor::getBonus()

{

	return bonus;

}

double ShiftSupervisor::getSalary()

{

	return salary;

}

void ShiftSupervisor::setBonus(double bonus)

{

	this->bonus = bonus;

}

void ShiftSupervisor::setSalary(double salary)

{

	this->salary = salary;

}

double ShiftSupervisor::earnings()

{

	return salary + bonus;

}

void ShiftSupervisor::print()

{
    Employee::print();
    
	cout << "Base salary: " << getSalary() << endl;

	cout << "Bonus: " << getBonus() << endl;
    
    cout << "Total Earnings: " << earnings() << endl;

}
