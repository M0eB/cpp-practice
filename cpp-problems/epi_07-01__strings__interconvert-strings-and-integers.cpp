#include <iostream>
using namespace std;

#include <cassert>
#include <math.h>

/* Problem Statement : 

    Implement methods that take a string representing an integer and return 
    the correcsponding integer, and vice versa. Your code should handle negative
    integers. You cannot use library funcions like stoi (C++) or parseInt (java)

*/

/* EPI Solutions */

string IntToString( int x )
{
    string s;
    bool isNegative = false;

    if ( x < 0 )
    {
        x = -x;
        isNegative = true;
    }

    do
    {
        s += '0' + x % 10;
        x /= 10;
    } 
    while ( x );

    if ( isNegative )
        s += '-';

    reverse( s.begin(), s.end() );

    return s;
}

int StringToInt( const string& str )
{
    /* It is more efficient to go through in order rather than reverse */

    bool isNegative = str[0] == '-';

    int value = 0;

    for ( int i = ( isNegative ? 1 : 0 ); i < str.size( ); i++ )
    {
        int digit = str[i] - '0';
        value = value * 10 + digit;
    }

    return isNegative ? -value : value;
}


/* Solutions */

int strint_to_int( string str )
{
    /* Brute Force :( */

    int value = 0;
    int digit = 0;

    for ( auto it = str.rbegin( ); it != str.rend( ); it++ )
    {
        if ( *it == '-' )
        {
            value = -value;
            break;
        }
        else
            value += ( *it - 48 ) * pow( 10, digit );
        
        digit++;
    }

    return value;
}

string int_to_string( int value )
{
    string str;
    char val;
    bool isNegative = false;

    if ( value < 0 )
    {
        isNegative = true;
        value = -value;
    }

    while ( value > 0 )
    {
        val =  value % 10;
        val = (char)( val + 48 );
        str = val + str;
        value = value / 10;
    }

    if ( isNegative )
        str = "-" + str;

    return str;
}


//int main()
int convert_ints_and_strings_main()
{

    assert( StringToInt( "123" ) == 123 );
    assert( StringToInt( "-123" ) == -123 );

    assert( IntToString( 123 ) == "123" );
    assert( IntToString( -123 ) == "-123" );

    assert( strint_to_int( "123" ) == 123 );
    assert( strint_to_int( "-123" ) == -123 );

    assert( int_to_string( 123 ) == "123" );
    assert( int_to_string( -123 ) == "-123" );

    return 0;
}











