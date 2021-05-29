#include <string>
#include "User.h"

using namespace std;

class Donor : public User
{
public:
	Donor(); // constructor

	//variables
	enum suffersFromDisease{};
	string other;
	string date_latest_donation;

	//functions - methods
	void donationRequest();

	
	~Donor(); // destructor


};

