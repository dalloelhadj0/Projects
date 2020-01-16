//Elhadj Diallo
//Assignment#6
//December 06, 2019
//CSSC UWB Fall2019

/*This BSTree class store the Accound created by the account class.
 * It is sorted by ID and you can erace the whole account by eracing the BSTree*/
#include "BSTree.h"
#include <iostream>

using namespace std;
//default constructor
BSTree::BSTree()
{
    root = nullptr;
}

//default node constructor
BSTree::Node::Node()
{
    pAcct = nullptr;
    left = nullptr;
    right = nullptr;
}

//Node creating an account
BSTree::Node::Node(Account* account)
{
    pAcct = account;
    left = nullptr;
    right = nullptr;
}
//destructor
BSTree::~BSTree()
{
    Empty();
}

//
bool BSTree::Insert(Account* account)
{
    if (root == nullptr)
    {
        Node* temp = new Node(account);
        root = temp;
        return true;
    }
    else
    {
        Insert(account, root);
    }

    return false;
}


BSTree::Node* BSTree::Insert(Account* account, Node* rootNode)
{
    if (rootNode == nullptr)
    {
        Node* temp = new Node;
        temp->pAcct = account;
        temp->left = nullptr;
        temp->right = nullptr;
        rootNode = temp;
        return temp;
    }
    else
    {
        if (account->getID() < rootNode->pAcct->getID())
        {
            rootNode->left = Insert(account, rootNode->left);
        }
        else
        {
            rootNode->right = Insert(account, rootNode->right);
        }


    }

    return rootNode;
}

// retrieve object, first parameter is the ID of the account
// second parameter holds pointer to found object, NULL if not found
bool BSTree::Retrieve(const int& accountID, Account*& pFoundObject) const
{
    Node* temp = root;
    return Retrieve(accountID, pFoundObject, temp);
}


bool BSTree::Retrieve(const int& accountID, Account*& pFoundObject, Node* rootNode) const
{

    if (rootNode != nullptr)
    {
        if (accountID == rootNode->pAcct->getID())
        {
            pFoundObject = rootNode->pAcct;
            return true;
        }
        else if (accountID < rootNode->pAcct->getID())
        {

            return Retrieve(accountID, pFoundObject, rootNode->left);
        }
        else
        {

            return Retrieve(accountID, pFoundObject, rootNode->right);
        }
    }

    pFoundObject = nullptr;
    return false;
}

// display the contents of the tree account
void BSTree::Display() const
{

    Display(root);
}

void BSTree::Display(Node* rootNode) const
{
    if (rootNode != nullptr)
    {
        Display(rootNode->left);
        cout << *rootNode->pAcct << endl;
        Display(rootNode->right);
    }
}

//destroy the entiere tree
void BSTree::Empty()
{
    Destroyer(root);
}

void BSTree::Destroyer(Node* rootNode)
{
    if (rootNode != nullptr)
    {
        Destroyer(rootNode->left);
        Destroyer(rootNode->right);
        delete rootNode->pAcct;
        delete rootNode;
    }
}

//check if the tree is empthy, return true if empty, false otherwise
bool BSTree::isEmpty() const
{
    return root == nullptr;
}
