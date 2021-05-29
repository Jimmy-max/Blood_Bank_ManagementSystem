#include <string>

using namespace std;
class User
{
public:
	User(); // constructor

	//variables
	int id;
	string name;
	string mail;
	int password;
	int age;
	enum  gender {};
	string blood_type;

	//functions - methods
	void reg(); // register
	void login();
	void updateAccount();
	void deleteAccount();

	~User();// destructor
};

