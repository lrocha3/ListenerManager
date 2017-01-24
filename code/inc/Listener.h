/*
 * Listener.h
 *
 *  Created on: 23/01/2017
 *      Author: Luis Rocha
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <cstring>
#include <stdio.h>
#include "Queue.h"
#include <mutex>

using namespace std;

class Listener {
private:

public:
	Listener();
	~Listener();
	void Events(uint16_t event);
	uint16_t GetEvents();
	virtual void PrintEvents();

private:
	mutex myMutex;
	uint16_t events; // each bit has one event
};

class ActivityToListen {
public:
	ActivityToListen(uint16_t id);
	~ActivityToListen();
	Queue<Listener> * GetMyListeners();
	void NotifyListeners();
private:
	Queue<Listener> * myListeners;
	uint16_t id;
};

#endif /* PERSON_H_ */
