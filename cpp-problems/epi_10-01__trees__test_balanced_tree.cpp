//
//#include <iostream>
//using namespace std;
//
//#include <math.h>
//#include <cpp-data-structures\ds-tree.h>
//
//
//
//
//int get_tree_height( Node* root )
//{
//    int height = 0;
//
//    if ( root != NULL )
//    {
//        height += get_tree_height( root->left() );
//        height += get_tree_height( root->right() );
//        height++;
//    }
//
//    return height;
//}
//
//bool test_balanced_tree( Node* root )
//{
//    int height_diff = get_tree_height( root->left( ) ) - get_tree_height( root->right( ) );
//
//    if ( abs( height_diff ) > 1 )
//        return false;
//    else
//        return true;
//}
//
//
////int main()
//int test_balanced_tree_main()
//{
//    BTree* tree = new BTree();
//    tree->AddNode( 4 );
//    tree->AddNode( 6 );
//    tree->AddNode( 5 );
//    tree->AddNode( 7 );
//    tree->AddNode( 2 );
//    tree->AddNode( 1 );
//    tree->AddNode( 3 );
//    tree->AddNode( 8 );
//
//    bool balanced = test_balanced_tree( tree->Root() );
//
//    balanced ? cout << "Tree is balanced" 
//             : cout << "Tree is not balanced";
//
//    return 0;
//}
