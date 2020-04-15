
#ifndef Customer_h
#define Customer_h

#include "Movie.h"
#include "Transaction.h"
#include <iostream>
using namspace std;

class Customer
{
    friend ostream& operator<<(ostream& outStream, const Customer& rhs);
public:
    Customer();
    virtual~Customer();
    
    Customer(istream&);
    
    int getID();
    string  getLastName();
    string  getFirstName();
    
    int setID(int);
    string  setLastName(string);
    string  setFirstName(string)
    
    void setData(istream& );
    virtual bool operator==(const & )const;
    virtual bool operator!=(const & )const;
    
private:
    int  CustomerID;//an int to have unique numbers
    string  LastName;
    string FirstName;
};
    
#endif /* Customer_h */
