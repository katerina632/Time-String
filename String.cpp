#include "String.h"
#include "String.h"

String::String():length(0)
{
	str = nullptr;
}

String::String(int count, char symb) : length(count)
{
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = symb;
	}
	str[length] = 0;
}

String::String(const char* str)
{
	length = strlen(str);
	this->str = new char[length + 1];
	strcpy_s(this->str, length + 1, str);
}

String::String(const String& other)
{
	length = other.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, other.str);
}

String& String::operator=(const String& other)
{
	if (this == &other)
		return *this;

	if (str != nullptr)
		delete[] str;

	length = other.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, other.str);

	return *this;
}

String::~String()
{
	if (str != nullptr)
		delete[] str;
}

void String::Print() const
{
	cout << str << endl;
}

void String::operator+=(const char& symbol)
{
	++length;
	char* newStr = new char[length + 1]{};
	if (str != nullptr)
		strcpy_s(newStr, length, str);
	newStr[length - 1] = symbol;
	delete[]str;
	str = newStr;
}

void String::operator+=(const String& str)
{
	length = this->length + str.length;
	char* newStr = new char[length + 1];

	strcpy_s(newStr, length + 1, this->str);
	strcat_s(newStr, length + 1, str.str);

	delete[] this->str;
	this->str = newStr;
}

String String::operator+(const String& str) const
{
	String res(*this);
	res += str;
	return res;
}

String String::operator*(const String& str) const
{
	String res;
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < str.length; j++) {
			if (this->str[i] == str.str[j])
			{
				res += this->str[i];
			}
		}
	}
	return res;
}
