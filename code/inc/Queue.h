/*
 * Queue.h
 *
 *  Created on: 22/01/2017
 *      Author: Luis Rocha
 */

#ifndef SRC_QUEUE_H_
#define SRC_QUEUE_H_

#include <cstddef>
#include <string.h>
#include <stdint.h>
#include <stdio.h>



template<class X> class QueueNode{
public:
	X * Data;
	QueueNode * Next;
};



template<class X> class Queue {
public:
	Queue();
	~Queue();
	bool AddToQueue(X * Data);
	void PrintQueue();
	/*Missing: RemoveFromQueue(X * Data) */
	QueueNode<X> * GetHead();
private:
	QueueNode<X> * Head;
	uint8_t Lenght;

};


#endif /* SRC_QUEUE_H_ */
