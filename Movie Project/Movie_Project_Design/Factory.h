
#ifndef Factory_h
#define Factory_h

#include "Classic.h"
#include "Drama.h"
#include "Comedy.h"
#include "Borrow.h"
#include "Return.h"
#include "History.h"
#include "Transaction.h"

#include <iostream>
using namspace std;

//implemented in inventory and transaction classes

class Factory
{
private:
bool validReturnTransaction(istream& ); //Process for verifing transaction 
bool validBorrowTransaction(istream& ); // process for verifing inventory


public:
    void buildInventory(); // builds the inventory into a BST
    void ReadCustomer(istream& );// reads in all the customer
    void processTransaction();// central process for transaction commands
	bool changeStock(int numOfStock);//checks stock of each movie for validation

    Inventory storeInventory[];
    Transaction transactionInventory[];

};
#endif /* Factory_h */