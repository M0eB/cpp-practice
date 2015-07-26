#include <iostream>
using namespace std;


class Node
{
public:
    Node() : nValue( -1 ), pLeft( NULL ), pRight( NULL )
    { }

    Node( int key ) : pLeft( NULL ), pRight( NULL )
    {
        nValue = key;
    }

    void SetValue( int value ) { nValue = value; };
    void SetLeft( Node* left ) { pLeft = left; };
    void SetRight( Node* right ) { pRight = right; };

    int value() { return nValue; };
    Node* left() { return pLeft; };
    Node* right() { return pRight; };

private:
    int nValue;
    Node* pLeft;
    Node* pRight;
};

class BTree
{
public:
    BTree();
    ~BTree();

    Node* Root() { return root; }
    void AddNode( int key );

private:
    Node* root;

    void AddNode( int val, Node* leaf );
    void FreeNode( Node* leaf );
};