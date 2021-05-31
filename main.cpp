#include <iostream>
#include "FileManager.h"


using namespace std;

int main() {

	//Store Logic
	vector<Donor> vDonor;
	vector<Donor> vDonations;
	vector<Recipient> vRecipient;
	FileManager file;
	file.readDonor(vDonor);
	file.readRecipient(vRecipient);
	file.readDonations(vDonations);

	////Start here!!!
	cout << "                              Welcome to the Blood Bank Management system                              \n " << endl;
	int choice;
	int c;
	bool correct = true;
	do
	{
		cout << "Please enter a choice: \n " << endl;
		cout << "to login , Please press  1:" << endl;
		cout << "if you a new user to register data, Please press  2:" << endl;
		cout << "If you want to Exit press  3 :" << endl;
		cin >> choice;

		switch (choice)
		{
		    case 1:               // login
			{ 
				cout << "        You have successfully logged in        " << endl;
		        cout << "       ###############################################################################################      " << endl;
		        break;  
			}
		    case 2:             // register
		    { 
				cout << "if you a Donor ,please press : 1" << endl;
		        cout << "if you a Recipient ,please press : 2" << endl;
		        cin >> c;
		        switch (c)
				{
			     	case 1:
					{   
						Donor donor;
		                donor.reg();
		                vDonor.push_back(donor);
		                cout << "         Registration was successful      " << endl;
		                cout << "       ###############################################################################################      " << endl;
		                break; 
					}
		            case 2:
					{	
						Recipient recipient;
		                recipient.reg();
		                vRecipient.push_back(recipient);
		                cout << "         Registration was successful      " << endl;
	                    cout << "       ###############################################################################################      " << endl;
	                	break; 
					}
		            default:
						
			            cout << " Choice is not available: " << endl;
			           break;
		
				}
		             break;
		
			}
		    case 3:
			{
				cout << "                  ######### The exit was successful ,Thank you for using system ##########               " << endl;
			    correct = false;
			    break; 
			}
		    default:
			{
				cout << " Choice is not available ,please try again " << endl;
			    break; 
			}
		}
	} while (correct != false);


	//End here!!!!
	file.writeRecipient(vRecipient);
	file.writeDonor(vDonor);
	file.writeDonations(vDonations);
}



