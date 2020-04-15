// ------------------------------------------------ Return.cpp -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements all functions in Return.h

// --------------------------------------------------------------------------------------------------------------------


#include "Return.h"

//constructor
Return::Return() {  }

//destructor
Return::~Return() { }

// ------------------------------------setData------------------------------------------------
// adds Return transaction history to related customer record
// -------------------------------------------------------------------------------------------
bool Return::setData(string title, Customer *&ct) {
    if (title != "" && ct != NULL)
    {
        History ht;
        ht.setMediaType(getMediaType());
        ht.setTransType('R');
        ht.setMovie(title);
        ct->addHistory(ht);
        return true;
    }
    return false;
}



