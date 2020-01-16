//Elhadj Diallo
//Assignment#6
//December 06, 2019
//CSSC UWB Fall2019

/*Process withdrawn transaction with a giving amound and save the
 * transaction history of the withdraw amount */

#include "WithdrwmMoney.h"
WithdrwmMoney::WithdrwmMoney()
{
}

WithdrwmMoney::~WithdrwmMoney()
{
}

WithdrwmMoney::WithdrwmMoney(istream& istr)
{
    string ID;
    istr >> ID;
    int length = ID.length();
    if (length > MAX_ID_LENGTH || length < MAX_ID_LENGTH)
    {
        setValid(false);
        cout << "Error: Invalid Account Input" << endl;

    }
    else
    {
        fundType = ID[ID.length() - 1] - '0';
        ID.resize(ID.length() - 1);
        accountID = stoi(ID);
        istr >> amount;
        setValid(true);
    }
}

int WithdrwmMoney::getAmount() const
{
    return amount;
}

string WithdrwmMoney::historyLog() const
{
    string retVal = Transaction::historyLog();
    retVal += " " + to_string(amount);
    return retVal;
}

void WithdrwmMoney::setAmount(int amount)
{
    this->amount = amount;
}

bool WithdrwmMoney::IsValid() const
{
    return valid;
}