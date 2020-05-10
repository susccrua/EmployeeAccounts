// ProductionWorker.cpp

#include <iostream>

#include <string>

using namespace std;

#include "ProductionWorker.h"

#include "Employee.h"

// Default constructor

ProductionWorker::ProductionWorker() : Employee()

{
	shift = 0; payRate = 0.0; hours = 0;
}

// Constructor

ProductionWorker::ProductionWorker(string aName, string ID, int ahours, double aPayRate, int aShift) : Employee(aName, ID)

{
    this->shift = aShift;
    this->payRate = aPayRate;
    this->hours = ahours;
}

// Mutators

void ProductionWorker::setShift(int s)

{
	this->shift = s;
}

void ProductionWorker::setPayRate(double r)

{
	this->payRate = r;
}

// Accessors

int ProductionWorker::getShiftNumber() const

{
	return shift;
}

double ProductionWorker::getPayRate() const

{
	return payRate;
}

double ProductionWorker::earnings()

{

	return hours * payRate;

}

int ProductionWorker::getHours()

{

	return hours;

}

void ProductionWorker::setHours(int ahours)

{

	this->hours = ahours;

}

void ProductionWorker::print()
{
    Employee::print();
    
    cout << "Shift: " << getShiftNumber() << endl;
    
    cout << "Hours: " << getHours() << endl;
    
    cout << "Hourly Pay: " << getPayRate() << endl;
    
    cout << "Salary :" << earnings() << endl;
}

//
