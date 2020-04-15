
#ifndef History_h
#define History_h

#include "Transaction.h"
#include <iostream>
using namspace std;
// This is a child class of the transaction class that display
// the history for a given customer

class History: public Transaction
{
public:
    History();
    ~History();
    
    History(const History& );
    
    virtual bool setData(string , Inventory , Customer);
    virtual void display() const;
    virtual Transaction* build();
};
#endif /* History_h */
