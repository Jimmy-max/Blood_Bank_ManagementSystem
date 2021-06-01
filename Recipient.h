#include <string>
#include <vector>
#include "Donor.h"
#include "User.h"

#pragma once

using namespace std;
class Recipient : public User
{
public:
	Recipient(); // constructor

	//variables
	string hospital;
	string doc_of_case;

	//functions - methods
	void reg(); // register
	void login();
	void updateAccount(vector<Recipient>& datarecipient , int index);
	void deleteAccount(vector<Recipient>& datarecipient, int index);
	static void isBloodAvailable(vector<Donor>& donation, int index, vector<Recipient>& recipient);
	static void displayBloodData(vector<Donor>& donation);
	void requestAndConfirm(vector<Donor>& donation);
	static string calculateExpiryDate(string s);

	~Recipient(); //destructor
};


