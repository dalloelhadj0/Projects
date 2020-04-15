// ------------------------------------------------ Classic.cpp -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements all functions in Classic.h

// --------------------------------------------------------------------------------------------------------------------


#include "Classic.h"

// ------------------------------------constructor------------------------------------------------
// constructor for Classic class
// -------------------------------------------------------------------------------------------
Classic::Classic(){}

// ------------------------------------destructor------------------------------------------------
// destructor for Classic class
// -------------------------------------------------------------------------------------------
Classic::~Classic(){}

// ------------------------------------copy constructor------------------------------------------------
// copy constructor for Classic class
// -------------------------------------------------------------------------------------------
Classic::Classic(const Classic &rhs) {
    this->stock = rhs.stock;
    this->director = rhs.director;
    this->title = rhs.title;
    this->majorActor= rhs.majorActor;
    this->releaseMonth = rhs.releaseMonth;
}

// ------------------------------------getMajorActor------------------------------------------
// Description: get major actor name
// -------------------------------------------------------------------------------------------
const string & Classic::getMajorActor() const{
    return majorActor;
}

// ------------------------------------setMajorActor------------------------------------------
// Description: sets major actor name
// -------------------------------------------------------------------------------------------
void Classic::setMajorActor(const string & mName)
{
    majorActor = mName;
}

// ------------------------------------getMonth-----------------------------------------------
// Description: returns month
// -------------------------------------------------------------------------------------------
int Classic::getReleaseMonth() const {
    return releaseMonth;
}
// ------------------------------------setMonth-----------------------------------------------
// Description: sets month info
// -------------------------------------------------------------------------------------------
void Classic::setReleaseMonth(int month)
{
    this->releaseMonth = month;
}

// ------------------------------------isEqual------------------------------------------------
// Description: checks whether two classic movies is equal to each other. returns boolean
// -------------------------------------------------------------------------------------------
bool Classic::isEqual(const Classic &mov) const
{
    return mov.getYear() == year &&
            mov.getMajorActor().compare(majorActor) == 0 &&
            mov.getReleaseMonth() == releaseMonth;
}

// ------------------------------------isGreater----------------------------------------------
// Description: checks whether one classics object is greater than another. returns boolean
// -------------------------------------------------------------------------------------------
bool Classic::isGreater(const Classic &mov) const
{
    if (year != mov.getYear())
        return year > mov.getYear();

    if (releaseMonth != mov.getReleaseMonth())
        return releaseMonth > mov.getReleaseMonth();

    return majorActor.compare(mov.getMajorActor()) > 0;
}

//------------------------------------print--------------------------------------------------
// Description: display movie info. used for test puposes.
// -------------------------------------------------------------------------------------------
void Classic::print() const
{
    cout << "C, " << stock << ", " << director << ", " << title <<
    ", " << majorActor << " " << releaseMonth << " " << year << endl;
}

// ------------------------------------getMovieType-------------------------------------------
// Description: returns movie type
// -------------------------------------------------------------------------------------------
MovieType Classic::getMovieType() const
{
    return ClassicalType;
}
//--------------------Operator Overloading----------------------------------------
bool Classic::operator==(const Classic &mov) const {
    return mov.getYear() == year &&
           mov.getMajorActor().compare(majorActor) == 0 &&
           mov.getReleaseMonth() == releaseMonth;
}

bool Classic::operator!=(const Classic &rhs) const {
    if ( getMovieType() != rhs.getMovieType() || title != rhs.title || year != rhs.year
         || stock != rhs.stock || director != rhs.director ) {
        return true;
    }
    return false;
}

bool Classic::operator<(const Classic &rhs) const {
    if ( getMovieType() != rhs.getMovieType() && title < rhs.title && year < rhs.year
         && stock < rhs.stock && director < rhs.director ) {
        return true;
    }
    return false;
}
bool Classic::operator>(const Classic &mov) const {
    if (year != mov.getYear())
        return year > mov.getYear();

    if (releaseMonth != mov.getReleaseMonth())
        return releaseMonth > mov.getReleaseMonth();

    return majorActor.compare(mov.getMajorActor()) > 0;
}