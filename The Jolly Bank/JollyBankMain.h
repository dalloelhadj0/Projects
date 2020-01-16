//Elhadj Diallo
//Assignment#6
//December 06, 2019
//CSSC UWB Fall2019

/*This is my main and also class that handle and process the transaction by using a queue
 *string qeueue. This queue help us effectue the transaction in order they are reading
 * to the file*/

#ifndef BANK_H
#define BANK_H
#include "BSTree.h"
#include "Transaction.h"
#include "CreatAccount.h"
#include "DepositMoney.h"
#include "WithdrwmMoney.h"
#include "TransferMoney.h"
#include "TransactionHistory.h"
#include <queue>
#include <string>
using namespace std;

class JollyBankMain
{
public:
    JollyBankMain();
    ~JollyBankMain();
    const BSTree getAccounts() const;
    const queue<Transaction*> getTransactions() const;
    bool CreateTransactionsFromFile(string fileName);
    void ProcessTransactionsInOrder();
    void DisplayAccounts() const;

private:
    //private helper functions to process transactions
    Transaction* CreateTransaction(string file);
    bool PerformTransaction(Transaction *& trans);
    void Deposit(Transaction*& trans);
    void Withdraw(Transaction *&  trans);
    void Transfer(Transaction *& trans);
    void OpenAccount(Transaction *& trans);
    void DisplayHistory(Transaction *& trans) const;
    BSTree accounts;
    queue<Transaction*> transactions;
};

#endif 