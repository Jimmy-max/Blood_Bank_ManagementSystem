#include <string>
#include <regex>

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
	string password;
	int age;
	string  gender;
	string blood_type;

	static bool Email_check(string); // validate Email
	~User();// destructor
};

