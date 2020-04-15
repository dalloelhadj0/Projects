// ------------------------------------------------ HashTable.h -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements variables & functions for Hash Table

// --------------------------------------------------------------------------------------------------------------------


#ifndef PROJECT_4_FINAL_HASHTABLE_H
#define PROJECT_4_FINAL_HASHTABLE_H

#include "Customer.h"
class HashTable {

    public:
        HashTable();
        HashTable(int bucket);      //constructor to initialize table with size
        ~HashTable();               //destructor
        int hashFunction(int key);  //hash function to get a index where value
    // is stored in a table. key is customer ID
        int hashFunctionQuad(int n);  //quadratic hash function
        bool insert(const Customer&);     //insert customer into table
        bool get(const int& key, Customer *&val);   //get value mapped to key
        bool remove(const int& key);    //remove value mapped to key
        void display() const;             //display all customers in table
        bool setData(std::istream& );

private:

        Customer* table; //pointer array containing bucket
        int BUCKET;
        int numOfCustomer;
        void makeEmpty();           //clear all values in table
        void rehashing();
        void initialize();
};


#endif //PROJECT_4_FINAL_HASHTABLE_H

