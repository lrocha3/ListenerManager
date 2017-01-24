/*
 * Phone.h
 *
 *  Created on: 23/01/2017
 *      Author: Luis Rocha
 */

#ifndef INC_PHONE_H_
#define INC_PHONE_H_

#include "Definitions.h"
#include "Listener.h"

class Phone: public ActivityToListen {
public:
	Phone(uint16_t id);
};

class OnePlus: public Phone {
public:
	OnePlus(uint16_t id);
};

class Huawei: public Phone {
public:
	Huawei(uint16_t id);
};

class Client: public Listener {
public:
	Client() {
	}
	;
	void PrintEvents();
	bool GetEventValue(uint8_t bitIndex);
};

#endif /* INC_PHONE_H_ */
