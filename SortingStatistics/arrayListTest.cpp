

#include "arrayList.h"



////////////////////////////////////////////////////////
//  Macros and methods for magically making tests easier.
//  method must return void and have no arguments.
//  Call using macro Test.  IE
//     Test(<someMethodName>);
//
//   In your g method, use "Assert( boolean ) " for your test
//
/////////////////////////////////////////////////////////
#include <stdexcept>
#include <string>
#include <iostream>
int maxPoints = 0;
int myPoints = 0;
#define Test( X , Y )  testOne ( #X, &X, Y);
// Calls testOne func passing in paramaters  magically
void testOne( std::string funcName, void (*fname)() , int points) {
    maxPoints += points;
    try {
	fname();
    }
    catch ( std::logic_error err) {
	std::cout << "ERROR in "<<funcName << err.what()<< std::endl;
	return;
    }
    myPoints += points;
    std::cout << funcName <<std::endl;
}

#define Assert( X )  \
    if (!(X)) \
{string s = "  at line "+std::to_string(__LINE__);; \
    throw std::logic_error( s ); }

void printPoints()
{
    if ( maxPoints ) {
	std::cout<< "Score "<<myPoints<<" out of "<< maxPoints<<std::endl;
    }
}

///////////////////////////////////////////////////////////
//  End of testing magic. 
///////////////////////////////////////////////////////////


#include "arrayList.h"
using namespace std;

//////////////////////////////////////////////////////////
//  TEst helper to fill array with data up to couont. 
//////////////////////////////////////////////////////////
void fillTestArray(ArrayList<int> & aref, int count)
{
    for ( int i = 0 ; i < count ; i++) {
	aref.append(i);
    }
}


//////////////////////////////////////////////////////////
//test helper to do one of each thing so we can check stats
//////////////////////////////////////////////////////////
void doOneOfEach ( ArrayList<int> & aref) {
    aref.append(1);
    int fred =  aref[0];

    aref.swap(0,1);
    aref.removeAt(0);
    aref.insertAt(0, 0);
}


//////////////////////////////////////////////////////////
// TEst that we have different counts for different 
// types of arrayLists ( string and int)
//////////////////////////////////////////////////////////
void testInstrumentOne()
{
    ArrayList<int> ilist ;
    ArrayList<string> slist;
    ilist.clearStatistics();

    Assert( slist.getNumAppends() == 0);
    Assert( ilist.getNumAppends() == 0);

    ilist.append(3);
    Assert( ilist.getNumAppends() == 1);
    Assert( slist.getNumAppends() == 0);

    ilist.clearStatistics();
    Assert( ilist.getNumAppends() == 0);
}

//////////////////////////////////////////////////////////
// Test that we are counting everything and that
// our count fields are statix. 
//////////////////////////////////////////////////////////
void testInstrumentTwo()
{
    ArrayList<int> list1;
    ArrayList<int> list2;

    list1.clearStatistics();

    list1.append(2);
    doOneOfEach( list1);
    Assert( list1.getNumAppends() == 2);
    Assert( list2.getNumAppends() == 2);
    Assert( list1.getNumSwap() == 1);
    Assert( list2.getNumSwap() == 1);
    Assert( list1.getNumRemove() == 1);
    Assert( list2.getNumRemove() == 1);
    Assert( list1.getNumInsertAt() == 1);
    Assert( list2.getNumInsertAt() == 1);
    Assert( list1.getNumRemove() == 1);
    Assert( list2.getNumRemove() == 1);
}





//////////////////////////////////////////////////////////
//  Simple append 
//////////////////////////////////////////////////////////

void testAppendOne()
{

    ArrayList<int> aList ;
    Assert(aList.isEmpty());
    Assert( aList.getSize() == 0);
    aList.append(3);
    Assert( aList.isEmpty() == false);
    Assert( aList.getSize() == 1);
}


