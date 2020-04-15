// ------------------------------------------------ Customer.h -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements variables & functions for Customer class

// --------------------------------------------------------------------------------------------------------------------

#ifndef PROJECT_4_FINAL_CUSTOMER_H
#define PROJECT_4_FINAL_CUSTOMER_H



#include <iostream>
#include <vector>

using namespace std;

#include "History.h"

class Customer{
public:
    Customer();
    Customer(int id, string firstname, string lastname);
    ~Customer();
    int getCustomerID() const;
    string getFirstName() const;
    string getLastName() const;
    void addHistory(History h);

    //overloading assignment operators
    friend ostream& operator<<(ostream& out, const Customer& rha);
    Customer& operator=(const Customer& );
private:
    int customerID;
    string lastName;
    string firstName;
    std::vector<History> history;   //stores user's transaction records
};

#endif //PROJECT_4_FINAL_CUSTOMER_H


