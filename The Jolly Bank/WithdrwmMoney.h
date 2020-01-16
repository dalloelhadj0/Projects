#ifndef WITHDRAW_TRANSACTION_H
#define WITHDRAW_TRANSACTION_H
#include "Transaction.h"

class WithdrwmMoney : public Transaction
{

public:
    WithdrwmMoney();
    virtual ~WithdrwmMoney();
    WithdrwmMoney(istream& istr);
    int getAmount() const;
    void setAmount(int amount);
    string historyLog() const;
    bool IsValid() const;


private:
    int amount;

};
#endif