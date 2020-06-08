#include<iostream>
#include "Time.h"
#include "String.h"


using namespace std;

int main() {

	//Time
	Time t1(5555);
	t1.Print();
	
	Time t2(1, 122, 59);
	
	t2.Print();	
	t2.AddSecond();
	t2.Print();

	Time t3;
	t3 = t1 + t2;
	t3.Print();

	t3 = t1 - t2;
	t3.Print();

	t3 = t2 / t1;
	t3.Print();

	if (t1 > t2) {
		cout << "t1 is bigger! " << endl;
	}
	else {
		cout << "t2 is bigger! " << endl;

	}

	if (t1 != t2) {
		cout << "t1 != t2 " << endl;
	}
	else {
		cout << "t2=t1 " << endl;
	}

	//String
	String str1("Hello");
	str1.Print();

	String str2(3, '!');
	str2.Print();

	if (str1 != str2) {
		cout << "str1 != str2" << endl;
	}	

	str2 = "Hello";

	if (str1 == str2) {
		cout << "str1=str2" << endl;
	}
	else {
		cout << "str1 != str2" << endl;
	}

	str2 = "Aloha";

	if (str1 > str2) {
		cout << "str1>str2" << endl;
	}
	else {
		cout << "str1 < str2" << endl;
	}

	String str3;
	str3 = str1 + str2;
	str3.Print();

	str1 = "asde2";
	str2 = "gds32";
	str3 = str1 * str2;
	str3.Print();


	system("pause");
	return 0;
}