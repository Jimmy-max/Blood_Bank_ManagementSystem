#include <string>
#pragma once

using namespace std;
class User
{
public:
	User(); // constructor

	//variables
	int id;
	string name;
	string mail;
	int password;
	int age;
	string  gender;
	string blood_type;

	~User();// destructor
};

