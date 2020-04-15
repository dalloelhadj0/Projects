// ------------------------------------------------ Polynomial.cpp -------------------------------------------------------
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
 * BinTree.cpp
 */
#include "BinTree.h"
#include <iostream>
#include <istream>
using namespace std;

// Creates an empty BinTree with the root set to NULL
BinTree::BinTree()
{
    root = NULL;
}

// Creates a deep copy of a referenced BinTree passed in
BinTree::BinTree(const BinTree &sourceTree)
{
    root = NULL;
    *this = sourceTree;
}

// Calls makeEmpty to delete a BinTree
BinTree::~BinTree()
{
    makeEmpty();
}


// Checks whether a BinTree is empty or not
bool BinTree::isEmpty() const
{
    if (root == NULL)
    {
        return true;
    }

    return false;
}

// Deletes and entire BinTree
// Uses helper function makeEmptyHelpter
void BinTree::makeEmpty()
{
    makeEmptyHelper(root);
}

// Helper function for makeEmpty
void BinTree::makeEmptyHelper(Node*& current)
{
    if (current != NULL)    // post order traversal
    {
        makeEmptyHelper(current->left); // left
        makeEmptyHelper(current->right);    // right

        if (current->data != NULL)
        {
            delete current->data;   // deletes the data
            current->data = NULL;
        }

        delete current; // sets pointer to NULL
        current = NULL;
    }
}

// Makes the left tree a deep copy of the right tree
// Uses helper function assignmentHelper to traverse the tree
BinTree& BinTree::operator=(const BinTree &rTree)
{
    if (*this == rTree) // check if both trees are the same
    {
        return *this;
    }

    this->makeEmpty();  // deletes the left tree

    assignmentHelper(rTree.root, root);

    return *this;   // returns lTree when its the same as rTree
}

// Helper function to overloaded assignment operator
void BinTree::assignmentHelper(Node* rTree, Node* &lTree)
{
    if (rTree != NULL) // preorder traverse right tree
    {

        lTree = new Node;   // new node for left tree
        NodeData *temp = new NodeData(*rTree->data);    //copies rTree NodeData to temp
        lTree->data = temp; // set left tree data to temp

        assignmentHelper(rTree->left, lTree->left); // left
        assignmentHelper(rTree->right, lTree->right);   //right
    }
    else
    {
        lTree = NULL;  // copy empty tree
    }
}

// Checks if two BSTrees are exactly the same
// Uses helper function equalityComparisonHelper
bool BinTree::operator==(const BinTree &rTree) const
{
    if (root == NULL && rTree.root == NULL)
    {
        return true;
    }
    else
    {
        return equalityComparisonHelper(root, rTree.root);
    }
}

// Helper function to overloaded operator ==
bool BinTree::equalityComparisonHelper(Node* lNode, Node* rNode) const
{
    if (lNode == NULL && rNode == NULL)
    {
        return true;    // tree if both nodes are NULL
    }

    if (lNode == NULL || rNode == NULL)
    {
        return false;   // false if one node has data and the other does not
    }

    if (*lNode->data == *rNode->data
        && lNode->left == NULL && rNode->left == NULL
        && lNode->right == NULL && rNode->right == NULL)
    {
        return true;    // true if nodes being compared have the same data and no children
    }

    // both nodes contain the same NodeData
    // continue to traverse both trees
    return (*lNode->data == *rNode->data
            && equalityComparisonHelper(lNode->left, rNode->left)
            && equalityComparisonHelper(lNode->right, rNode->right));
}

// Checks if two BSTrees are not exactly the same
bool BinTree::operator!=(const BinTree &nwBS) const
{
    return !(*this == nwBS);
}

// Inserts a new node containing NodeData into a BinTree
// Uses helper function insertHelperMethods
bool BinTree::insert(NodeData* toInsert)
{
    return insertHelperMethods(root, toInsert);
}

// Helper function to insert
// If NodeData is already in BinTree then node is not inserted
bool BinTree::insertHelperMethods(Node*& current, NodeData* nodeToInsert)
{
    if (current == NULL)    // insert new node here
    {
        current = new Node;   // new node created
        current->data = nodeToInsert;   // NodeData set to node
        current->left = NULL;   // left child set to NULL
        current->right = NULL;  // right child set to NULL
    }
    else if (*nodeToInsert < *current->data)
    {
        insertHelperMethods(current->left, nodeToInsert);  // traverse left
    }
    else if (*nodeToInsert > *current->data)
    {
        insertHelperMethods(current->right, nodeToInsert); // traverse right
    }
    else
    {
        return false;
    }

    return true;
}

// Checks whether or not a NodeData is in a BinTree
// If found returns a pointer to that node
// Uses helper function retrieveHelper
bool BinTree::retrieve(const NodeData &toRetrieve, NodeData* &retrieved)
{
    retrieveHelper(root,toRetrieve, retrieved);   // search tree

    if (retrieved != NULL)
    {
        return true;    // NodeData found
    }

    return false;   // NodeData not in tree
}

