// ------------------------------------------------ Inventory.cpp -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements all functions in Inventory.h

// --------------------------------------------------------------------------------------------------------------------


#include "Inventory.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
using  namespace std;

Inventory::Inventory(){}

Inventory::~Inventory(){}


// ------------------------------------readMovieFile-----------------------------------------
// Description: reads from .txt file and insert each movie in
// movies in corresponding binary search tree.
// ------------------------------------------------------------------------------------------
void Inventory::readMovieFile(string name) {
    //const string movieFileName = "data4movies.txt";
    fstream infile(name, ios_base::in);

    if (infile.fail())
    {
        cerr << "Can't find movie file: " << endl;
        return;
    }

    while(!infile.eof())
    {
        Movie* movie;
        if (!Inventory::Create(infile, movie))
            continue;

        if (movie)
        {
            switch (movie->getMovieType())
            {
                case MovieType ::ComedyType:
                   ComedyTree.insert(dynamic_cast<Comedy *>(movie));
                    //ComedyTree.print();
                    break;
                case MovieType::DramaType:
                    DramaTree.insert(dynamic_cast<Drama *>(movie));
                    //DramaTree.print();
                    break;
                case MovieType::ClassicalType:
                    ClassicsTree.insert(dynamic_cast<Classic *>(movie));
                    //ClassicsTree.print();
                    break;
                default:
                    throw new logic_error("Unexpected type");

            }
        }
    }
}

// ------------------------------------create-------------------------------------------------
// Description: reads from the file. creates movies . Depending on the movie type calls
// corresponding helper methods
// -------------------------------------------------------------------------------------------
bool Inventory::Create(istream &stream, Movie*& movie) {
    char movieType;
    int movieStock;
    string movieDirector;
    string movieTitle;

    stream >> movieType;
    if (stream.fail())
        return false;

    stream.ignore();
    stream >> movieStock;
    stream.ignore();
    getline(stream >> ws, movieDirector, ',');
    stream.ignore();
    getline(stream >> ws, movieTitle, ',');


    switch (movieType)
    {
        case 'F':
            movie = CreateComedy(stream);
            break;
        case 'C':
            movie = CreateClassic(stream);
            break;
        case 'D':
            movie = CreateDrama(stream);
            break;
        case 'Z':
            stream.ignore();
        default:
            cout << "Invalid movie type: " << movieType << endl;
            stream.ignore(512, '\n');
            return false;
            break;
    }

    movie->setDirector(movieDirector);
    movie->setTitle(movieTitle);
    movie->setStock(movieStock);

    return true;
}

// ------------------------------------Create Comedy-------------------------------------------
// Description: helper method to create comedy movie
// -------------------------------------------------------------------------------------------
Comedy* Inventory::CreateComedy(istream &stream){
    int movieYear;
    stream >> movieYear;
    Comedy *comedy = new Comedy();
    comedy->setYear(movieYear);

    return comedy;
}

// ------------------------------------Create Drama-------------------------------------------
// Description: helper method to create drama movie
// -------------------------------------------------------------------------------------------
Drama * Inventory::CreateDrama(istream &stream){
    int movieYear;
    stream >> movieYear;
    Drama *drama = new Drama();
    drama-> setYear(movieYear);

    return drama;
}

// ------------------------------------CreateClassics -------------------------------------------
// Description: helper method to create classics  movie
// -------------------------------------------------------------------------------------------
Classic* Inventory::CreateClassic(istream &stream){
    int movieMonth;
    int movieYear;
    string movieMajorActorName;
    string movieMajorActorLastname;

    stream >> movieMajorActorName;
    stream >> movieMajorActorLastname;
    stream >> movieMonth;
    stream >> movieYear;

    Classic *classics = new Classic();

    classics->setMajorActor(movieMajorActorName + " " + movieMajorActorLastname);
    classics->setReleaseMonth(movieMonth);
    classics->setYear(movieYear);

    return classics;
}

// -------------------------------------getComedyTree()--------------------------------------
// Description: returns the three that holds comedy movies
// ------------------------------------------------------------------------------------------

const BSTree<Comedy> & Inventory::getComedyTree() const
{
    return ComedyTree;
}

// -------------------------------------getDramaTree()---------------------------------------
// Description: returns the three that holds drama movies
// ------------------------------------------------------------------------------------------
const BSTree<Drama> & Inventory::getDramaTree() const
{
    return DramaTree;
}

// -------------------------------------getClassicsTree()------------------------------------
// Description: returns the three that holds classics movies
// ------------------------------------------------------------------------------------------
const BSTree<Classic> & Inventory::getClassicsTree() const
{
    return ClassicsTree;
}

void Inventory::printAllMovies() const{
    getComedyTree().print();
    getDramaTree().print();
    getClassicsTree().print();
}
