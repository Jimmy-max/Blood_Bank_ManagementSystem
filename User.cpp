#include "User.h"
#include <regex>

// constructor
User::User() {
	int id;
	string name;
	string mail;
	string password;
	int age;
	string  gender;
	string blood_type;
}


 bool User::Email_check(string email)
{
	const regex pattern("(\\w+)(\\.|_)?(\\w*)@gmail.com");
	return regex_match(email, pattern);
}

// destructor
User::~User() {

}