// Helper function to retrieve
bool BinTree::retrieveHelper(Node* &current, const NodeData &toRetrieve, NodeData* &retrieved) const
{
    if (current == NULL)    // NodeData is not found
    {
        retrieved = NULL;   // return pointer set to NULL
        return false;
    }

    if (*current->data == toRetrieve)   // NodeData found
    {
        retrieved = current->data;  // return pointer set to NodeData
        return true;
    }
    else if (*current->data < toRetrieve)
    {
        retrieveHelper(current->right, toRetrieve, retrieved);  // traverse right
    }
    else if (*current->data > toRetrieve)
    {
        retrieveHelper(current->left, toRetrieve, retrieved);   // traverse left
    }
    else
    {
        return false;   // NodeData not found
    }
    return true;
}

//  helper function getHeightHelper
// Returns the height of a given node in a binary standard tree
// If the node given is a leaf than the height is 1
int BinTree::getHeight(const NodeData &toFind) const
{
    return getHeightHelper(toFind, root);
}

// Helper function to getHeight
// Finds the specific node in the tree, if it exists
// Uses helper function recursiveGetHeightHelper
int BinTree::getHeightHelper(const NodeData &toFind, Node* current) const
{
    if (current == NULL)
    {
        return 0;   // node is not in tree, return height = 0
    }
    else if (*current->data == toFind)
    {
        return recursiveGetHeightHelper(current);   // node found
    }
    else
    {
        int left = getHeightHelper(toFind, current->left);  // search left
        int right = getHeightHelper(toFind, current->right);    // search right

        return max(left, right);
    }
}

// Helper function to getHeightHelper
// Determines the height of the root node
int BinTree::recursiveGetHeightHelper(Node* current) const
{
    if (current == NULL)
    {
        return 0;   // have reached a leaf node
    }
    else
    {
        // counts the amount of levels in the tree from root node
        return 1 + max(recursiveGetHeightHelper(current->left), recursiveGetHeightHelper(current->right));
    }
}

// Transfers all of the nodes from a BST into an array and then deletes the BST
// Uses helper function bstreeToArrayHelper
void BinTree::bstreeToArray(NodeData* arr[])
{
    bstreeToArrayHelper(root, arr);
    makeEmpty();  // delete the BST
}

// Helper function to bstreeToArrayHelper
int BinTree::bstreeToArrayHelper(Node* current, NodeData* arr[])
{
    if (current == NULL)
    {
        return 0;   // end of BST
    }

    int left = bstreeToArrayHelper(current->left, arr);

    NodeData *temp;
    temp = current->data; // saves NodeData to temp
    current->data = NULL; // current no longer points to node
    *(arr + left) = temp; //arr points to temp
    int right = bstreeToArrayHelper(current->right, arr + left + 1);

    return left + right + 1; // return position
}

// Builds a balanced BST from a sorted array of NodeData
// Array is filled with NULLs at the end
// Uses helper function arrayToBSTreeHelper
void BinTree::arrayToBSTree(NodeData* sourceArray[])
{
    makeEmpty();  // empty current BST

    int high = 0;

    for(int i = 0; i < 100; i++)    // assumed to be no more than 100 elements
    {
        if (sourceArray[i] != NULL)
        {
            high++; // find how many elements points to NodeData
        }
        else
        {
            sourceArray[i] = NULL;
        }
    }

    arrayToBSTreeHelper(root, sourceArray, 0, high-1);
}

// Helper function to arrayToBSTree
// Builds BST and sets array to NULL
void BinTree::arrayToBSTreeHelper(Node *current, NodeData* sourceArray[], int low, int high)
{
    if (low > high)
    {
        current = NULL; // end of array NodeData
    }
    else
    {
        int mid = (low + high) / 2; // picks NodeData from array to build balanced tree

        NodeData* temp; // temp NodeData pointer
        temp = sourceArray[mid];    // assigns mid element from array section to temp
        sourceArray[mid] = NULL;    // sets that array element to NULL

        insert(temp);   // inserts NodeData int BST
        arrayToBSTreeHelper(current, sourceArray, low, mid - 1);    // fill left
        arrayToBSTreeHelper(current, sourceArray, mid + 1, high);   // fill right
    }
}

// Helper function for overloaded operator <<
void BinTree::inorderHelper(Node* current) const
{
    if (current != NULL)  // traverse and print data
    {
        inorderHelper(current->left);
        cout << *current->data << " ";
        inorderHelper(current->right);
    }
}

// Help display tree sideways
void BinTree::displaySideways() const
{
    sideways(root, 0);  // get her comments
}


// Sideway helper function
// help print the tree sideway
void BinTree::sideways(Node* current, int level) const
{
    if (current != NULL) {
        level++;
        sideways(current->right, level);

        // indent for readability, 4 spaces per depth level
        for (int i = level; i >= 0; i--) {
            cout << "    ";
        }

        cout << *current->data << endl;        // display information of object
        sideways(current->left, level);
    }
}

// Displays data from the BinTree in order.
// Uses helper function inorderHelper to traverse tree
ostream &operator<<(ostream &outStream, const BinTree &tree)
{
    tree.inorderHelper(tree.root);
    outStream << endl;
    return outStream;
}
