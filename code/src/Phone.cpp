/*
 * Phone.cpp
 *
 *  Created on: 22/10/2016
 *      Author: Luis Rocha
 */

#include "Phone.h"

Phone::Phone(uint16_t id) :
		ActivityToListen(id) {
}

OnePlus::OnePlus(uint16_t id) :
		Phone(id) {
}

Huawei::Huawei(uint16_t id) :
		Phone(id) {
}

bool Client::GetEventValue(uint8_t bitIndex) {

	if (bitIndex > 16) {
		return false;
	}
	uint16_t events = this->GetEvents();
	bool result = (bool) ((events >> (bitIndex - 1)) & 0x0001);
	return result;

}

void Client::PrintEvents() {

	if (GetEventValue(ONE_PLUS_3T)) {
		printf("%p - One Plus on sales!\n", this);
	}

	if (GetEventValue(HUAWEI_P10)) {
		printf("%p - Huawei on sales!\n", this);
	}

}
