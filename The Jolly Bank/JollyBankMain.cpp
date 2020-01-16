//Elhadj Diallo
//Assignment#6
//December 06, 2019
//CSSC UWB Fall2019

/*This is my main and also class that handle and process the transaction by using a queue
 *string qeueue. This queue help us effectue the transaction in order they are reading
 * to the file*/

#include "JollyBankMain.h"
#include "Transaction.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc == 2) {
        //creat a bank
        JollyBankMain MyBank;
        //read the file and then creat transaction based on the file containt.
        MyBank.CreateTransactionsFromFile(argv[1]);
        //This call effectue all the transaction  withing the queue
        MyBank.ProcessTransactionsInOrder();
        //Call Display all Accound
        // Destroy all account
        // output message stating all destroyed if the queue is empty
        MyBank.DisplayAccounts();
        return 0;
    } else {
        //If commande argument fail display this message
        cout << "Enter the name of the file correctly like this: FileName.txt" << endl;
        return 1;
    }
};

bool JollyBankMain::CreateTransactionsFromFile(string fileName) {
    queue<string> myTra;
    ifstream file(fileName);
    string readLine;
    if (!file)            // unable to find the file
    {
        cout << "Error No such file found " << endl;
    }

    while (getline(file, readLine))                //read until the file is empty
    {
        Transaction *transaction;                    // creates a dynamically alloacted
        transaction = CreateTransaction(readLine); // Transaction pointer of the proper type

        if (readLine == "")
            break;
        if (transaction->IsValid()) {
            transactions.push(transaction);
        }
    }
    file.close();
    return true;
}

//default constructor
JollyBankMain::JollyBankMain() {
}

//destructor
JollyBankMain::~JollyBankMain() {
    while (!transactions.empty()) {
        Transaction *save = transactions.front();
        delete save;
        save = nullptr;
        transactions.pop();
    }
}

const BSTree JollyBankMain::getAccounts() const {
    return accounts;
}

//reading and return the transaction done in the queue
const queue<Transaction *> JollyBankMain::getTransactions() const {
    return transactions;
}

//process the transaction in the queue
void JollyBankMain::ProcessTransactionsInOrder() {
    while (!transactions.empty()) {

        if (transactions.front() != nullptr) {

            PerformTransaction(transactions.front()); //perform transactions in order from the queue
        }
        transactions.pop();
    }
    cout << "\nProcessing Done.";
}

Transaction *JollyBankMain::CreateTransaction(string file) {
    stringstream fileStream(file); //convert to an istream
    Transaction *retVal = nullptr;
    char type;
    fileStream >> type; // read the first char to determine
    if (type == OPEN)    // which child class to dynamically allocate
    {
        retVal = new CreatAccount(fileStream);
        retVal->setTransactionType(type);
    } else if (type == DEPOSIT) {
        retVal = new DepositMoney(fileStream);
        retVal->setTransactionType(type);
    } else if (type == WITHDRAW) {
        retVal = new WithdrwmMoney(fileStream);
        retVal->setTransactionType(type);
    } else if (type == TRANSFER) {
        retVal = new TransferMoney(fileStream);
        retVal->setTransactionType(type);
    } else if (type == HISTORY) {
        retVal = new TransactionHistory(fileStream);
        retVal->setTransactionType(type);
    }

    return retVal;
}

void JollyBankMain::DisplayAccounts() const {
    if (!accounts.isEmpty()) {
        cout << " Final Balances" << endl;
        accounts.Display();
    } else {
        cout << "Queue Empty or All destroyed." << endl;
    }
}

bool JollyBankMain::PerformTransaction(Transaction *&trans) {

    char Type = trans->getTransactionType();
    if (Type == OPEN) {
        OpenAccount(trans);
    } else if (Type == DEPOSIT) {
        Deposit(trans);
    } else if (Type == WITHDRAW) {
        Withdraw(trans);
    } else if (Type == TRANSFER) {
        Transfer(trans);
    } else if (Type == HISTORY) {
        DisplayHistory(trans);
    } else {
        cout << "Invalid input" << endl;
        return false;
    }
    return true;
}

