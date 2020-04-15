

#ifndef Transaction_h
#define Transaction_h

#include <iostream>
using namspace std;

class Transaction
{
public:
    Transaction();
    Transaction(const Transaction&);
    virtual ~Transaction();
    virtual setData(istream& );
    string getMediaType();
    string getTransactionType()
    virtual void display()const;
    virtual Transaction *build();
    
private:
    string transactionType;
    string mediaType;
};
#endif /* Transaction_h */
