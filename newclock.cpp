/*
*	Class to demonstrate operator overloading
*	Adapted from example in C++ Programming: From Problem Analysis to Problem Design by D.S. Malik
*/
#include "newclock.h"

NewClock::NewClock(int hrs, int mins, int secs)
{
	setTime(hrs, mins, secs);
}

void NewClock::setTime(int hrs, int mins, int secs)
{
	if (0 <= hrs && hrs < 24)
		hours = hrs;
	else
		hours = 0;

	if (0 <= mins && mins < 59)
		minutes = mins;
	else
		minutes = 0;

	if (0 <= secs && secs < 60)
		seconds = secs;
	else
		seconds = 0;
}

// Returns a string containing the time
std::string NewClock::getTimeStr()
{
	return (std::to_string(hours)+":"+std::to_string(minutes)+":"+std::to_string(seconds));
}

//	Overloads logical equality operator
bool NewClock::operator==(const NewClock& otherClock) const
{
	return(hours == otherClock.hours && minutes == otherClock.minutes && seconds == otherClock.seconds);
}

// Overloads less than or equal to
bool NewClock::operator<=(const NewClock& otherClock) const
{
	return( (hours <= otherClock.hours) ||
			(hours == otherClock.hours && minutes <= otherClock.minutes) ||
			(hours == otherClock.hours && minutes == otherClock.minutes  && seconds <= otherClock.seconds));
}

//	Overload pre-increment unary operator
NewClock NewClock::operator++()
{
	seconds++;
	if (seconds > 59)
	{
		seconds = 0;
		minutes++;
		if (minutes > 59)
		{
			minutes = 0;
			hours++;
			if (hours > 23)
				hours = 0;
		}
	}
	return *this;
}

NewClock NewClock::operator+(const NewClock& deltaTime)
{
	if (deltaTime.hours < 24 && deltaTime.minutes < 60 && deltaTime.seconds < 60)
	{
		seconds += deltaTime.seconds;
		if (seconds > 59)
		{
			seconds %= 60;
			minutes++;
		}
		minutes += deltaTime.minutes;
		if (minutes > 59)
		{
			minutes %= 60;
			hours++;
		}
		hours += deltaTime.hours;
		if (hours > 23)
			hours %= 24;
	}
	return *this;
}
