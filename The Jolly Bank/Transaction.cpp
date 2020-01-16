//Elhadj Diallo
//Assignment#6
//December 06, 2019
//CSSC UWB Fall2019


/*This class handle the different type of transaction that
 * the bank can effective and the way they can be read from
 * the file. It save the history of the transaction of every
 * account transaction by using its ID and its funds type*/

#include "Transaction.h"
#include <sstream>

Transaction::Transaction()
{
    valid = true;
}

Transaction::~Transaction()
{
}

//return the transaction chart
char Transaction::getTransactionType() const
{
    return charType;
}

//set the transaction type
void Transaction::setTransactionType(char Type)
{
    charType = Type;
}

//get the account ID
int Transaction::getAccountID() const
{
    return accountID;
}

//get the fund type
int Transaction::getFundType() const
{
    return fundType;
}

//set the accoundID
void Transaction::setAccountID(int ID)
{
    accountID = ID;
}

//set the amount to be effectueted
void Transaction::setAmount(int amount)
{

}

//saving the history of the transaction efectued
string Transaction::historyLog() const
{
    stringstream ss;
    string type;
    ss << getTransactionType();
    ss >> type;
    string retVal = type + " " + to_string(getAccountID()) + "" +
                    to_string(getFundType());
    return retVal;
}

//check if the transaction is valid
bool Transaction::IsValid() const
{
    return valid;
}
void Transaction::setValid(bool valid)
{
    this->valid = valid;
}