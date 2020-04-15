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
 * BinTree.h
 */

#include "NodeData.h"
#include <iostream>
#include <istream>
using namespace std;

struct Node
{
    NodeData* data;						// pointer to data object
    Node* left;							// left subtree pointer
    Node* right;						// right subtree pointer
};

class BinTree
{
    // Overloaded << operator
    friend std::ostream& operator<<(std::ostream &outStream, const BinTree &);

public:
    // Constructors
    BinTree();

    // copy constructor
    BinTree(const BinTree &);

    // Destructor
    ~BinTree();

    // destructor, calls makeEmpty
    // true if tree is empty, otherwise false
    bool isEmpty() const;

    // make the tree empty so isEmpty returns true
    void makeEmpty();

    // Returns the height of node in tree
    int getHeight(const NodeData &) const;

    // Builds an array of NodeData from a BinTree'
    void bstreeToArray(NodeData* []);

    // Builds a BinTree from a NodeData array
    void arrayToBSTree(NodeData* []);

    // Displays the tree sideways
    void displaySideways() const;

    // Assignment operator
    BinTree& operator=(const BinTree &);

    // Comparison operators
    bool operator==(const BinTree &) const;
    bool operator!=(const BinTree &) const;

    // Inserts a node into a tree
    bool insert(NodeData*);

    // Searches a particular value in the BinTree
    bool retrieve(const NodeData &, NodeData* &);

private:
    // root of the tree
    Node* root;

    // helper for overloaded <<
    void inorderHelper(Node*) const;
    int getHeightHelper(const NodeData&, Node*) const;

    // helper for the getHeighthelper
    int recursiveGetHeightHelper(Node*) const;

    // helper for bstreeToArray
    int bstreeToArrayHelper(Node*, NodeData* []);

    // helper for overloaded ==
    bool equalityComparisonHelper(Node*, Node*) const;

    // helper for insert
    // helper for getHeight
    bool insertHelperMethods(Node *&current, NodeData *nodeToInsert);

    // helper for arrayToBSTree
    void arrayToBSTreeHelper(Node*, NodeData* [], int, int);

    // helper for displaySideways
    void sideways(Node*, int) const;//helper for displaySideways()

    // helper for makeEmpty
    void makeEmptyHelper(Node*& current);

    // helper for overloaded =
    void assignmentHelper(Node*, Node* &);

    // helper for retrieve
    bool retrieveHelper(Node* &, const NodeData &, NodeData* &) const;
};
