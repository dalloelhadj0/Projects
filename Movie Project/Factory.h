
// ------------------------------------------------ Factory.h -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements variables &  functions Factory class

// --------------------------------------------------------------------------------------------------------------------

#ifndef PROJECT_4_FINAL_FACTORY_H
#define PROJECT_4_FINAL_FACTORY_H

#include <iostream>
#include <fstream>
#include "Transaction.h"
#include "HashTable.h"
#include "Borrow.h"
#include "Return.h"
#include "Inventory.h"
using namespace std;
class Factory{

public:
    Factory();
    ~Factory();
    //void buildInventory(); for movie
    bool readCustomer(string file);
    bool readTransaction(string file);
    bool processTransaction(istream&);
    void displayCustomerList() const;
    bool readMovie(string file);
    void displayTransactonHistory() const;
    void displayMovieList() const;
private:
    //vector<Transaction> transInventory;
    HashTable customer;
    Inventory movieInv;
    vector <string> transactionHistory;

    bool changeStock(int numOfStock, char type, istream& movie, string& mTitle);
    //change the number of stock for specific movie
};
#endif //PROJECT_4_FINAL_FACTORY_H
