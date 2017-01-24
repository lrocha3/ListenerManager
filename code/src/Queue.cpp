/*
 * Queue.cpp
 *
 *  Created on: 22/01/2017
 *      Author: Luis Rocha
 */

#include <Listener.h>
#include "Queue.h"

/* This template can be of type Listener or int. */

template class Queue<Listener> ;
template class QueueNode<Listener> ;

template class Queue<int> ;
template class QueueNode<int> ;

template<class X>
Queue<X>::Queue() {
	Head = NULL;
	Lenght = 0;
}

template<class X>
Queue<X>::~Queue() {

	QueueNode<X> * Current, *Auxiliar;

	for (Current = Head; Current != NULL;) {
		Auxiliar = Current->Next;
		delete Current;
		Current = Auxiliar;
	}

}

template<class X>
bool Queue<X>::AddToQueue(X *Data) {

	QueueNode<X> * NewQueueNode = new QueueNode<X>();
	if (!NewQueueNode || !Data) {
		return false;
	}

	NewQueueNode->Data = Data;

	/* Add the Node to the Queue*/

	NewQueueNode->Next = Head;
	Head = NewQueueNode;
	Lenght++;
	return true;

}

template<class X>
void Queue<X>::PrintQueue() {

	for (QueueNode<X> * Current = Head; Current != NULL; Current =
			Current->Next) {
		printf("%p\n", Current->Data);
	}
}

template<class X>
QueueNode<X> * Queue<X>::GetHead() {
	return Head;
}

