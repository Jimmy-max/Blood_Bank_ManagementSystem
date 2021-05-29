#include <string>
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
	void updateAccount();
	void deleteAccount();
	bool isBloodAvailable();
	void displayBloodData();
	void requestAndConfirm();

	~Recipient(); //destructor
};

