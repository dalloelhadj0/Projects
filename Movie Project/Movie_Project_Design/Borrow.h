#ifndef Borrow_h
#define Borrow_h

#include "Transaction.h"
#include <iostream>
using namspace std;

// This is a child class of the transaction class that contain
//data from the transaction object

class Borrow: public Transaction {
public:
  Borrow();
  ~Borrow();

  Borrow(const Borrow& );

  virtual bool setData(string , Inventory, Customer);
  virtual void display() const;
  virtual Transaction *build();
};

#endif /* Borrow_h */
