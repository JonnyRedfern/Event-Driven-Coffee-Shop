/*
 * Shop.h
 *
 *  Created on: Feb 19, 2016
 *      Author: jonny
 */

#ifndef SHOP_H_
#define SHOP_H_
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
#include "PriorityQueue.h"
#include "Event.h"
#include "Customer.h"
#include "Arrival.h"
#include "OpenLine.h"
#include "CloseLine.h"
#include "StartService.h"
#include "CompleteService.h"
class Shop {
public:
	Shop();
	virtual ~Shop();
	void printLines();
	void addArrival(int time,Customer* input);
	void addStartService(int time, Customer* cust);
	void insertCustToLine(Customer* cust);
	void popCustLine(CompleteService* oldCust);
	Event* popEvent();
	void openPriLine(int time);
	void closePriLine(int time);
	void printShop();
	bool checkPriLine(Customer* input);
	bool eventListEmpty();
	Node* getRegHead();
	Customer* getRegLineHead();
	Customer* getPriLineHead();
	void openLine(int input);
	void closeLine();
private:
	PriorityQueue* regLine;
	PriorityQueue* priLine;
	PriorityQueue* eventQueue;
	bool priLineOpen;
	double totalCustPri;
	double totalCustReg;
	double totalWaitPri;
	double totalWaitReg;
	double totalServicePri;
	double totalServiceReg;
	double averageWaitPri;
	double averageWaitReg;
	double averageServicePri;
	double averageServiceReg;
};

#endif /* SHOP_H_ */
