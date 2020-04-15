// ------------------------------------------------ BSTree.cpp -------------------------------------------------------
/*
 ELhadj Diallo
 Creation Date: 01/24/2020
 Last Modification: 02/01/2020
 CSS343 UWB
 Winter 2020
 Major: CSSE
 */

// ------------------------------------------------ Purpose-------------------------------------------------------
/*
 * This programming exercises BinTree to create a BS tree class called BinTree
 * along with some additional functions
 * (remove function is not required).
 * This is my main drive that test all methods
 */

#include <iostream>
#include <istream>
#include "BinTree.h"

using namespace std;

const int ARRAYSIZE = 100;

void initArray(NodeData *ndArray[]);

void Test1() {
    NodeData *ndArray[ARRAYSIZE];
    initArray(ndArray);
    BinTree tree1;
    BinTree tree2;
    BinTree tree3;
    string s = "Hello";
    string s1 = "Guinea";
    string s2 = "Diallo";
    string s3 = "ELhadj";
    string s4 = "   ";
    string s10 = "Elhadj";
    string s11 = "Diallo";
    string s12 = "Nimma";
    string s13 = "Ok";
    string s14 = "   ";

    NodeData *n = new NodeData(s);
    NodeData *n1 = new NodeData(s1);
    NodeData *n2 = new NodeData(s2);
    NodeData *n3 = new NodeData(s3);
    NodeData *n4 = new NodeData(s4);
    NodeData *n5 = new NodeData(s10);
    NodeData *n6 = new NodeData(s11);
    NodeData *n7 = new NodeData(s12);
    NodeData *n8 = new NodeData(s13);
    NodeData *n9 = new NodeData(s14);

    //INSERT NODE TO Tree1
    tree1.insert(n);
    tree1.insert(n1);
    tree1.insert(n2);
    tree1.insert(n3);
    tree1.insert(n4);
    tree1.insert(n5);
    tree1.insert(n6);
    tree1.insert(n7);
    tree1.insert(n8);
    tree1.insert(n9);

    //Display sideways tree1
    cout << "DisplaySideways: " << endl;
    tree1.displaySideways();

    //display tree1 BinTree
    cout << "tree1: " << tree1 << endl;

    //Assign tree2 to tree1
    tree2 = tree1;

    //display tree2 filled from tree1
    cout << "tree1: " << tree1 << endl;

    //copy BinTree to array
    cout << "\nTest  BSTree to Array" << endl;
    tree1.bstreeToArray(ndArray);

    //tree1 must be empty after the copy
    if (tree1.isEmpty()) {
        cout << "tree1 is empty" << endl;
    } else {
        cout << "tree1 is NOT empty" << endl;
    }

    //create a new tree
    BinTree tree4;

    //check if array is null,
    //should be null so Array must be empty
    cout << "\nTest arrayTo BSTree" << endl;
    for (int i = 0; i < 100; i++) {
        if (ndArray[i] != NULL) {
            cout << "B3 is : " << i << " " << *ndArray[i] << endl;
        }
    }

    tree4.arrayToBSTree(ndArray);

    cout << "tree2 is : " << tree2 << endl;
    cout << "tree4 is : " << tree4 << endl;

    //B3 should be empty since the array is copied to B4
    cout << " \ntree3 is : " << tree3 << " Must be empty " << endl;

    cout << "The Height of n7 : " << tree1.getHeight(*n7) << endl;


     cout << "\nTest copy constructor and Equal and Inequal operators" << endl;
    BinTree dup(tree1);
    //check if equal methods Works.
    if (tree1 != dup) {
        cout << "tree1 is NOT equal to dup" << endl;

    } else {
        cout << "tree1 is equal to dup" << endl;
    }

    cout << "\nTest Retreive methods" << endl;
    //should reurn the node value
    if (tree2.retrieve(*n7, n5)) {
        cout << "Node was found" << endl;
        cout << "N5 is: " << *n5 << endl;
    } else {
        cout << "Node was NOT found" << endl;
    }
}

int main() {
    Test1();
    return 0;
}

void initArray(NodeData *ndArray[]) {
    for (int i = 0; i < ARRAYSIZE; i++) {
        ndArray[i] = NULL;
    }
}