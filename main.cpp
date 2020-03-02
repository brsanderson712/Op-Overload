/*
*	Class to demonstrate operator overloading
*	Adapted from example in C++ Programming: From Problem Analysis to Problem Design by D.S. Malik
*/
#include <iostream>
#include <string>
#include "newclock.h"

int main()
{
	NewClock clock1{12, 0, 0};
	NewClock clock2;

	std::cout << "Init Clock1: " << clock1.getTimeStr() << "\n";
	std::cout << "Init Clock2: " << clock2.getTimeStr() << "\n";

	srand(1000);
	// Advance both clocks by a random amount
	int t1 = rand();
	int t2 = rand();
	for(int i = 0; i < t1; i++)	
		++clock1;
	for(int i = 0; i < t2; i++)	
		++clock2;

	std::cout << "Advanced Clock1: " << clock1.getTimeStr() << "\n";
	std::cout << "Advanced Clock2: " << clock2.getTimeStr() << "\n";

	if (clock1 <= clock2 && !(clock1==clock2))
		std::cout << "Clock1 is earlier than Clock2\n";
	if (!(clock1 <= clock2))
		std::cout << "Clock1 is later than Clock2\n";
	if (clock1 == clock2)
		std::cout << "Clock1 and Clock2 have the same time\n";

	// Create a time increment
	NewClock timeDelta{3, 15,0};

	// Advance both clocks by the time increment
	clock1 = clock1 + timeDelta;
	clock2 = clock2 + timeDelta;
	std::cout << "Summed Clock1: " << clock1.getTimeStr() << "\n";
	std::cout << "Summed Clock2: " << clock2.getTimeStr() << "\n";

	system("pause");
}