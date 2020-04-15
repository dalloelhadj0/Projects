// ------------------------------------------------ Return.h -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements variable & functions for Return

// --------------------------------------------------------------------------------------------------------------------

#ifndef PROJECT_4_FINAL_RETURN_H
#define PROJECT_4_FINAL_RETURN_H

#include "Transaction.h"
#include "Customer.h"
#include <iostream>
using namespace std;

class Return : public Transaction {
public:
    Return();
    ~Return();
    bool setData(string, Customer *&);
    //adds Return transaction history to related customer record
};
#endif //PROJECT_4_FINAL_RETURN_H
