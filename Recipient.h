#include <string>
#include "User.h"

using namespace std;
class Recipient : public User
{
public:
	Recipient(); // constructor

	//variables
	string hospital;
	string doc_of_case;

	//functions - methods
	bool isBloodAvailable();
	void displayBloodData();
	void requestAndConfirm();

	~Recipient(); //destructor
};

