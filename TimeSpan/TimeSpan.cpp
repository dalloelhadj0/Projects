//Elhadj diallo
//CSSS342 FALL 2019
//ASSIGNMENT 2
//  Created by Elhadj Diallo on 10/15/19.
//  Copyright © 2019 Elhadj Diallo. All rights reserved.
//
/*This program control operator overloading of a time class, it formate time at the right one and add,
 * substract or multiply it by an integer, it uses the friend methods to help access private variable
 * and being able to print them at any giving time*/

#include "TimeSpan.h"
#include <iostream>
#include <cmath>
using namespace std;

/* constructor declaration*/

int const  HOUR_CONVERSION = 3600;
int const  MINUTES_CONVERSION = 60;

TimeSpan::TimeSpan(){
    setTimes(0, 0.0, 0.0);
}
TimeSpan::TimeSpan(double hour){
    setTimes(hour, 0, 0);
}

TimeSpan::TimeSpan(double hour, double minutes){
    setTimes(hour, minutes, 0);

}

TimeSpan::TimeSpan(double hour, double minutes, double second){
    setTimes(hour, minutes, second);

}

// function handling floating and negative values to make sure we are running with the right data
void TimeSpan::simplify(){
// convert all time to second and then reformating it based on the requirement
    int whole_number = abs(hour * HOUR_CONVERSION + minutes*MINUTES_CONVERSION + second);
    second = whole_number % MINUTES_CONVERSION;
    int minutesC = whole_number / MINUTES_CONVERSION;
    minutes = minutesC % MINUTES_CONVERSION;
    hour = minutesC / MINUTES_CONVERSION;

    // to assure that the program deal with decimal input
    double decimalHour, wholeHour;
    wholeHour = modf(hour, &decimalHour);
    minutes = minutes + abs(wholeHour * 60);
    hour = decimalHour;
    double firstMinutes, secondMinutes;
    secondMinutes = modf(minutes, &firstMinutes);
    second = second + abs(secondMinutes * 60);
    minutes = firstMinutes;
    second = round(second);
}

//setters help add element to the constructor and it is also used for construction.
void TimeSpan::setTimes(double hour, double minutes, double second)
{
    this->hour = hour;
    this->minutes = minutes;
    this->second = second;
    simplify();
}

// getters hours
double TimeSpan::getHour() const {
    return hour;
}
// getters minutes
double TimeSpan::getMinutes() const {
    return minutes;
}

// getters seconds
double TimeSpan::getSecond() const {
    return second;
}

//Equality operator checking whether two time is the same.
bool TimeSpan::operator==(const TimeSpan& other) const {
    return (hour==other.hour && minutes==other.minutes && second==other.second);
}

// Equality operator checking whether two giving time is different
bool TimeSpan::operator!=(const TimeSpan& other) const{
    return !(hour==other.hour && minutes==other.minutes && second==other.second);
}

// comparison operator comparing whether this time is egal or less than the giving time
//return true if it is, false otherwise
bool TimeSpan::operator<=(const TimeSpan& other) const {
    if(this->hour <= other.hour){
        return true;
    }
    else if (this->hour == other.hour && this->minutes <= other.minutes ){
        return true;
    }
    else if(this->hour == other.hour && this->minutes == other.minutes && this->second <= other.second ){
        return true;
    }
    else{
        return false;
    }
}

//  comparison operator comparing whether this time is egal or greater than other timeSpan
// return true if it is, false otherwise
bool TimeSpan::operator>=(const TimeSpan& other) const {
    if(this->hour >= other.hour){
        return true;
    }
    else if (this->hour == other.hour && this->minutes >= other.minutes ){
        return true;
    }
    else if(this->hour == other.hour && this->minutes == other.minutes && this->second >= other.second ){
        return true;
    }
    else{
        return false;
    }
}

// comparison operator comparing whether this time is strictly greater than other timeSpan
// return true if it is, also if not
bool TimeSpan::operator >(const TimeSpan& other) const {
    if(this->hour > other.hour){
        return true;
    }
    else if (this->hour == other.hour && this->minutes > other.minutes ){
        return true;
    }
    else if(this->hour == other.hour && this->minutes == other.minutes && this->second > other.second ){
        return true;
    }
    else{
        return false;
    }
}

// comparison operator comparing whether this time is strictly less than other timeSpan
bool TimeSpan::operator < (const TimeSpan& other) const {
    if(this->hour < other.hour){
        return true;
    }
    else if (this->hour == other.hour && this->minutes < other.minutes ){
        return true;
    }
    else if(this->hour == other.hour && this->minutes == other.minutes && this->second < other.second ){
        return true;
    }
    else{
        return false;
    }
}

//addition & substration overloading function
TimeSpan TimeSpan::operator+(TimeSpan & otherTime){
    TimeSpan newTime;
    newTime.hour = this->hour + otherTime.hour;
    newTime.minutes = this->minutes + otherTime.minutes;
    newTime.second = this->second + otherTime.second;
    newTime.simplify();
    return newTime;
}

// substration perator overload
TimeSpan TimeSpan::operator-(TimeSpan & otherTime){
    TimeSpan newTime;
    newTime.hour = this->hour - otherTime.hour;
    newTime.minutes = this->minutes - otherTime.minutes;
    newTime.second = this->second - otherTime.second;
    newTime.simplify();
    return newTime;
}

// += operator overload
TimeSpan& TimeSpan::operator +=(TimeSpan& otherTime){
    return *this = *this + otherTime;
}

// += operator overload
TimeSpan& TimeSpan::operator -=(TimeSpan& otherTime){
    return *this = *this - otherTime;
}

// integer multiplication
TimeSpan TimeSpan::operator*(int num)  {
    TimeSpan newTime;
    newTime.hour = this->hour * num;
    newTime.minutes = this->minutes * num;
    newTime.second = this->second * num;
    newTime.simplify();
    return newTime;
}


// Displaying operator formating the time correctly
ostream&  operator<<(ostream &outStream, const TimeSpan &time){
    outStream << time.hour << ":" ;
    if(time.minutes>=0 && time.minutes<=9){
        outStream << "0"<< time.minutes <<":" ;
    }
    else{
        outStream << time.minutes <<":";
    }
    if(time.second >=0 && time.second<=9){
        outStream << "0"<< time.second ;
    }
    else{
        outStream <<time.second ;
    }
    return outStream ;
}

// istream operator helping to promt user to add times
istream& operator >> (istream& input,  TimeSpan &time)
{
    double hour, minutes, second;
    cout <<"Enter the number of hours: "<<endl;
    input>>hour;
    cout << "Enter the number of minutes: " << endl;
    input>>minutes;
    cout << "Enter the number of second: " << endl;
    input>>second;
    time.setTimes(hour, minutes, second);
    return input;

}
