//Elhadj Diallo
//Assignment#6
//December 06, 2019
//CSSC UWB Fall2019

/*This class creat an account and open qo different type for the account
 * and linked the type of fund to the account. It help the program g=creat
 * new type of account every time we have to creat a new onea and it is store
 * in a BSTree class*/

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include "Transaction.h"
#include "DepositMoney.h"
#include "CreatAccount.h"
#include "WithdrwmMoney.h"
#include "TransactionHistory.h"
#include "TransferMoney.h"
const int MAX_FUND_SIZE = 10;
const string FUNDS[10] = {
        "Money Market",
        "Prime Money Market",
        "Long-Term Bond",
        "Short-Term Bond",
        "500 Index Fund",
        "Capital Value Fund",
        "Growth Equity Fund",
        "Growth Index Fund",
        "Value Fund",
        "Value Stock Index"
};

using namespace std;
class Account
{
    friend ostream& operator<<(ostream& os, const Account& rhs);
public:
    Account();
    Account(string firstName, string lastName, int ID);
    ~Account();
    void setName(string firstName, string lastName);
    void setID(int ID);
    string getFirstName() const;
    string getLastName() const;
    bool Deposit(Transaction *&  depositAmount);
    bool Withdraw(int amount, int fundType, Transaction *&  withdrawAmount);
    bool Transfer(Transaction *&  transferAmount, Account& accountToTransfer);
    int getID() const;
    void displayHistory() const;
    void displayHistoryBySpecifiedFund(int fundType) const;

    //operators overloading to help compare account
    bool operator<(const Account& rhs) const;
    bool operator>(const Account& rhs) const;
    bool operator<=(const Account& rhs) const;
    bool operator>=(const Account& rhs) const;
    bool operator==(const Account& rhs) const;
    bool operator!=(const Account& rhs) const;
    //enum classs to handle the FundType
    enum FundType
    {
        MoneyMarket,
        PrimeMoneyMarket,
        LongTermBond,
        ShortTermBond,
        IndexFund500,
        CapitalValueFund,
        GrowthEquityFund,
        GrowthIndexFund,
        ValueFund,
        ValueStockIndex
    };

private:
    bool withdrawHelper(int firstFund, int secondFund, int amount, Transaction *&  trans);
    string firstName;
    string lastName;
    int ID;
    int Balance;
    int fundType;
    vector<bool> active;
    vector<int> fundBalance;
    vector<TransactionHistory> historyLog;

};

#endif