void JollyBankMain::Deposit(Transaction *&trans) {
    //dynamically cast to child class
    DepositMoney *deposit = dynamic_cast<DepositMoney *>(trans);
    Account *accountToDeposit;
    if (accounts.Retrieve(deposit->getAccountID(), accountToDeposit)) // validate if account exists
    {
        accountToDeposit->Deposit(trans);
    } else {
        cout << "ERROR: Account " << deposit->getAccountID() << " not found.Deposit refused" << endl;
    }
    delete trans;
    trans = nullptr;

}

//withdraw transaction done by transfering money from one account to another acound
void JollyBankMain::Withdraw(Transaction *&trans) {
    \
    //dynamically casts to child class
    WithdrwmMoney *withdraw = dynamic_cast<WithdrwmMoney *>(trans);
    Account *accountToWithdraw;
    if (accounts.Retrieve(withdraw->getAccountID(), accountToWithdraw)) // verifying funds
    {
        bool sufficientFunds = accountToWithdraw->Withdraw(withdraw->getAmount(), withdraw->getFundType(), trans);
        if (!sufficientFunds) //print error message if there are insufficientFunds
        {
            cout << "ERROR: Not enough funds to withdraw " << withdraw->getAmount() << " from " <<
                 accountToWithdraw->getFirstName() + " " +
                 accountToWithdraw->getLastName() << +" " + FUNDS[trans->getFundType()] << endl;
        }
    } else {
        cout << "ERROR: Account " << to_string(trans->getAccountID()) << " not found. Withdraw refused" << endl;
    }

    delete trans;
    trans = nullptr;

}


void JollyBankMain::Transfer(Transaction *&trans) {
    TransferMoney *transfer = dynamic_cast<TransferMoney *>(trans);
    Account *accountToTransFrom;
    Account *ToAccount;

    string accountNumber = to_string(trans->getAccountID());

    bool AccountExists = accounts.Retrieve(trans->getAccountID(), accountToTransFrom);
    bool OtherAccountExists = accounts.Retrieve(transfer->getSecondaryID(), ToAccount);
    if (AccountExists && OtherAccountExists) {
        accountToTransFrom->Transfer(trans, *ToAccount);
    } else {
        accountNumber = to_string(trans->getAccountID()) + " and " + to_string(transfer->getSecondaryID());
        if (AccountExists && !OtherAccountExists) {
            accountNumber = to_string(transfer->getSecondaryID());
        } else if (!AccountExists && OtherAccountExists) {
            accountNumber = to_string(trans->getAccountID());
        }


        cout << "ERROR: Account " << accountNumber << " not found. Transferral refused" << endl;

    }
    delete trans;
    trans = nullptr;

}

//opening new account if doesnt exist before transfering money
void JollyBankMain::OpenAccount(Transaction *&trans) {

    Account *pAccount;
    accounts.Retrieve(trans->getAccountID(), pAccount);
    if (pAccount == nullptr) // verifyiing doesn't exit
    {
        CreatAccount *open = dynamic_cast<CreatAccount *>(trans);
        pAccount = new Account(open->getFirstName(), open->getLastName(), open->getAccountID());
        accounts.Insert(pAccount);
    } else {
        cout << "ERROR: Account " << trans->getAccountID() << " is already open. Transaction refused." << endl;
    }

    delete trans;
    trans = nullptr;
}

//display the history of transaction from a bank
void JollyBankMain::DisplayHistory(Transaction *&trans) const {
    Account *history;
    if (accounts.Retrieve(trans->getAccountID(), history)) {
        if (trans->getFundType() == -1) {
            history->displayHistory();
        } else {
            history->displayHistoryBySpecifiedFund(trans->getFundType());
        }
    } else {
        cout << "ERROR: Account " << trans->getAccountID() << " not found. History refused" << endl;
    }
    delete trans;
    trans = nullptr;
}