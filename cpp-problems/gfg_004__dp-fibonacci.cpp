/*
    Fibonacci series 1 1 2 3 5 8 13 21
    Given a number find the fibonacci series value for that number
    e.g 
        n = 3 -> 3
        n = 4 -> 5
        n = 5 -> 8
*/


#include <iostream>
using namespace std;


/* Recursive Solution :
                          f(5)
             f(4)           +            f(3)
    f(3)+f(2)    f(2)+f(1)      f(2)+f(1)    f(1)+f(0)
*/


int fib_recursive( int n )
{
    if( n == 0 || n == 1 )
        return 1;
    else
        return fib_recursive( n - 1 ) + fib_recursive( n - 2 );
}


/* Dynamic Programming Solution :
    a = 1 1 1 2 3 
    b = 1 1 2 3 5
    c = 1 2 3 5 8
*/

int fib_dynamic( int n )
{
    int a = 1;
    int b = 1;
    int c = 1;

    for( int i = 1; i < n; i++ )
    {
        a = b;
        b = c;
        c = a + b;
    }

    return c;
}


//int main()
int fibonacci()
{
    cout << fib_recursive( 3 ) << endl;
    cout << fib_recursive( 5 ) << endl;
    cout << fib_recursive( 8 ) << endl;

    cout << fib_dynamic( 3 ) << endl;
    cout << fib_dynamic( 5 ) << endl;
    cout << fib_dynamic( 8 ) << endl;

    return 0;
}