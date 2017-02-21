
     // Author: Jonathan Redfern, 7748707
     //
     // REMARKS: This class is created when a customer reaches the front of the line and starts there service, it calculates when
     // their order will be complete then creates and object of this class and inserts it into the event queue
     //-----------------------------------------

#include "CompleteService.h"

CompleteService::CompleteService(Customer* input,int num,int wait):Event(num) {
	cust = input;
	waitTime = wait;
}

CompleteService::~CompleteService() {
	// TODO Auto-generated destructor stub
}

void CompleteService::printStatus()
{
	cout<<"Time "<<eventTime<<": Customer "<<cust->getNum()<<" completes service Arrival: "<<cust->getTime()<<" complete: "<<eventTime<<" wait: "<<waitTime<<endl;
}

int CompleteService::getWaitTime()
{
    return waitTime;
}

Customer* CompleteService::getCust()
{
	return cust;
}

