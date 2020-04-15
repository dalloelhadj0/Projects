
#ifndef Return_h
#define Return_h

#include "Transaction.h"
#include <iostream>
using namspace std;
// This is a child class of the transaction class that contain
//data from the transaction object
class Return: public Transaction
{
public:
    Return();
    ~Return();
    
    Return(const Return& );
    
    virtual bool setData(string , Inventory, Customer);
    virtual void display() const;
    virtual Transaction* build();
};

#endif /* Return_h */
