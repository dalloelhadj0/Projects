// ------------------------------------------------ Comedy.h -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements variables & functions for  Comedy class

// --------------------------------------------------------------------------------------------------------------------

#ifndef PROJECT4_COMEDY_H
#define PROJECT4_COMEDY_H
#include "Movie.h"

class Comedy : public Movie {
    friend ostream &operator<<(ostream &outStream, const Comedy &rhs);

public:
    Comedy();

    //Comedy(int year) {  year =  }
    Comedy(const Comedy &rhs);

    virtual ~Comedy();

     void print() const;

    //functions
    bool isEqual(const Comedy &comedy) const;
    bool isGreater(const Comedy &comedy) const;

    virtual MovieType getMovieType() const;
    bool setData(istream&);

     //--------------------Operator Overloading-----------------------------------
     bool operator==(const Comedy &rhs)const;

     bool operator!=(const Comedy &rhs)const;

     bool operator<(const Comedy &rhs) const;

     bool operator>(const Comedy &rhs) const;
};


#endif //PROJECT4_COMEDY_H
