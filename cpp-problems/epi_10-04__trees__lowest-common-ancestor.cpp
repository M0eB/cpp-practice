



    //        4
    //    2        [8]
    //1      3   6       [9]
    //         5   [7]

#include <iostream>
using namespace std;
#include <cpp-data-structures\ds-tree.h>
#include <queue>


int lowest_common_ancestor( Node* root, int val1, int val2 )
{
    //finding nodes - log n

    queue<int> path1;
    queue<int> path2;

    //Find path to first node
    Node* currNode = root;
    path1.push( root->value() );
    while ( currNode->value( ) != val1 )
    {
        if ( val1 < currNode->value( ) )
            currNode = currNode->left( );
        else
            currNode = currNode->right( );

        path1.push( currNode->value( ) );
    }

    //Find path to second node
    currNode = root;
    path2.push( root->value( ) );
    while ( currNode->value( ) != val2 )
    {
        if ( val2 < currNode->value( ) )
            currNode = currNode->left( );
        else
            currNode = currNode->right( );

        path2.push( currNode->value( ) );
    }

    //Compare paths

    int lca = root->value( );
    while ( path1.front() == path2.front() )
    {
        lca = path1.front();
        path1.pop();
        path2.pop();
    }

    return lca;
}





int main()
//int lowest_common_ancestor
{
    BTree* tree = new BTree( );
    tree->AddNode( 4 );
    tree->AddNode( 2 );
    tree->AddNode( 1 );
    tree->AddNode( 3 );
    tree->AddNode( 8 );
    tree->AddNode( 6 );
    tree->AddNode( 9 );
    tree->AddNode( 5 );
    tree->AddNode( 7 );

    int ancestor = lowest_common_ancestor( tree->Root( ), 7, 9 );

    return 0;
}
