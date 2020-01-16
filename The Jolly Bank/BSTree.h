//Elhadj Diallo
//Assignment#6
//December 06, 2019
//CSSC UWB Fall2019

/*This BSTree class store the Accound created by the account class.
 * It is sorted by ID and you can erace the whole account by eracing the BSTree*/

#ifndef BSTREE_H
#define BSTREE_H
#include "Account.h"

using namespace std;
class BSTree
{
public:
    BSTree();
    ~BSTree();

    bool Insert(Account* account);
    // retrieve object, first parameter is the ID of the account
    // second parameter holds pointer to found object, NULL if not found
    bool Retrieve(const int &, Account * &) const;

// display the contents of the tree account
    void Display() const;
    void Empty();
    bool isEmpty() const;


private:

    struct Node
    {
        Node();
        Node(Account* account);
        Account* pAcct;
        Node* right;
        Node* left;
    };

    Node* root;
    void Display(Node* rootNode) const;
    Node* Insert(Account* account, Node* rootNode);
    void Destroyer(Node* rootNode);
    bool Retrieve(const int& accountID, Account*& pFoundObject, Node* rootNode) const;
};

#endif