//
// Elhadj Diallo
//CSS342 UWB
//Assignment5
/*This program  is design to sort efficiently a huge data readed from a file and output it in different format based on the
 * user input on the commande line. It also print out the statistic of ho much each sorted function has to access the function
 * from a data structure ArrayList that is implemented and ouput. It output the sorted value with the statistic along if -d is selected.
 * only the statistic if two argument or it says the length must be in the rage 2-3.*/

#ifndef ASS5_ARRAYLIST_H
#define ASS5_ARRAYLIST_H
using namespace std;

#include <iostream>
#include <stdio.h>
#include <string>
#include "ListInterface.h"
#include <assert.h>

template<class Type>
class ArrayList : public ListInterface<Type> {
private:
    //The maxmum size of the array
    int arrayLength ;

    //the current size of the ArrayList
    int listSize;

    //grow an array doubly if the length at max
    void growArray();

    //the type of items stored in the arrayList
    Type *items;

    //statictist accessors variable
    static int acessCounter ;
    static int swapCounter;
    static int removeAtCounter ;
    static int insertAtCounter ;
    static int appendCounter ;
public:
    //constructor
    ArrayList();

    //destructor
    ArrayList(int capacity);

    ~ArrayList();

    // The easy way to access an element
    Type &operator[](int) const throw(std::out_of_range);

    //get size of the array
    int getSize() const;

    //destructor clear all teh araayList
    void clearAll();

    // chech if the arrayList is empthy
    bool isEmpty() const;

    //insert element at a giving idex
    void insertAt(int index, const Type &newEntry) throw(std::out_of_range);

    // Append to end
    void append(const Type &);

    // delete at location
    void removeAt(int index) throw(std::out_of_range);

    //swapCounter two giving value
    void swap(int from, int to) throw(std::out_of_range);

    // Get an item at location
    Type &getAt(int index) const throw(std::out_of_range);

    // Clear out any instrumentation
    void clearStatistics();

    // Provide statistics on number of times method was performed
    int getNumAccess() const;   // operator [] OR getAt

    int getNumSwap() const;

    int getNumRemove() const;

    int getNumInsertAt() const;

    int getNumAppends() const;

    //operator
    ArrayList(const ArrayList<Type>& source);
    ArrayList<Type>& operator=(const ArrayList<Type>& source);
};

//----------------------------------------IMPLEMENTATION--------------------------------------------------------------------
template <class Type>
int ArrayList<Type>::acessCounter=0;

template <class Type>
int ArrayList<Type>::swapCounter=0;

template <class Type>
int ArrayList<Type>::removeAtCounter=0;

template <class Type>
int ArrayList<Type>::insertAtCounter=0;

template <class Type>
int ArrayList<Type>::appendCounter=0;

//array constructor
template<class Type>
ArrayList<Type>::ArrayList(int arrayLength) {
    this->arrayLength = arrayLength;
    listSize =0;
    items = new Type[arrayLength];
}

template<class Type>
ArrayList<Type>::~ArrayList() {
    delete [] items;
    //clearAll();
}

//default constructor
template<class Type>
ArrayList<Type>::ArrayList() {
    items = nullptr;
    arrayLength = 0;
    listSize = 0;
}

//grow an array doubly if the length at max
template<class Type>
void ArrayList<Type>::growArray() {
    int arrayIncrement = 1;
    Type *newItems = new Type[arrayLength + arrayIncrement];
    assert(newItems != nullptr);
    if(listSize>0) {
        for(int i=0; i< listSize; i++){
            newItems[i]=items[i];
        }
       // memcpy(newItems, items, arrayLength * sizeof(Type));
        delete[] items;
    }
    arrayLength += arrayIncrement;
    items = newItems;
}

//return the size of the array
template<class Type>
int ArrayList<Type>::getSize() const {
    return listSize;
}

//array destructor
template<class Type>
void ArrayList<Type>::clearAll() {
    listSize = 0;
    arrayLength =0;
    delete[] items;
    items = nullptr;
}

template<class Type>
bool ArrayList<Type>::isEmpty() const {
    return getSize() == 0;
}

//inserting an element at a giving point
template<class Type>
void ArrayList<Type>::insertAt(int index, const Type &newEntry) throw(std::out_of_range) {
    if (index > listSize || index < 0) {
        throw std::out_of_range("Invalid index");
    }
    if (listSize == arrayLength) {
        growArray();
    }
    for (int i = listSize; i > index; i--) {
        items[i] = items[i - 1];
    }
    items[index] = newEntry;
    listSize++;
    ++insertAtCounter;

}

// Append to end
template<class Type>
void ArrayList<Type>::append(const Type &newEntry) {
    if (listSize == arrayLength) {
        growArray();
    }
    items[listSize++] = newEntry;
    ++appendCounter;
}

// delete at location
template<class Type>
void ArrayList<Type>::removeAt(int index) throw(std::out_of_range) {
    if (index < 0 || index > arrayLength) {
        throw std::out_of_range("invalid index");
    }
    for (int i = index; i < listSize - 1; i++) {
        items[i] = items[i + 1];
    }
    listSize--;
    ++removeAtCounter;

}

//Swapping two element in the array
template<class Type>
void ArrayList<Type>::swap(int from, int to) throw(std::out_of_range) {
    if ((from < 0 || from >= listSize) || (to < 0 || to >= listSize)) {
        throw std::out_of_range("invalid index");
    }
    Type temp;
    temp = items[from];
    items[from] = items[to];
    items[to] = temp;
    ++swapCounter;
}

// Get an item at location
template<class Type>
Type &ArrayList<Type>::getAt(int index) const throw(std::out_of_range) {
    if (index < 0 || index >= listSize) {
        throw std::out_of_range("Invalid index");
    }
    acessCounter++;
    return items[index];
}

// Clear out any instrumentation
template<class Type>
void ArrayList<Type>::clearStatistics() {
    swapCounter = 0;
    acessCounter = 0;
    removeAtCounter = 0;
    insertAtCounter = 0;
    appendCounter = 0;

}

template<class Type>
Type &ArrayList<Type>::operator[](int index) const throw(std::out_of_range) {
    //modify listSize to arraylegn in order for the merge to work
    if (index < 0 || index >=listSize) {
        throw std::out_of_range("Invalid index");
    }
    acessCounter++;
    return items[index];

}

// Provide statistics on number of times method was performed
template<class Type>
int ArrayList<Type>::getNumAccess() const {  // operator [] OR getAt
    return acessCounter;
}

template<class Type>
int ArrayList<Type>::getNumSwap() const {
    return  swapCounter;
}

template<class Type>
int ArrayList<Type>::getNumRemove() const {
    return removeAtCounter;
}

template<class Type>
int ArrayList<Type>::getNumInsertAt() const {
    return insertAtCounter;
}

template<class Type>
int ArrayList<Type>::getNumAppends() const {
    return appendCounter;
}
//operator copy constructor
template <class Type>
ArrayList<Type>::ArrayList(const ArrayList<Type>& source) {
    this->listSize = source.listSize;
    this->arrayLength = source.arrayLength;
    items = new Type[source.arrayLength];
    for(int i=0; i< listSize; i++){
        items[i]= source.items[i];
    }
}

//assignment operator
template <class Type>
ArrayList<Type>& ArrayList<Type>::operator=(const ArrayList<Type>& source){
    if(this == &source){
        return *this;
    }
    this->listSize = source.listSize;
    this->arrayLength= source.arrayLength;
    items = new Type[source.arrayLength];
    for(int i=0; i< listSize; i++){
        items[i]= source.items[i];
    }
    return *this;
}

#endif //ASS5_ARRAYLIST_H