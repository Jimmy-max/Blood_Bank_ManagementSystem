#include "Recipient.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "FileManager.h"
#include <map>
#include <iterator>
#include <stack>
#include <sstream>
#include <tabulate/table.hpp>
using namespace tabulate;
#pragma warning(disable : 4996)



using namespace std;


Recipient::Recipient() {

}

void Recipient ::reg() 
{
	cout << "\n  Please enter your id\n  It should be a number : ";
	cin >> id;
	while (cin.fail())
	{
		Table error;
		error.add_row({ "ERROR ,Please enter an ID using numbers only" });
		error.format().font_color(Color::red).border("").corner("").padding_left(2);
		cout << error << endl;

		cin.clear();
		cin.ignore(256, '\n');
		cout << "\n  Another One --> ";
		cin >> id;
	}

	Table valid;
	valid.add_row({ "It is valid" });
	valid.format().font_color(Color::green).border("").corner("").padding_left(2);
	cout << valid << endl;
	

	cout << "\n  Please enter your name : ";
	cin.ignore();
	getline(cin, name);

	string str;
	int m = true;
	cout << "\n  Enter your Email \n  like : user_name@gmail.com : ";
	cin >> str;
	do
	{
		if (Email_check(str)) {

			Table valid;
			valid.add_row({ "It is valid" });
			valid.format().font_color(Color::green).border("").corner("").padding_left(2);
			cout << valid << endl;

			mail = str;
			m = false;
			break;
		}

		else {

			Table error;
			error.add_row({ "Your Email is invalid , please try again" });
			error.format().font_color(Color::red).border("").corner("").padding_left(2);
			cout << error << endl;
			cout << "\n  Another One --> ";
			cin >> str;
		}
	} while (m != false);

	cout << "\n  Please enter your password : ";
	cin >> password;


	cout << "\n  Please enter your age \n  The donor must be between 17 and 60";
	int year;
	int old = true;
	while (true)
	{
		cout << " \n  --> ";
		cin >> year;
		if (cin.fail())
		{
			Table error;
			error.add_row({ "ERROR ,Please enter age using numbers only" });
			error.format().font_color(Color::red).border("").corner("").padding_left(2);
			cout << error << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		else
		{
			if (year < 60 && year > 17)
			{
				age = year;
				old = false;
				break;
			}
			else
			{
				Table error;
				error.add_row({ "ERROR ,Please enter age between 17 and 60" });
				error.format().font_color(Color::red).border("").corner("").padding_left(2);
				cout << error << endl;
				continue;
			}
		}
	}

	cout << "\n  Please enter your gender (female / male) \n  -->  ";
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
			Table error;
			error.add_row({ "Error,not available data pleas try again ?" });
			error.format().font_color(Color::red).border("").corner("").padding_left(2);
			cout << error << endl;
			cout << "\n  Please enter your gender (female / male) \n  --> : ";
			cin >> g;
		}
	} while (count != false);

	cout << "\n  Enter your blood type \n  Please(-O, +O,- A, +A,-B,+B,+AB,-AB) : ";
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
			Table error;
			error.add_row({ "Incorrect blood type, please try again" });
			error.format().font_color(Color::red).border("").corner("").padding_left(2);
			cout << error << endl;
			cout << "  --> ";
			cin >> B;
		}
	} while (y != false);
	

	cout << "\n  Please enter the name of the hospital : ";
	cin >> hospital;
	cout << "\n  Please enter the name of the Doctor \n  responsible for the case : ";
	cin >> doc_of_case;
}

int Recipient::login(vector<Recipient>& datarecipient)


