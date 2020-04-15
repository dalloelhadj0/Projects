// ------------------------------------------------ Inventory.h -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements variables & functions for Inventory class

// --------------------------------------------------------------------------------------------------------------------


#ifndef PROJECT4_INVENTORY_H
#define PROJECT4_INVENTORY_H

#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"
#include "BSTree.h"


class Inventory {
public:
    static bool Create(istream &stream, Movie*&);
    Inventory();
   virtual  ~Inventory();

    void readMovieFile(string name);
    void printAllMovies() const;
    //store different type of Movies
    const BSTree<Comedy> &getComedyTree() const;
    const BSTree<Drama> &getDramaTree() const;
    const BSTree<Classic> &getClassicsTree() const;

private:

    static Comedy* CreateComedy(istream &stream);
    static Drama* CreateDrama(istream &stream);
    static Classic* CreateClassic(istream &stream);
    //storing movie base don their type
    BSTree<Comedy> ComedyTree;
    BSTree<Drama> DramaTree;
    BSTree<Classic> ClassicsTree;
    BSTree<Movie> allMovies;

};


#endif //PROJECT4_INVENTORY_H
