#include <iostream>
using namespace std;

#include <cpp-data-structures\ds-list.h>

#include <cassert>
#include <string>
//#include <cstdio>

/* Solution */

class Stack
{
public:

    Stack() : head( NULL ), m_max( 0 ), m_count( 0 )
    {
    }

    ~Stack()
    {}

    void push( int val )
    {
        Node<int>* newNode = new Node<int>( val );
    
        if ( !head )
            head = newNode;
        else
        {
            newNode->next = head;
            head = newNode;
        }

        if ( val > m_max )
        {
            m_max = val;
            m_count = 1;
        }
        else if ( val == m_max )
            m_count++;
    }

    int pop( )
    {
        int val = head->data;
        Node<int>* temp = head;
        head = head->next;
        free( temp );

        //Update max
        if ( val == m_max )
        {
            m_count == 1 ? findmax() : m_count--;
        }

        return val;
    }

    int max()
    {
        return m_max;
    }

private:

    void findmax()
    {
        Node<int>* curr = head;

        m_max = 0;
        while ( curr )
        {
            if ( curr->data > m_max )
            {
                m_max = curr->data;
                m_count = 1;
            }
            else if ( curr->data == m_max )
            {
                m_count++;
            }

            curr = curr->next;
        }
    }

    Node<int>* head;
    int m_max;
    int m_count;
};



int main( )
//int stack_with_max_main()
{
    std::string input;
    getline( cin, input );




    Stack test;
    test.push( 3 );
    test.push( 1 );
    test.push( 4 );
    test.push( 3 );
    assert( test.max() == 4 );
    test.push( 5 );
    test.push( 2 );
    test.push( 5 );
    assert( test.max( ) == 5 );
    test.pop();
    assert( test.max( ) == 5 );
    test.pop();
    test.pop();
    assert( test.max( ) == 4 );

    return 0;
}
