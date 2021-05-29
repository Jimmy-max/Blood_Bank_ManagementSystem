#include "Donor.h"
#include <iostream>

using namespace std;

Donor::Donor() {

}

void Donor::reg() {
	cout << "pleas enter your id " << endl;
	cin >> id;
	cout << "pleas enter your name " << endl;
	cin >> name;
	cout << "pleas enter your email " << endl;
	cin >> mail;
	cout << "pleas enter your password " << endl;
	cin >> password;
	cout << "pleas enter your age " << endl;
	cin >> age;
	cout << "pleas enter your gender (fmail / mail) " << endl;
	cin >> gender;
	string fmail;
	string mail;
}


void Donor::donationRequest() {

}

Donor::~Donor() {

}