
#ifndef Drama_h
#define Drama_h

#include "Movie.h"
#include <iostream>
using namspace std;

//comdedy class is child of the movie class and grand child of Inventory
//class that hold drama movie data
class Drama: public Movie
{
public:
    Drama();
    ~Drama();
    Drama(const Drama&);
    
    virtual void setData(istream& )
    virtual void display();
    virtual bool operator==(const & )const;
    virtual bool operator!=(const & )const;
    virtual bool operator<(const &) const;
    virtual bool operator>(const &) const;
private:

    char movieType;//the type of the movie
    
    };
    
#endif /* Drama_h */
