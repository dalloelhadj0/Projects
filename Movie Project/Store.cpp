// ------------------------------------------------ main.cpp -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file tests if the program works without any error.

// --------------------------------------------------------------------------------------------------------------------


#include <iostream>
#include "HashTable.h"
#include "Customer.h"
#include "Factory.h"
#include "History.h"
#include "Inventory.h"
#include <stdexcept>

#include <cassert>
using namespace std;

// ------------------------------------Test 1----------------------------
//  Testing  Hash Table
// -------------------------------------------------------------------------------------------
void Test1()
{
    cout << "=============== Test 1===============" << endl;
    HashTable ht(10);
    Customer c1(1001, "A", "B");
    Customer c3(2011, "A", "B");
    Customer c4(1004, "A", "B");
    Customer c5(1112, "A", "B");
    Customer c6(1551, "A", "B");
    Customer c7(2195, "A", "B");
    Customer c8(1881, "A", "B");
    Customer c9(1251, "A", "B");
    Customer c10(3647, "A", "B");
    Customer c11(7531, "A", "B");
    ht.insert(c1);
    ht.insert(c3);
    ht.insert(c4);
    ht.insert(c5);
    ht.insert(c6);
    ht.display();
    ht.insert(c7);
    ht.insert(c8);
    ht.insert(c9);
    ht.insert(c10);
    ht.insert(c11);
    Customer* c2;
    bool res = ht.get(1001, c2);
    assert(c2->getCustomerID() == 1001);
    assert(c2->getFirstName() == "A");
    assert(c2->getLastName() == "B");
    ht.get(1251, c2);
    History h1;
    h1.setMediaType('D');
    h1.setTransType('B');
    h1.setMovie("3 1971 Ruth Gordon");
    c2->addHistory(h1);
    assert(c2->getCustomerID() == 1251);
    ht.get(1881, c2);
    assert(c2->getCustomerID() == 1881);
    ht.get(1112, c2);
    assert(c2->getCustomerID() == 1112);
    ht.get(1004, c2);
    assert(c2->getCustomerID() == 1004);
    ht.get(3647, c2);
    assert(c2->getCustomerID() == 3647);
    ht.get(2011, c2);
    assert(c2->getCustomerID() == 2011);
    ht.get(1551, c2);
    assert(c2->getCustomerID() == 1551);
    ht.display();
    cout << "====================================" << endl;
}

// ------------------------------------Test 2----------------------------
//  Testing  Hash Table using customer data
// -------------------------------------------------------------------------------------------
void Test2()
{
    cout << "=============== Test 2===============" << endl;

    HashTable ht;
    ifstream inFile("data4customers.txt");

    if (inFile.is_open())
    {
        while (!inFile.eof())
        {
            ht.setData(inFile);
        }
    }
    else {
        cout << "File fail to open" << endl;
    }
    ht.display();
    cout << "====================================" << endl;

}


// ------------------------------------Test 3----------------------------
//  Testing Inventory class which stores movies
// -------------------------------------------------------------------------------------------
void Test3()
{
    cout << "=============== Test 3===============" << endl;
    Inventory inv;
    inv.readMovieFile("data4movies.txt");
    inv.printAllMovies();
    //< Sorting >
    // DRAMA     director -> title
    // COMEDY    title -> year
    // CLASSIC   month -> year -> actor
    cout << "====================================" << endl;
}

// ------------------------------------Test 4----------------------------
//  Testing the entire system inc. Customer, Movie, and Transaction
// -------------------------------------------------------------------------------------------
void Test4()
{
    cout << "=============== Test 4===============" << endl;

    Factory fac;
    fac.readCustomer("data4customers.txt");
    fac.readMovie("data4movies.txt");
    fac.readTransaction("data4commands.txt");
    fac.displayMovieList();
    fac.displayTransactonHistory();
    fac.displayCustomerList();
    cout << "====================================" << endl;

}

int main() {

    Test1();
    Test2();
    Test3();
    Test4();
    std::cout << endl << "Passed All Tests ..." << std::endl;
    return 0;
}

