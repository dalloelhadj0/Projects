//Elhadj Diallo
//Assignment#6
//December 06, 2019
//CSSC UWB Fall2019

/*Process transfer transaction with a giving amound and save the
 * transaction history of the transfer */

#ifndef TRANSFER_TRANSACTION_H
#define TRANSFER_TRANSACTION_H
#include "Transaction.h"
#include <sstream>
class TransferMoney : public Transaction
{
public:
    TransferMoney();
    virtual ~TransferMoney();
    TransferMoney(istream& istr);
    int getFundType() const;
    int getSecondaryID() const;
    int getSecondFundType() const;
    int getAmount() const;
    void setAmount(int amount);
    string historyLog() const;
    bool IsValid() const;


private:
    int secondFundType;
    int secondaryID;
    int amount;
};

#endif