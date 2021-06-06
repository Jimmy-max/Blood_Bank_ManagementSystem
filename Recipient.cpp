#include "Recipient.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "FileManager.h"
#include <map>
#include <iterator>
#include <stack>
#include <sstream>
#pragma warning(disable : 4996)



using namespace std;


Recipient::Recipient() {

}

void Recipient ::reg() 
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

	string str;
	int m = true;
	cout << "Enter your Email like : user_name@gmail.com " << endl;
	cin >> str;
	do
	{
		if (Email_check(str)) {
			cout << "Your Email is valid" << endl;
			mail = str;
			m = false;
			break;
		}

		else {
			cout << "Your Email is invalid , please try again " << endl;
			cin >> str;
		}
	} while (m != false);

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

int Recipient::login(vector<Recipient>& datarecipient)
{
	int x; // to take the id from the user.
	string p; // password.
	int idx = 0; // to save the index of the user.
	int idxl = 0, idxr = 0;
	bool flag = 0;
	bool flag2 = 0;
	sort(datarecipient.begin(), datarecipient.end(), [](const Recipient& lhs, const Recipient& rhs) {return lhs.id < rhs.id; });
	printf("please enter your id \n");
	cin >> x;
	int l, r, mid;
	l = datarecipient[idxl].id;
	idxr = (datarecipient.size() - 1);
	r = datarecipient[idxr].id;
	while (l < r)
	{
		idx = idxl + ((idxr - idxl) / 2);
		mid = datarecipient[idx].id;
		if (mid == x)
		{
			flag = 1;
			break;
		}
		else if (x == datarecipient[idxl].id)
		{
			flag = 1;
			idx = idxl;
			break;
		}
		else if (x == datarecipient[idxr].id)
		{
			flag = 1;
			idx = idxr;
			break;
		}
		else if (x < mid)
		{

			r = datarecipient[idx - 1].id;
			idxr = idx - 1;

		}
		else if (x > mid)
		{
			l = datarecipient[idx + 1].id;
		}  idxl = idx + 1;
	}
	if (flag) // if the id have been found.
	{
		printf("please enter your password \n");
		cin >> p;
		if (p == datarecipient[idx].password)
		{
			printf("welcome to your account sir \n");
			flag2 = 1;
		}
		else // password doesn't match.
		{
			printf("Wrong password \n");
		}
	}
	else // if the id doesn't found.
	{
		printf("this id is not found \n");
	}
	if (flag2)
	{
		return idx;
	}
	else
	{
		return -1;
	}
}

void Recipient::displayBloodData(vector<Donor>& donation) {
	map<string, int> mQuantity;
	map<string, stack<string>> mDates;
	map<string, int>::iterator itr;

	for (size_t i = 0; i < donation.size(); i++)
	{
		if (calculateExpiryDate(donation[i].date_latest_donation) == "0")
		{
			donation.erase(donation.begin()+i);
			continue;
		}
		mQuantity[donation[i].blood_type] += 1;
		mDates[donation[i].blood_type].push(donation[i].date_latest_donation);
	}
	for (itr = mQuantity.begin(); itr != mQuantity.end(); ++itr)
	{
		cout << "Type: " << itr->first << "  Quantity: " << itr->second << '\n';
		while (!mDates[itr->first].empty())
		{
			cout << "Received Date: " << mDates[itr->first].top() << "  Expiry Date : " << calculateExpiryDate(mDates[itr->first].top()) << endl;
			mDates[itr->first].pop();
		}
		cout << endl;

	}
}

string Recipient::calculateExpiryDate(string oldDate) {
	//https://web.archive.org/web/20170507133619/https://alcor.concordia.ca/~gpkatch/gdate-algorithm.html Days algorism
	time_t curr_time;
	tm* curr_tm;
	char currentDate[50];
	time(&curr_time);
	curr_tm = localtime(&curr_time);
	strftime(currentDate, 50, "%F", curr_tm);
	string cr = currentDate;
	int oldY = stoi(oldDate.substr(0, 3));
	int oldM = stoi(oldDate.substr(5, 6));
	int oldD = stoi(oldDate.substr(8, 9));
	oldM = (oldM + 9) % 12;
	oldY = oldY - oldM / 10;
	int curY = stoi(cr.substr(0, 3));
	int curM = stoi(cr.substr(5, 6));
	int curD = stoi(cr.substr(8, 9));
	curM = (curM + 9) % 12;
	curY = curY - curM / 10;
	int daysLeft = 20 - (((365 * curY + curY / 4 - curY / 100 + curY / 400 + (curM * 306 + 5) / 10 + (curD - 1))) - (365 * oldY + oldY / 4 - oldY / 100 + oldY / 400 + (oldM * 306 + 5) / 10 + (oldD - 1)));
	if (daysLeft <= 0)
	{
		return "0";
	}
	else
	{
		return to_string(daysLeft) + " Days left";
	}
}


void Recipient::isBloodAvailable(vector<Donor>& donation, int index, vector<Recipient>& recipient) {
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
		cout << "Your Blood type is Available : " << recipient[index].blood_type << '\n' << endl;
	}
	else
	{
		cout << "Your Blood type is Unavailable : " << recipient[index].blood_type << '\n' << endl;
	}
}

void Recipient::requestAndConfirm(vector<Donor>& donation) {
	map<string, int> mQuantity;
	map<string, stack<string>> mDates;
	map<string, int>::iterator itr;
	for (size_t i = 0; i < donation.size(); i++)
	{
		if (calculateExpiryDate(donation[i].date_latest_donation) == "0")
		{
			donation.erase(donation.begin() + i);
			continue;
		}
		mQuantity[donation[i].blood_type] += 1;
		mDates[donation[i].blood_type].push(donation[i].date_latest_donation);
	}
	
	while (true)
	{
		cout << "Enter Blood Type: "; string bloodType; cin >> bloodType;
		if (mQuantity[bloodType]) {
			cout << "Enter Quantity: "; int quantity; cin >> quantity;

			if (mQuantity[bloodType] >= quantity) {
				for (size_t i = 0; i < donation.size(); i++)
				{
					if (quantity == 0)
					{
						break;
					}
					if (donation[i].blood_type == bloodType)
					{
						donation.erase(donation.begin() + i);
						quantity--;
					}
				}
				cout << "Your request has been confirmed" << '\n' << endl;
				break;
			}
			else {
				cout << "Quantity is not Available" << '\n' << endl;
			}
		}
		else
		{
			cout << "Blood Type is not Available" << endl;
		}
	}
	
	
}

Recipient::~Recipient() {

}

void Recipient::updateAccount(vector<Recipient>& datarecipient, int index)
{

	char c = 'y';
	while (c == 'y')
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
			while (cin.fail())
			{
				cout << "     ERROR ,Please enter age using numbers only" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> newage ;
			}
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
}

void Recipient::deleteAccount(vector<Recipient>& datarecipient, int index)
{

	datarecipient.erase(datarecipient.begin() + index);
}
