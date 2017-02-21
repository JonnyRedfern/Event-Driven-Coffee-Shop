/*
 * CompleteService.h
 *
 *  Created on: Feb 17, 2016
 *      Author: jonny
 */

#ifndef COMPLETESERVICE_H_
#define COMPLETESERVICE_H_
#include <string>
#include <iostream>
#include "Event.h"
#include "Customer.h"
using namespace std;

class CompleteService: public Event {
public:
	CompleteService(Customer* input,int num,int wait);//num is the event time and wait is the waittime that the customer had
	virtual ~CompleteService();
	Customer* getCust();
	void printStatus();
	int getWaitTime();
private:
	Customer* cust;
	int waitTime;//used when printing out facts about the customer
};

#endif /* COMPLETESERVICE_H_ */
