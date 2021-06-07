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
	bool date_check(string); // validate Email
	void reg(); // register
	static int login(vector<Donor>& dataDonar);
	static void updateAccount(vector<Donor>& dataDonar, int index);
	static void deleteAccount(vector<Donor>& dataDonar, int index);
	static void donationRequest(vector<Donor>& donor, int index, vector<Donor>& donations);

	
	~Donor(); // destructor


};

