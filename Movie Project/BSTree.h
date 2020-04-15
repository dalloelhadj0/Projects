//
// Created by Elhadj Diallo on 3/10/20.
//

#ifndef PROJECT4_BSTREE_H
#define PROJECT4_BSTREE_H


#include <stdio.h>

template <class item_type> class BSTree
{
public :
    // ------------------------------------BSTree default constructor----------------------------
    //  creates an BSTree object
    // -------------------------------------------------------------------------------------------
    BSTree()
    {
        root = NULL;
        size = 0;
    }

    // ------------------------------------BSTree destructor--------------------------------------
    // destructs BSTree object
    // -------------------------------------------------------------------------------------------
    ~BSTree()
    {
        makeEmpty();
    }

    // ------------------------------------isEmpty------------------------------------------------
    // checks whether BST is empty
    // -------------------------------------------------------------------------------------------
    bool isEmpty() const
    {
        return (root == NULL);
    }
    // ------------------------------------makeEmpty----------------------------------------------
    // Description: calls makeEmpty helper method to delete all nodes in the item
    // -------------------------------------------------------------------------------------------
    void makeEmpty()
    {
        makeEmptyHelper(root);
    }
    // ------------------------------------insert-------------------------------------------------
    // Description: inserts a new data to the current bst
    // -------------------------------------------------------------------------------------------
    bool insert(item_type* dataptr)
    {
        // create a new noe to insert
        Node *insertNode = new Node;
        if (dataptr != NULL)
        {
            insertNode->data = dataptr;
        }
        insertNode->left = NULL;
        insertNode->right = NULL;


        //Insert note
        if(root == NULL)
        {
            root= insertNode;
            size++;
        }
        else
        {
            Node *currentPtr = root; //keep track of position
            bool inserted = false;

            // look for a place to insert
            // if data is less than current data , insert in left subtree
            // otherwise insert in right subtree
            while(!inserted)
            {
                if(insertNode->data->isEqual(*currentPtr->data)) // no insertion, duplicates are not allowed
                {
                    delete insertNode;
                    insertNode = NULL;
                    return false;

                }
                else if (currentPtr->data->isGreater(*insertNode->data)) // go left
                {
                    if(currentPtr->left == NULL) // insert left
                    {
                        currentPtr->left = insertNode;
                        inserted = true;
                        size++;

                    }
                    else
                    {
                        currentPtr = currentPtr->left; // move current to one step left
                    }

                }
                else // (*insertNode-> data > *currentPtr->data) //go right
                {
                    if (currentPtr->right == NULL) // insert right
                    {
                        currentPtr->right = insertNode;
                        inserted = true;
                        size++;

                    }
                    else
                    {
                        currentPtr = currentPtr->right;

                    }
                }
            }


        }
        return true;
    }
    // ------------------------------------retrieve-----------------------------------------------
    // Description: find a desired item in the bst. Returns boolean
    // -------------------------------------------------------------------------------------------
    bool retrieve(const item_type &dataItem, item_type* & dataFound) const
    {
        retrieveHelper(root, dataItem, dataFound);

        if (dataFound != NULL) //Check is dataFound was changed
        {
            return true;
        }
        else
        {
            return false; //If dataFound was not found then return false
        }
    }
    // ------------------------------------remove-------------------------------------------------
    // Description: removes an item from the tree. returns boolean
    // -------------------------------------------------------------------------------------------
    bool remove(const item_type &dataItem)
    {
        return false;
    }
    // -----------------------------------print --------------------------------------------------
    // Description: calls print helper to print out bst info
    // -------------------------------------------------------------------------------------------
    void print() const
    {
        printHelper(root);
    }

private:
    struct Node
    {
        Node()
        {
            data =NULL;
            left = NULL;
            right = NULL;

        }
        item_type* data;						// pointer to data object
        Node* left;							// left subtree pointer
        Node* right;						// right subtree pointer
    };
    Node* root;								// root of the tree
    int size;
    // ------------------------------------makeEmptyHelper ---------------------------------------
    // Description: helper method to delete all items in BST
    // -------------------------------------------------------------------------------------------
    void makeEmptyHelper(Node *& treePtr)
    {
        //Postorder traversal
        if (treePtr != NULL)
        {
            makeEmptyHelper(treePtr->left);
            makeEmptyHelper(treePtr->right);

            delete treePtr->data;// delete nodedata
            treePtr->data= NULL;

            delete treePtr; //delete node itself
            treePtr = NULL;

        }
    }
    // ------------------------------------isEqual------------------------------------------------
    // Description: checks whether two items in bst is equal
    // -------------------------------------------------------------------------------------------
    bool isEqual(Node *leftPtr, Node *rightPtr) const
    {
        //Check whether the node data is the same
        //Safeguard against crash from comparison of empty BST, checks if NULL
        if ((leftPtr != NULL && rightPtr != NULL) && (leftPtr->data->isEqual(*rightPtr->data)))
        {
            return true;
        }
        //Return false when reached the end
        if ((leftPtr == NULL) || (rightPtr == NULL))
        {
            return false;
        }

        //Check data and recursively search tree
        return isEqual(leftPtr->left,  rightPtr->left ) && isEqual (leftPtr->right, rightPtr->right);
    }
    // ------------------------------------retrieveHelper------------------------------------------
    // Description:helper method to retrieve a given node
    // -------------------------------------------------------------------------------------------
    void retrieveHelper(Node *curPtr , const item_type &dataItem, item_type *&dataFound) const
    {
        if (curPtr == NULL) //Not Found
            dataFound = NULL;

        else if (dataItem.isEqual(*curPtr->data)) //Item Found
        {
            dataFound = curPtr->data;
        }
        else if(curPtr->data->isGreater(dataItem)) //Check left
        {
            retrieveHelper(curPtr->left, dataItem, dataFound);
        }
        else //Check right
        {
            retrieveHelper(curPtr->right, dataItem, dataFound);
        }
    }
    // ------------------------------------print-------------------------------------------------
    // Description: helper method to print out the tree
    // -------------------------------------------------------------------------------------------
    void printHelper(Node *curPtr) const
    {
        if (curPtr == NULL)
            return;

        printHelper(curPtr->left);
        curPtr->data->print();
        printHelper(curPtr->right);
    }
};



#endif //PROJECT4_BSTREE_H
