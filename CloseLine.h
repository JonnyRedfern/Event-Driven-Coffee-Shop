/*
 * CloseLine.h
 *
 *  Created on: Feb 19, 2016
 *      Author: jonny
 */

#ifndef CLOSELINE_H_
#define CLOSELINE_H_
#include "Event.h"
class CloseLine:public Event {
public:
	CloseLine(int time);
	virtual ~CloseLine();
};

#endif /* CLOSELINE_H_ */