//////////////////////////////////////////////////////////
//  Append where we have to grow. 
//////////////////////////////////////////////////////////
void testArrayAccessAndGrow()
{
    ArrayList<int> alist(10);
    // Fill 0 thru 8 
    fillTestArray(alist, 9);
    Assert ( alist.getAt(0) == 0);
    Assert( alist.getAt(5) == 5);
    alist.append(9);
    alist.append(10);
    alist.append(11);
    alist.append(12);

    Assert( alist.getAt(0) == 0);
    Assert( alist.getAt(5) == 5);
    Assert( alist.getAt(11) == 11);
    Assert ( alist.getAt(12) == 12);
    try {
	alist.getAt(13);
	Assert(false);
    }
    catch ( std::out_of_range & ex) {
	Assert(true);
    }
}

//////////////////////////////////////////////////////////
// Simple test of insert.  No worries about growing array
//////////////////////////////////////////////////////////
void testInsert()
{
    ArrayList<int> alist(10);
    fillTestArray(alist, 5);

    alist.insertAt(3, 93);
    Assert( alist.getSize() == 6);
    Assert( alist.getAt(2) == 2);
    Assert( alist.getAt(3) == 93);
    Assert( alist.getAt(4) == 3);


    // Now insert at head
    alist.insertAt(0, 23);
    Assert( alist.getSize() == 7);
    Assert( alist.getAt(0) == 23);
    Assert( alist.getAt(1) == 0);


    // And at tail.  
    alist.insertAt(7, 40);

    Assert( alist.getSize() == 8);
    Assert( alist.getAt(7) == 40);
    Assert(alist.getAt(6) == 4);
}


//////////////////////////////////////////////////////////
// test that we grow as needed on an insert. 
//////////////////////////////////////////////////////////
void testInsertAndGrow()
{
    ArrayList<int> alist(10) ;
    // Put one less than max into us.
    fillTestArray(alist, 9);
    // The first should not make us grow.
    alist.insertAt(5, 98);
    Assert( alist.getAt(9) == 8);

    // This one should make it grow
    alist.insertAt(5, 99);
    Assert( alist.getSize() == 11);
    Assert( alist.getAt(10) == 8);
    Assert( alist.getAt(9) == 7);

}

//////////////////////////////////////////////////////////
//  Just remove a test etc. 
//////////////////////////////////////////////////////////
void testRemove()
{
    ArrayList<int> alist(10);
    fillTestArray(alist, 9);

    alist.removeAt(0);
    Assert( alist.getSize() == 8);
    Assert( alist.getAt(0) == 1);

    // Now remove the last one
    alist.removeAt(7);
    Assert( alist.getSize() == 7);
    Assert( alist.getAt(6) == 7);

    // And someplace in the middle
    alist.removeAt(3);
    Assert( alist.getSize() == 6);
    Assert( alist.getAt(2) == 3);
    Assert( alist.getAt(3) == 5);
}


//////////////////////////////////////////////////////////
//  Just test access. 
//////////////////////////////////////////////////////////
void testSquareBracket()
{
    ArrayList<int> alist (10);
    fillTestArray(alist, 8);
    Assert( alist[3] == 3);
    alist[3] = 99;
    Assert ( alist[3] == 99);
}

//////////////////////////////////////////////////////////
// Test the guard to make sure we do not do something ugly. 
//////////////////////////////////////////////////////////
void testOperatorEqualOne()
{
    ArrayList<int> ilist(10);
    ilist.append(1);
    ilist.append(2);

    ilist = ilist;
    Assert( true);
    Assert( ilist.getSize() == 2);
}

//////////////////////////////////////////////////////////
//  TEst when the RHS is much bigger than the LHS
//////////////////////////////////////////////////////////
void testOperatorEqualTwo()
{
    ArrayList<int> list1 (10);
    ArrayList<int>  list2(20);
    list1.append(100);
    list1.append(101);
    fillTestArray(list2, 15);

    list1 = list2;
    for ( int i = 0 ; i < 15 ; i++) {
	Assert( list1[i] == i);
    }
}


