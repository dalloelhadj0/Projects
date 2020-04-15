// ------------------------------------------------ Drama.cpp -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements all functions in Drama.h

// --------------------------------------------------------------------------------------------------------------------


#include "Drama.h"

Drama::Drama(){
}

Drama::~Drama(){

}

// ------------------------------------isEqual----------------------------------------------
// checks whether one drama object is equal to another. returns boolean
// -------------------------------------------------------------------------------------------
bool Drama::isEqual(const Drama &mov) const
{
    return mov.getDirector().compare(director) == 0 &&
            mov.getTitle().compare(title) == 0;
}
// ------------------------------------isGreater----------------------------------------------
// checks whether one drama object is greater than another. returns boolean
// -------------------------------------------------------------------------------------------
bool Drama::isGreater(const Drama &mov) const
{
    if (director.compare(mov.getDirector()) != 0)
        return director.compare(mov.getDirector()) > 0;

    if (title.compare(mov.getTitle()) != 0)
        return title.compare(mov.getTitle()) > 0;

    return year > mov.getYear();
}

// ------------------------------------getMovieType-------------------------------------------
// Description: returns movie type
// -------------------------------------------------------------------------------------------
MovieType Drama::getMovieType() const // ok
{
    return MovieType::DramaType;
}

// ------------------------------------print--------------------------------------------------
// prints movie info. used for test puposes.
// -------------------------------------------------------------------------------------------
void Drama::print() const
{
    cout << "D, " << stock << ", " << director << ", " << title << ", " << year << endl;
}

// ------------------------------------Compare Operators----------------------------------------------
bool Drama::operator==(const Drama &rhs) const {
    if ( getMovieType() != rhs.getMovieType() || title != rhs.title || year != rhs.year
         || stock != rhs.stock || director != rhs.director ) {
        return false;
    }
    return true;
}

bool Drama::operator!=(const Drama &rhs) const {
    if ( getMovieType() != rhs.getMovieType()|| title != rhs.title || year != rhs.year
         || stock != rhs.stock || director != rhs.director ) {
        return true;
    }
    return false;
}

bool Drama::operator<(const Drama &rhs) const {
    if ( getMovieType() != rhs.getMovieType()&& title < rhs.title && year < rhs.year
         && stock < rhs.stock && director < rhs.director ) {
        return true;
    }
    return false;
}
bool Drama::operator>(const Drama &rhs) const {
    if ( getMovieType() != rhs.getMovieType() && title > rhs.title && year > rhs.year
         && stock > rhs.stock && director > rhs.director ) {
        return true;
    }
    return false;
}