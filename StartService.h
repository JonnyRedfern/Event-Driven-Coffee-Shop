/*
 * StartService.h
 *
 *  Created on: Feb 17, 2016
 *      Author: jonny
 */

#ifndef STARTSERVICE_H_
#define STARTSERVICE_H_
#include <string>
#include <iostream>
#include "Event.h"
#include "Customer.h"
#include "CompleteService.h"
using namespace std;

class StartService:public Event {
public:
	StartService(Customer* input, int num);
	virtual ~StartService();
	Customer* getCust();
	CompleteService* startComplete();
	int getWait();
private:
	Customer* cust;
};

#endif /* STARTSERVICE_H_ */
