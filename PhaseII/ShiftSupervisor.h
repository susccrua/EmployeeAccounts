// ShiftSupervisor.h

#ifndef SHIFTSUPERVISOR_H

#define SHIFTSUPERVISOR_H
#include "Employee.h"
#include <iostream>
#include <string>

using namespace std;

class ShiftSupervisor : public Employee
{

public:

	ShiftSupervisor();

	ShiftSupervisor(string, string, double, double);

	double getBonus();

	double getSalary();

	void setBonus(double);

	void setSalary(double);

	double earnings();

	void print();

private:

	// Declaring variables

	double bonus;

	double salary;

};

#endif
