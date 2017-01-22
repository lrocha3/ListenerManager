/*
 * Person.cpp
 *
 *  Created on: 22/10/2016
 *      Author: Luis Rocha
 */

#include "Listener.h"

ActivityToListen::ActivityToListen(uint16_t id) {

	myListeners = new Queue<Listener>();
	this->id = id;
}

ActivityToListen::~ActivityToListen() {
	if (myListeners) {
		delete myListeners;
	}
}

Queue<Listener> * ActivityToListen::GetMyListeners() {
	return this->myListeners;
}

void ActivityToListen::NotifyListeners() {
	for(QueueNode<Listener> * Current = myListeners->GetHead(); Current != NULL; Current = Current->Next){
		Current->Data->Events(this->id);
	}
}

Listener::Listener() {
	events = 0U;
}

Listener::~Listener() {

}

void Listener::Events(uint16_t event){
	myMutex.lock();
	this->events |= event;
	printf("%p | %u\n", this, this->events);
	myMutex.unlock();

}
