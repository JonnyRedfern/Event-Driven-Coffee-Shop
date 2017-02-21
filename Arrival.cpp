
     // Author: Jonathan Redfern, 7748707
     //
     // REMARKS: This class is created when a arrival is read from the desired text file and inserted into the event queue
     //
     //-----------------------------------------

#include "Arrival.h"

//the customer in the constructor params is the one that is linked to this arrival
Arrival::Arrival(Customer* input, int num):Event(num) {
	cust = input;
}

Arrival::~Arrival() {
	// TODO Auto-generated destructor stub
}

Customer* Arrival::getCust()
{
	return cust;
}

void Arrival::printStatus()
{
cout<<"Time "<<eventTime<<":  Customer "<<cust->getNum()<<" arrives: ";
cust->printOrder();
cout<<"service time: " << cust->getOrderTime()<<endl;
}

