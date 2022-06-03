#pragma once
#ifndef CLOCK_H
#define CLOCK_H
#define _CRT_SECURE_NO_WARNINGS

//import libraries
#include<string>
#include<iostream>
#include <ctime>
#include <iomanip>

using namespace std;

class Clock
{
private:
	int hour;
	int minute;
	int second;

	void display12HourTime();
	void display24HourTime();
public:
	//Clock constructors
	Clock();
	Clock(int, int, int);

	void addSecond(int);
	void addMinute(int);
	void addHour(int);

	//Clock accessors
	string getAmPm();
	int getHour12();

	void displayClock();
};

#endif