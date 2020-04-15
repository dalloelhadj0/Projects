// ------------------------------------------------ Classic.h -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements variables & functions for Classic class

// --------------------------------------------------------------------------------------------------------------------


#ifndef PROJECT4_CLASSIC_H
#define PROJECT4_CLASSIC_H
#include "Movie.h"

class Classic : public Movie {
public:
    Classic();

    virtual ~Classic();

    Classic(const Classic &rhs);

    int getReleaseMonth() const;
    void setReleaseMonth(int year);


    virtual const string & getMajorActor() const;
    virtual void setMajorActor(const string & name);

    virtual bool isEqual(const Classic &mov) const;
    virtual bool isGreater(const Classic &mov) const;

    virtual MovieType getMovieType() const;
    void print() const;

    //-------------Operator Overloading--------------------------
     bool operator==(const Classic &rhs)const;

     bool operator!=(const Classic &rhs)const;

     bool operator<(const Classic &rhs) const;

     bool operator>(const Classic &rhs) const;

private:
    string majorActor;//name of the actor
    int releaseMonth;// month was released

};


#endif //PROJECT4_CLASSIC_H
