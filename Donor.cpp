#include "Donor.h"
#include <iostream>

using namespace std;

Donor::Donor() {

}

void Donor::reg()
{
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
	cout << "pleas enter your e-mail " << endl;
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
		if (g == "female" || g == "male")
		{
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


	cout << "If you have a chronic illnes,  like(blood pressure disorders, thyroid disease, diabetes ,cancer, heart disorders,hepatitis) Please write down these disease" << endl;
	cout << "If you do not have any disease, write (NO)" << endl;
	string d;  cin >> d;
	int k = true;
	do {
		if (d == "blood pressure disorders" || d == "thyroid disease" || d == "diabetes " || d == "cancer" || d == "heart disorders" || d == "hepatitis" || d == "NO")
		{
			suffersFromDisease = d;
			k = false;
			break;
		}
		else
		{
			cout << "     same thing is wrong ,please try again ?!" << endl;
			cin >> d;
		}

	} while (k != false);
	int t = true;
	do
	{
		int f;
		cout << "If you have other diseases or take any medicine, please press 1  " << endl;
		cout << "If you are not suffering from any other diseases, please press 2  " << endl;
		cin >> f;
		if (f == 1)
		{
			cout << "Please enter this disease here " << endl;
			cin >> other;
			cout << "pleas enter your date latest donation,like :day/month/year " << endl;
			cin.ignore();
			getline(cin, date_latest_donation);
			t = false;
			break;
		}
		else if (f == 2)
		{
			cout << "pleas enter your date latest donation ,like :day/month/year" << endl;
			cin.ignore();
			getline(cin, date_latest_donation);
			t = false;
			break;
		}
		else
		{
			cout << " Choice is not available ,please try again " << endl;
			break;

		}
	} while (t != false);
	
}

void Donor::login()
{

}
void Donor::updateAccount()
{
}
void Donor::deleteAccount()
{
}
void Donor::donationRequest() {

}

Donor::~Donor() {

}