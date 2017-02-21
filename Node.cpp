
     //
     // Author: Jonathan Redfern, 7748707
     //
     // REMARKS: This is the node class that will hold events for the priority queues
     //
     //-----------------------------------------


#include "Node.h"

Node::Node(Event* input) {
 contents = input;
 next = NULL;
 prev = NULL;
}

Node::~Node() {

}

void Node::setNext(Node* input)
{
	next = input;
}

void Node::setPrev(Node* input)
{
	prev = input;
}

Node* Node::getNext()
{
	return next;
}

Node* Node::getPrev()
{
	return prev;
}

Event* Node::getContents()
{
	return contents;
}

