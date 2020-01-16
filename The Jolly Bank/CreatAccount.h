//Elhadj Diallo
//Assignment#6
//December 06, 2019
//CSSC UWB Fall2019

/*This account creat account and check account valididty
 * Every account has to has four digit and it convert the fve digit giving
 * by the file to determne which type of transaction in which different funtype
 * it must perform*/

#ifndef OPEN_ACCOUNT_TRANSACTION_H
#define OPEN_ACCOUNT_TRANSACTION_H
#include "Transaction.h"

class CreatAccount : public Transaction
{
public:
    CreatAccount();
    virtual ~CreatAccount();
    CreatAccount(istream& istr);
    bool IsValid() const;
    string getFirstName() const;
    string getLastName() const;
private:
    string firstName;
    string lastName;
};
#endif
