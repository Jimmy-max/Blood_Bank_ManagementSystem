#include <iostream>
#include "FileManager.h"
#include <ctime>
#include <chrono>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#pragma warning(disable : 4996)

#include <tabulate/table.hpp>
using namespace tabulate;
using namespace std;




int main() {
	//Design Logic
	Table mainPage;
	mainPage.add_row({ "Welcome to the Blood Bank Management system" });
	mainPage[0].format().padding_top(1).padding_bottom(1).font_align(FontAlign::center).font_style({ FontStyle::bold }).font_background_color(Color::cyan).border(" ").corner(" ");
	mainPage.add_row({ "To login, please type 1:" });
	mainPage.add_row({ "If you a new user, to register, please type 2:" });
	mainPage.add_row({ "If you want to exit, please type 3:" });
	for (int i = 1; i < 4; i++) { mainPage[i].format().padding_bottom(0.5).border(" ").corner(" ").font_style({ FontStyle::bold });}

	Table loginPage;
	loginPage.add_row({ "Welcome in login page" });
	loginPage[0].format().padding_top(1).padding_bottom(1).padding_right(14).padding_left(13).font_align(FontAlign::center).font_style({ FontStyle::bold }).font_background_color(Color::red).border(" ").corner(" ");
	loginPage.add_row({ "If you a Donor, please press : 1" });
	loginPage.add_row({ "If you a Recipient, please press : 2" });
	loginPage.add_row({ "If you want to back, please press : 3" });
	for (int i = 1; i < 4; i++) { loginPage[i].format().padding_bottom(0.5).border(" ").corner(" ").font_style({ FontStyle::bold }); }

	Table registrationPage;
	registrationPage.add_row({ "Welcome in Registration page" });
	registrationPage[0].format().padding_top(1).padding_bottom(1).padding_right(10).padding_left(10).font_align(FontAlign::center).font_style({ FontStyle::bold }).font_background_color(Color::yellow).border(" ").corner(" ");
	registrationPage.add_row({ "If you a Donor, please press : 1" });
	registrationPage.add_row({ "If you a Recipient, please press : 2" });
	registrationPage.add_row({ "If you want to back, please press : 3" });
	for (int i = 1; i < 4; i++) { registrationPage[i].format().padding_bottom(0.5).border(" ").corner(" ").font_style({ FontStyle::bold }); }

	Table exitPage;
	exitPage.add_row({ "The exit was successful\nThank you for using system ^_^" });
	exitPage.format().corner("").padding_top(0.5).padding_bottom(0.5).padding_right(9).padding_left(9).font_align(FontAlign::center).font_color(Color::yellow).border_color(Color::yellow);
	


	
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
		cout << mainPage << "\n  --> ";
		int choice; cin >> choice;
		User::clear_screen(' ');

		// main choices
		if (choice == 1)
		{
			while (true)
			{
				cout << loginPage << "\n  --> ";
				int choice; cin >> choice;
				User::clear_screen(' ');

				int index = -1;
				if (choice == 1)
				{
					// Donor Body
					index = Donor::login(vDonor);

					while (index !=-1)
					{
						Table donorPage;
						donorPage.add_row({ "Welcome in Donor page" });
						donorPage[0].format().padding_top(1).padding_bottom(1).padding_right(14).padding_left(13).font_align(FontAlign::center).font_style({ FontStyle::bold }).font_background_color(Color::blue).border(" ").corner(" ");
						cout << donorPage << endl;
						cout << "  To update your account ,please press : 1" << endl;
						cout << "  To delete your account ,please press : 2" << endl;
						cout << "  To make your donation request ,please press : 3" << endl;
						cout << "  To logout ,please press : 4\n  --> ";
						int choice; cin >> choice;
						User::clear_screen(' ');
						if (choice == 1)
						{
							Donor::updateAccount(vDonor, index);
						}
						else if (choice == 2)
						{
							Donor::deleteAccount(vDonor, index);
							Table valid;
							valid.add_row({ "Your account is deleted" });
							valid.format().font_color(Color::green).border("").corner("").padding_left(2);
							cout << valid << endl;
							index = -1;
						}
						else if (choice == 3)
						{
							Donor::donationRequest(vDonor, index,vDonations);
						}
						else if (choice == 4)
						{
							User::clear_screen(' ');
							Table valid;
							valid.add_row({ "Your logout is successfully" });
							valid.format().font_color(Color::green).border("").corner("").padding_left(2);
							cout << valid << endl;
							index = -1;
						}
						else
						{
							cout << "\n  Choice is not available ,please try again " << endl;
						}
					}
				}
				else if (choice == 2)
				{
					// Recipient Body
					index = Recipient::login(vRecipient);
					while (index!=-1)
					{
						Table recipientPage;
						recipientPage.add_row({ "Welcome in Recipient page" });
						recipientPage[0].format().padding_top(1).padding_bottom(1).padding_right(12).padding_left(11).font_align(FontAlign::center).font_style({ FontStyle::bold }).font_background_color(Color::blue).border(" ").corner(" ");
						cout << recipientPage << endl;
						cout << "\n  To update your account ,please press : 1" << endl;
						cout << "  To delete your account ,please press : 2" << endl;
						cout << "  To check if your Blood is Available press : 3" << endl;
						cout << "  To display all Blood Data ,please press : 4" << endl;
						cout << "  To request and Confirm ,please press : 5" << endl;
						cout << "  To logout ,please press : 6\n  --> ";
						int choice; cin >> choice;
						User::clear_screen(' ');
						if (choice == 1)
						{
							Recipient::updateAccount(vRecipient, index);
						}
						else if (choice == 2)
						{

							Recipient::deleteAccount(vRecipient, index);
							User::clear_screen(' ');
							Table valid;
							valid.add_row({ "Your account is deleted" });
							valid.format().font_color(Color::green).border("").corner("").padding_left(2);
							cout << valid << endl;
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
							Recipient::requestAndConfirm(vDonations, index, vRecipient);
						}
						else if (choice == 6)
						{
							Table valid;
							valid.add_row({ "Your logout is successfull" });
							valid.format().font_color(Color::green).border("").corner("").padding_left(2);
							cout << valid << endl;
							index = -1;
						}
						else
						{
							cout << "  Choice is not available ,please try again " << endl;
						}
					}
				}
				else if (choice == 3)
				{
					User::clear_screen(' ');
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
				cout << registrationPage << "\n  --> ";
				int choice; cin >> choice;
				User::clear_screen(' ');
				if (choice == 1)
				{
					Table RegistrationPage;
					RegistrationPage.add_row({ "Welcome in Donor Registration page" });
					RegistrationPage.format().padding_top(1).padding_bottom(1).padding_right(7).padding_left(7).font_align(FontAlign::center).font_style({ FontStyle::bold }).font_background_color(Color::green).border(" ").corner(" ");
					cout << RegistrationPage;

					Donor donor;
					donor.reg();
					vDonor.push_back(donor);

					//User::clear_screen(' ');
					Table valid;
					valid.add_row({ "Your registration is successfully" });
					valid.format().font_color(Color::green).border("").corner("").padding_left(2);
					cout << valid << endl;
					

				}
				else if (choice == 2)
				{
					Table RegistrationPage;
					RegistrationPage.add_row({ "Welcome in Recipient Registration page" });
					RegistrationPage.format().padding_top(1).padding_bottom(1).padding_right(5).padding_left(5).font_align(FontAlign::center).font_style({ FontStyle::bold }).font_background_color(Color::green).border(" ").corner(" ");
					cout << RegistrationPage;

					Recipient recipient;
					recipient.reg();
					vRecipient.push_back(recipient);
					
					User::clear_screen(' ');
					Table valid;
					valid.add_row({ "Your registration is successfully" });
					valid.format().font_color(Color::green).border("").corner("").padding_left(2);
					cout << valid << endl;
				}
				else if (choice == 3)
				{
					User::clear_screen(' ');
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
			User::clear_screen(' ');
			cout << exitPage;
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
	return 0;
}



