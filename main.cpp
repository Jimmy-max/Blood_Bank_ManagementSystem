#include <iostream>
#include "FileManager.h"

using namespace std;
int main() {
	//Store Logic
	vector<Donor> vDonor;
	vector<Recipient> vRecipient;
	FileManager file;
	file.readDonor(vDonor);
	file.readRecipient(vRecipient);

	//Start here!!!

	Donor donor;
	donor.reg();
	vDonor.push_back(donor);
	//Recipient recipient;
	//recipient.reg();
	//vRecipient.push_back(recipient);


	//End here!!!!
	file.writeRecipient(vRecipient);
	file.writeDonor(vDonor);
}



