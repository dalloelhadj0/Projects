
// Elhadj Diallo
// Assignment1
// SID:1978477
// Major: CSSSE UWB
// Library implementation
// Date: 9/28/19.
/* I designed this main to help run and test the program and
 * make sure that all the tests are running perfectly fine
 */

#include <iostream>
#include "Library.h"
#include <cassert>
using namespace std;

void Test1()
{
    cout << "Test1 : \n ";
    Library libs("UWB");
    libs.AddBook("The Odyssey");
    libs.AddBook("In Search of Lost Time");
    libs.AddBook("Ulysses");
    libs.AddBook("Don Quixote");
    libs.AddBook("Ulyshises");


//print the whole  library list
    libs.ListAllBooks();

//should generate already in library message and return true
    bool result = libs.IsInLibrary("The Odyssey");
    assert(result);

// ​cannot add book twice, result should be false
    result = libs.AddBook("The Odyssey");
    assert(!result);

// ​ test remove, result should be true
    result = libs.RemoveBook("The Odyssey");
    assert(result);

//  not in library, result should be false
    result = libs.IsInLibrary("The Odyssey");
    assert(!result);

// cannot remove twice, result should be false
    result = libs.RemoveBook("The Odyssey");
    assert(!result);
}

void Test2()
{
    cout <<  " \n\n Test2 : ";
    Library elh("Elhadj@UWDIallo");
    elh.AddBook("Kemba");
    elh.AddBook("Nimma diallo");
    elh.AddBook("Elhadj");
    elh.AddBook("Bisrat");
    elh.AddBook("Kadiatou Bah");

    // print the name of the library
    cout <<"\nMy Library Name for the second test is : " + elh.getLibraryName() <<endl;

    //print the number of book in the array
    cout <<"The number of book in this library is : " << elh.getNumberOfBooks() << endl;

    //print the whole  library list
    elh.ListAllBooks();

    //try to add a duplicate book, result should be false
    bool response = elh.AddBook("Elhadj") ;
    assert(!response);

    //try to remove a book, result should be true
    response = elh.RemoveBook("Kadiatou Bah");
    assert(response);

   //try to remove a book twise, result is false
    response = elh.RemoveBook("Kadiatou Bah");
    assert(!response);

    //  not in library, result should be false
    response = elh.IsInLibrary("The Odyssey");
    assert(!response);

    //should generate already in library message and return true
     response = elh.IsInLibrary("Kemba");
    assert(response);

}


void TestALL() {
    Test1();
    Test2();
    cout << "\n\nSuccessfully completed all tests." << endl;
}
int main()
{
    TestALL();
    return 0;

}





