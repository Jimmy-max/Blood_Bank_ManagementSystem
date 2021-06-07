#include "Donor.h"
#include "FileManager.h"
#include <iostream>
#include <algorithm>
#include <tabulate/table.hpp>
using namespace tabulate;
#pragma warning(disable : 4996)

using namespace std;


Donor::Donor() {

}

void Donor::reg()
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

	cout << "\n  Please enter your name : " ;
	cin.ignore();
	getline(cin, name);

	string str;
	int m = true;
	cout << "\n  Enter your Email \n  like : user_name@gmail.com : " ;
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


	cout << "\n  If you have a chronic illnes like: \n\n  blood pressure disorders, thyroid disease\n  diabetes, cancer, heart disorders,hepatitis\n  Please write down these disease.";
	cout << "\n\n  If you do not have any disease, write (NO) \n  --> ";
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
			Table error;
			error.add_row({ "Same thing is wrong ,please try again ?!" });
			error.format().font_color(Color::red).border("").corner("").padding_left(2);
			cout << error << endl;
			cout << "  --> ";
			cin >> d;
		}

	} while (k != false);
	int t = true;
	do
	{
		int f;
		cout << "\n  If you have other diseases\n  Or take any medicine, please press 1  ";
		cout << "\n  If you are not suffering\n  From any other diseases, please press 2  \n  --> ";
		cin >> f;
		if (f == 1)
		{
			cout << "\n  Please enter this disease here : ";
			cin >> other;
			cout << "\n  Please enter your date latest donation\n  Like :Year-Month-Day : ";
			cin.ignore();
			getline(cin, date_latest_donation);
			t = false;

			break;
		}
		else if (f == 2)
		{
			other = "No";
			cout << "\n  Please enter your date latest donation\n  Like :year-month-day : ";
			cin.ignore();
			getline(cin, date_latest_donation);
			t = false;

			break;
		}
		else
		{
			Table error;
			error.add_row({ "Choice is not available ,please try again" });
			error.format().font_color(Color::red).border("").corner("").padding_left(2);
			cout << error << endl;

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
	printf("\n  Please enter your id : ");
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
		printf("  Please enter your password : ");
		cin >> p;
		if (p == dataDonar[idx].password)
		{
			User::clear_screen(' ');
			Table valid;
			valid.add_row({ "welcome to your account sir" });
			valid.format().font_color(Color::green).border("").corner("").padding_left(2);
			cout << valid << endl;
				flag2 = 1;
		}
		else // password doesn't match.
		{
			Table error;
			error.add_row({ "Wrong password" });
			error.format().font_color(Color::red).border("").corner("").padding_left(2);
			cout << error << endl;
		}
	}
	else // if the id doesn't found.
	{
		Table error;
		error.add_row({ "This id is not found" });
		error.format().font_color(Color::red).border("").corner("").padding_left(2);
		cout << error << endl;
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
		cout << "\n  Enter number to update \n  1-Password  \n  2-Age \n  3-Diseases that you suffer from \n  4-Other diseases or take any medicine \n  5-Date latest donation  \n  6-Done \n  --> ";
		int choice;
		cin >> choice;
		cout << " \n-----------------------------\n";
		if (choice == 1)
		{
			cout << "  Enter your New password : ";
			string newpassword;
			cin >> newpassword;
			dataDonar[index].password = newpassword;
			cout << " \n-----------------------------\n";

		}
		else if (choice == 2)
		{
			cout << "  Please enter your age\n  It must be between 17 and 60 years old";
			int newage;
			while (true)
			{
				cout << "\n  --> ";
				cin >> newage;
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
					if (newage < 60 && newage > 17)
					{
						dataDonar[index].age = newage ;
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

			cout << " \n-----------------------------\n";
		}
		else if (choice == 3)
		{
			cout << "\n  If you have a chronic illnes like: \n\n  blood pressure disorders, thyroid disease\n  diabetes, cancer, heart disorders,hepatitis\n  Please write down these disease.";
			cout << "\n\n  If you do not have any disease, write (NO) \n  --> ";
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
					Table error;
					error.add_row({ "same thing is wrong ,please try again ?!" });
					error.format().font_color(Color::red).border("").corner("").padding_left(2);
					cout << error << endl;
					cout << "  --> ";
					cin >> suffersFromDisease ;
				}

			} while (m != false);

		}
		else if (choice == 4)
		{
			int check = true;
			do
			{	
				cout << "  If you have other diseases or take medicine press 1  " << endl;
				cout << "  If you aren't suffering from other diseases press 2\n  --> " << endl;
				int t ;
				cin >> t ;
				if (t == 1)
				{
					cout << "  Please enter this disease here : ";
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
					Table error;
					error.add_row({ "Choice is not available ,please try again" });
					error.format().font_color(Color::red).border("").corner("").padding_left(2);
					cout << error << endl;
					break;

				}
			} while (check != false);
			
			cout << " \n-----------------------------\n";
		}
		else if (choice == 5)
		{
			cout << "  Please enter your date latest donation\n  Like :Year-Month-Day : ";
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

void Donor::deleteAccount(vector<Donor>& dataDonar, int index)
{
	dataDonar.erase(dataDonar.begin() + index);
	User::clear_screen(' ');
}

void Donor::donationRequest(vector<Donor>& donor, int index, vector<Donor>& donations) {
	User::clear_screen(' ');
	Table valid;
	valid.add_row({ "Your donation is accepted" });
	valid.format().font_color(Color::green).border("").corner("").padding_left(2);
	cout << valid << endl;
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