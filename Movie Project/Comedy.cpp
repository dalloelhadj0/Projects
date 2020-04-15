// ------------------------------------------------ Comedy.cpp -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements all functions in Comedy.h

// --------------------------------------------------------------------------------------------------------------------


#include "Comedy.h"

//default constructor
Comedy::Comedy() {
}

Comedy::Comedy(const Comedy &rhs) {
    this->stock = rhs.stock;
    this->director = rhs.director;
    this->title = rhs.title;
    this->year = rhs.year;

}

//destructor
Comedy::~Comedy() {}

// ------------------------------------print--------------------------------------------------
// Description: output the current movie
// -------------------------------------------------------------------------------------------

void Comedy::print() const{
    cout << "F, " << stock << ", " << director << ", " << title << ", " << year << endl;
}

// ------------------------------------isEqual------------------------------------------------
// Description: checks whether two comedy movies is equal to each other. returns boolean
// -------------------------------------------------------------------------------------------
bool Comedy::isEqual(const Comedy &node) const
{
    return
            node.getTitle().compare(title) == 0 &&
            node.getYear() == year;
}

// ------------------------------------isGreater----------------------------------------------
// Description: checks whether one comedy object is greater than another. returns boolean
// -------------------------------------------------------------------------------------------
bool Comedy::isGreater(const Comedy &node) const
{
    if (title.compare(node.getTitle()) != 0)
        return title.compare(node.getTitle()) > 0;

    return year > node.getYear();
}

// ------------------------------------getMovieType-------------------------------------------
// Description: returns movie type
// -------------------------------------------------------------------------------------------
MovieType Comedy::getMovieType() const
{
    return MovieType::ComedyType;
}

//--------------------------------OPERATOR-OVERLOADING---------------------------------
//equal operator
bool Comedy::operator==(const Comedy &rhs) const {
    if ( getMovieType() != rhs.getMovieType() || title != rhs.title || year != rhs.year
         || stock != rhs.stock || director != rhs.director ) {
        return false;
    }
    return true;
}

//inequal operator
bool Comedy::operator!=(const Comedy &rhs) const {
    if ( getMovieType() != rhs.getMovieType() || title != rhs.title || year != rhs.year
         || stock != rhs.stock || director != rhs.director ) {
        return true;
    }
    return false;
}

//less then operator
bool Comedy::operator<(const Comedy &rhs) const {
    if ( getMovieType() < rhs.getMovieType() && title < rhs.title && year < rhs.year
         && stock < rhs.stock && director < rhs.director ) {
        return true;
    }
    return false;
}

//geater than operator
bool Comedy::operator>(const Comedy &rhs) const {
    if ( getMovieType() > rhs.getMovieType() && title > rhs.title && year > rhs.year
         && stock > rhs.stock && director > rhs.director ) {
        return true;
    }
    return false;
}

//read Comedy movies
bool Comedy::setData(istream& inFile) {
    if (inFile.eof())
        return false;

    int movieYear;
    inFile >> movieYear;
    setYear(movieYear);
    return true;
}
