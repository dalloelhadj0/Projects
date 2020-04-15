// ------------------------------------------------ Transaction.cpp -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements all functions in Transaction.h

// --------------------------------------------------------------------------------------------------------------------

#include "Transaction.h"

//constructor
Transaction::Transaction() {

}

//destructor
Transaction::~Transaction() {

}

// ------------------------------------getTransactionType------------------------------------------------
// returns transaction type
// -------------------------------------------------------------------------------------------
char Transaction::getTransactionType() const {
    return transactionType;
}

// ------------------------------------setTransactionType------------------------------------------------
// change transction type
// -------------------------------------------------------------------------------------------
void Transaction::setTransactionType(char type) {
    transactionType = type;
}

// ------------------------------------getMediaType------------------------------------------------
// returns media type
// -------------------------------------------------------------------------------------------
char Transaction::getMediaType() const {
    return mediaType;
}

// ------------------------------------setMediaType------------------------------------------------
// change media type
// -------------------------------------------------------------------------------------------
void Transaction::setMediaType(char type) {
    mediaType = type;
}

// ------------------------------------setData------------------------------------------------
// virtual function to add transacion history to costomer record
// -------------------------------------------------------------------------------------------
bool Transaction::setData(string, Customer *&ct) {
    return false;
}
