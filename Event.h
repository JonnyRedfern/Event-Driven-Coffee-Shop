/*
 * Event.h
 *
 *  Created on: Feb 15, 2016
 *      Author: jonny
 */

#ifndef EVENT_H_
#define EVENT_H_
#include <string>
#include <iostream>
using namespace std;

class Event {
public:
	Event(int input);
	virtual ~Event();
	void setTime(int input);
	int getTime();
	virtual void printStatus(){}// this will be different for every event subclass
protected:
	int eventTime;//used across all the sub classes
};

#endif /* EVENT_H_ */
