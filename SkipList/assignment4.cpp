#include <iostream>
#include "SkipList.h"
#include <assert.h>
void test1() {
    cout << "\nTEST I "<<endl;
    SkipList s(4);
    s.Add(1);
    s.Add(6);
    s.Add(4);
    s.Add(5);
    s.Add(5);
    s.Add(1);
    s.Add(4);
    s.Add(5);
    s.Add(1);
    s.Add(3);
    s.Add(2);
    s.Add(6);
    s.Add(26);
    s.Add(443);
    s.Add(54);
    s.Add(53);
    s.Add(13);
    s.Add(42);
    s.Add(53);
    s.Add(14);
    s.Add(3565);
    s.Add(245);
    s.Add(623);

    assert(s.Contains(1));
    assert(s.Contains(443));
    assert(s.Contains(13));
    assert(s.Contains(3565));
    assert(s.Contains(245));
    assert(!s.Contains(1413431));
    cout << "successfully pass all test for contain methods" << endl;

    cout << "Giving a skipList displayed below: "<<endl;
    cout << s << endl;
    cout << "After sucessfully delete " << 54 << endl;
    assert(s.Remove(54));
    cout << s << endl;
    cout << "sucessfully delete " << 4 << endl;
    assert(s.Remove(4));
    cout << s << endl;
    cout << "sucessfully delete " << 3 << endl;
    assert(s.Remove(3));
    cout << s << endl;
    cout << "sucessfully delete " << 2 << endl;
    assert(s.Remove(2));
    cout << s << endl;
    cout << "After sucessfully delete " << 5 << endl;
    assert(s.Remove(5));
    cout << s << endl;
    cout << "After sucessfully delete " << 6 << endl;
    assert(s.Remove(6));
    cout << s << endl;
    cout << "After Trying to delete element already deleted " << 3 << endl;
    assert(!s.Remove(3));
    cout << s << endl;
    cout << "After Trying to delete non existing element " << 25 << endl;
    assert(!s.Remove(25));
    cout << s << endl;
    cout << "After Trying to delete non existing element " << 36 << endl;
    assert(!s.Remove(36));
    cout << s << endl;
    cout << "After Trying to delete element already deleted " << 3 << endl;
    assert(!s.Remove(3));
    cout << s << endl;

}


void test2() {
    cout << "\nTEST II " << endl;
    SkipList s(6);
    s.Add(-1);
    s.Add(-6);
    s.Add(-4);
    s.Add(-5);
    s.Add(-5);
    s.Add(-1);
    s.Add(-4);
    s.Add(-5);
    s.Add(-1);
    s.Add(-3);
    s.Add(-13);
    s.Add(-2);
    s.Add(6);
    s.Add(26);
    s.Add(-443);
    s.Add(54);
    s.Add(-53);
    s.Add(13);
    s.Add(42);
    s.Add(-53);
    s.Add(14);
    s.Add(-3565);
    s.Add(-245);
    s.Add(-623);

    //contain test case
    assert(s.Contains(-1));
    assert(s.Contains(-443));
    assert(s.Contains(-13));
    assert(s.Contains(-3565));
    assert(s.Contains(-245));
    assert(!s.Contains(-1413431));
    cout << "successfully pass all test for contain methods" << endl;

    cout << "Giving a skipList displayed below: "<<endl;
    cout << s << endl;
    cout << "After sucessfully delete " << -443 << endl;
    assert(s.Remove(-443));
    cout << s << endl;
    cout << "sucessfully delete " << -53 << endl;
    assert(s.Remove(-53));
    cout << s << endl;
    cout << "sucessfully delete " << -3 << endl;
    assert(s.Remove(-3));
    cout << s << endl;
    cout << "sucessfully delete " << -2 << endl;
    assert(s.Remove(-2));
    cout << s << endl;
    cout << "After sucessfully delete " << -245 << endl;
    assert(s.Remove(-245));
    cout << s << endl;
    cout << "After sucessfully delete " << -6 << endl;
    assert(s.Remove(-6));
    cout << s << endl;
    cout << "After Trying to delete element already deleted " << -245 << endl;
    assert(!s.Remove(-245));
    cout << s << endl;
    cout << "After Trying to delete non existing element " << 25 << endl;
    assert(!s.Remove(25));
    cout << s << endl;
    cout << "After Trying to delete non existing element " << 36 << endl;
    assert(!s.Remove(36));
    cout << s << endl;
    cout << "After sucessfully delete " << -623 << endl;
    assert(s.Remove(-623));
    cout << s << endl;
    cout << "After Trying to delete element already deleted " << -623 << endl;
    assert(!s.Remove(-623));
    cout << s << endl;
}

void test03() {
    cout<< "\nTEST III"<<endl;
    cout << "Constructor generating random element to build the linkedList giving by the instructor"<<endl;
    SkipList s(5);
    for (int i = 0; i < 20; ++i) {
        int number = rand() % 100;
        s.Add(number);
        cout << "After adding " << number << endl;
        cout << s << endl;
    }
}

int main() {
    test1();
    test2();
    test03();

    return 0;
}