{
	int x; // to take the id from the user.
	int check = 0;
	string p; // password.
	int idx = 0; // to save the index of the user.
	int idxl = 0, idxr = 0;
	bool flag = 0;
	bool flag2 = 0;
	sort(datarecipient.begin(), datarecipient.end(), [](const Recipient& lhs, const Recipient& rhs) {return lhs.id < rhs.id; });
	printf("please enter your id \n");
	cin >> x;

	if (datarecipient.size() == 1)
	{
		if (x == datarecipient[0].id)
		{
			cout << "please enter your password " << datarecipient[0].name << endl;
			cin >> p;
			if (p == datarecipient[0].password)
			{
				User::clear_screen(' ');
				Table passwordValid;
				string s = "welcome to your account " + datarecipient[0].name;
				passwordValid.add_row({ s });
				passwordValid.format().font_color(Color::green).border("").corner("").padding_left(2);
				cout << passwordValid << endl;
				return 0;
			}
			else
			{
				while (true)
				{
					Table passwordInvalid;
					string s = "please re enter the right password Mr." + datarecipient[0].name;
					passwordInvalid.add_row({ s });
					passwordInvalid.format().font_color(Color::red).border("").corner("").padding_left(2);
					cout << passwordInvalid << endl;
					cout << "Or enter ' B ' to back\n";
					cin >> p;
					if (p == datarecipient[0].password)
					{
						User::clear_screen(' ');
						Table passwordValid;
						string s = "welcome to your account " + datarecipient[0].name;
						passwordValid.add_row({ s });
						passwordValid.format().font_color(Color::green).border("").corner("").padding_left(2);
						cout << passwordValid << endl;
						return 0;
					}
					else if (p == "B")
						return -1;

				}
			}
		}
		else
		{
			while (true)
			{
				User::clear_screen(' ');
				Table idReenter;
				idReenter.add_row({ "please re enter the right id sir" });
				idReenter.add_row({ "Or enter ' -1 ' to back" });
				idReenter.format().font_color(Color::red).border("").corner("").padding_left(2);
				cout << idReenter << endl;
				cin >> x;

				if (x == datarecipient[0].id)
				{
					Table passwordEnter;
					string s = "please enter your password " + datarecipient[0].name;
					passwordEnter.add_row({ s });
					passwordEnter.format().font_color(Color::white).border("").corner("").padding_left(2);
					cout << passwordEnter << endl;
					cin >> p;
					if (p == datarecipient[0].password)
					{
						User::clear_screen(' ');
						Table passwordValid;
						string s = "welcome to your account " + datarecipient[0].name;
						passwordValid.add_row({ s });
						passwordValid.format().font_color(Color::green).border("").corner("").padding_left(2);
						cout << passwordValid << endl;
						return 0;
					}
					else
					{
						while (true)
						{
							Table passReenter;
							string s = "please re enter the right password Mr " + datarecipient[0].name;
							passReenter.add_row({ s });
							passReenter.add_row({ "Or enter ' B ' to back" });
							passReenter.format().font_color(Color::red).border("").corner("").padding_left(2);
							cout << passReenter << endl;
							cin >> p;
							if (p == datarecipient[0].password)
							{
								User::clear_screen(' ');
								Table passwordValid;
								string s = "welcome to your account " + datarecipient[0].name;
								passwordValid.add_row({ s });
								passwordValid.format().font_color(Color::green).border("").corner("").padding_left(2);
								cout << passwordValid << endl;
								return 0;
							}
							else if (p == "B")
								return -1;

						}
					}

				}
				else if (x == -1)
					return -1;
			}
		}
	}
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
		Table passwordEnter;
		string s = "Please enter your password Mr " + datarecipient[idx].name;
		passwordEnter.add_row({ s });
		passwordEnter.format().font_color(Color::white).border("").corner("").padding_left(2);
		cout << passwordEnter << endl;
		cin >> p;
		if (p == datarecipient[idx].password)
		{
			User::clear_screen(' ');
			Table passwordValid;
			string s = "welcome to your account " + datarecipient[idx].name;
			passwordValid.add_row({ s });
			passwordValid.format().font_color(Color::green).border("").corner("").padding_left(2);
			cout << passwordValid << endl;
			flag2 = 1;
		}
		else // password doesn't match.
		{
			User::clear_screen(' ');
			Table passwordInvalid;
			passwordInvalid.add_row({ "Wrong password" });
			passwordInvalid.format().font_color(Color::red).border("").corner("").padding_left(2);
			cout << passwordInvalid << endl;
			while (true)
			{
				Table passwordInvalid;
				string s = "please re enter the right password Mr " + datarecipient[idx].name;
				passwordInvalid.add_row({ s });
				passwordInvalid.add_row({ "Or enter ' B ' to back" });
				passwordInvalid.format().font_color(Color::red).border("").corner("").padding_left(2);
				cout << passwordInvalid << endl;
				cin >> p;
				if (p == datarecipient[idx].password)
				{
					User::clear_screen(' ');
					Table passwordValid;
					string s = "welcome to your account Mr " + datarecipient[idx].name;
					passwordValid.add_row({ s });
					passwordValid.format().font_color(Color::green).border("").corner("").padding_left(2);
					cout << passwordValid << endl;
					return idx;
				}
				else if (p == "B")
					return -1;

			}
		}
	}
	else // if the id doesn't found.
	{
		User::clear_screen(' ');
		Table idReenter;
		idReenter.add_row({ "ID not found, please enter 1 to try again" });
		idReenter.add_row({ "Or enter ' -1 ' to back" });
		idReenter.format().font_color(Color::red).border("").corner("").padding_left(2);
		cout << idReenter << endl;
		while (cin >> x)
		{
			if (x == 1)
			{
				return Recipient::login(datarecipient);
			}
			else if (x == -1)
			{
				return -1;
			}
			else {
				Table idReenter;
				idReenter.add_row({ "wrong input ,please enter 1 to try again" });
				idReenter.add_row({ "Or enter ' -1 ' to back" });
				idReenter.format().font_color(Color::red).border("").corner("").padding_left(2);
				cout << idReenter << endl;
				continue;
			}
		}



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
		cout << "  Type: " << itr->first << "  Quantity: " << itr->second << '\n';
		while (!mDates[itr->first].empty())
		{
			cout << "  Received : " << mDates[itr->first].top() << "  Expiry : " << calculateExpiryDate(mDates[itr->first].top()) << endl;
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
		Table valid;
		valid.add_row({ "Lucky ^_^" });
		valid.format().font_color(Color::green).border("").corner("").padding_left(2);
		cout << valid << endl;
		cout << "  Your Blood type is Available : " << recipient[index].blood_type << '\n' << endl;
	}
	else
	{
		Table error;
		error.add_row({ "Sorry" });
		error.format().font_color(Color::red).border("").corner("").padding_left(2);
		cout << error << endl;
		cout << "  Your Blood type is Unavailable : " << recipient[index].blood_type << '\n' << endl;
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
		User::clear_screen(' ');
		cout << "  Enter Blood Type: "; string bloodType; cin >> bloodType;
		if (mQuantity[bloodType]) {
			cout << "  Enter Quantity: "; int quantity; cin >> quantity;

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
				User::clear_screen(' ');
				Table valid;
				valid.add_row({ "Your request has been confirmed" });
				valid.format().font_color(Color::green).border("").corner("").padding_left(2);
				cout << valid << endl;
				break;
			}
			else {
				User::clear_screen(' ');
				Table error;
				error.add_row({ "Quantity is not Available" });
				error.format().font_color(Color::red).border("").corner("").padding_left(2);
				cout << error << endl;
			}
		}
		else
		{
			User::clear_screen(' ');
			Table error;
			error.add_row({ "Blood Type is not Available" });
			error.format().font_color(Color::red).border("").corner("").padding_left(2);
			cout << error << endl;
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
		cout << "\n  Enter number to updata \n  1-Password  \n  2-Age  \n  3-Hospital  \n  4-Your Doctor  \n  5-Done  \n  --> ";
		int choice;
		cin >> choice;
		cout << " \n-----------------------------\n";
		if (choice == 1)
		{
			cout << "  Enter your New password \n  --> ";
			string newpassword;
			cin >> newpassword;
			datarecipient[index].password = newpassword;
			cout << " \n-----------------------------\n";

		}
		else if (choice == 2)
		{
			cout << "  Enter your New age \n  --> ";
			int newage;
			cin >> newage;
			while (cin.fail())
			{
				Table error;
				error.add_row({ "ERROR ,Please enter age using numbers only" });
				error.format().font_color(Color::red).border("").corner("").padding_left(2);
				cout << error << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cout << "  --> ";
				cin >> newage ;
			}
			datarecipient[index].age = newage;
			cout << " \n-----------------------------\n  --> ";
		}
		else if (choice == 3)
		{

			cout << "  Enter your New Hospital \n  --> ";
			string newhospital;
			cin >> newhospital;
			datarecipient[index].hospital = newhospital;
			cout << " \n-----------------------------\n";
		}
		else if (choice == 4)
		{
			cout << "  Enter your New doctor \n  --> ";
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
			Table error;
			error.add_row({ "You enter wrong number" });
			error.format().font_color(Color::red).border("").corner("").padding_left(2);
			cout << error << endl;
		}

		cout << "  Do you want to make anthor update ? (y/n) \n  --> ";
		cin >> c;
		do
		{
			if (c == 'y' || c == 'n')
			{
				break;
			}
			else
			{
				cout << "     error,not available data pleas try again ?" << endl;
				cout << "Do you want to make anthor update ? (y/n) " << endl;
				cin >> c;
			}
		} while (true);

		cout << " \n-----------------------------\n";

	}
	User::clear_screen(' ');
	Table valid;
	valid.add_row({ "Update successful" });
	valid.format().font_color(Color::green).border("").corner("").padding_left(2);
	cout << valid << endl;
	cout << "-----------------------------\n";
}

void Recipient::deleteAccount(vector<Recipient>& datarecipient, int index)
{

	datarecipient.erase(datarecipient.begin() + index);
}
