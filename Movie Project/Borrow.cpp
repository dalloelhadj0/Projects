// ------------------------------------------------ Borrow.cpp -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements all functions in Borrow.h

// --------------------------------------------------------------------------------------------------------------------

#include "Borrow.h"

//constructor
Borrow::Borrow() {

}

//destructor
Borrow::~Borrow() {

}

// ------------------------------------setData------------------------------------------------
// adds Borrow transaction history to related customer record
// -------------------------------------------------------------------------------------------
bool Borrow::setData(string title, Customer *&ct) {

    if (title != "" && ct != NULL)
    {
        History ht;
        ht.setMediaType('D');
        ht.setTransType('B');
        ht.setMovie(title);
        ct->addHistory(ht);
        return true;
    }
    return false;
}

