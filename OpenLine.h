/*
 * OpenLine.h
 *
 *  Created on: Feb 19, 2016
 *      Author: jonny
 */

#ifndef OPENLINE_H_
#define OPENLINE_H_
#include "Event.h"
class OpenLine:public Event {
public:
	OpenLine(int time);
	virtual ~OpenLine();
};

#endif /* OPENLINE_H_ */
