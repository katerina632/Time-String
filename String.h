#pragma once
#include<iostream>

using namespace std;
class String
{
private:
	char* str; 
	int length;	

public:
	String();	
	
	String(int count, char symb); 	

	String(const char* str);	

	String(const String& other);	

	String& operator=(const String& other);	

	~String();	

	void Print() const;

	void operator+=(const char& symbol);

	void operator+=(const String& str);	

	String operator+(const String& str) const;	

	String operator*(const String& str) const;	

	bool operator==(const String& other) const
	{
		return strcmp(str, other.str) == 0;	
	}

	bool operator!=(const String& other) const
	{
		return strcmp(str, other.str) != 0;
	}

	bool operator>(const String& other) const
	{
		return strcmp(str, other.str) > 0;
	}

	bool operator<(const String& other) const
	{
		return strcmp(str, other.str) < 0;
	}
};

