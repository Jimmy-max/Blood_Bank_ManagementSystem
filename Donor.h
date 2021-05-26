#include <string>

using namespace std;

class Donor
{
public:
	Donor(); // constructor

	//variables
	int id;
	string name;
	string mail;
	int password;
	int age;
	enum  gender{};
	string  bloodType;
	enum suffersFromDisease{};
	string other;
	string date_latest_donation;

	//functions - methods
	void reg(); // register
	void login();
	void updateAccount();
	void deleteAccount();
	void donationRequest();

	
	~Donor(); // destructor


};

