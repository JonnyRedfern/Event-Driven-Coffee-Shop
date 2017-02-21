
     //
     // Author: Jonathan Redfern, 7748707
     //
     // REMARKS: This is the shop class it is created in the main file, it keeps track of all the goings on in the shop
     //
     //-----------------------------------------


#include "Shop.h"

Shop::Shop() {
	regLine = new PriorityQueue();
	priLine = new PriorityQueue();
	eventQueue = new PriorityQueue();
	priLineOpen = false;//when pri line is open it will be set to true

    //these variables are used for the stats that print at the end
	totalCustPri = 0;
	totalCustReg = 0;
	 totalWaitPri = 0;
	 totalWaitReg = 0;
	totalServicePri = 0;
	 totalServiceReg = 0;
	 averageWaitPri = 0;
	 averageWaitReg = 0;
	 averageServicePri = 0;
	 averageServiceReg = 0;
}

Shop::~Shop() {
	// TODO Auto-generated destructor stub
}

//adds a new arrival to the event queue and puts the customer in the correct line
//the time is the time that this event occured
void Shop::addArrival(int time,Customer* cust)
{
	eventQueue->insert(new Arrival(cust,time));
}

//pops a customer off a the correct line when their service is complete and starts the next customer in lines order, also deletes the customer and node
//the parameter is the complete service event of the customer
void Shop::popCustLine(CompleteService* oldCust)
{
    Node* temp; // this will hold the old node that held the customer
    //if the customer whos service is complete is in the regular line do this
    if(regLine->getHead() != NULL)
    {
	if(oldCust->getCust() == regLine->getHead()->getContents())
	{
		totalServiceReg += oldCust->getCust()->getOrderTime();
		totalCustReg++;
		temp = regLine->pop();
		//if there is another customer in line start their service
		if(regLine->getCurrNum() > 0)
		{
			StartService temp(getRegLineHead(),oldCust->getTime());
			cout <<"Time " << oldCust->getTime() <<" Customer " << getRegLineHead()->getNum() << " begins service in regular line."<<endl;
			CompleteService* newComplete = temp.startComplete();
			totalWaitReg += newComplete->getWaitTime();
			eventQueue->insert(newComplete);
		}
		delete temp->getContents();//deletes the customer
		delete temp;
	}
    }
    //if the customer whos service is complete is in the express line do this
	if(priLine->getHead() != NULL)
	{
	    if(priLine->getHead()->getContents() == oldCust->getCust())
        {
	    totalServicePri += oldCust->getCust()->getOrderTime();
	    totalCustPri++;
		temp = priLine->pop();
		//if there is another customer in line start their service
		if(priLine->getCurrNum() > 0)
		{
			StartService temp(getPriLineHead(),oldCust->getTime());
			cout <<"Time "<<oldCust->getCust()->getTime()<<": Customer " << getPriLineHead()->getNum() << " begins service in express line."<<endl;
			CompleteService* newComplete = temp.startComplete();
			totalWaitPri += newComplete->getWaitTime();
			eventQueue->insert(newComplete);
		}
		delete temp; // deletes un-needed node
        }
	}
}

//inserts a customer into the correct line when their arrive event is read
//parameter is the customer
void Shop::insertCustToLine(Customer* cust)
{
	if(checkPriLine(cust))
    {
		priLine->insert(cust);
    }
	else
    {
		regLine->insert(cust);
    }
}

//this starts the service on the customer and creates a complete service event as well.
//the time param is the time of the start service event and the cust param is the customer
void Shop::addStartService(int time,Customer* cust)
{
	StartService* temp = new StartService(cust,time);
	eventQueue->insert(temp->startComplete());
}

//this checks to see if the customer ordered anything not on the express line list or if the line is even open
//param is the customer that this method is checking
bool Shop::checkPriLine(Customer* cust)
{

	if(!priLineOpen || cust->getPanNum() > 0 || cust->getIceNum() > 0)
		return false;
	else
		return true;
}

//creates and openLine event and inserts it intot he event queue
void Shop::openPriLine(int time)
{
	eventQueue->insert(new OpenLine(time));
}
//creates a close line event and insertes it into the event queue
void Shop::closePriLine(int time)
{
	eventQueue->insert(new CloseLine(time));
}
//pops and returns the next event to be dealt with in the main method also deletes unnecessary node
Event* Shop::popEvent()
{
    Node* currNode = eventQueue->pop();
    Event* currEvent = currNode->getContents();
    delete currNode;
	return currEvent;
}
//returns true if the event list is empty
bool Shop::eventListEmpty()
{
	if(eventQueue->getCurrNum() == 0)
		return true;
	else
		return false;
}
//returns the customer at the head of the regular line
Customer* Shop::getRegLineHead()
{
    if(regLine->getHead() == NULL)
        return NULL;
    else
        return (Customer*)regLine->getHead()->getContents();
}
//returns the node at the head of the regular line
Node* Shop::getRegHead()
{
    return regLine->getHead();
}
//returns the customer at the head of the express line
Customer* Shop::getPriLineHead()
{
    if(priLine->getHead() == NULL)
        return NULL;
    else
        return (Customer*)priLine->getHead()->getContents();
}
//when a openLine event is read from the event queue this method is called, it transfers the customers from the regular line to
//the express line and starts service to the new head of the express line
void Shop::openLine(int input)
{
    priLineOpen = true;
    Node* curr = regLine->getHead();
    if(curr != NULL)
    {
        curr = curr->getNext();
    while(curr != NULL)
    {
        if(checkPriLine((Customer*)curr->getContents()))
           {
            if(curr == regLine->getHead()->getNext() && priLine->getHead() == NULL)
            {
             cout << "Time " << input << ": Customer " << ((Customer*)curr->getContents())->getNum() << " begins service in express lane."<<endl;
             addStartService(input,(Customer*)curr->getContents());
            }

           Customer* temp = (Customer*)regLine->remove(curr->getContents());
           priLine->insert(temp);
           }
           curr = curr->getNext();
    }
    }
}

void Shop::printLines()
{
    regLine->printQueue();
    priLine->printQueue();
}

//called when a close line event is read from the event queue
void Shop::closeLine()
{
    priLineOpen = false;
}

//called at the end of the main class to print the statistics of the shop for the day
void Shop::printShop()
{
	cout << "Lane"<<setw(15)<<"Total"<<setw(15)<<"Total"<<setw(15)<<"Total"<<setw(15)<<"Average"<<setw(15)<<"Average"<<endl;
	cout <<"    "<<setw(15)<<"Customers"<<setw(15)<<"Service Time"<<setw(15)<<"Wait Time"<<setw(15)<<"Service Time"<<setw(15)<<"Wait Time"<<endl;
	cout << "-----------------------------------------------------------------------------"<<endl;
	cout <<"Regular"<<setw(10)<<totalCustReg<<setw(14)<< totalServiceReg <<setw(17)<<totalWaitReg<<setw(15)<<totalServiceReg/totalCustReg<<setw(15)<<totalWaitReg/totalCustReg<<endl;
    cout <<"Express"<<setw(10)<<totalCustPri<<setw(14)<< totalServicePri <<setw(17)<<totalWaitPri<<setw(15)<<totalServicePri/totalCustPri<<setw(15)<<totalWaitPri/totalCustPri<<endl;
}



