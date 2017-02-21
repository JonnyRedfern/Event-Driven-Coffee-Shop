
     // Author: Jonathan Redfern, 7748707
     //
     // REMARKS: This is the parent class for all the event classes, it will hold the time of the event
     //
     //-----------------------------------------


#include "Event.h"

Event::Event(int input) {
 eventTime = input;
}

Event::~Event() {
	// TODO Auto-generated destructor stub
}

void Event::setTime(int input)
{
	eventTime = input;
}//setTime

int Event::getTime()
{
	return eventTime;
}//getTime


