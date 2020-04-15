
// ------------------------------------------------ HashTable.cpp -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements all functions in Hash Table.h

// --------------------------------------------------------------------------------------------------------------------

#include <cmath>
#include <queue>
#include <iostream>
#include "HashTable.h"
#include <fstream>
#include <sstream>

using namespace std;

//constrctor
HashTable::HashTable() {
    BUCKET = 10;
    numOfCustomer = 0;
    table = new Customer[BUCKET];
    initialize();
}

//parametarized constrctor
HashTable::HashTable(int bucket) {
    BUCKET = bucket;
    numOfCustomer = 0;
    table = new Customer[BUCKET];
    initialize();
}

//destructor
HashTable::~HashTable() {
    makeEmpty();
}

// ------------------------------------initialize------------------------------------------------
// initializes table array to stoe customers
// -------------------------------------------------------------------------------------------
void HashTable::initialize() {
    Customer customer(0, "", "");
    for (int i = 0; i < BUCKET; i++)
    {
        table[i] = customer;
    }
}

// ------------------------------------hashFunction------------------------------------------------
// hash function to get a index where value
// -------------------------------------------------------------------------------------------
int HashTable::hashFunction(int key) {
    return key % BUCKET;
}

// ------------------------------------hashFunctionQuad------------------------------------------------
// quadratic hash function
// -------------------------------------------------------------------------------------------
int HashTable::hashFunctionQuad(int n) {
    return pow(n, 2);
}

// ------------------------------------insert------------------------------------------------
// insert customer into table
// -------------------------------------------------------------------------------------------
bool HashTable::insert(const Customer &val) {
    int hc = hashFunction(val.getCustomerID());
    if (table[hc].getCustomerID() == 0)
    {
        table[hc] = val;
        numOfCustomer++;
        return true;
    }
    else {
        int n = 0;
        int hc2;
        int idx = -1;
        do {
            if (idx == hc)
            {
                rehashing();
                //hc = hashFunction(c.getCustomerID());
            }

            n++;
            hc2 = hashFunctionQuad(n);
            idx = (hc + hc2) >= BUCKET ? (hc + hc2) % BUCKET : hc + hc2;

            if (table[idx].getCustomerID() == val.getCustomerID())
            {
                return false;
            }

        } while(table[idx].getCustomerID() != 0);
        table[idx] = val;
        numOfCustomer++;
        return true;

    }
    return false;
}


// ------------------------------------get------------------------------------------------
// get value mapped to key
// -------------------------------------------------------------------------------------------
bool HashTable::get(const int &key, Customer *&val) {
    int hc = hashFunction(key);
    if (table[hc].getCustomerID() == key) {
        val = &table[hc];
        return true;
    }
    else {
        int n = 0;
        int hc2;
        int idx = -1;
        do {
            if (idx == hc)
                return false;
            n++;
            hc2 = hashFunctionQuad(n);
            idx = (hc + hc2) >= BUCKET ? (hc + hc2) % BUCKET : hc + hc2;
        } while(table[idx].getCustomerID() != key);
        val = &table[idx];
        return true;
    }
    return false;
}

// ------------------------------------remove------------------------------------------------
// remove value mapped to key
// -------------------------------------------------------------------------------------------
bool HashTable::remove(const int &key) {
    int hc = hashFunction(key);
    Customer cinit(0, "", "");
    if (table[hc].getCustomerID() == key) {
        table[hc] = cinit;
        numOfCustomer--;
        return true;
    }
    else {
        int n = 0;
        int hc2;
        int idx = -1;
        do {
            if (idx == hc)
                return false;
            n++;
            hc2 = hashFunctionQuad(n);
            idx = (hc + hc2) >= BUCKET ? (hc + hc2) % BUCKET : hc + hc2;
        } while(table[idx].getCustomerID() != key);
        table[idx] = cinit;
        numOfCustomer--;
        return true;
    }
}


// ------------------------------------display------------------------------------------------
// display all customers in table
// -------------------------------------------------------------------------------------------
void HashTable::display() const{
    cout << "**** Displaying Customer Lists ****" << endl;
    for (int i = 0; i < BUCKET; i++)
    {
        if (table[i].getCustomerID() != 0)
            cout << table[i];
    }
}


// ------------------------------------makeEmpty------------------------------------------------
// clear all values in table
// -------------------------------------------------------------------------------------------
void HashTable::makeEmpty() {
    delete[] table;
    BUCKET = 0;
    numOfCustomer = 0;
}


// ------------------------------------rehashing------------------------------------------------
// change the size of table
// -------------------------------------------------------------------------------------------
void HashTable::rehashing() {
    queue<Customer> q;
    for (int i = 0; i < BUCKET; i++)
    {
        if (table[i].getCustomerID() != 0)
        {
            q.push(table[i]);
        }
    }
    delete[] table;
    table = new Customer[BUCKET * 2];
    BUCKET = BUCKET * 2;
    numOfCustomer = 0;
    initialize();
    while (!q.empty())
    {
        insert(q.front());
        q.pop();
    }
}

// ------------------------------------setData------------------------------------------------
// read data from customer file
// -------------------------------------------------------------------------------------------
bool HashTable::setData(std::istream &inFile) {
    if (inFile.eof())
        return false;

    string line;
    int id;
    string first, last;

    if (getline(inFile, line))
    {
        istringstream ss(line);
        ss >> id;
        ss >> first;
        ss >> last;

        Customer c(id, first, last);

        if (insert(c))
            return true;
    }
    return false;
}



