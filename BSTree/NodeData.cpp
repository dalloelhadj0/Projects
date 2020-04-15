//
// Elhadj Diallo.
//

#include "BinTree.h"
#include "NodeData.h"

//default constructors
NodeData::NodeData() { data = ""; }

// Destructor
// needed so strings are deleted properly
NodeData::~NodeData() { }

// copy constructor
NodeData::NodeData(const NodeData& nd) { data = nd.data; }

// cast string to NodeData
NodeData::NodeData(const string& s) { data = s; }

// Assignment operator
//reassign a node to new node given as parameter
NodeData& NodeData::operator=(const NodeData& rhs) {
    if (this != &rhs) {
        data = rhs.data;
    }
    return *this;
}

// == operator compare two Node string
// return true if the two node data are ==, false otherwise
bool NodeData::operator==(const NodeData& rhs) const {
    return data == rhs.data;
}

// != operator compare two Node string
// return true if the two node data are !=, false otherwise
bool NodeData::operator!=(const NodeData& rhs) const {
    return data != rhs.data;
}

//< operator compare two Node string
// return true if current data < to given node, false otherwise
bool NodeData::operator<(const NodeData& rhs) const {
    return data < rhs.data;
}

//> operator compare two Node string
// return true if current data > to given node, false otherwise
bool NodeData::operator>(const NodeData& rhs) const {
    return data > rhs.data;
}

//<= operator compare two Node string
// return true if current data <= to given node, false otherwise
bool NodeData::operator<=(const NodeData& rhs) const {
    return data <= rhs.data;
}

//>= operator compare two Node string
// return true if current data >= to given node, false otherwise
bool NodeData::operator>=(const NodeData& rhs) const {
    return data >= rhs.data;
}

// Set node data by reading the string file
// returns true if the data is set, false when bad data, i.e., is eof
bool NodeData::setData(istream& infile) {
    getline(infile, data);
    return !infile.eof();       // eof function is true when eof char is read
}

//Output operator return a node
ostream& operator<<(ostream& output, const NodeData& currentNode) {
    output << currentNode.data;
    return output;
}
