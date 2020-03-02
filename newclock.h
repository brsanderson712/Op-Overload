/*
*	Class to demonstrate operator overloading
*	Adapted from example in C++ Programming: From Problem Analysis to Problem Design by D.S. Malik
*/
#ifndef NEWCLOCK_H
#define NEWCLOCK_H

#include <iostream>
#include <string>

class NewClock
{
public:
	NewClock(int hrs = 0, int mins = 0, int secs = 0);
	void setTime(int, int, int);
	std::string getTimeStr();
	bool operator==(const NewClock&) const;
	bool operator<=(const NewClock&) const;
	NewClock operator++();
	NewClock operator+(const NewClock&);
private:
	int hours;
	int minutes;
	int seconds;
};

#endif
