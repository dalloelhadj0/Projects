

#ifndef PROJECT4_HASHTABLE_H
#define PROJECT4_HASHTABLE_H

#include "Customer.h"
#include <list>
class HashTable{
public:
    HashTable(int bucket);      //constructor to initialize table with size
    ~HashTable();               //destructor
    int hashFunction(int key);  //hash function to get a index where value
                                // is stored in a table. key is customer ID
    void insert(Customer*);     //insert customer into table
    void get(const int& key);   //get value mapped to key
    void remove(const int& key);    //remove value mapped to key
    void display();             //display all customers in table
    void makeEmpty();           //clear all values in table

private:
    std::list<Customer>* table; //pointer array containing bucket
    int BUCKET;                 // # of bucket, which is size of table array
};

/********************* PSEUDO CODE **********************
Hash(int bucket)
{
    BUCKET = bucket
    initialize table = new list<Customer>[BUCKET]
}

int hashFunction(int key) {
        return (key % BUCKET);
}

void insert(Customer* value)
{
    get index from hashFunction(key) where key is customerID
    push value to table
    table[index].push_back(key)
}

void remove(int key)
{
     get index from hashFunction(key) where key is customerID

     find the key in table[index]
     list <int> :: iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
            if (*i == key)
                break;
    }
    if key is found in hash table, remove it
    if (i != table[index].end())
        table[index].erase(i);
}

void display() {

    for (int i = 0; i < BUCKET; i++) {
        for (Customer ct : table[i])
            cout << ct.ID << ", " << ct.name << endl;
    }
}
*****************************************************/
#endif //PROJECT4_HASHTABLE_H

