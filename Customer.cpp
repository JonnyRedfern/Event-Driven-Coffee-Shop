
     // Author: Jonathan Redfern, 7748707
     //
     // REMARKS: This class is used whenever a new customer enters the store it holds all the information on a customer
     //
     //-----------------------------------------


#include "Customer.h"
int Customer::custNum = 1; // static var that will keep track of the total number of customers that have entered the store

Customer::Customer(int input):Event(input) {
	orderTime = 0;
	//these vars keep track of how many of what product this customer ordered
	cofNum = 0;
	teNum = 0;
	bagNum = 0;
	iceNum = 0;
	panNum = 0;
	donNum = 0;
	num = custNum;
	custNum++;
}

Customer::~Customer() {
	// TODO Auto-generated destructor stub
}

int Customer::getOrderTime()
{
	return orderTime;
}

int Customer::getNum()
{
	return num;
}

//this adds an order for the customer, the input will be what they ordered and the num is how many
void Customer::addOrder(string input,int num)
{
	if(input == "COFFEE")
	{
		cofNum = num;
		orderTime += COF*num;
	}
	else if(input == "BAGEL")
	{
		bagNum = num;
		orderTime += BAG*num;
	}
	else if(input == "DONUT")
	{
		donNum = num;
		orderTime += DON*num;
	}
	else if(input == "TEA")
	{
		teNum = num;
		orderTime += TE*num;
	}
	else if(input == "ICEDCAPP")
	{
		iceNum = num;
		orderTime += ICE*num;
	}
	else
	{
		panNum = num;
		orderTime += PAN*num;
	}
}

void Customer::printOrder()
{
	if(cofNum > 0)
		cout << "COFFEE: " << cofNum << " ";
	if(bagNum > 0)
		cout << "BAGEL: " << bagNum << " ";
	if(donNum > 0)
		cout << "DONUT: " << donNum << " ";
	if(teNum > 0)
		cout << "TEA: " << teNum << " ";
	if(iceNum > 0)
		cout << "ICECAPP: " << iceNum << " ";
	if(panNum > 0)
		cout << "PANNINI: " << panNum << " ";

}

int Customer::getPanNum()
{
    return panNum;
}

int Customer::getIceNum()
{
    return iceNum;
}

