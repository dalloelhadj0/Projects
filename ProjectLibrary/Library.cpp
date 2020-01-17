// Elhadj Diallo
// Assignment1
// SID:1978477
// Major: CSS SE UWB
// Library implementation
// Date: 9/28/19.
/*This program is destined to help manage a library of book. It helps add/remove a book with at a specific
  index. It is also build to avoid using duplicates books so it won't add a book twice or remove it twice.
  Any tentative of adding a duplicate books will return false and the program wont crash.
 * The Library can take only up to 100 book. Any additional book more than the limited amount setted would
  not be addded and it will return false telling you that there are no space for it*/

#include <iostream>
#include "Library.h"
using namespace std;

// creat Library constructor to add Books in the library
Library::Library(const string &name): libraryName(name){
    numberOfBooks = 0; //number of book within the library
}

// return the name of the library tha stored books
string Library::getLibraryName()
{
    return libraryName;
}

// setted method set teh name of library
void Library::setLibrary(){
    this->libraryName == libraryName;
}

int Library::getNumberOfBooks()
{
    return numberOfBooks;
}
// Add a new book,
// return true for success, false if book already in library
bool Library::AddBook(const string &name)
{
    if(IsInLibrary(name) || numberOfBooks >= MAX_OF_ARRAY) // check to found out if the book already existe
    {
       // cout << "Can't add book because of duplicate or MAX Array reached " << endl;
        return false;
    }
   /* if(numberOfBooks > MAX_OF_ARRAY)
    {
        cout << "you reach the maximum space of the library" << endl;
        return false;
    }*/
    numberOfBooks++;
    BookList[numberOfBooks-1]= name; // add the book to the array
    return true;
}

// Remove a book
// return true for success, false if book not in library
bool Library::RemoveBook(const string &name){
    int index = FindTheIndex(name);
        if( FindTheIndex(name) == -1)
        {
            return false;
        }
    BookList[index] = BookList[numberOfBooks-1];
    numberOfBooks--;
    return true;

}

// List all books in library
void Library::ListAllBooks() const
{
    cout  << "The Book in the library are: ";
    for(int i =0; i< numberOfBooks; i++)
    {
        cout  << BookList[i] << ", ";
    }

}

// Return true if book in library, false otherwise
bool Library::IsInLibrary(const string &name) const
{
    //cout << boolalpha << name << endl;
    for(int i=0; i< numberOfBooks; i++){
        if (BookList[i] == name)
        {
            return true;
        }
    }
    return false;
}

//find index method
// return the index of the book, return -1 if not found
int Library::FindTheIndex(const string &name) {
    for (int i = 0; i < numberOfBooks; i++) {
        if (BookList[i] == name) {
            return i;
        }

    }
    return -1;
}

// friend function
ostream &operator<<(ostream &out, const Library &lib);
