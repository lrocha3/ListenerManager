//============================================================================
// Name        : Main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <Listener.h>
#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

int main(void) {

	ActivityToListen ActivityOne(2U);
	ActivityToListen ActivityTwo(4U);

	Listener A;
	Listener B;

	printf("A: %p B: %p\n", &A, &B);

	ActivityOne.GetMyListeners()->AddToQueue(&A);
	ActivityOne.GetMyListeners()->AddToQueue(&B);

	ActivityTwo.GetMyListeners()->AddToQueue(&B);


	ActivityOne.NotifyListeners();
	ActivityTwo.NotifyListeners();


	return EXIT_SUCCESS;
}
