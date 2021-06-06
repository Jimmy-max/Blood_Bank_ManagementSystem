#include "Donor.h"
#include "FileManager.h"
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)

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

	cout << "please enter your password " << endl;
	cin >> password;


	cout << "please enter your age (The donor must be between 17 and 60 years old)" << endl;
	int year;
	int old = true;
	while (true)
	{
		cin >> year;
		if (cin.fail())
		{
			cout << "     ERROR ,Please enter age using numbers only" << endl;
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
				cout << "     ERROR ,Please enter age between 17 and 60 years old " << endl;
				continue;
			}
		}
	}

	cout << "please enter your gender (female / male) " << endl;
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
			cout << "please enter your gender (female / male) " << endl;
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
			cout << "pleas enter your date latest donation,like :year-month-day" << endl;
			cin.ignore();
			getline(cin, date_latest_donation);
			t = false;
			break;
		}
		else if (f == 2)
		{
			other = "No";
			cout << "pleas enter your date latest donation ,like :year-month-day" << endl;
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

int Donor::login(vector<Donor>& dataDonar)
{
	int x; // to take the id from the user.
	string p; // password.
	int idx=0; // to save the index of the user.
	int idxl=0, idxr=0;
	bool flag = 0;
	bool flag2 = 0;
	sort(dataDonar.begin(), dataDonar.end(), [](const Donor& lhs, const Donor& rhs) {return lhs.id < rhs.id; });
	printf("please enter your id \n");
	scanf("%d", &x);
	int l, r, mid;
	l = dataDonar[idxl].id;
	idxr = (dataDonar.size()-1);
	r = dataDonar[idxr].id;
	while (l < r)
	{
		idx = idxl + ((idxr - idxl) / 2);
		mid = dataDonar[idx].id;
		if (mid == x)
		{
			flag = 1;
			break;
		}
		else if (x == dataDonar[idxl].id)
		{
			flag = 1;
			idx = idxl;
			break;
		}
		else if (x == dataDonar[idxr].id)
		{
			flag = 1;
			idx = idxr;
				break;
		}
		else if (x < mid)
		{

			r = dataDonar[idx - 1].id;
			idxr = idx - 1;

		}
		else if (x > mid)
		{
			l = dataDonar[idx+1].id;
		}  idxl = idx + 1;
	}
	if (flag) // if the id have been found.
	{
		printf("please enter your password \n");
		cin >> p;
		if (p == dataDonar[idx].password)
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

void Donor::updateAccount(vector<Donor>& dataDonar, int index)
{
	char c = 'y';
	while (c = 'y')
	{
		cout << "Enter number to update \n 1-Password  \n 2-Age \n 3-Diseases that you suffer from \n 4-Other diseases or take any medicine \n 5-Date latest donation  \n 6-Done \n";
		int choice;
		cin >> choice;
		cout << " \n-----------------------------\n";
		if (choice == 1)
		{
			cout << "Enter your New password \n";
			string newpassword;
			cin >> newpassword;
			dataDonar[index].password = newpassword;
			cout << " \n-----------------------------\n";

		}
		else if (choice == 2)
		{
			cout << "pleas enter your age (The donor must be between 17 and 60 years old)" << endl;
			int newage;
			while (true)
			{
				cin >> newage;
				if (cin.fail())
				{
					cout << "     ERROR ,Please enter age using numbers only" << endl;
					cin.clear();
					cin.ignore(256, '\n');
					continue;
				}
				else
				{
					if (newage < 60 && newage > 17)
					{
						dataDonar[index].age = newage ;
						break;
					}
					else
					{
						cout << "     ERROR ,Please enter age between 17 and 60 years old " << endl;
						continue;
					}
				}
			}

			cout << " \n-----------------------------\n";
		}
		else if (choice == 3)
		{
			cout << "If you have a chronic illnes,  like(blood pressure disorders, thyroid disease, diabetes ,cancer, heart disorders,hepatitis) Please write down these disease" << endl;
			cout << "If you do not have any disease, write (NO)" << endl;
			string suffersFromDisease ;
			cin >> suffersFromDisease ;
			bool m = true;
			do {
				if (suffersFromDisease == "blood pressure disorders" || suffersFromDisease == "thyroid disease" || suffersFromDisease == "diabetes " || suffersFromDisease == "cancer" || suffersFromDisease == "heart disorders" || suffersFromDisease == "hepatitis" || suffersFromDisease == "NO")
				{
					dataDonar[index].suffersFromDisease = suffersFromDisease ; 
					cout << " \n-----------------------------\n";
					break;
				}
				else
				{
					cout << "     same thing is wrong ,please try again ?!" << endl;
					cin >> suffersFromDisease ;
				}

			} while (m != false);

		}
		else if (choice == 4)
		{
			int check = true;
			do
			{	
				cout << "If you have other diseases or take any medicine, please press 1  " << endl;
				cout << "If you are not suffering from any other diseases, please press 2  " << endl;
				int t ;
				cin >> t ;
				if (t == 1)
				{
					cout << "Please enter this disease here " << endl;
					string other;
					cin >> other;
					dataDonar[index].other = other ;
					break;
				}
				else if (t == 2)
				{
					dataDonar[index].other = "NO"; 
					break;
				}
				else
				{
					cout << " Choice is not available ,please try again " << endl;
					break;

				}
			} while (check != false);
			
			cout << " \n-----------------------------\n";
		}
		else if (choice == 5)
		{
			cout << "pleas enter your date latest donation ,like :year-month-day" << endl;
			string date_latest_donation; 
			cin.ignore();
			getline(cin, date_latest_donation);
			dataDonar[index].date_latest_donation = date_latest_donation; 
			cout << " \n-----------------------------\n";

		}
		else if (choice == 6)
		{
			break; 
		}
		else
		{
			cout << "You enter wrong number";
		}

		cout << "Do you want to make anthor update ? (y/n) \n";
		cin >> c;
		do
		{
			if (c == "y" || c == "n")
			{
				break;
			}
			else
			{
				cout << "     error,not available data pleas try again ?" << endl;
				cout << "please enter your gender (female / male) " << endl;
				cin >> c;
			}
		} while (true);
		
		cout << " \n-----------------------------\n";
	}

	cout << "update successful \n";
	cout << "-----------------------------\n";
}

void Donor::deleteAccount(vector<Donor>& dataDonar, int index)
{
	dataDonar.erase(dataDonar.begin() + index);
	cout << "delete successful \n";
	cout << "-----------------------------\n";
}

void Donor::donationRequest(vector<Donor>& donor, int index, vector<Donor>& donations) {
	//if() check date of last donation
	cout << "Your donation is accepted"<<endl;
	time_t curr_time;
	tm* curr_tm;
	char s[50];
	time(&curr_time);
	curr_tm = localtime(&curr_time);
	strftime(s, 50, "%F", curr_tm);
	donor[index].date_latest_donation = s;

	donations.push_back(donor[index]);
}

Donor::~Donor() {

}