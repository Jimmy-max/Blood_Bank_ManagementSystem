#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "Recipient.h"
#include "Donor.h"
#pragma once


using namespace std;
class FileManager
{
public:
	void readDonor(vector<Donor>& donor);
	void writeDonor(vector<Donor>);
	void readRecipient(vector<Recipient>& recipient);
	void writeRecipient(vector<Recipient>);
	void readDonations(vector<Donor>& donor);
	void writeDonations(vector<Donor>);
};

