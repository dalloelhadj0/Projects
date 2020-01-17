//Elhadj diallo
//CSSS342 FALL 2019
//ASSIGNMENT 2
//  Created by Elhadj Diallo on 10/15/19.
//  Copyright © 2019 Elhadj Diallo. All rights reserved.
//
/*This program control operator overloading of a time class, it formate time at the right one and add,
 * substract or multiply it by an integer, it uses the firend methode to help access private varuiable
 * and being able to print them at any giving time*/
#ifndef ASS2_TIMESPAN_H
#define ASS2_TIMESPAN_H

#include <iostream>
using namespace std;

class TimeSpan {
    // operator io friend
    friend ostream&  operator<<(ostream &outStream, const TimeSpan &time);
    friend istream& operator >> (istream& input, const TimeSpan &time);

private:
    double hour;
    double minutes;
    double second;
    // help control the data set entered in the file and format it to a right regular time
    void simplify();
public:
    // different constructors
    TimeSpan();
    TimeSpan(double second);
    TimeSpan(double minutes, double second);
    TimeSpan(double hour, double minutes, double second);
    //setters
    void setTimes(double hour, double minutes, double second);
    //getters
    double getHour() const;
    double getMinutes() const;
    double getSecond() const;

    // equal operator
    bool operator==(const TimeSpan& other) const;

    //inequal operator
    bool operator!=(const TimeSpan& other) const;

    // <= operatot
    bool operator<=(const TimeSpan& other) const;

    //  comparison operator comparing whether this time is egal or greater than other timeSpan
    bool operator>=(const TimeSpan& other) const ;

    // comparison operator comparing whether this time is strictly greater than other timeSpan
    bool operator>(const TimeSpan& other) const;

    // comparison operator comparing whether this time is strictly less than other timeSpan
    bool operator < (const TimeSpan& other) const;

    //addition operator
    TimeSpan operator+(TimeSpan & otherTime);

    // substration operator
    TimeSpan operator-(TimeSpan & otherTime);

    // += operator overload
    TimeSpan& operator +=(TimeSpan& otherTime);

    // += operator overload
    TimeSpan& operator -=(TimeSpan& otherTime);

    //interger multiplication operator
    TimeSpan operator *(int num);
};

#endif //ASS2_TIMESPAN_H
