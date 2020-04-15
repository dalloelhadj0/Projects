// ------------------------------------------------ GraphM.h -------------------------------------------------------
/*
 ELhadj Diallo
 Creation Date: 02/05/2020
 Last Modification: 02/15/2020
 CSS343 UWB
 Winter 2020
 Major: CSSE
 */

// ------------------------------------------------ Purpose-------------------------------------------------------
/*/* This section of the program is to implement Dijkstra's shortest path algorithm.
 * It'll be able to find the lowest cost paths (findShortestPath function)
 * and display the cost and path from every node to every other node using displayAll methods.
 * It must also have the capability to display routine (display function) will output one path in detail.
 * GraphM.h
 */

#ifndef UNTITLED7_GRAPHM_H
#define UNTITLED7_GRAPHM_H

#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <limits>
#include <climits>
#include <fstream>
#include <iomanip>
#include "NodeData.h"

using namespace std;

// constant size for the table T and C
int const MAXNODES_M = 101;

class GraphM {
public:

    //constructor for graph object
    GraphM();

    //Distructor for graph object
    ~GraphM();

    // Functions
    void buildGraph(ifstream &);

    // finds shortest path  using Dijkstra's algorithm
    void findShortestPath();

    //insert an edge between two given nodes
    bool insertEdge(int from, int to, int dist);

    // remove edge between two given nodes
    bool removeEdge(int from, int to);

    //displays shortest path
    void display(int source, int destination);

    //display the all result to the user with shortest path included
    void displayAll();

private:
    struct Type {
        bool visited;                       // whether node has been visited
        int dist;                           // shortest distance from source known so far
        int path;                           // previous node in path of min dist
    };

    NodeData data[MAXNODES_M];              // data for graph nodes
    int C[MAXNODES_M][MAXNODES_M];          // cost array, the adjacency matrix
    int size;                               // number of nodes in the graph
    Type T[MAXNODES_M][MAXNODES_M];    // stores visited, distance, path

    // helper for display()
    void findData(int from, int to);

    // helper for display() and displayAll()
    void findPath(int from, int to);
};

#endif //UNTITLED7_GRAPHM_H
