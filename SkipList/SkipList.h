/*
Elhadj Diallo
CSS 342
 Assignment 4
 Major CSSE
 UWB fall2019
*/

#ifndef ASS4_SKIPLIST_H
#define ASS4_SKIPLIST_H
#include <iostream>

/*This program is design to build a skipList using a dubly linkedList, All element are store at the level 0, so from there,
 * we toss a coins to check wheter this element should be at the next level and so on.
 * Each element might have a chance to be in the next level but it is not garanted that they all would be there.*/

using namespace std;

class SkipList {
    friend ostream &operator<<(ostream &os, const SkipList &list);

public:
// default SkipList has depth of 1, just one doubly-linked list explicit
    explicit SkipList(int depth = 1);

// destructor
    virtual ~SkipList();

// return true if successfully added, no duplicates
    bool Add(int data);

// return true if successfully removed
    bool Remove(int data);

// return true if found in SkipList
    bool Contains(int data);

// return true 50% of time,
// each node has a 50% chance of being at higher level
    bool alsoHigher() const;

private:
    class SNode {
    public:
// SNoide stores int as data
        explicit SNode(int data);

// data for SNode
        int data;
// link to next SNode
        SNode *next;
// link to prev SNode
        SNode *prev;
// link to up one level
        SNode *upLevel;
// link to down one level
        SNode *downLevel;
    };

// depth of SkipList, levels are 0 to depth-1
    int depth;
// array of depth SNode* objects as frontGuards linking levels // if depth = 2, we'd have frontGuards[0] and frontGuards[1]
    SNode **frontGuards;
// array of depth SNode* objects as rearGuards linking levels
    SNode **rearGuards;

    // given a SNode, place it before the given NextNode
    void addBefore(SNode *newNode, SNode *nextNode);

};


#endif //ASS4_SKIPLIST_H
