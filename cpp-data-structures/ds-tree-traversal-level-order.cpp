#include <iostream>;
using namespace std;

#include "ds-tree.h"
#include <queue>


void level_order_traversal( Node* root )
{
    Node* temp;
    std::queue<Node*> queue;
    
    if( !root )
        return;
    
    queue.push( root );

    while( !queue.empty() )
    { 
        temp = queue.front();
        queue.pop();

        cout << temp->value() << endl;

        if( temp->left() )
            queue.push( temp->left() );
        if( temp->right() )
            queue.push( temp->right() );
    }
}



//int main()
int level_order_main()
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

    cout << "Level-Order Traversal :" << endl;
    level_order_traversal( Tree->Root() );

    return 0;
}







