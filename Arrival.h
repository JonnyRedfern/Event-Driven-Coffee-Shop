/*
 * Arrival.h
 *
 *  Created on: Feb 17, 2016
 *      Author: jonny
 */

#ifndef ARRIVAL_H_
#define ARRIVAL_H_
#include <string>
#include <iostream>
#include "Customer.h"
#include "Event.h"
using namespace std;

class Arrival: public Event{
public:
	Arrival(Customer* input,int num);
	virtual ~Arrival();
	Customer* getCust();
	void printStatus();
private:
	Customer* cust;//this is corresponding customer that arrived

};

#endif /* ARRIVAL_H_ */
