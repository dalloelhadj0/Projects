//
//  Movie.h
//  MovieStore
//
//  Created by leul hagos on 3/1/20.
//  Copyright © 2020 Leul Hagos. All rights reserved.
//

#ifndef Movie_h
#define Movie_h

#include "inventory.h"
using namespace std;
//child of Inventory class 
class Movie: public Inventory
{
    friend ostream& operator<<(ostream& outStream, const Movie& rhs);
public:
    Movie();
    virtual ~Movie();
    Movie(const Movie*& );
    int getStock();
    virtual void setStock(int);
    string getTitle();//returns the title of the movie
    virtual void setTitle(string); //sets the Title
    string getDirector();//the director gets returned
    void setDirector(string);//sets the name of the director
    int getYear();//get the year when the movie was made
    virtual void setYear(int);//sets the year when the movie was made
    char getMovieType();//get the type of the movie
    virtual void setMovieType(char);//set the type of the movie
    
    virtual bool operator==(const & )const = 0;//checks the equality of two movies
    virtual bool operator!=(const & )const = 0;
    virtual bool operator<(const &) const = 0;
    virtual bool operator>(const &) const = 0;
    
protected:
    int stock; //number of items of a given title
    string title; //title of the move
    string director;//name of the director
    int year;//the year the movie was made
    char movieType;//the type of the movie
    };

#endif /* Movie_h */
