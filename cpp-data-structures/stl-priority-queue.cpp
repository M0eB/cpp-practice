#include <iostream>
using namespace std;

#include <iomanip>
#include <queue>


void pq_simple_example()
{
    priority_queue<string> pq;

    pq.push( "the quick" );
    pq.push( "fox" );
    pq.push( "jumped over" );
    pq.push( "the lazy dog" );

    while( !pq.empty() )
    {
        cout << pq.top().c_str() << endl;
        pq.pop();
    }
}

struct Time
{
    int h;
    int m;
    int s;

    Time( int hour, int minute, int second ) : h( hour ), m( minute ), s( second )
    {}
};

class CompareTime
{
public:

    /* When a user-defined class overloads the function call 
       operator, operator(), it becomes a FunctionObject type. 
       Many standard algorithms, from std::sort to std::accumulate 
       accept objects of such types to customize behavior.
    */

    bool operator()( Time& t1, Time& t2 )
    {
        if( t1.h < t2.h ) 
            return true;
        else if( t1.h == t2.h && t1.m < t2.m ) 
            return true;
        else if( t1.h == t2.h && t1.m == t2.m && t1.s < t2.s ) 
            return true;
        else
            return false;
    }
};

void pq_custom_example()
{
    priority_queue<Time, vector<Time>, CompareTime> pq;

    pq.emplace( 3, 2, 40 );
    pq.emplace( 3, 2, 26 );
    pq.emplace( 5, 16, 13 );
    pq.emplace( 5, 14, 20 );

    while( !pq.empty() )
    {
        Time t2 = pq.top();
        cout << setw( 3 ) << t2.h << " " << setw( 3 ) << t2.m << " " << setw( 3 ) << t2.s << endl;
        pq.pop();
    }

}

int main()
//int stl_priority_queue()
{
    cout << "Simple Example :" << endl;
    pq_simple_example();

    cout << endl;

    cout << "Custom Example :" << endl;
    pq_custom_example();

    return 0;
}

