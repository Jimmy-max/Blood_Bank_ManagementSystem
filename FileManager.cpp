#include "FileManager.h"


///
/// 
/// Donor Functions
/// 
///
void FileManager::readDonor(vector<Donor>& donor) {
    ifstream file;
    file.open("Donor.txt", ios::in);
    Donor d;
    while (!file.eof())
    {
        //Initiating vars
        int id;
        string name;
        string mail;
        string password;
        int age;
        string  gender;
        string blood_type;
        string suffersFromDisease;
        string other;
        string date_latest_donation;

        //Reading files
        file>> id >> name >> mail >> password >> age >> gender >> blood_type >> suffersFromDisease >> other >> date_latest_donation;
        
        //Transefering to the Vector
        d.id = id;
        d.name = name;
        d.mail = mail;
        d.password = password;
        d.age = age;
        d.gender = gender;
        d.blood_type = blood_type;
        d.suffersFromDisease = suffersFromDisease;
        d.other = other;
        d.date_latest_donation = date_latest_donation;
        donor.push_back(d);
    }
    file.close();
}

//Write ""Method"" 3shan gemy
void FileManager::writeDonor(vector<Donor>donor) {
    ofstream file;
    file.open("Donor.txt", ios::out);
    Donor std;
    int flag = 0;
    for (size_t i = 0; i < donor.size(); i++)
    {
        file <<donor[i].id << endl << donor[i].name << endl << donor[i].mail << endl << donor[i].password << endl <<
            donor[i].age << endl << donor[i].gender << endl << donor[i].blood_type << endl <<
            donor[i].suffersFromDisease << endl << donor[i].other << endl << donor[i].date_latest_donation;
        if (flag < donor.size() - 1)
            file << endl;
        flag++;
    }
    file.close();
}


///
/// 
/// Recipient Functions
/// 
///
void FileManager::readRecipient(vector<Recipient>& recipient) {
    ifstream file;
    file.open("Recipient.txt", ios::in);
    Recipient r;
    while (!file.eof())
    {
        //Initiating vars
        int id;
        string name;
        string mail;
        string password;
        int age;
        string  gender;
        string blood_type;
        string hospital;
        string doc_of_case;

        //Reading files
        file >> id >> name >> mail >> password >> age >> gender >> blood_type >> hospital >> doc_of_case;

        //Transefering to the Vector
        r.id = id;
        r.name = name;
        r.mail = mail;
        r.password = password;
        r.age = age;
        r.gender = gender;
        r.blood_type = blood_type;
        r.hospital = hospital;
        r.doc_of_case = doc_of_case;
        recipient.push_back(r);
    }
    file.close();
}

//Write ""Method"" 3shan gemy
void FileManager::writeRecipient(vector<Recipient> recipient) {
    ofstream file;
    file.open("Recipient.txt", ios::out);
    Recipient r;
    int flag = 0;
    for (size_t i = 0; i < recipient.size(); i++)
    {
        file << recipient[i].id << endl << recipient[i].name << endl << recipient[i].mail << endl << recipient[i].password << endl <<
            recipient[i].age << endl << recipient[i].gender << endl << recipient[i].blood_type << endl <<
            recipient[i].hospital << endl << recipient[i].doc_of_case;
        if (flag < recipient.size() - 1)
            file << endl;
        flag++;
    }
    file.close();
}
