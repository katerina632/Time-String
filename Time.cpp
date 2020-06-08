#include "Time.h"
#include "Time.h"

Time::Time(int seconds) 
{
	hours = seconds / 3600;
	minutes = (seconds - hours * 3600) / 60;
	this->seconds = seconds - hours * 3600 - minutes * 60;
}

Time::Time() : hours(0), minutes(0), seconds(0)
{
}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
{
	CorrectValues();
}

Time Time::operator-(const Time& other) const
{
	Time res(hours - other.hours, minutes - other.minutes, seconds - other.seconds);
	if (res.hours <= 0 || res.minutes <= 0 || res.seconds <= 0)
	{
		res.hours = 0;
		res.minutes = 0;
		res.seconds = 0;
	}
	return res;
}

Time Time::operator*(const Time& other) const
{
	return Time(hours * other.hours, minutes * other.minutes, seconds * other.seconds);
}

Time Time::operator/(const Time& other) const
{
	if (other.hours == 0 || other.minutes == 0 || other.seconds == 0)
	{
		return Time();
	}
	else {
		return Time(hours / other.hours, minutes / other.minutes, seconds / other.seconds);
	}
}

Time Time::operator+(const Time& other) const
{
	return Time(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
}

bool Time::operator>(const Time& other) const
{
	return (hours * 3600 + minutes * 60 + seconds > other.hours * 3600 + other.minutes * 60 + other.seconds);
}

bool Time::operator<(const Time& other) const
{
	return (hours * 3600 + minutes * 60 + seconds < other.hours * 3600 + other.minutes * 60 + other.seconds);
}

bool Time::operator==(const Time& other) const
{
	return (hours * 3600 + minutes * 60 + seconds == other.hours * 3600 + other.minutes * 60 + other.seconds);
}

bool Time::operator!=(const Time& other) const
{
	return (hours * 3600 + minutes * 60 + seconds != other.hours * 3600 + other.minutes * 60 + other.seconds);
}

bool Time::operator>=(const Time& other) const
{
	return (hours * 3600 + minutes * 60 + seconds >= other.hours * 3600 + other.minutes * 60 + other.seconds);
}

bool Time::operator<=(const Time& other) const
{
	return (hours * 3600 + minutes * 60 + seconds <= other.hours * 3600 + other.minutes * 60 + other.seconds);
}

void Time::AddSecond()
{
	seconds++;
	CorrectValues();
}

void Time::Print() const
{
	cout << hours << ":" << minutes << ":" << seconds << endl;
}

void Time::CorrectValues()
{
	if (seconds >= 60) {
		minutes = minutes + seconds / 60;
		while (seconds >= 60) {
			seconds = seconds - 60;
		}
	}
	if (minutes >= 60) {
		hours = hours + minutes / 60;
		while (minutes >= 60) {
			minutes = minutes - 60;
		}
	}
}

