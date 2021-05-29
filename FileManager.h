#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "Donor.h"
#include "Recipient.h"
#pragma once


using namespace std;
class FileManager
{
public:
	void readDonor(vector<Donor>& donor);
	void writeDonor(vector<Donor>);
	void readRecipient(vector<Recipient>& recipient);
	void writeRecipient(vector<Recipient>);
};

