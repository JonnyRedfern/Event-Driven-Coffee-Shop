 //-----------------------------------------
     // NAME		: Jonathan Redfern
     //
     // REMARKS: This is an event driven simulation of a coffee shop. it reads a text file with events and times and orders
     // them in the event queue then starts and completes those events it then prints all of the statistics at the end
     //
     //-----------------------------------------
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <stdlib.h>
using namespace std;
#include "Event.h"
#include "Node.h"
#include "PriorityQueue.h"
#include "Customer.h"
#include "Arrival.h"
#include "CompleteService.h"
#include "StartService.h"
#include "Shop.h"
int main() {
	Shop coffeeShop;
	cout << "Please enter the file name."<<endl;
	string fileName;
	cin >> fileName;
	ifstream file(fileName.c_str());
	string line ;
	do{

        getline(file,line);

        if(!file.eof())
        {
		//this block of code breaks up the string read from the file
		char* temp = new char[line.length()+1];
		strcpy(temp,line.c_str());
		char* p = strtok(temp," ");
		char* time = p; // holds the time of the event in string version must be changed to int
		char* eventType = strtok(NULL," ");//this holds the type of event i.e ARRIVE or open/close lane
		int eventTime = atoi(time);//changes time to int from string
		if(strcmp(eventType,"ARRIVE")==0)
		{
				Customer* newCust = new Customer(eventTime);
				char* orderType = strtok(NULL," ");
				char* ordrCnt;//this will hold the string version of the order count
				int orderCount;//this will hold the actual int value of the number of items they want to order

				//this block of code adds all of the orders that the customer wanted

				while(orderType != NULL)
				{
					ordrCnt = strtok(NULL," ");
					orderCount = atoi(ordrCnt);
					newCust->addOrder(orderType,orderCount);
					orderType = strtok(NULL," ");
				}
				coffeeShop.addArrival(eventTime,newCust);
		}
        //if event being read is open
		else if(strcmp(eventType,"OPEN")==0)
        {
			coffeeShop.openPriLine(eventTime);
        }
        //else event will be close line
		else
        {
			coffeeShop.closePriLine(eventTime);
        }
    }

        Event* currEvent = coffeeShop.popEvent();//curr event being popped off from event list

        //iff currEvent that got popped off is an arrival event
        if(Arrival* arrive = dynamic_cast<Arrival*>(currEvent))
        {
            cout << "Time " << arrive->getTime() << ": Customer " << arrive->getCust()->getNum() << " arrives:";
            arrive->getCust()->printOrder();
            cout << " service time: " << arrive->getCust()->getOrderTime() << endl;

            coffeeShop.insertCustToLine(arrive->getCust());

            if(coffeeShop.getRegLineHead() == arrive->getCust())
            {
                cout << "Time " << arrive->getTime() << ": Customer " << arrive->getCust()->getNum() << " begins service in regular lane."<<endl;
                coffeeShop.addStartService(arrive->getTime(),arrive->getCust());
            }
            if(coffeeShop.getPriLineHead() == arrive->getCust())
            {
                cout << "Time " << arrive->getTime() << ": Customer " << arrive->getCust()->getNum() << " begins service in express lane."<<endl;
                coffeeShop.addStartService(arrive->getTime(),arrive->getCust());
            }
        }
        //else if currEvent being popped off was a complete service event
        else if(CompleteService* complete = dynamic_cast<CompleteService*>(currEvent))
        {
            complete->printStatus();
            coffeeShop.popCustLine(complete);
        }
        //else if currEvent being popped off was a OpenLine event
        else if(OpenLine* open = dynamic_cast<OpenLine*>(currEvent))
        {
            cout << "Time " << currEvent->getTime() << ": Express lane open."<<endl;
            coffeeShop.openLine(currEvent->getTime());
        }
        //else if currEvent being popped off was a CloseLine event
        else if(CloseLine* close = dynamic_cast<CloseLine*>(currEvent))
        {
            cout << "Time " << currEvent->getTime() << ": Express lane close."<<endl;
            coffeeShop.closeLine();
        }
     delete currEvent; //delete event now that it is done with it
	}while(!coffeeShop.eventListEmpty());
    cout << endl;
	coffeeShop.printShop();
	file.close();
	return 0;
}