//////////////////////////////////////////////////////////
//  Test if there is nothing in list 1;
//////////////////////////////////////////////////////////
void testOperatorEqualThree()
{
    ArrayList<int> list1(10);
    ArrayList<int> list2;
    list2.append(3);
    list1 = list2;
    Assert( list1.getSize() == 1);
    Assert( list1[0] == 3);
}

//////////////////////////////////////////////////////////
//  Test operator equal - where we delete the rhs.
//  Attempt to make sure it is a deep copy
//////////////////////////////////////////////////////////
void testOperatorEqualFour()
{
    ArrayList<int> * list1 = new ArrayList<int>(10) ;
    ArrayList<int> list2;

    list1->append(10);
    list2 = * list1;

    delete list1;
    Assert( list2.getSize() == 1);
    Assert( list2[0] == 10);
}

/////////////////////////////////////////////////////////
//  TEst copy constructor. 
////////////////////////////////////////////////////////
void testCopyConstructor()
{
    ArrayList<int> * list1 = new ArrayList<int>(10);
    fillTestArray( *list1, 30);
    ArrayList<int> list2( *list1);
    delete list1;

    Assert( list2.getSize() == 30);
    for ( int i = 0 ; i < 30 ; i++) {
	Assert( list2[i] == i);
    }
}


/////////////////////////////////////////////////////////
// TEst that we throw an exception if bad index
// on operator[], insertAt, removeAt, geetAt, swap
// //////////////////////////////////////////////////////
void testExceptionThrowing()
{
    ArrayList<int> alist (10);
    fillTestArray( alist, 20);
    bool shouldNotBeHere = false;
    try {
	alist[20];
	Assert( shouldNotBeHere)
    }
    catch ( std::out_of_range ex) {  }
    try {
	alist[-1];
	Assert( shouldNotBeHere)
    }
    catch ( std::out_of_range ex) {  }
    try {
	alist.insertAt(30, 30);
	Assert( shouldNotBeHere)
    }
    catch ( std::out_of_range ex) {  }
    try {
	alist.insertAt(-1, 30);
	Assert( shouldNotBeHere)
    }
    catch ( std::out_of_range ex) {  }
    try {
	alist.removeAt(25);
	Assert( shouldNotBeHere)
    }
    catch ( std::out_of_range ex) {  }
    try {
	alist.removeAt(-1);
	Assert( shouldNotBeHere)
    }
    catch ( std::out_of_range ex) {  }
    try {
	alist.getAt(20);
	    Assert( shouldNotBeHere)
    }
    catch ( std::out_of_range ex) {  }
    try {
	alist.getAt(-1);
	Assert( shouldNotBeHere)
    }
    catch ( std::out_of_range ex) {  }
    try {
	alist.swap( 3, 20);
	Assert( shouldNotBeHere)
    }
    catch ( std::out_of_range ex) {  }
    try {
	alist.swap( 20, 3);
	Assert( shouldNotBeHere)
    }
    catch ( std::out_of_range ex) {  }
    try {
	alist.swap( -1, 3);
	Assert( shouldNotBeHere)
    }
    catch ( std::out_of_range ex) {  }
    try {
	alist.swap( 2, -1);
	Assert( shouldNotBeHere)
    }
    catch ( std::out_of_range ex) {  }
}







///////////////////////////////////////////////////////
//  Main test driver. 
//////////////////////////////////////////////////////

int main()
{
    Test ( testAppendOne, 1);
    Test ( testArrayAccessAndGrow, 1);
    Test ( testInsert, 1);
    Test ( testInsertAndGrow, 1);
    Test ( testRemove, 1);
    Test ( testSquareBracket, 1);
    Test ( testInstrumentOne, 1);
    Test ( testInstrumentTwo, 2);
    Test ( testOperatorEqualOne, 1);
    Test ( testOperatorEqualTwo, 1);
    Test ( testOperatorEqualThree, 1);
    Test ( testOperatorEqualFour, 1);
    Test ( testCopyConstructor, 2);
    Test ( testExceptionThrowing, 2);
    printPoints();
}

