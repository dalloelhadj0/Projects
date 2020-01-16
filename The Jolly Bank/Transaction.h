//Elhadj Diallo
//Assignment#6
//December 06, 2019
//CSSC UWB Fall2019

/*This class handle the different type of transaction that
 * the bank can effective and the way they can be read from
 * the file. It save the history of the transaction of every
 * account transaction by using its ID and its funds type*/

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//initialise
const char OPEN = 'O';
const char DEPOSIT = 'D';
const char WITHDRAW = 'W';
const char TRANSFER = 'T';
const char HISTORY = 'H';
const int MAX_ID_LENGTH = 5;
class Transaction
{
public:
    Transaction();
    virtual ~Transaction();
    virtual void setTransactionType(char Type);
    virtual void setAccountID(int ID);
    virtual char getTransactionType() const;
    virtual int getAccountID() const;
    virtual int getFundType() const;
    virtual void setAmount(int amount);
    virtual string historyLog() const;
    virtual bool IsValid() const;
    virtual void setValid(bool valid);
protected:
    bool valid;
    char charType;
    int accountID;
    int fundType;
};


#endif 