// ------------------------------------------------ Factory.cpp -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements all functions in Factory.h

// --------------------------------------------------------------------------------------------------------------------

#include "Factory.h"
#include <fstream>
#include <sstream>

using namespace std;

//constructor
Factory::Factory() {
}

//destructor
Factory::~Factory() {
}


// ------------------------------------readCustomer------------------------------------------------
// read customer's file
// -------------------------------------------------------------------------------------------
bool Factory::readCustomer(string file) {
    ifstream inFile(file);

    if (!inFile.is_open())
    {
        cout << "File fail to open" << endl;
        return false;
    }

    while (!inFile.eof())
    {
        if (!customer.setData(inFile))
            return false;
    }
    return true;
}

// ------------------------------------readTransaction------------------------------------------------
// read transaction file
// -------------------------------------------------------------------------------------------
bool Factory::readTransaction(string file) {
    ifstream inFile(file);

    if (!inFile.is_open())
    {
        cout << "File fail to open" << endl;
        return false;
    }
    string line;
    while (!inFile.eof())
    {
        processTransaction(inFile);

    }
    return true;
}

// ------------------------------------readMovie------------------------------------------------
// read movie file
// -------------------------------------------------------------------------------------------
bool Factory::readMovie(string file) {
    ifstream inFile(file);

    if (!inFile.is_open())
    {
        cout << "File fail to open" << endl;
        return false;
    }

    movieInv.readMovieFile(file);
    return true;
}

// ------------------------------------processTransaction------------------------------------------------
// process transactions
// -------------------------------------------------------------------------------------------
bool Factory::processTransaction(istream& inFile) {


    int id;
    char type, media, movieType;
    string title, tmp;

    //inFile.ignore();
    inFile >> type;
    if (inFile.fail())
        return false;

    if (type != 'H' &&  type != 'B' &&type != 'R' && type != 'I')
    {
        getline(inFile, title);
        cout << "INVALID ACTION CODE" << type << endl;
        return false;
    }

    if (type == 'I')
    {
        //print out all transactin history
        displayMovieList();
        transactionHistory.push_back("I");
        return true;
    }

    inFile.ignore();
    inFile >> id;
    Customer* ct;
    if (!customer.get(id, ct))
    {
        cout << "INCORRECT CUSTOMER ID" << id << endl;
        return false;
    }

    if (type == 'H')
    {
        cout << *ct;
        transactionHistory.push_back("H " + to_string(ct->getCustomerID()));
        return true;
    }

    inFile.ignore();
    inFile >> media;
    inFile.ignore();
    inFile >> movieType;

    Transaction* tr;
    Borrow br;
    Return rt;

    switch (type){
        case 'B':

            if (!changeStock(-1, movieType, inFile, title))
            {
                tr->setData(title, ct);
                return false;
            }
            tr = &br;
            break;
        case 'R':
            if (!changeStock(1, movieType, inFile, title))
            {
                tr->setData(title, ct);
                return false;
            }
            tr = &rt;
            break;

        default:
            cout << "INVALID ACTION CODE" << endl;
            return false;
    }
    tr->setMediaType(media);
    tr->setTransactionType(type);
    tr->setData(title, ct); //change to inFile later
    transactionHistory.push_back(type + (to_string(ct->getCustomerID())) + " " + movieType);

    return true;
}

// ------------------------------------changeStock------------------------------------------------
// retrive the movie and change the number of stock
// -------------------------------------------------------------------------------------------
bool Factory::changeStock(int numOfStock, char type,  istream& inFile, string& mTitle) {
    //DRAMA director & title
    //CLASSIC year & actor & month
    //COMEDY title & year
    Comedy cm;
    Comedy *cmFound;
    Drama dm;
    Drama *dmFound;
    Classic cs;
    Classic* csFound;
    string title, director, actF, actL, tmp, actor;
    int year, month;
    switch (type){
        case 'F':

            inFile.ignore();
            getline(inFile >> ws, title, ',');
            inFile.ignore();
            inFile >> year;
            cm.setTitle(title);
            cm.setYear(year);
            mTitle = title + " " + to_string(year);
            if (movieInv.getComedyTree().retrieve(cm, cmFound))
                if ((cmFound->getStock() + numOfStock) >= 0)
                {
                    cmFound->setStock(cmFound->getStock() + numOfStock);
                    return true;
                }
                else {
                    cout << "Out of Stock :  " << mTitle << endl;
                    mTitle += "  *** OUT OF STOCK : TRANSACTION FAILED ***";

                    return false;
                }
            break;
        case 'D':
            inFile.ignore();
            getline(inFile >> ws, director, ',');
            inFile.ignore();
            getline(inFile >> ws, title, ',');
            dm.setTitle(title);
            dm.setDirector(director);
            mTitle = title + " " + director;

            if (movieInv.getDramaTree().retrieve(dm, dmFound))
                if ((dmFound->getStock() + numOfStock) >= 0)
                {
                    dmFound->setStock(dmFound->getStock() + numOfStock);
                    return true;
                }
                else {
                    cout << "Out of Stock :  " << mTitle << endl;
                    mTitle += "  *** OUT OF STOCK : TRANSACTION FAILED ***";

                    return false;
                }
            break;
        case 'C':
            inFile >> month;
            inFile >> year;
            inFile >> actF;
            inFile >> actL;
            cs.setYear(year);
            cs.setReleaseMonth(month);
            actor = actF + " " +  actL;
            cs.setMajorActor(actor);
            mTitle = to_string(month) + " " + to_string(year) + " " + actor;

            if (movieInv.getClassicsTree().retrieve(cs, csFound))
                if ((csFound->getStock() + numOfStock) >= 0)
                {
                    csFound->setStock(csFound->getStock() + numOfStock);
                    return true;
                }
                else {
                    cout << "Out of Stock :  " << mTitle << endl;
                    mTitle += "  *** OUT OF STOCK : TRANSACTION FAILED ***";
                    return false;
                }
            break;
        default:
            mTitle = "                    *** MOVIE NOT FOUND : TRANSACTION FAILED ***";
            getline(inFile, title);
            cout << "INVALID VIDEO CODE" << title << endl;
            return false;
    }
    mTitle = "                    *** MOVIE NOT FOUND : TRANSACTION FAILED ***";
    return false;
}

// ------------------------------------displayCustomer------------------------------------------------
// displays customer list
// -------------------------------------------------------------------------------------------
void Factory::displayCustomerList() const {
    cout << endl;
    customer.display();
}

// ------------------------------------displayTransition------------------------------------------------
// displays transaction history
// -------------------------------------------------------------------------------------------
void Factory::displayTransactonHistory() const {
    cout << endl;
    cout << "****** Transaction History ******:" << endl;
    for (string s : transactionHistory)
    {
        cout << s << endl;
    }
}

// ------------------------------------displayMovies------------------------------------------------
// display movie list
// -------------------------------------------------------------------------------------------
void Factory::displayMovieList() const {
    cout << endl;
    cout << "**** Displaying Movie List ****" << endl;
    movieInv.printAllMovies();
}

