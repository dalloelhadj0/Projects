// ------------------------------------------------ Graphl.h -------------------------------------------------------
/*
 ELhadj Diallo
 Creation Date: 02/05/2020
 Last Modification: 02/15/2020
 CSS343 UWB
 Winter 2020
 Major: CSSE
 */

// ------------------------------------------------ Purpose-------------------------------------------------------
/*This section of the project is to is to display the graph information and implement depth-first (search always starts at node #1).
 * After reading a file from the console, each line consists of 2 integers representing an edge.
 * If there is an edge from node 1 to node 2, the data is: 1 2.
 * A zero for the first integer signifies the end of the data for that one graph.
 * In the file, all the edges for the 1st node will be listed first, then all the edges for the 2nd node, etc.
 * The algorithm take them as they come, no sorting. There may be several graphs, each having at most 100 nodes.
 * GraphL.h
 */
#ifndef UNTITLED7_GRAPHL_H
#define UNTITLED7_GRAPHL_H

#include <iomanip>
#include "NodeData.h"
#include <cstdint>
#include <limits>
#include <climits>
using namespace std;


//const for the array size
const int MAXNODE = 101;

class GraphL
{
public:
    //constructor for a graph object
    GraphL();

    //Destructor for a graph object
    ~GraphL();

    void buildGraph(ifstream& input);
    void DFS();// finds the shortest path
    void DisplayDFS() const;
    void CleanAll();

private:

    //forward reference for the compiler
    struct EdgeNode;

    //structs used simplicity, use classes if desired
    struct GraphNode
    {
        //head of the list of edges
        EdgeNode* edgeHead;
        //data information about each node
        NodeData  data;
        //check whether or not Current is been visited
        bool      visited;
    };


    struct EdgeNode
    {
        //subscript of the adjacent graph node
        int  adjGraphNode;
        //pointer to the next edge node of the current node
        EdgeNode* nextEdge;
    };

    //array of graphNodes
    GraphNode* arr[MAXNODE];

    // insert an edge to the function
    bool insertEdge(int source, int destination, int size);

    //helper method to perform depth first searcrh
    void DFSHelper(int v);

};

#endif //UNTITLED7_GRAPHL_H
