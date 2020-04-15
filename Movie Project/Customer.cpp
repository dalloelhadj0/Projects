// ------------------------------------------------ Customer.cpp -------------------------------------------------------

// Tomomi Nakamura & Elhadj Diallo CSS343 Section C

// March 14, 2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file implements all functions in Customer.h

// --------------------------------------------------------------------------------------------------------------------

#include <sstream>
#include "Customer.h"
#include <fstream>

// ------------------------------------constructor------------------------------------------------
// constructor for Customer class
// -------------------------------------------------------------------------------------------
Customer::Customer() {
    customerID = 0;
    firstName = "";
    lastName = "";
}

// ------------------------------------parametarized constructor------------------------------------------------
// parametarized constructor for Customer class
// -------------------------------------------------------------------------------------------
Customer::Customer(int id, string firstname, string lastname) {
    this->customerID = id;
    this->firstName = firstname;
    this->lastName = lastname;
}

// ------------------------------------destructor------------------------------------------------
// destructor for Customer class
// -------------------------------------------------------------------------------------------
Customer::~Customer() {
}

// ------------------------------------getCustomerID------------------------------------------------
// returns customer ID
// -------------------------------------------------------------------------------------------
int Customer::getCustomerID() const{
    return this->customerID;
}

// ------------------------------------getFirstname------------------------------------------------
// returns firstname
// -------------------------------------------------------------------------------------------
string Customer::getFirstName() const{
    return this->firstName;
}

// ------------------------------------getLastname------------------------------------------------
// returns lastname
// -------------------------------------------------------------------------------------------
string Customer::getLastName() const{
    return this->lastName;
}

// ------------------------------------operator = ------------------------------------------------
// overloading operator = for Customer
// -------------------------------------------------------------------------------------------
Customer& Customer::operator=(const Customer &customer) {
    customerID = customer.getCustomerID();
    lastName = customer.getLastName();
    firstName = customer.getFirstName();
    return *this;
}

// ------------------------------------operator << ------------------------------------------------
// overloading operator << for Customer
// -------------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Customer& c)
{
    cout << endl;
    out << "USER: " << c.getCustomerID() << ", " << c.getFirstName() << ", " << c.getLastName() << endl;
    if (!c.history.empty())
    {
        out << "Transaction   Media   Movie" << endl;
        for (int i = c.history.size() - 1; i >= 0; i--)
        {
            out << c.history.at(i).getTransType() << "             " << c.history.at(i).getMediaType() << "       " << c.history.at(i).getMovie() << endl;
        }
    }

    return out;
}

// ------------------------------------ addHistory ------------------------------------------------
// adds history a vector which stores transacton record
// -------------------------------------------------------------------------------------------
void Customer::addHistory(History h) {
    history.push_back(h);
}

