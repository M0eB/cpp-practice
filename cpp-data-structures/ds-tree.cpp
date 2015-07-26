
#include <iostream>
using namespace std;

#include "ds-tree.h"


BTree::BTree() 
{}

BTree::~BTree() 
{}

void BTree::AddNode( int key )
{
    if( !root )
        root = new Node( key );
    else
        AddNode( key, root );

}

void BTree::AddNode( int val, Node* leaf )
{
    if( val <= leaf->value() )
    {
        if( leaf->left() == NULL )
        {
            Node* newNode = new Node( val );
            leaf->SetLeft( newNode );
        }
        else
            AddNode( val, leaf->left() );
    }
    else if( val > leaf->value() )
    {
        if( leaf->right() == NULL )
        {
            Node* newNode = new Node( val );
            leaf->SetRight( newNode );
        }
        else
            AddNode( val, leaf->right() );
    }
}

void BTree::FreeNode( Node* leaf )
{
    if( leaf != NULL )
    {
        FreeNode( leaf->left() );
        FreeNode( leaf->right() );
        delete leaf;
    }
}

