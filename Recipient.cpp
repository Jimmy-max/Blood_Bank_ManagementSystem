#include "Recipient.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "FileManager.h"
#include <map>
#include <iterator>
#include <stack>
#pragma warning(disable : 4996)



using namespace std;

Recipient::Recipient() {

}

void Recipient::reg() {

	cout << "pleas enter your id (It should be a number)" << endl;
	cin >> id;
	while (cin.fail())
	{
		cout << "     ERROR ,Please enter an ID using numbers only" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> id;
	}
	cout << "pleas enter your name " << endl;
	cin.ignore();
	getline(cin, name);
	cout << "pleas enter your email " << endl;
	cin >> mail;
	cout << "pleas enter your password " << endl;
	cin >> password;
	cout << "pleas enter your age " << endl;
	cin >> age;
	while (cin.fail())
	{
		cout << "     ERROR ,Please enter age using numbers only" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> age;
	}
	cout << "pleas enter your gender (female / male) " << endl;
	string g;
	cin >> g;
	string male;
	string female;
	int count = true;
	do
	{
		if (g == "female" || g == "male") {
			gender = g;
			count = false;
			break;
		}
		else 
		{
			cout << "     error,not available data pleas try again ?" << endl;
			cout << "pleas enter your gender (female / male) " << endl;
			cin >> g;
		}
	} while (count != false);
	cout << "Enter your blood type, please(-O, +O,- A, +A,-B,+B,+AB,-AB)" << endl;
	string B;
	cin >> B;
	int y = true;
	do
	{
		if (B == "-O" || B == "+O" || B == "-A" || B == "+A" || B == "-B" || B == "+B" || B == "+AB" || B == "-AB")
		{
			blood_type = B;
			y = false;
			break;
		}
		else 
		{
			cout << "     Incorrect blood type, please try again" << endl;
			cin >> B;
		}
	} while (y != false);

	cout << "Please enter the name of the hospital" << endl;
	cin >> hospital;
	cout << "Please enter the name of the Doctor responsible for the case " << endl;
	cin >> doc_of_case;
}

 

void Recipient::displayBloodData(vector<Donor>& donation) {
	map<string, int> m;
	map<string, stack<string>> m2;
	map<string, int>::iterator itr;
	for (size_t i = 0; i < donation.size(); i++)
	{
		m[donation[i].blood_type] += 1;
		m2[donation[i].blood_type].push(donation[i].date_latest_donation);
	}
	for (itr = m.begin(); itr != m.end(); ++itr)
	{
		cout << "Type: " << itr->first << " Quantity: " << itr->second << '\n';
		while (!m2[itr->first].empty())
		{
			cout << "Received Date: " << m2[itr->first].top() << " Expiry Date :" << calculateExpiryDate(m2[itr->first].top()) << " Days Left" << endl;
			m2[itr->first].pop();
		}
		
	}
}

string Recipient::calculateExpiryDate(string oldDate) {
	time_t curr_time;
	tm* curr_tm;
	char currentDate[50];
	time(&curr_time);
	curr_tm = localtime(&curr_time);
	strftime(currentDate, 50, "%F", curr_tm);
	return 0;
}


void Recipient::isBloodAvailable(vector<Donor>& donation,int index, vector<Recipient>& recipient) {
	bool isBloodAvailable = false;
	for (size_t i = 0; i < donation.size(); i++)
	{
		if (donation[i].blood_type == recipient[index].blood_type)
		{
			isBloodAvailable = true;
			break;
		}
	}
	if (isBloodAvailable)
	{
		cout << "Your Blood type is Available : " << recipient[index].blood_type << endl;
	}
	else
	{
		cout << "Your Blood type is Unavailable : " << recipient[index].blood_type << endl;
	}
}

void Recipient::requestAndConfirm(vector<Donor>& donation) {
	cout << "Enter Blood Type: "; string bloodType; cin >> bloodType;
	cout << "Enter Quantity: "; int quantity; cin >> quantity;

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
			string newpassword;
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

	// Wrong (remind her/ask why)
	//FileManager file; 
	//file.writeRecipient(datarecipient);
	
}

void Recipient::deleteAccount(vector<Recipient>& datarecipient, int index)
{

	datarecipient.erase(datarecipient.begin() + index);
}
