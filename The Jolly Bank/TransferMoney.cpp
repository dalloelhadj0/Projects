//Elhadj Diallo
//Assignment#6
//December 06, 2019
//CSSC UWB Fall2019

/*Process transfer transaction with a giving amound and save the
 * transaction history of the transfer */
#include "Transaction.h"
#include "TransferMoney.h"
TransferMoney::TransferMoney()
{
}

TransferMoney::TransferMoney(istream& istr)
{
    string ID;
    istr >> ID;
    int length = ID.length();
    if (length > MAX_ID_LENGTH || length < MAX_ID_LENGTH)
    {
        setValid(false);
        cout<< "Error: Invalid Account Input" << endl;

    }
    else
    {
        fundType = ID[ID.length() - 1] - '0';
        ID.resize(ID.length() - 1);
        accountID = stoi(ID);
        istr >> amount;

        string secondID;
        istr >> secondID;
        int secondLength = secondID.length();

        if (secondLength  > MAX_ID_LENGTH || secondLength  < MAX_ID_LENGTH)
        {
            setValid(false);
            cout << "Error: Invalid Account Input" << endl;

        }
        else
        {

            secondFundType = secondID[secondID.length() - 1] - '0';
            secondID.resize(secondID.length() - 1);
            secondaryID = stoi(secondID);
            setValid(true);
        }

    }

}


TransferMoney::~TransferMoney()
{
}
bool TransferMoney::IsValid() const
{
    return valid;
}
int TransferMoney::getSecondaryID() const
{
    return secondaryID;
}

int TransferMoney::getFundType() const
{
    return fundType;
}

int TransferMoney::getSecondFundType() const
{
    return secondFundType;
}

int TransferMoney::getAmount() const
{
    return amount;
}

string TransferMoney::historyLog() const
{
    stringstream ss;
    string type;
    ss << getTransactionType();
    ss >> type;
    string retVal = type + " " + to_string(getAccountID()) + "" +
                    to_string(getFundType()) + " " + to_string(getAmount()) +  " " +
                    to_string(getSecondaryID()) + "" + to_string(getSecondFundType());
    return retVal;
}

void TransferMoney::setAmount(int amount)
{
    this->amount = amount;
}