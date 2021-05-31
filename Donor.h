#include <string>
#include <vector>
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
	static void donationRequest(vector<Donor> donor, int index, vector<Donor>& donations);

	
	~Donor(); // destructor


};

