#include <iostream>
#include <sstream>
#include <cassert>
#include "TimeSpan.h"
using namespace std;

void test1() {
    TimeSpan ts(1, 20, 30);
    stringstream ss;
    ss << ts;
    assert(ss.str() == "1:20:30");
    TimeSpan ts2(4, -20, -90);
    ss.str("");
    ss << ts2;
    assert(ss.str() == "3:38:30");
    TimeSpan ts3(1.5, 30.5, -90);
    ss.str("");
    ss << ts3;
    assert(ss.str() == "1:59:00");
    TimeSpan ts4(0, 0.07, 0);
    ss.str("");
    ss << ts4;
    assert(ss.str() == "0:00:04");
}
// testing equality, addition, subtraction, multiplication
void test2() {
    TimeSpan ts(1, 20, 30);
    TimeSpan ts2(1, 20, 30);
    TimeSpan ts3(0, 0, 0);
    assert(ts == ts2);
    assert(!(ts != ts2));
    assert(ts != ts3);
    assert((ts + ts + ts) == (ts2 * 3));
    assert((ts * 5) == (ts2 * 4) + ts2);
    assert((ts * 5) == (ts2 * 6) - ts2);
    assert((ts + ts - ts) == ((ts2 * 2) - ts));
    assert((ts - ts2) == ts3);
    assert(( ts3 * 5 ) == ts3);
}

void test3 (){
    TimeSpan t1(2.5);
    TimeSpan t9(76,54);
    TimeSpan t2(1, 50, 33);
    TimeSpan t3(12, 23, 55);
    TimeSpan t4(12, 23, 55);
    TimeSpan t5(-3.4, -238, -240);
    stringstream ss;
    ss << t2;
    assert((t2 + t3) >= t3);
    assert((t2-t3)< t3);
    assert(!((t2*5) > t3));
    assert((t2-t3)< t3 *2 );
    assert((t2 * 3) < t3);
    assert(((t2-t3)* 2)< t3 * 4);
    assert((t3 * 3) <= (t3 * 3));
    assert(t2!= t3);
    assert(!((t2 * 3) == t3));
    assert((t2 * 3) < t3);
    assert((t2 * 2) == (t2*2));
    assert((t2 * 2) <= (t2*2));
    assert((t2 * 4) >= (t2*3));
    assert((t2 * 2) < (t2*3));
    assert((t2 * 2) < (t2* 3));
    assert(((t3 - t2) * 2) <= (t5* 3));


}
void test4 (){
    cout << "This test will print some overloaded function to check that the program runn efficietly"<< endl;
    TimeSpan t1(4.5);
    TimeSpan t2(1, 50, 33);
    TimeSpan t3(12, 23, 55);
    TimeSpan t4(12, 23, 55);
    TimeSpan t5(-3.4, -238, -240);
    TimeSpan tx(1,20,30) ,  ty(1,20,30);
    TimeSpan tz = tx + ty;
    TimeSpan add1 = t3 + t2;
    TimeSpan addTime = t3+=t2;
    cout << "The tz (addition of tx + ty) = " << tz <<endl;
    cout << "The ts3 (addition of ts3 + ts2) = " << t3 <<endl;
    cout << "The addition of ts3 and ts2= " << addTime <<endl;
    cout << "The addition of ts3 and ts2= " << add1 << endl;
    TimeSpan xx = t1 + t2;
    TimeSpan x1 = t1-t2;
    TimeSpan x3 = t1*4;
    cout<< "Time x3 = "<<x3 << endl;
    cout<<"Time x1= "<< x1 << endl;
    cout << "Time xx =" << xx<< endl;
    cout<<"Time t5= " << t5 << endl;

}

void testAll() {
    test1();
    test2();
    test3();
    test4();
}
int main() {
    testAll();
    cout << "\nsuccessfully passed all test." <<endl;
    return 0;
}