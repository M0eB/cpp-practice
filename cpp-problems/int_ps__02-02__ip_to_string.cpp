#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string ipToString( unsigned int ipV4 )
{
    // parse a binary IP value and format as a dotted-decimal string

    int vals[4] = { 0 };

    vals[0] = ipV4 & 0xFF;
    vals[1] = ( ipV4 >>  8 ) & 0xFF;
    vals[2] = ( ipV4 >> 16 ) & 0xFF;
    vals[3] = ( ipV4 >> 24 ) & 0xFF;

    std::stringstream result;

    result << vals[3] << "." << vals[2] << "." << vals[1] << "." << vals[0] << endl;

    return result.str( );
}

//int main( )
int ip_to_string_main()
{
    cout << ipToString( 2130706433 ) << "\n"; // "127.0.0.1"
    cout << ipToString( 3232235521 ) << "\n"; // "192.168.0.1"

    return 0;
}

