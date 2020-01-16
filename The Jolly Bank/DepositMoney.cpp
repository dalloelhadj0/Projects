//Elhadj Diallo
//Assignment#6
//December 06, 2019
//CSSC UWB Fall2019

/*Process deposit transaction with a giving amound and save the
 * transaction history of the deposit */
#include "DepositMoney.h"

DepositMoney::DepositMoney()
{
}
DepositMoney::DepositMoney(istream& istr)
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

DepositMoney::~DepositMoney()
{
}

int DepositMoney::getAmount() const
{
    return amount;
}

string DepositMoney::historyLog() const
{
    string retVal = Transaction::historyLog();
    retVal += " " + to_string(getAmount());
    return retVal;
}

void DepositMoney::setAmount(int amount)
{
    this->amount = amount;
}
bool DepositMoney::IsValid() const
{
    return valid;
}
