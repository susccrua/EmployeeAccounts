//ProductionWorker.h

#ifndef PRODUCTION_WORKER_H
#define PRODUCTION_WORKER_H

#include "Employee.h"

#include <iostream>
#include <string>

using namespace std;

class ProductionWorker : public Employee

{

private:

	// declare The worker's shift as int

	int shift;

	int hours;

	// declare The worker's hourly pay rate as a double

	double payRate;

public:

	// Default constructor

	ProductionWorker();

	// Constructor

	ProductionWorker(string, string, int, double, int);

	// Mutators

	void setShift(int);

	void setPayRate(double);

	// Accessors

	int getShiftNumber() const;

	int getHours();

	void setHours(int);

	double getPayRate() const;

	double earnings();

	void print();

};

#endif

//