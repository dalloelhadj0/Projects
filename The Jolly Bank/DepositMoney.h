//Elhadj Diallo
//Assignment#6
//December 06, 2019
//CSSC UWB Fall2019

/*Process deposit transaction with a giving amound and save the
 * transaction history of the deposit */

#ifndef DEPOSIT_TRANSACTION_H
#define DEPOSIT_TRANSACTION_H
#include "Transaction.h"

class DepositMoney : public Transaction
{

public:
    DepositMoney();
    virtual ~DepositMoney();
    DepositMoney(istream& istr);
    string historyLog() const;
    void setAmount(int amount);
    int getAmount() const;
    bool IsValid() const;

private:
    int amount;
};

#endif