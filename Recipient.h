#include <string>
#include <vector>
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
	bool isBloodAvailable();
	void displayBloodData();
	void requestAndConfirm();

	~Recipient(); //destructor
};


