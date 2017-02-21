
     // Author: Jonathan Redfern, 7748707
     //
     // REMARKS: This class is created and inserted into the event queue when a close line event is read from the text file
     //
     //-----------------------------------------


#include "CloseLine.h"

CloseLine::CloseLine(int time):Event(time) {}

CloseLine::~CloseLine() {
	// TODO Auto-generated destructor stub
}

