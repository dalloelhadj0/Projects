// ------------------------------------------------ Transaction.h -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements variables & functions for Transacton class

// --------------------------------------------------------------------------------------------------------------------


#ifndef PROJECT_4_FINAL_TRANSACTION_H
#define PROJECT_4_FINAL_TRANSACTION_H

#include <iostream>
#include "Customer.h"
using namespace std;


class Transaction {
public:
    Transaction();
    ~Transaction();
    char getTransactionType() const;
    void setTransactionType(char type);
    char getMediaType() const;
    void setMediaType(char type);
    virtual bool setData(string, Customer *&);
    //virtual function to add transaction record to customer's history
private:
    char transactionType;
    char mediaType;
};

#endif //PROJECT_4_FINAL_TRANSACTION_H
