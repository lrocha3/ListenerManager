/*
 * Person.h
 *
 *  Created on: 22/10/2016
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
