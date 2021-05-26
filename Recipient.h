#include <string>

using namespace std;
class Recipient
{
public:
	//variables
	int id;
	string name;
	string mail;
	int password;
	int age;
	string gender;
	string blood_type;
	string hospital;
	string doc_of_case;
	//functions
	Recipient();
	void reg(); // register
	void login();
	void updateAccount();
	void deleteAccount();
	bool isBloodAvailable();
	void displayBloodData();
	void requestAndConfirm();
	~Recipient();
};

