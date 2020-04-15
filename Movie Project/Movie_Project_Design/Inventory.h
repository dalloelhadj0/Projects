

#ifndef Inventory_h
#define Inventory_h
#include <iostream>

using namespace std;

class Inventory
{
public:
    Inventory();
    virtual ~Inventory();
    virtual bool setData(istream& );
    virtual void display();
    
    void buildInventory(istream&);
    bool ReadCustomer(istream& );
    void processTransaction(istream&);
    
    Inventory movieInventory[];
    Transaction transactionInventory[];
    virtual bool operator==(const & )const = 0;
private:
    int stockNumber;
};
#endif /* Inventory_h */

