//Elhadj Diallo
//Assignment#6
//December 06, 2019
//CSSC UWB Fall2019

/*This class creat an account and open qo different type for the account
 * and linked the type of fund to the account. It help the program g=creat
 * new type of account every time we have to creat a new onea and it is store
 * in a BSTree class*/
#include "Account.h"
#include <iostream>
#include "TransferMoney.h"
using namespace std;

Account::Account()
{
    firstName = "";
    lastName = "";
    Balance = 0;
    fundType = 0;
    ID = 0;
}

Account::Account(string firstName, string lastName, int ID)
{
    //initialized firstName, lastName, ID
    //and the array that holds the individual balances of the funds
    setName(firstName, lastName);
    setID(ID);
    fundBalance.resize(MAX_FUND_SIZE);
    historyLog.resize(MAX_FUND_SIZE);
    active.resize(MAX_FUND_SIZE);
    for (int i = 0; i < MAX_FUND_SIZE; i++)
    {
        fundBalance[i] = 0;
        active[i] = false;
    }
    Balance = 0;


}

Account::~Account()
{

}

void Account::setName(string firstName, string lastName)
{
    this->firstName = firstName;
    this->lastName = lastName;
}

void Account::setID(int ID)
{
    this->ID = ID;
}

string Account::getFirstName() const
{
    return firstName;
}

string Account::getLastName() const
{
    return lastName;
}


int Account::getID() const
{
    return ID;
}

bool Account::operator<(const Account& rhs) const
{
    return ID < rhs.ID;
}
bool Account::operator>(const Account& rhs) const
{
    return ID > rhs.ID;
}
bool Account::operator<=(const Account& rhs) const
{
    return ID <= rhs.ID;
}
bool Account::operator>=(const Account& rhs) const
{
    return ID >= rhs.ID;
}
bool Account::operator==(const Account& rhs) const
{
    return ID == rhs.ID;
}
bool Account::operator!=(const Account& rhs) const
{
    return ID != rhs.ID;
}


bool Account::Deposit(Transaction *&  trans)
{
    DepositMoney* depositAmount = dynamic_cast<DepositMoney*>(trans);
    int amount = depositAmount->getAmount();	// retreive amount to deposit
    int fundType = depositAmount->getFundType(); // retreive fund type to depoit to
    if (amount < 0)		// verifiying valid amount to deposit
    {
        return false;
    }
    else
    {
        Balance += amount; // update the total balnce
        fundBalance[fundType] += amount; // update the individual fund type
        historyLog[fundType].updateHistory(trans,true);
        active[fundType] = true;
        return true;
    }

}
bool Account::Withdraw(int amount, int fundType, Transaction *&  trans)
{

    if (amount > Balance)		//verifying valid amount to withdraw
    {
        historyLog[fundType].updateHistory(trans,false);
        active[fundType] = true;
        return false;
    }
    else if (amount <= fundBalance[fundType])    // case: there are enough funds to withdraw from
    {

        Balance -= amount;        // update total balance
        fundBalance[fundType] -= amount; // update balance of fund type
        historyLog[fundType].updateHistory(trans, true);
        active[fundType] = true;
        return true;
    } else if (fundType == MoneyMarket) {

        if (withdrawHelper(MoneyMarket, PrimeMoneyMarket, amount, trans)) {

            return true;
        }
    } else if (fundType == PrimeMoneyMarket) {

        if (withdrawHelper(PrimeMoneyMarket, MoneyMarket, amount, trans)) {
            return true;
        }
    } else if (fundType == LongTermBond) {
        if (withdrawHelper(LongTermBond, ShortTermBond, amount, trans)) {
            return true;
        }
    } else if (fundType == ShortTermBond) {
        if (withdrawHelper(ShortTermBond, LongTermBond, amount, trans)) {
            return true;
        }
    } else {
        historyLog[fundType].updateHistory(trans, false);
        return false;
    }

    return true;
}

//withraw function that handles coverage
//returns true if successfully withdrew
bool Account::withdrawHelper(int firstFund, int secondFund, int amount, Transaction *&  trans)
{
    int combinedBalance = fundBalance[firstFund] + fundBalance[secondFund];
    if (combinedBalance >= amount)
    {
        trans->setAmount(fundBalance[firstFund]);
        historyLog[firstFund].updateHistory(trans,true);
        int remaining = amount - fundBalance[firstFund];
        fundBalance[firstFund] = 0;
        fundBalance[secondFund] -= remaining;
        Balance -= amount;
        trans->setAmount(remaining);
        historyLog[secondFund].updateHistory(trans,true);
        active[firstFund] = true;
        active[secondFund] = true;
        return true;
    }

    historyLog[firstFund].updateHistory(trans,false);
    return false;

}

//function that transfers amount to another account by refereence
bool Account::Transfer(Transaction *&  trans, Account& accountToTransfer)
{

    TransferMoney* transferAmount = dynamic_cast<TransferMoney*>(trans); //dynamically cast to it's child class

    int fundType = transferAmount->getFundType(); // retrieve the fund type to transfer from
    int toFund = transferAmount->getSecondFundType(); // retrieve the fund type to transfer to
    int amount = transferAmount->getAmount(); // retrieve the amount to transfer



    if (amount < 0)	// verify valid amount
    {
        return false;
    }
    else
    {

        Withdraw(amount, fundType, trans);
        accountToTransfer.Balance += amount;
        accountToTransfer.fundBalance[toFund] += amount;
        trans->setAmount(amount);
        accountToTransfer.historyLog[toFund].updateHistory(trans, true);
        active[toFund] = true;
        return true;
    }
}

void Account::displayHistory() const
{
    cout << "Transaction History for " << firstName << " " << lastName << " by fund." << endl;
    for (int i = 0; i < MAX_FUND_SIZE; i++)
    {
        if (active[i] != false)
        {
            cout << FUNDS[i] << ": $" << fundBalance[i] << endl;
            cout << historyLog[i];

        }
    }

}

void Account::displayHistoryBySpecifiedFund(int fundType) const
{
    cout << "Transaction History for " << firstName << " " <<
         lastName << " " << FUNDS[fundType] << ": $" << fundBalance[fundType] << endl;
    cout << historyLog[fundType];
}

ostream& operator<<(ostream& os, const Account& rhs)
{
    os << rhs.getFirstName() << " " << rhs.getLastName() << " Account ID: " << rhs.getID() << endl;
    for (int i = 0; i < MAX_FUND_SIZE; i++)
    {
        os << "\t" << FUNDS[i] << ": $" << rhs.fundBalance[i] << endl;
    }
    return os;

}