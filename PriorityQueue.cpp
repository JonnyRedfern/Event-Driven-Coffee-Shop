
     //
     // Author: Jonathan Redfern, 7748707
     //
     // REMARKS: This class is used for the event queue, the regular line, and the priority line in the Shop class
     //
     //-----------------------------------------


#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {
	currNum = 0;
	head = NULL;
	tail = NULL;
}

PriorityQueue::~PriorityQueue() {
	Node* curr = head;
	Node* prev;
	while(curr != NULL)
    {
        prev = curr;
        curr = curr->getNext();
        delete prev;
    }
    delete prev;
}

//this inserts a new event into the pri queue
void PriorityQueue::insert(Event* input)
{
	//special case for when queue is empty
	if(currNum == 0)
	{
		head = new Node(input);
		tail = head;
	}
	else
	{
		Node* curr = head;
		Node* temp = new Node(input);

		while(curr != NULL && input->getTime() >= curr->getContents()->getTime())
			curr = curr->getNext();
		if(curr == head)
		{
		  temp->setNext(head);
		  head->setPrev(temp);
		  head = temp;
		}
		else if(curr == NULL)
		{
			tail->setNext(temp);
			temp->setPrev(tail);
			tail = temp;
		}
		else
		{
			temp->setNext(curr);
			temp->setPrev(curr->getPrev());
			curr->getPrev()->setNext(temp);
			curr->setPrev(temp);
		}
	}
	currNum++;
}

//this pops off the head of the queue and returns the node
Node* PriorityQueue::pop()
{
	if(currNum == 0)
		return NULL;
	else
	{
		Node* temp = head;
		head = head->getNext();
		currNum--;
		return temp;
	}
}

//this searches teh list and removes a desired event, used for when changing customers from one line to another
//this event returns the event that it removed and NULL if it was not found
Event* PriorityQueue::remove(Event* input)
{
    Node* curr = head;
    while(curr != NULL)
    {
        if(curr->getContents() == input)
        {
            Node* temp;
            if(curr == head)
            {
                temp = head;
                pop();
            }
            else if(curr == tail)
            {
                temp = tail;
                tail->getPrev()->setNext(NULL);
                tail = tail->getPrev();
            }
            else
            {
                temp = curr;
                curr->getPrev()->setNext(curr->getNext());
                curr->getNext()->setPrev(curr->getPrev());
            }
            currNum--;
            Event* tempCont = temp->getContents();
            return tempCont;
        }
        curr = curr->getNext();
    }
    return NULL;
}

Node* PriorityQueue::getHead()
{
	return head;
}

Node* PriorityQueue::getTail()
{
	return tail;
}

int PriorityQueue::getCurrNum()
{
	return currNum;
}

void PriorityQueue::printQueue()
{
	Node* curr = head;

	while(curr != NULL)
	{
		if(curr->getNext() == NULL)
			cout << curr->getContents()->getTime()<<endl;
		else
			cout << curr->getContents()->getTime()<<", ";
		curr = curr->getNext();
	}
}




