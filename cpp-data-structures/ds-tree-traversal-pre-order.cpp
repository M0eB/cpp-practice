#include <iostream>;
using namespace std;

#include "ds-tree.h"
#include <stack>


void pre_order_recursive( Node* node )
{
    if( node == NULL )
        return;

    cout << node->value() << endl;
    pre_order_recursive( node->left() );
    pre_order_recursive( node->right() );
}

void pre_order_non_recursive( Node* root )
{

}

//int main()
int pre_order_main()
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

    cout << "Pre-Order Recursive :" << endl;
    pre_order_recursive( Tree->Root() );

    cout << endl;

    cout << "Pre-Order Non-Recursive :" << endl;
    pre_order_non_recursive( Tree->Root() );

    return 0;
}







