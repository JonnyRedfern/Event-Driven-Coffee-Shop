/*
 * Customer.h
 *
 *  Created on: Feb 15, 2016
 *      Author: jonny
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <iostream>
#include <string>
#include "Event.h"
using namespace std;

class Customer: public Event{
public:
	static int custNum;
	//these are the individual time costs of ordering an item
	static const int COF = 2;
	static const int PAN = 12;
	static const int TE = 3;
	static const int DON = 1;
	static const int ICE = 6;
	static const int BAG = 4;
	Customer(int input);
	virtual ~Customer();
	void addOrder(string input,int num);
	int getOrderTime();
	int getNum();
	void printOrder();//prints what customer bought and how much
	//these two methods will be used to see if a customer is allowed in the express lane
	int getPanNum();
	int getIceNum();
private:
	int orderTime; //time it takes to complete the order
	int num; //this customers number
	//these will hold the number of each item that the customer ordered
	int cofNum;
	int panNum;
	int teNum;
	int donNum;
	int iceNum;
	int bagNum;
};

#endif /* CUSTOMER_H_ */
