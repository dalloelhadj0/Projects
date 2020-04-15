
#ifndef Classic_h
#define Classic_h

#include "Movie.h"
#include <iostream>
using namspace std;
//comdedy class is child of the movie class and grand child of Inventory
//class that hold classic movie data
class Classic: public Movie
{
public:
    Classic();
    ~Classic();
    Classic(const  Classic&);
    
    int getActor();
    int getMonth();
    void setMonth();
    void display();
    
    virtual bool operator==(const & )const;
    virtual bool operator!=(const & )const;
    virtual bool operator<(const &) const;
    virtual bool operator>(const &) const;
private:

    string actor;//name of the actor
    int month;// month was released
    char movieType;//Type of the movie
};

#endif /* Classic_h */
