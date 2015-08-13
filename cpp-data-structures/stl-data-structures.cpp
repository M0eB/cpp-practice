/********************************************************************

STL Data Structures ( Containers ) 

           NAME    IMPLEMENTATION    LOOKUP    INSERTION
____________________________________________________________________

          array
         vector            
           list              
   forward_list
          stack             
          queue             
 priority_queue
          deque             
            map            
            set             
       multiset
  unordered_map               
  unordered_set              

*********************************************************************/

#include <iostream>
using namespace std;


class bigobject
{
public:
    bigobject( string string1 ) : m_string( string1 ){}
    bigobject( int num, string string ): m_num( num ), m_string( string ){}
    ~bigobject(){}
private:
    bigobject();   //disable default constructor
    int    m_num;
    string m_string;
};


#include <vector>
void stl_vector()
{


}

#include <list>
void stl_list()
{
    list<int> foo;

    foo.push_back( 1 );
    foo.push_back( 2 );
    foo.push_back( 3 );
    foo.push_front( 4 );
    foo.push_front( 5 );
    foo.push_front( 6 );

    foo.pop_back();
    foo.pop_back();
    foo.pop_front();

    auto it = foo.begin();
    advance( it, 1 );

    foo.erase( it );
    foo.erase( it );

    foo.size();
    foo.empty();

}

void forward_list()
{

}

#include <stack>
void stl_stack()
{
/*
    push    : insert element
    top     : access next element
    pop     : remove top element
    emplace : create object, passing constructor arguments
    size    : return size
    empty   : test if empty
    swap    : swap current stack contents with input stack contents 
*/

    stack<int> foo;

    foo.push( 1 );     // 1
    foo.push( 2 );     // 2,1
    foo.push( 3 );     // 3,2,1
    
    foo.top( );        // 3
    foo.top( );        // 3
    
    foo.pop( );        // 2,1
    foo.top( );        // 2
    foo.pop( );        // 1

    foo.emplace( 4 );  // 4,1
    foo.emplace( 5 );  // 5,4,1
    foo.size( );       // 3
    foo.empty( );      // false

    stack<int> bar;
    bar.push( 6 );
    bar.push( 7 );

    foo.swap( bar );   // foo = 7,6 , bar = 5,4,1

    stack<bigobject> baz;
    baz.emplace( "yo" );
    baz.emplace( 1, "one" );

    //baz.emplace();     //error- private default constructor
    //baz.emplace( 1 );  //error- invalid constructor arguement

}


#include <queue>
void stl_queue()
{

}

void stl_priority_queue()
{


}


#include <deque>
void stl_deque()
{


}


#include <map>
void stl_map()
{

}

#include <unordered_map>
void stl_unordered_map()
{


}

#include <set>
void stl_set()
{

}

#include <unordered_set>
void stl_unordered_set()
{

}


int main()
{
    stl_vector();
    stl_list();
    stl_stack();
    stl_queue();
    stl_deque();
    stl_map();
    stl_unordered_map();
    stl_set();
    stl_unordered_set();

    return 0;
}

