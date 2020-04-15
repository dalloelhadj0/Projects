
#ifndef Comedy_h
#define Comedy_h

#include "Movie.h"
#include <iostream>
using namspace std;

//comdedy class is child of the movie class and grand child of
//Inventory class that hold comedy movie data
class comedy: public Movie
{
public:
    Comedy();
    〜Comedy();
    Comedy(const Comedy&);
    
    virtual void setData(istream&)
    virtual void display();
    virtual bool operator==(const & )const;
    virtual bool operator!=(const & )const;
    virtual bool operator<(const &) const;
    virtual bool operator>(const &) const;
private:
    char movieType;//the type of the movie
};

#endif /* Comedy_h */
