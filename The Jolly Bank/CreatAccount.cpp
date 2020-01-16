//Elhadj Diallo
//Assignment#6
//December 06, 2019
//CSSC UWB Fall2019

/*This account creat account and check account valididty
 * Every account has to has four digit and it convert the fve digit giving
 * by the file to determne which type of transaction in which different funtype
 * it must perform*/

#include "CreatAccount.h"

CreatAccount::CreatAccount()
{
}

CreatAccount::CreatAccount(istream& istr)
{
    istr >> lastName;
    istr >> firstName;
    string ID;
    istr >> ID;
    int length = ID.length();
    if (length != 4)
    {
        setValid(false);
        cout << "Error: Invalid Account Input" << endl;

    }
    else
    {
        accountID = stoi(ID);
        setValid(true);
    }
}

bool CreatAccount::IsValid() const
{
    return valid;
}

CreatAccount::~CreatAccount()
{
}
string CreatAccount::getFirstName() const
{
    return firstName;
}
string CreatAccount::getLastName() const
{
    return lastName;
}