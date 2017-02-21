/*
 * PriorityQueue.h
 *
 *  Created on: Feb 15, 2016
 *      Author: jonny
 */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_
#include <string>
#include <iostream>
#include "Node.h"
using namespace std;

class PriorityQueue {
public:
	PriorityQueue();
	virtual ~PriorityQueue();
	Node* getHead();
	Node* getTail();
	Event* remove(Event* input);
	void insert(Event* input);
	Node* pop();
	int getCurrNum();
	void printQueue();
private:
	Node* head;
	Node* tail;
	int currNum; //curr number of nodes in list
};

#endif /* PRIORITYQUEUE_H_ */
