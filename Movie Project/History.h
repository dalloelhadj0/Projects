// ------------------------------------------------ History.h -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements variables & functions for History class

// --------------------------------------------------------------------------------------------------------------------

#ifndef PROJECT_4_FINAL_HISTORY_H
#define PROJECT_4_FINAL_HISTORY_H

//#include "Transaction.h"
#include <iostream>
using namespace std;

class History {
public:
    History();
    char getMediaType() const;
    string getMovie() const;
    char getTransType() const;
    void setMediaType(char) ;
    void setMovie(string) ;
    void setTransType(char) ;

private:
    char mediaType;
    string movie;
    char transType;
};

#endif //PROJECT_4_FINAL_HISTORY_H
