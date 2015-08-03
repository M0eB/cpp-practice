
#include <iostream>

using namespace std;
using std::cout;
using std::endl;


template<class T>
class Node
{
public:
    T data;
    Node<T> * next;
    Node<T>( const T& d ) : data( d ), next( ) {}
    Node<T>( const Node<T>& copyNode ) : data( copyNode.data ), next( ) {}

private:
    Node<T>& operator=( const Node<T>& );
};

template<class T>
class LinkedList
{
public:

    Node<T> * head;
    Node<T> * tail;

    LinkedList( const LinkedList& LL );
    LinkedList& operator=( LinkedList byValList );
    LinkedList( ) : head( NULL ), tail( NULL ) {}
    LinkedList( Node<T> * newNode ) : head( newNode ), tail( newNode ) {}
    ~LinkedList( );

    void insertToTail( T val );
    void insertToHead( T val );
    void print( );
    void printBackwards( );
};

template<class T>
LinkedList<T>::LinkedList( const LinkedList<T>& LL ) : head( NULL ), tail( NULL )
{
    const Node<T> * curr = LL.head;

    if ( !head && curr )
    {
        head = new Node<T>( curr->data );
        tail = head;
        curr = curr->next;
    }

    while ( curr )
    {
        Node<T> * newNode = new Node<T>( curr->data );
        tail->next = newNode;
        tail = newNode;
        curr = curr->next;
    }
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=( LinkedList byValList )
{
    std::swap( head, byValList.head );
    return *this;
}

template<class T>
LinkedList<T>::~LinkedList( )
{
    Node<T> * curr = head;
    while ( head )
    {
        head = head->next;
        delete curr;
        curr = head;
    }
}

template<class T>
void LinkedList<T>::insertToTail( T val )
{
    Node<T> * newNode = new Node<T>( val );
    if ( tail == NULL )
    {
        newNode->next = tail;
        tail = newNode;
        head = newNode;
        return;
    }
    tail->next = newNode;
    tail = tail->next;
}




template<class T>
void LinkedList<T>::insertToHead( T val )
{
    Node<T> * newNode = new Node<T>( val );
    newNode->next = head;
    head = newNode;
    if ( head->next == NULL )
        tail = newNode;
}

template<class T>
void LinkedList<T>::print( )
{
    Node<T> * curr = head;
    while ( curr )
    {
        cout << curr->data << " --> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

template<class T>
void LinkedList<T>::printBackwards( )
{
    Node<T> * curr;
    LinkedList ReversedList( new Node<T>( head->data ) );
    curr = head->next;
    while ( curr )
    {
        ReversedList.insertToHead( curr->data );
        curr = curr->next;
    }

    curr = ReversedList.head;
    while ( curr )
    {
        cout << curr->data << " --> ";
        curr = curr->next;
    }
    cout << "NULL\n";
}
