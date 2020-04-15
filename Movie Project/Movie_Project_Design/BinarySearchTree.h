
#ifndef BinarySearchTree_h
#define BinarySearchTree_h

class BInarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();
    BinarySearchTree& operator=(const BinarySearchTree&);
    
    bool operator==(const BinarySearchTree&) const;
    bool operator!=(const BinarySearchTree&) const;
    bool insert(NodeData*);
    bool retrieve(const Node& , NodeData*& ) const;
    int getHeight(const NodeData& data);
    void displaySideways() const;
    void arrayToBSTree(NodeData* arr[]);
    void arrayToBSTree(NodeData* arr[]);
    bool isEmpty();
    void makeEmpty();
    
private:
    struct Node
    {
        NodeData* data;
        Node* left;
        Node* right;
    }
    
    Node* root;
    
    void assignmentOperatorHelper(Node*& , Node* ) const;
    bool comparisonOperatorHelper(Node* , Node* ) const;
    bool insertHelper(Node*& , NodeData*& ) const;
    bool retrieveHelper(Node*& , const NodeData& , NodeData*& ) const;
    int getHeightHelper(const NodeData& , Node*& , int& );
    void arrayToBSTreeHelper(const Node* , NodeData* arr[], int, int);
    void makeEmptyHelper(Node*& );
    
};
#endif /* BinarySearchTree_h */
