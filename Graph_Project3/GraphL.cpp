// ------------------------------------------------ Graphl.cpp -------------------------------------------------------
/*
 ELhadj Diallo
 Creation Date: 02/05/2020
 Last Modification: 02/15/2020
 CSS343 UWB
 Winter 2020
 Major: CSSE
 */

// ------------------------------------------------ Purpose-------------------------------------------------------
/*/*This section of the project is to is to display the graph information and implement depth-first (search always starts at node #1).
 * After reading a file from the console, each line consists of 2 integers representing an edge.
 * If there is an edge from node 1 to node 2, the data is: 1 2.
 * A zero for the first integer signifies the end of the data for that one graph.
 * In the file, all the edges for the 1st node will be listed first, then all the edges for the 2nd node, etc.
 * The algorithm take them as they come, no sorting. There may be several graphs, each having at most 100 nodes.
 * GraphL.cpp
 */

#include "GraphL.h"

//constructor for a graph object
GraphL::GraphL() {
//go through the array and set all node to zero
    for (int i = 1; i < MAXNODE; ++i) {
        arr[i] = NULL;
    }
}

//Destructor for a graph object
GraphL::~GraphL() {
    CleanAll();
}

//delete all thre graph in the DFS
void GraphL::CleanAll() {
    EdgeNode *temp;

    for (int i = 1; i < MAXNODE && arr[i] != NULL; i++) {
        temp = arr[i]->edgeHead;

        while (temp != NULL) {
            arr[i]->edgeHead = arr[i]->edgeHead->nextEdge;
            delete temp;
            temp = arr[i]->edgeHead;
        }
    }

    temp = NULL;
}

//read the file input and build the DFS graph
void GraphL::buildGraph(ifstream &input) {
    int nodeCount, source, destination;
    input >> nodeCount;
    string description;
    getline(input, description);
    //input.get();
    if (nodeCount > 0 && nodeCount < MAXNODE) {
        for (int i = 1; i <= nodeCount; i++) {
            getline(input, description);
            arr[i] = new GraphNode();
            arr[i]->data = description;
        }

        for (;;) {
            input >> source >> destination;
            getline(input, description);
            if (input.eof()) break;

            if (source == 0 || destination == 0) break;

            insertEdge(source, destination, nodeCount);
        }
    }
}

// finds the shortest path
void GraphL::DFS() {
    for (int i = 1; i < MAXNODE && arr[i] != NULL; i++) {
        arr[i]->visited = false;
    }

    cout << endl << "Depth-First-Ordering: ";

    for (int v = 1; (v < MAXNODE && arr[v] != NULL); v++) {
        if (!arr[v]->visited) {
            DFSHelper(v);
        }
    }

    cout << endl << endl;
}

//helper method to perform depth first searcrh
void GraphL::DFSHelper(int v) {
    EdgeNode *visit = arr[v]->edgeHead;

    arr[v]->visited = true;
    cout << v << ' ';

    while (visit != NULL) {
        if (!arr[visit->adjGraphNode]->visited) {
            DFSHelper(visit->adjGraphNode);
        }

        visit = visit->nextEdge;
    }
}

//display the shortest path of the DFS
void GraphL::DisplayDFS() const {
    EdgeNode *cur;

    cout << endl << "Graph:" << endl;

    for (int i = 1; i < MAXNODE && arr[i] != NULL; i++) {
        cout << "Node " << i << "        "
             << arr[i]->data << endl;

        cur = arr[i]->edgeHead;

        while (cur != NULL) {
            cout << "  edge " << i << ' ' << cur->adjGraphNode << endl;
            cur = cur->nextEdge;
        }
    }

    cout << endl;
}

// insert an edge to the function
bool GraphL::insertEdge(int source, int destination, int size) {
    bool success = (source > 0 && source <= size && destination > 0 && destination <= size && source != destination);
    if (success) {
        EdgeNode *newPtr = new EdgeNode;
        newPtr->adjGraphNode = destination;
        newPtr->nextEdge = arr[source]->edgeHead;
        arr[source]->edgeHead = newPtr;
        newPtr = NULL;
    }

    return success;
}
