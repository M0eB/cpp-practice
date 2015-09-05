//#include <iostream>
//
//using namespace std;
//#include <list>
//
//#include <cpp-data-structures\ds-list.h>
//
//#include "./Linked_list_prototype.h"
//
//
//
//
//
///* EPI Solution */
//void AppendNode( shared_ptr<ListNode<int>> *node, shared_ptr<ListNode<int>> *tail ) 
//{
//    ( *tail )->next = *node;
//    *tail = *node;             // Updates tail.
//    *node = ( *node )->next;
//}
//
//shared_ptr<ListNode<int>> MergeTwoSortedLists( shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2 ) 
//{
//    // Creates a placeholder for the result.
//    shared_ptr<ListNode<int>> dummy_head( new ListNode<int> );
//    auto tail = dummy_head;
//
//    while ( L1 && L2 ) 
//    {
//        AppendNode( L1->data <= L2->data ? &L1 : &L2, &tail );
//    }
//
//    // Appends the remaining nodes of L1 or L2.
//    tail->next = L1 ? L1 : L2;
//    return dummy_head->next;
//}
//
//
//
//
///* Solution */
//Node<int>* MergeLists( Node<int>* headA, Node<int>* headB )
//{
//    Node<int>* headR = NULL;
//
//    if ( headA == NULL ) return headB;
//    if ( headB == NULL ) return headA;    
//    
//    if ( headA->data <= headB->data )
//    {
//        headR = headA;
//        headA = headA->next;
//    }
//    else
//    {
//        headR = headB;
//        headB = headB->next;
//    }
//
//    Node<int>* temp = headR;
//
//    while ( headA || headB )
//    {
//        if ( ( headA && !headB ) || headA->data <= headB->data )
//        {
//            temp->next = headA;
//            headA = headA->next;
//        }
//        else if ( headB )
//        {
//            temp->next = headB;
//            headB = headB->next;
//        }
//
//        if ( !headR )
//            headR = temp;
//
//        temp = temp->next;
//    }
//
//    return headR;
//}
//
////int main()
//int merege_lists_main()
//{
//    LinkedList<int>* L1 = new LinkedList<int>();
//    L1->insertToTail( 5 );
//    L1->insertToTail( 6 );
//    L1->insertToTail( 8 );
//    L1->insertToTail( 11 );
//    L1->print();
//
//    LinkedList<int>* L2 = new LinkedList<int>( );
//    L2->insertToTail( 2 );
//    L2->insertToTail( 4 );
//    L2->insertToTail( 7 );
//    L2->print();
//
//    Node<int>* result = MergeLists( L1->head, L2->head );
//
//    while ( result )
//    {
//        cout << result->data << " ";
//        result = result->next;
//    }
//
//    return 0;
//}
//
//
//
//
