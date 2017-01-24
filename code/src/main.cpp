//============================================================================
// Name        : Main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : ListenerManager to handle events.
//============================================================================

#include <Listener.h>
#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"
#include "Definitions.h"
#include "Phone.h"

void exampleOne() {
	printf("Example One:\n");
	ActivityToListen ActivityOne(2U);
	ActivityToListen ActivityTwo(4U);

	Listener A;
	Listener B;

	printf("Listener A: %p Listener B: %p\n", &A, &B);

	ActivityOne.GetMyListeners()->AddToQueue(&A);
	ActivityOne.GetMyListeners()->AddToQueue(&B);

	ActivityTwo.GetMyListeners()->AddToQueue(&B);

	ActivityOne.NotifyListeners();
	ActivityTwo.NotifyListeners();

	A.PrintEvents();
	B.PrintEvents();
}

void exampleTwo() {
	printf("\nExample Two:\n");

	OnePlus phone_one(ONE_PLUS_3T);
	Huawei phone_two(HUAWEI_P10);

	Client luis;
	Client peter;

	Listener B;

	printf("Client luis: %p Client peter: %p\n", &luis, &peter);

	phone_one.GetMyListeners()->AddToQueue(&peter);
	phone_two.GetMyListeners()->AddToQueue(&luis);

	phone_one.GetMyListeners()->AddToQueue(&luis);

	phone_one.NotifyListeners();
	phone_two.NotifyListeners();

	luis.PrintEvents();
	peter.PrintEvents();

}

int main(void) {

	exampleOne();
	exampleTwo();

	return EXIT_SUCCESS;
}
