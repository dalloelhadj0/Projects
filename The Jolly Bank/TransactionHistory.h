
//Elhadj Diallo
//Assignment#6
//December 06, 2019
//CSSC UWB Fall2019

/*This class print all transaction done by the different account*/

#ifndef HISTORY_TRANSACTION_H
#define HISTORY_TRANSACTION_H
#include "Transaction.h"
#include <vector>
class TransactionHistory : public Transaction
{
    friend ostream& operator<<(ostream& istr, const TransactionHistory& rhs);
public:
    TransactionHistory();
    virtual ~TransactionHistory();
    TransactionHistory(istream& istr);
    void updateHistory(Transaction* trans, bool valid);
    bool IsValid() const;

private:
    vector<string> history;
};

#endif