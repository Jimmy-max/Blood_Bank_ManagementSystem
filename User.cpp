#include "User.h"
#include <regex>
#include <windows.h>

// constructor
User::User() {
	int id;
	string name;
	string mail;
	string password;
	int age;
	string  gender;
	string blood_type;
}


 bool User::Email_check(string email)
{
	const regex pattern("(\\w+)(\\.|_)?(\\w*)@gmail.com");
	return regex_match(email, pattern);
}

// destructor
User::~User() {

}

void User::clear_screen(char fill) {
	fill = ' ';
	COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}