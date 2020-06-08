#pragma once
#include<iostream>

using namespace std;

class Time
{
	int hours, minutes, seconds;

public:
	Time(); 

	explicit Time(int h, int m, int s); 
	
	explicit Time(int seconds);
	
	Time operator-(const Time& other) const;	

	Time operator*(const Time& other) const;	

	Time operator/(const Time& other) const;	

	Time operator+(const Time& other) const;	

	bool operator>(const Time& other) const;	

	bool operator<(const Time& other) const;	

	bool operator==(const Time& other) const;	

	bool operator!=(const Time& other) const;
	
	bool operator>=(const Time& other) const;	

	bool operator<=(const Time& other) const;	

	void AddSecond();	

	void Print() const;

	void CorrectValues();
		
};



