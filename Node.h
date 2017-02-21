/*
 * Node.h
 *
 *  Created on: Feb 15, 2016
 *      Author: jonny
 */

#ifndef NODE_H_
#define NODE_H_
#include "Event.h"
#include <string>
#include <iostream>
using namespace std;

class Node {
public:
	Node(Event* input);
	virtual ~Node();
	Event* getContents();
	void setNext(Node* input);
	void setPrev(Node* input);
	Node* getNext();
	Node* getPrev();


private:
	Node* next;
	Node* prev;
	Event* contents;
};

#endif /* NODE_H_ */
