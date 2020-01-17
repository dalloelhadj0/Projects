/*
Elhadj Diallo
CSS 342
 Assignment 4
 Major CSSE
 UWB fall2019
*/

/*This program is design to build a skipList using a dubly linkedList, All element are store at the level 0, so from there,
 * we toss a coins to check wheter this element should be at the next level and so on.
 * Each element might have a chance to be in the next level but it is not garanted that they all would be there.*/

#include "SkipList.h"
#include <iostream>
#include <assert.h>
#include <climits>

using namespace std;

//Done
//Node constructor
SkipList::SNode::SNode(int data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
    this->upLevel = nullptr;
    this->downLevel = nullptr;
}

//Done
//connstructor for skiplist class
SkipList::SkipList(int depth) {
    if (depth > 0) {
        this->frontGuards = new SNode *[depth];
        this->rearGuards = new SNode *[depth];
        this->depth = depth;

        //Linked double list front and rear Guards horizontally
        for (int i = 0; i < depth; i++) {
            //connect horizontally
            SNode *front = new SNode(INT_MIN);
            SNode *Rear = new SNode(INT_MAX);

            //fill the gard with INT_MIN and INT_MAX
            frontGuards[i] = front;
            rearGuards[i] = Rear;

            //connect the guard horizontaly
            frontGuards[i]->next = rearGuards[i];
            rearGuards[i]->prev = frontGuards[i];
        }

        //linked guards vertically
        for (int i = 0; i < depth - 1; i++) {
            frontGuards[i]->upLevel = frontGuards[i + 1];
            frontGuards[i + 1]->downLevel = frontGuards[i];
            rearGuards[i]->upLevel = rearGuards[i + 1];
            rearGuards[i + 1]->downLevel = rearGuards[i];

        }
    }else{
        cout << "The level must be greater than or equal to 1" << endl;
    }
}


//destructor
SkipList::~SkipList() {
    SNode *current;
    SNode *NodeToDelete;
    for (int i = depth - 1; i >= 0; i--) {
        current = frontGuards[i]->next;
        if (frontGuards[i]->next->data == rearGuards[i]->data) {
            continue;
        } else {
            while (current->next != nullptr) {
                NodeToDelete = current;
                current = current->next;
                delete NodeToDelete;
            }
        }
    }

    for (int i = depth - 1; i >= 0; i--) {
        delete frontGuards[i];
        delete rearGuards[i];
    }
    delete[]frontGuards;
    delete[]rearGuards;
}

//return true if value being deleted, false otherwise
bool SkipList::Remove(int data) {
    if (!SkipList::Contains(data)) {
        return false;
    } else {
        SNode *current;
        SNode *NodeToDelete;
        current = frontGuards[0];
        while (current->next->data < data) {
            current = current->next;
        }
        if (current->next->data == data) {
            current = current->next;
        }
        if (current->upLevel == nullptr) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            return true;

        }
        while (current->upLevel != nullptr) {
            NodeToDelete = current;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            current = NodeToDelete->upLevel;
            delete NodeToDelete;
        }
        if (current->upLevel == nullptr) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            return true;
        }
    }
}

//add methode and tost coins to add to a higher level if lucky
//return true if successfully added, false otherwise
bool SkipList::Add(int data) {
    SNode *current = frontGuards[0]->next;
    while (current->data < data && current->next != nullptr) {
        current = current->next;
    }
    if (current->data == data) {
        return false;
    }
    SNode *newNode = new SNode(data);
    addBefore(newNode, current);
    int level = 1;
    while (alsoHigher() && level < depth) {
        SNode *newUpper = new SNode(data);

        //connect newUpper and newNode vertically
        newUpper->downLevel = newNode;
        newNode->upLevel = newUpper;

        //go toward Int_min to try to connect the two levels
        SNode *current = newNode->prev;
        while (current->upLevel == nullptr) {
            current = current->prev;
        }

        //go up one level
        current = current->upLevel; // maybe flip idk
        //go right toward int-MAX
        while (current->next != nullptr && current->data < data) {
            current = current->next;
        }

        //add the upper value;
        addBefore(newUpper, current);
        newNode = newUpper;
        level++;
    }
    return true;
}


// return true 50% of time,
// each node has a 50% chance of being at higher level
bool SkipList::alsoHigher() const {
    int r = rand();
    if (r % 2 == 1) {
        return true;
    }
    return false;
}

//add methods help us store data before a a giving node
void SkipList::addBefore(SNode *newNode, SNode *nextNode) {
    assert(newNode != nullptr && nextNode != nullptr && newNode->data < nextNode->data);
    //getting the node before head
    SNode *before = nextNode->prev;
//make my new node to point to the nextNode
    newNode->next = nextNode;
//make the newNode point to the previous node of the LinkedLIst
    newNode->prev = nextNode->prev;
//Make next_node point at its previoius node which is the newNode
    nextNode->prev = newNode;
//make the previous node point to the newNode
    before->next = newNode;
// after nodes have been linked
    assert (newNode->next == nextNode && nextNode->prev == newNode);
    assert (newNode->prev != nullptr && newNode->prev->data < newNode->data);
}

//check if a given value is whithin the data return true, false otherwise
bool SkipList::Contains(int data) {
    for (int i = depth - 1; i >= 0; i--) {
        SNode *current = frontGuards[i]->next;
        while (current != nullptr) {
            if (current->data == data) {
                return true;
            } else {
                current = current->next;
            }
        }
    }
    return false;
}

//Outstream method that help print the skipList data
ostream &operator<<(ostream &os, const SkipList &list) {
    //start fron the top to bottom
    for (int i = list.depth - 1; i >= 0; i--) {
        //get the top node of the linkedList
        SkipList::SNode *current = list.frontGuards[i];
        os << "Level : " << i << " -- ";
        while (current != nullptr) {
            os << current->data << ", ";
            current = current->next;
        }
        os << endl;
    }
    return os;
}
