
// ------------------------------------------------ Movie.cpp -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements all functions in Movie.h

// --------------------------------------------------------------------------------------------------------------------


#include "Movie.h"

//default constructor
Movie::Movie() {
    stock = 0;
    title = "";
    director = "";
    year = 0;
}

//destructor
Movie::~Movie() {};

Movie::Movie(const Movie *&rhs) {
    this->title = rhs->title;
    this->year = rhs->year;
    this->director = rhs->director;
    this->stock = rhs->stock;
}


// ------------------------------------getTitle-----------------------------------------------
// Description: returns movie title
// -------------------------------------------------------------------------------------------
const string & Movie::getTitle() const {
    return title;
}

// ------------------------------------setTitle-----------------------------------------------
// Description: sets movie title
// -------------------------------------------------------------------------------------------
void Movie::setTitle(string newTitle) {
    this->title = newTitle;
}

// ------------------------------------getYear------------------------------------------------
// Description: returns movie year
// -------------------------------------------------------------------------------------------
int Movie::getYear() const {
    return year;
}

// ------------------------------------setYear------------------------------------------------
// Description: sets movie year
// -------------------------------------------------------------------------------------------
void Movie::setYear(int newYear) {
    this->year = newYear;
}

// ------------------------------------getDirector--------------------------------------------
// Description: returns director's name // the director gets returned
// -------------------------------------------------------------------------------------------
const string & Movie::getDirector() const {
    return director;
}

// ------------------------------------setStock--------------------------------------------
//get the type of the movie
//-------------------------------------------------------------------------------------------
void Movie::setStock(int newStock) {
    this->stock = newStock;
}

// ------------------------------------getStock--------------------------------------------
//get the type of the movie
//-------------------------------------------------------------------------------------------
int Movie::getStock() const {
    return stock;
}

// ------------------------------------setDirector--------------------------------------------
// Description: setsdirector's name //sets the name of the director
// -------------------------------------------------------------------------------------------
void Movie::setDirector(const string &newDirector) {
    this->director = newDirector;
}


//------------------------------  Operator Overloading Movie--------------------------------
bool Movie::operator==(const Movie &rhs) const {
    if ( title == rhs.title && year == rhs.year
         && stock == rhs.stock && director == rhs.director ) {
        return true;
    }
    return false;
}

bool Movie::operator!=(const Movie &rhs) const {
    if ( title != rhs.title || year != rhs.year
        || stock != rhs.stock || director != rhs.director) {
        return true;
    }
    return false;
}

bool Movie::operator<(const Movie &rhs) const {
    if ( title < rhs.title && year < rhs.year
         && stock < rhs.stock && director < rhs.director ) {
        return true;
    }
    return false;
}

bool Movie::operator>(const Movie &rhs) const {
    if (title > rhs.title && year > rhs.year
         && stock > rhs.stock && director > rhs.director ) {
        return true;
    }
    return false;
}

ostream &operator<<(ostream &outStream, const Movie &rhs) {
    return outStream << rhs.getMovieType() << ", " <<rhs.getStock()   << ", "
                     << rhs.getDirector() << ", " << rhs.getTitle()<< ", " << rhs.getYear() << endl;
}