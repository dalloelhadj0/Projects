//Elhadj Diallo
//Assignment#6
//December 06, 2019
//CSSC UWB Fall2019

/*This class print all transaction done by the different account*/

#include "TransactionHistory.h"

TransactionHistory::TransactionHistory()
{
}

TransactionHistory::~TransactionHistory()
{
}

bool TransactionHistory::IsValid() const
{
    return valid;
}

TransactionHistory::TransactionHistory(istream& istr)
{
    string ID;
    istr >> ID;



    if (ID.length() == MAX_ID_LENGTH) // display history by specified fund
    {
        fundType = ID[ID.length() - 1] - '0';
        ID.resize(ID.length() - 1);
        accountID = stoi(ID);
        setValid(true);
    }
    else if(ID.length()	== 4)	// display history by fund
    {
        fundType = -1;
        accountID = stoi(ID);
        setValid(true);
    }
    else
    {
        cout << "Error: Invalid Account Input" << endl;
        setValid(false);
    }




}

void TransactionHistory::updateHistory(Transaction* trans, bool valid)
{
    if (valid)
    {
        history.push_back(trans->historyLog());
    }
    else
    {
        history.push_back(trans->historyLog() + " (Failed)");
    }
}

ostream& operator<<(ostream& istr, const TransactionHistory& rhs)
{
    for (int i = 0; i < rhs.history.size(); i++)
    {

        istr << "   " + rhs.history[i] << endl;

    }

    return istr;
}
