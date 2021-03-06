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
	void reg(vector<Recipient>& vRecipients); // register
	static int login(vector<Recipient>& datarecipient);
	static void updateAccount(vector<Recipient>& datarecipient , int index);
	static void deleteAccount(vector<Recipient>& datarecipient, int index);
	static void isBloodAvailable(vector<Donor>& donation, int index, vector<Recipient>& recipient);
	static void displayBloodData(vector<Donor>& donation);
	static void requestAndConfirm(vector<Donor>& donation, int index, vector<Recipient>& recipient);
	static int aski(char z);

	static string calculateExpiryDate(string s);

	~Recipient(); //destructor
};


