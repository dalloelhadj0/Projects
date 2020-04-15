

#ifndef NodeData_h
#define NodeData_h

#include <iostream>
#include <fstream>

using namespace std;

class NodeData
{
    friend &operator<<(ostream&, const NodeData&);
public:
    
    NodeData();
    ~NodeData();
    NodeData(const string&);
    NodeData(const NodeData&);//copy constructor
    NodeData& operator=(const NodeData&)
    
    bool setData(istream&);//checks if data is imported successflly
    bool operator==(const NodeData&) const;
    bool operator!=(const NodeData&) const;
    bool operator<(const NodeData&) const;
    bool operator>(const NodeData&) const;
    bool operator<=(const NodeData&) const;
    bool operator>=(const NodeData&) const;
private:
    string data;

};

#endif /* NodeData_h */
