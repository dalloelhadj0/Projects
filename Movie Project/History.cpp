// ------------------------------------------------ History.cpp -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements all functions in History.h

// --------------------------------------------------------------------------------------------------------------------


#include "History.h"
#include <iostream>
using namespace std;

//constructor
History::History() {

}


// ------------------------------------getMediaType------------------------------------------------
// returns media type
// -------------------------------------------------------------------------------------------
char History::getMediaType() const {
    return mediaType;
}

// ------------------------------------getMovie------------------------------------------------
// returns movie
// -------------------------------------------------------------------------------------------
string History::getMovie() const {
    return movie;
}

// ------------------------------------getTransType------------------------------------------------
// returns transaciton type
// -------------------------------------------------------------------------------------------
char History::getTransType() const {
    return transType;
}

// ------------------------------------setMediaType------------------------------------------------
// changes media type
// -------------------------------------------------------------------------------------------
void History::setMediaType(char type)  {
    mediaType = type;
}

// ------------------------------------setMovie------------------------------------------------
// changes movie
// -------------------------------------------------------------------------------------------
void History::setMovie(string type)  {
    movie = type;
}

// ------------------------------------setTransType------------------------------------------------
// changes transaction type
// -------------------------------------------------------------------------------------------
void History::setTransType(char type)  {
    transType = type;
}
