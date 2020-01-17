// Elhadj Diallo
// Assignment1
// SID:1978477
// Major: CSSE UWB
// Library implementation
// Date: 9/28/19.
/*This program is destined to help manage a library of book. It helps add/remove a book with at a specific
  index. It is also build to avoid using duplicates books so it won't add a book twice or remove it twice.
  Any tentative of adding a duplicate books will return false and the program wont crash.
 * The Library can take only up to 100 book. Any additional book more than the limited amount setted would
  not be addded and it will return false telling you that there are no space for it*/


#ifndef ASS1_LIBRARY_H
#define ASS1_LIBRARY_H

#include "ostream"
#include <iostream>
using namespace std;

class Library {

public:
    // friend function
    friend ostream &operator<<(ostream &out, const Library &lib);

    // return the name of the library
    Library(const string &name);

    //return the name of the library
    string getLibraryName();

    //setted method to set the name of the library
    void setLibrary();

    // access the number of book
    int getNumberOfBooks();

    // Add a new book,
    // return true for success, false if book already in library
    bool AddBook(const string &name);

    // Remove a book
    // return true for success, false if book not in library
    bool RemoveBook(const string &name);

    // List all books in library
    void ListAllBooks() const;

    // Return true if book in library, false otherwise
    bool IsInLibrary(const string &name) const;

    //return the index of the book searched
    int FindTheIndex(const string &name);

private:
    static const int MAX_OF_ARRAY = 100;
    string BookList[MAX_OF_ARRAY];
    string libraryName;
    int numberOfBooks;

};


#endif //ASS1_LIBRARY_H
