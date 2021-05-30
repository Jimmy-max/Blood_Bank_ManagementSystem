#include "Recipient.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "FileManager.h"


using namespace std;

Recipient::Recipient() {

}

void Recipient::displayBloodData() {

}


bool Recipient::isBloodAvailable() {
	return 0;
}

void Recipient::requestAndConfirm() {

}

Recipient::~Recipient() {

}

void Recipient::updateAccount(vector<Recipient>& datarecipient, int index)
{

	char c = 'y';
	while (c=='y')
	{
		cout << "Enter number to updata \n 1-Password  \n 2-Age \n 3-Hospital \n 4-Your Doctor \n 5-Done \n";
		int choice;
		cin >> choice;
		cout << " \n-----------------------------\n";
		if (choice == 1)
		{
			cout << "Enter your New password \n";
			int newpassword;
			cin >> newpassword;
			datarecipient[index].password = newpassword;
			cout << " \n-----------------------------\n";

		}
		else if (choice == 2)
		{
			cout << "Enter your New age \n";
			int newage;
			cin >> newage;
			datarecipient[index].age = newage;
			cout << " \n-----------------------------\n";
		}
		else if (choice == 3)
		{

			cout << "Enter your New Hospital \n";
			string newhospital;
			cin >> newhospital;
			datarecipient[index].hospital = newhospital;
			cout << " \n-----------------------------\n";
		}
		else if (choice == 4)
		{
			cout << "Enter your New doctor \n";
			string newdector;
			cin >> newdector;
			datarecipient[index].doc_of_case = newdector;
			cout << " \n-----------------------------\n";
		}
		else if (choice == 5)
		{
			break;
		}
		else
		{
			cout << "You enter wrong number";
		}

		cout << "Do you want to make anthor update ? (y/n) \n";
		cin >> c;
		cout << " \n-----------------------------\n";
	}

	cout << "update successful \n";
	cout << "-----------------------------\n";

	FileManager file; 
	file.writeRecipient(datarecipient);
	
}