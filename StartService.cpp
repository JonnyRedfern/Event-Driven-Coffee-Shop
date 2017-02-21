
     //
     // Author: Jonathan Redfern, 7748707
     //
     // REMARKS: An object of this class is created and inserted into the event queue when a customer reaches the head of a line
     //
     //-----------------------------------------

#include "StartService.h"

StartService::StartService(Customer* input, int num):Event(num) {
	cust = input;
}



StartService::~StartService() {
	// TODO Auto-generated destructor stub
}

//this starts a complete service event and returns it so it can be inserted into the event queue
CompleteService* StartService::startComplete()
{
	int wait = eventTime - cust->getTime();
	CompleteService* temp = new CompleteService(cust,eventTime+cust->getOrderTime(),wait);
	return temp;
}

