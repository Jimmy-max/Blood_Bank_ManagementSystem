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

bool Donor::date_check(string date)
{
	const regex pattern("(\\d\\d\\d\\d)(\\-)(\\d\\d)(\\-)(\\d\\d)");
	return regex_match(date, pattern);
};

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

	cout << "\n  Enter your blood type \n  Please(-O,+O,-A,+A,-B,+B,+AB,-AB) : ";
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
			string d;
			cin >> d;
			int l = true;
			do
			{
				int year = stoi(d.substr(0, 4));
				int month = stoi(d.substr(5, 6));
				int day = stoi(d.substr(8, 9));
				if (date_check(d) && month <= 12 && day <= 30 && year <= 2021 && year > 1899) {

						Table valid;
						valid.add_row({ "Your date of latest donation is valid" });
						valid.format().font_color(Color::green).border("").corner("").padding_left(2);
						cout << valid << endl;
						date_latest_donation = d;
						l = false;
						break;
				}
				else {
					Table error;
					error.add_row({ "Your date of latest donation is invalid\n  please try again" });
					error.format().font_color(Color::red).border("").corner("").padding_left(2);
					cout << error << endl << "  --> ";
					cin >> d;
				}
			} while (l != false);
			t = false;

			break;
		}
		else if (f == 2)
		{
			other = "No";
			cout << "\n  Please enter your date latest donation\n  Like :year-month-day : ";
			string d;
			cin >> d;
			
			int l = true;
			do
			{
				int year = stoi(d.substr(0, 4));
				int month = stoi(d.substr(5, 6));
				int day = stoi(d.substr(8, 9));
				if (date_check(d) && month <= 12 && day <= 30 && year <= 2021 && year > 1899) {
					Table valid;
					valid.add_row({ "Your date of latest donation is valid" });
					valid.format().font_color(Color::green).border("").corner("").padding_left(2);
					cout << valid << endl;
					date_latest_donation = d;
					l = false;
					break;
				}

				else {
					Table error;
					error.add_row({ "Your date of latest donation is invalid\n  Please try again" });
					error.format().font_color(Color::green).border("").corner("").padding_left(2);
					cout << error << endl << "  --> ";
					
					cin >> d;
				}
			} while (l != false);
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
	int check = 0;
	string p; // password.
	int idx = 0; // to save the index of the user.
	int idxl = 0, idxr = 0;
	bool flag = 0;
	bool flag2 = 0;
	sort(dataDonar.begin(), dataDonar.end(), [](const Donor& lhs, const Donor& rhs) {return lhs.id < rhs.id; });
	printf("please enter your id \n");
	cin >> x;

	if (dataDonar.size() == 1)
	{
		if (x == dataDonar[0].id)
		{
			cout << "please enter your password " << dataDonar[0].name << endl;
			cin >> p;
			if (p == dataDonar[0].password)
			{
				User::clear_screen(' ');
				Table passwordValid;
				string s = "welcome to your account " + dataDonar[0].name;
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
					string s = "please re enter the right password Mr." + dataDonar[0].name;
					passwordInvalid.add_row({ s });
					passwordInvalid.format().font_color(Color::red).border("").corner("").padding_left(2);
					cout << passwordInvalid << endl;
					cout << "Or enter ' B ' to back\n";
					cin >> p;
					if (p == dataDonar[0].password)
					{
						User::clear_screen(' ');
						Table passwordValid;
						string s = "welcome to your account " + dataDonar[0].name;
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

				if (x == dataDonar[0].id)
				{
					Table passwordEnter;
					string s = "please enter your password " + dataDonar[0].name;
					passwordEnter.add_row({ s });
					passwordEnter.format().font_color(Color::white).border("").corner("").padding_left(2);
					cout << passwordEnter<<endl;
					cin >> p;
					if (p == dataDonar[0].password)
					{
						User::clear_screen(' ');
						Table passwordValid;
						string s = "welcome to your account " + dataDonar[0].name;
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
							string s = "please re enter the right password Mr " + dataDonar[0].name;
							passReenter.add_row({ s });
							passReenter.add_row({ "Or enter ' B ' to back" });
							passReenter.format().font_color(Color::red).border("").corner("").padding_left(2);
							cout << passReenter << endl;
							cin >> p;
							if (p == dataDonar[0].password)
							{
								User::clear_screen(' ');
								Table passwordValid;
								string s = "welcome to your account " + dataDonar[0].name;
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
	l = dataDonar[idxl].id;
	idxr = (dataDonar.size() - 1);
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
			l = dataDonar[idx + 1].id;
		}  idxl = idx + 1;
	}
	if (flag) // if the id have been found.
	{
		Table passwordEnter;
		string s = "Please enter your password Mr " + dataDonar[idx].name ;
		passwordEnter.add_row({ s });
		passwordEnter.format().font_color(Color::white).border("").corner("").padding_left(2);
		cout << passwordEnter << endl;
		cin >> p;
		if (p == dataDonar[idx].password)
		{
			User::clear_screen(' ');
			Table passwordValid;
			string s = "welcome to your account " + dataDonar[idx].name;
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
				string s = "please re enter the right password Mr " + dataDonar[idx].name;
				passwordInvalid.add_row({ s });
				passwordInvalid.add_row({ "Or enter ' B ' to back" });
				passwordInvalid.format().font_color(Color::red).border("").corner("").padding_left(2);
				cout << passwordInvalid << endl;
				cin >> p;
				if (p == dataDonar[idx].password)
				{
					User::clear_screen(' ');
					Table passwordValid;
					string s = "welcome to your account Mr " + dataDonar[idx].name;
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
				return Donor::login(dataDonar);
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

void Donor::updateAccount(vector<Donor>& dataDonar, int index)
{
	char c = 'y';
	while (c == 'y')
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