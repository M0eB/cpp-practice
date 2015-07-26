#include <iostream>;
using namespace std;

#include "ds-tree.h"
#include <stack>


void in_order_recursive( Node* node )
{
    if( node == NULL )
        return;

    in_order_recursive( node->left() );
    cout << node->value() << endl;
    in_order_recursive( node->right() );
}

void in_order_non_recursive( Node* root )
{
    std::stack<Node*> NodeStack;

    while( true )
    {
        while( root )
        {
            NodeStack.push( root );
            root = root->left();
        }

        if( NodeStack.empty() )
            break;
        else
        {
            root = NodeStack.top();
            NodeStack.pop();
            cout << root->value() << endl;
            root = root->right();
        }
    }
}

//int main()
int in_order_main()
{
    //        4
    //     2     6
    //   1   3  5   7

    BTree* Tree = new BTree();
    Tree->AddNode( 4 );
    Tree->AddNode( 2 );
    Tree->AddNode( 6 );
    Tree->AddNode( 1 );
    Tree->AddNode( 3 );
    Tree->AddNode( 5 );
    Tree->AddNode( 7 );

    cout << "In-Order Recursive :" << endl;
    in_order_recursive( Tree->Root() );
    
    cout << endl;

    cout << "In-Order  Non-Recursive :" << endl;
    in_order_non_recursive( Tree->Root() );

    return 0;
}
