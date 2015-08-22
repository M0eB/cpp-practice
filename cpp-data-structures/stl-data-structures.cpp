/********************************************************************

STL Data Structures ( Containers ) 

           NAME    IMPLEMENTATION      LOOKUP       INSERTION
____________________________________________________________________

          array
         vector    dynamic array
           list    doubly-linked      constant       constant
   forward_list                
          stack    deque
          queue    deque
 priority_queue    deque
          deque      
            map     
            set             
       multiset
  unordered_map               
  unordered_set              

*********************************************************************/

#include <iostream>
using namespace std;

#include <vector>
#include <list>
#include <forward_list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

#include "ds-bigobject.h";




void stl_vector()
{
    /*
        - use contiguous storage locations for their elements
        - size can change dynamically 
        - insertion at the end is amortized constant time (push_back)
        - efficient in accessing elements (random access)
        - efficient in adding/removing at end
        - less efficient than (deques, lists, forward_lists) if 
          inserting/removing at other positions (new copy)
    */

    vector<int> foo;
    vector<int> baz;

    // INSERT =================================================================

    foo.push_back( 1 );            //  1
    foo.push_back( 2 );            //  1  2
    foo.push_back( 3 );            //  1  2  3
    
    auto it1 = foo.begin();        // [1] 2  3

    foo.insert( it1, 4 );          //  4  1  2  3       - iterator lost
    
    // ACCESS =================================================================

    int val;

    val = foo[ 2 ];                //  4  1 [2] 3
    val = foo.at( 2 );             //  4  1 [2] 3
    val = foo.front();             // [4] 1  2  3
    val = foo.back();              //  4  1  2 [3]

    int* p = foo.data();           // [4] 1  2  3 - pointer to array

    // REMOVE =================================================================

    foo.pop_back();                //  4  1  2
    foo.pop_back();                //  4  1

    foo.erase( foo.begin() + 1 );  // 4         - remove range (first, last )
    foo.clear();                   //           - remove all

    // COPY ===================================================================

    foo.assign( 5, 99 );                   // 99  99  99  99  99
    auto it2 = foo.begin();
    baz.assign( it2 + 2, foo.end() - 1 );  // 99  99  99    - copy range

    vector<bigobject> bar;

    bar.emplace( bar.begin(), "obj1" );
    bar.emplace_back( "obj2" );

}

void stl_list()
{
    list<int> foo;

    foo.push_back( 1 );     // 1
    foo.push_back( 2 );     // 1 2
    foo.push_back( 3 );     // 1 2 3
    foo.push_front( 4 );    // 4 1 2 3
    foo.push_front( 5 );    // 5 4 1 2 3
    foo.push_front( 6 );    // 6 5 4 1 2 3

    foo.pop_back();         // 6 5 4 1 2
    foo.pop_back();         // 6 5 4 1
    foo.pop_front();        // 5 4 1

    auto it = foo.begin();  // 5 4 1
    advance( it, 1 );       //   ^

    foo.erase( it );        // 5 1  (it lost)

    foo.size();             // =2
    foo.empty();
}

void forward_list()
{

}

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

void stl_queue()
{
    int  n;
    bool b;

    queue<int> foo;

    foo.push( 1 );      //  1
    foo.push( 2 );      //  1  2
    foo.push( 3 );      //  1  2  3
    
    n = foo.front();    // [1] 2  3
    n = foo.back();     //  1  2 [3]

    foo.pop();          //  2  3
    foo.pop();          //  3

    n = foo.size();     // =1
    b = foo.empty();    // false

    queue<int> bar;
    bar.push( 1 );      
    bar.push( 2 );
    bar.swap( foo );    // foo= 1  2 , bar = 3
    
    queue<bigobject> baz;
    baz.push( bigobject( 1, "yo" ) );
    baz.emplace( 1, "hey" );
}

void stl_priority_queue()
{
    int  n;
    bool b;

    priority_queue<int> foo;  //same as stack ? 

    foo.push( 2 );     //  2
    foo.push( 1 );     //  2  1
    foo.push( 3 );     //  3  2  1
    foo.push( 2 );     //  3  2  2  1
    foo.push( 4 );     //  4  3  2  2  1

    n = foo.top();     // 
    n = foo.top();

    foo.pop();
    foo.pop();
    
    n = foo.size();
    b = foo.empty();

    priority_queue<int> bar;
    bar.push( 1 );
    bar.swap( foo );

    priority_queue <bigobject> baz;
    //baz.emplace( 1, "yo" );        //error - no way to compare objects and arrange

    //refer to "stl-priority-queue" for better example with custom data structure

}

void stl_deque()
{


}

void stl_map()
{

}

void stl_unordered_map()
{


}

void stl_set()
{

}

void stl_unordered_set()
{

}


//int main()
int stl_data_structures()
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

