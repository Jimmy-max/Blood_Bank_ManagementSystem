#include <string>
#include "User.h"

#pragma once
using namespace std;

class Donor : public User
{
public:
	Donor(); // constructor

	//variables
	string suffersFromDisease;
	string other;
	string date_latest_donation;

	//functions - methods
	void reg(); // register
	void login();
	void updateAccount();
	void deleteAccount();
	void donationRequest();

	
	~Donor(); // destructor


};

