// ------------------------------------------------ Movie.cpp -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements all functions in Movie.h

// --------------------------------------------------------------------------------------------------------------------


#ifndef PROJECT4_MOVIE_H
#define PROJECT4_MOVIE_H

#include <iostream>

using namespace std;

enum MovieType
{
    ComedyType,
    DramaType,
    ClassicalType
};

class Movie {
    friend ostream &operator<<(ostream &outStream, const Movie &rhs);

public:
    Movie();

    virtual ~Movie();

     Movie(const Movie *&);

    virtual int  getStock() const;
    virtual void setStock(int);

    virtual const string & getTitle() const;//returns the title of the movie
    virtual void setTitle(string) ; //sets the Title

    virtual const string & getDirector() const;//the director gets returned
    virtual void setDirector(const string&);//sets the name of the director


    virtual int getYear() const;//get the year when the movie was made
    virtual void setYear(int) ;//sets the year when the movie was made

    virtual MovieType getMovieType() const = 0;

    //checks the equality of two movies
    virtual bool operator==(const Movie &rhs) const ;

    virtual bool operator!=(const Movie &rhs) const ;

    virtual bool operator<(const Movie &rhs) const ;

    virtual bool operator>(const Movie &rhs) const ;

protected:
    string title; //title of the move
    string director;//name of the director
    int year;//the year the movie was made
    int stock; //number of items of a given title


};


#endif //PROJECT4_MOVIE_H
