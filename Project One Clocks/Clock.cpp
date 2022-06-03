#include "Clock.h"

//default Constructor
Clock::Clock()
{
	time_t now = time(0); //gets current Time
	tm* ltm = localtime(&now); //converts current Time to struct tm type

	this->hour = ltm->tm_hour;
	this->minute = ltm->tm_min;
	this->second = ltm->tm_sec;
}


Clock::Clock(int hour, int min, int sec)
{
	this->hour = hour;
	this->minute = min;
	this->second = sec;
}

void Clock::addHour(int hour = 1)
{
	//add hour to clock looping to 0 if it reaches 23
	this->hour++;
	if (this->hour > 23) {
		this->hour = 0;
	}
}

void Clock::addMinute(int min = 1)
{
	//add minute to clock up to 59 minutes
	this->minute++;
	if (this->minute > 59) {
		this->minute = 0;
		this->hour++;
		if (this->hour > 23) { //change the hour if minutes is at 59
			this->hour = 0;
		}
	}

}

void Clock::addSecond(int sec = 1)
{
	//add seconds to clock up to 59 seconds
	this->second++;
	if (this->second > 59) {
		this->second = 0;
		this->minute++;
		if (this->minute > 59) { //change the minute if seconds is at 59 
			this->minute = 0;
			this->hour++;
			if (this->hour > 23) { //change hour if both seconds and minutes are at 59
				this->hour = 0;
			}
		}
	}
}


// take the 24 hour format and convert it to 12 hour format 
int Clock::getHour12()
{
	int hour12;
	if (this->hour == 0) { //set hour to 12 if 24 hour format is at 0
		hour12 = 12;
	}
	else if (this->hour > 12) { //convert 24 hour format to 12 if it's greater than 12
		hour12 = this->hour - 12;
	}
	else {
		hour12 = this->hour;
	}
	return hour12;

}

// get whether it is AM or PM based off 24 hour clock
string Clock::getAmPm()
{
	return this->hour >= 12 ? "PM" : "AM";
}




// display 12 hour clock
void Clock::display12HourTime()
{
	cout.fill('0');
	cout << setw(2) << this->getHour12() << ":" << setw(2) << this->minute << ":" << setw(2) << this->second
		<< " " << this->getAmPm();
}

// display 24 hour clock
void Clock::display24HourTime()
{
	cout.fill('0');
	cout << setw(2) << this->hour << ":" << setw(2) << this->minute << ":" << setw(2) << this->second;
}

// display both clocks formatted
void Clock::displayClock()
{
	cout << "**************************" << "     " << "**************************\n";
	cout << "*      12-Hour Clock     *" << "     " << "*      24-Hour Clock     *\n";
	cout << "*      "; this->display12HourTime();
	cout << "       *     *        ";
	this->display24HourTime(); cout << "        *\n";
	cout << "**************************" << "     " << "**************************\n";
}