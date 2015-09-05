


#include <iostream>
using namespace std;
#include <cstring>
#include <algorithm>

int longest_common_substring( string str1, string str2 )
{
    cout << str1.c_str() << " and " << str2.c_str() << endl;

    int mx[ 6 + 1 ][ 6 + 1 ] = { 0 };  //find way to init this properly

    for( int i = 1; i <= str1.length(); i++ )
    {
        for( int j = 1; j <= str2.length(); j++ )
        {
            if( str1[ i - 1 ] == str2[ j - 1 ] )
                mx[ i ][ j ] = 1 + mx[ i - 1 ][ j - 1 ];
            else
                mx[ i ][ j ] = 0;
        }
    }

    int max = 0, imax = 0, jmax = 0;
    for( int i = 1; i <= str1.length(); i++ )
    {
        for( int j = 1; j <= str2.length(); j++ )
        {
            if( mx[ i ][ j ] > max )
            {
                max = mx[ i ][ j ];
                imax = i;
                jmax = j;
            }
        }
    }

    string result;
    while( mx[ imax ][ jmax ] != 0 )
    {
        result = str1[ imax - 1 ] + result;
        imax--;
        jmax--;
    }

    cout << "Longest Common Subsequence : " << max    << endl;
    cout << "Longest Common Subsequence : " << result.c_str() << endl;


    return 0;
}

int longest_common_substring_recursive( string str1, string str2 )
{


    return 0;
}

//int main()
int longest_common_substr_main()
{
 
    string str1 = "abcabf";
    string str2 = "bcadcf";
    longest_common_substring( str1, str2 );
    cout << endl;

    string str3 = "abcdef";
    string str4 = "232454";
    longest_common_substring( str3, str4 );
    cout << endl;

    string str5 = "abcdef";
    string str6 = "xbcdex";
    longest_common_substring( str5, str6 );
    cout << endl;

    return 0;
}

