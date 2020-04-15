// ------------------------------------------------ Drama.h -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements variables & functions for Drama class

// --------------------------------------------------------------------------------------------------------------------


#ifndef PROJECT4_DRAMA_H
#define PROJECT4_DRAMA_H

#include "Movie.h"
class Drama : public Movie {
public:
    Drama();

    Drama(const Drama &);

    virtual ~Drama();

    //functions
    bool isEqual(const Drama &mov) const;
    bool isGreater(const Drama &mov) const;

    virtual MovieType getMovieType() const;

    void print() const;

     bool operator==(const Drama &rhs)const;

     bool operator!=(const Drama &rh)const;

     bool operator<(const Drama &rh) const;

     bool operator>(const Drama &rh) const;
};


#endif //PROJECT4_DRAMA_H
