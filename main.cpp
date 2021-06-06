#include <iostream>
#include "FileManager.h"
#include <ctime>
#include <chrono>
#include <iomanip>
#pragma warning(disable : 4996)

#include <tabulate/table.hpp>
using namespace tabulate;
using namespace std;

int main() {
	
	//Store Logic
	vector<Donor> vDonor;
	vector<Donor> vDonations;
	vector<Recipient> vRecipient;
	FileManager file;
	file.readDonor(vDonor);
	file.readRecipient(vRecipient);
	file.readDonations(vDonations);

	////Start here!!!
	while (true)
	{
		cout << "                              Welcome to the Blood Bank Management system                              \n " << endl;
		cout << "Please enter a choice: \n " << endl;
		cout << "to login , Please press  1:" << endl;
		cout << "if you a new user to register data, Please press  2:" << endl;
		cout << "If you want to Exit press  3 :" << endl;
		int choice; cin >> choice;

		// main choices
		if (choice == 1)
		{
			while (true)
			{
				cout << "                              Welcome in login page                              \n " << endl;
				cout << "if you a Donor ,please press : 1" << endl;
				cout << "if you a Recipient ,please press : 2" << endl;
				cout << "if you want to back ,please press : 3" << endl;
				int choice; cin >> choice;
				int index = -1;
				if (choice == 1)
				{
					// Donor Body
					index = Donor::login(vDonor);
					while (index !=-1)
					{
						cout << "                              Welcome in Donor page                              \n " << endl;
						cout << "To update your account ,please press : 1" << endl;
						cout << "To delete your account ,please press : 2" << endl;
						cout << "To make your donation request ,please press : 3" << endl;
						cout << "To logout ,please press : 4" << endl;
						int choice; cin >> choice;
						if (choice == 1)
						{
							Donor::updateAccount(vDonor, index);
						}
						else if (choice == 2)
						{
							Donor::deleteAccount(vDonor, index);
							index = -1;
						}
						else if (choice == 3)
						{
							Donor::donationRequest(vDonor, index,vDonations);
						}
						else if (choice == 4)
						{
							index = -1;
						}
						else
						{
							cout << " Choice is not available ,please try again " << endl;
						}
					}
				}
				else if (choice == 2)
				{
					// Recipient Body
					cout << "                              Welcome in Recipient page                              \n " << endl;
					index = Recipient::login(vRecipient);
					while (index!=-1)
					{
						cout << "To update your account ,please press : 1" << endl;
						cout << "To delete your account ,please press : 2" << endl;
						cout << "To check if your Blood is Available ,please press : 3" << endl;
						cout << "To display all Blood Data ,please press : 4" << endl;
						cout << "To request and Confirm ,please press : 5" << endl;
						cout << "To logout ,please press : 6" << endl;
						int choice; cin >> choice;
						if (choice == 1)
						{
							Recipient::updateAccount(vRecipient, index);
						}
						else if (choice == 2)
						{
							Recipient::deleteAccount(vRecipient, index);
							index = -1;
						}
						else if (choice == 3)
						{
							Recipient::isBloodAvailable(vDonations,index,vRecipient);
						}
						else if (choice == 4)
						{
							Recipient::displayBloodData(vDonations);
						}
						else if (choice == 5)
						{
							Recipient::requestAndConfirm(vDonations);
						}
						else if (choice == 6)
						{
							index = -1;
						}
						else
						{
							cout << " Choice is not available ,please try again " << endl;
						}
					}
				}
				else if (choice == 3)
				{
					break;
				}
				else 
				{
					cout << " Choice is not available ,please try again " << endl;
				}
			}
		}

		else if (choice == 2)
		{
			while (true)
			{
				cout << "                              Welcome in Registration page                              \n " << endl;
				cout << "if you a Donor ,please press : 1" << endl;
				cout << "if you a Recipient ,please press : 2" << endl;
				cout << "if you want to back ,please press : 3" << endl;
				int choice; cin >> choice;
				if (choice == 1)
				{
					cout << "                              Welcome in Donor Registration page                              \n " << endl;
					Donor donor;
					donor.reg();
					vDonor.push_back(donor);
					cout << "         Registration was successful      " << endl;
					cout << "       ###############################################################################################      " << endl;

				}
				else if (choice == 2)
				{
					cout << "                              Welcome in Recipient Registration page                              \n " << endl;
					Recipient recipient;
					recipient.reg();
					vRecipient.push_back(recipient);
					cout << "         Registration was successful      " << endl;
					cout << "       ###############################################################################################      " << endl;

				}
				else if (choice == 3)
				{
					break;
				}
				else
				{
					cout << " Choice is not available ,please try again " << endl;
				}
			}
		}

		else if (choice == 3)
		{
			cout << "                  ######### The exit was successful ,Thank you for using system ##########               " << endl;
			break;
		}
		else
		{
			cout << " Choice is not available ,please try again " << endl;
		}
	}


	
	


	//End here!!!!
	file.writeRecipient(vRecipient);
	file.writeDonor(vDonor);
	file.writeDonations(vDonations);
}



