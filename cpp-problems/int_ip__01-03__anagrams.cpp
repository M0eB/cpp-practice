#include<iostream>
using namespace std;

#include <string>
#include <map>


bool is_anagram( string input1, string input2 )
{
    map<char, int> charMap;

    for ( auto it = input1.begin(); it != input1.end(); it++ )
    {
        if ( charMap.find( *it ) == charMap.end() )
            charMap.insert( std::pair<char, int>( *it, 1 ) );
        else
            charMap[*it]++;
    }

    for ( auto it = input2.begin(); it != input2.end(); it++ )
    {
        if ( charMap.find( *it ) == charMap.end() )
            return false;
        else if ( charMap[*it] == 1 )
            charMap.erase( *it );
        else
            charMap[*it]--;
    }
    
    if ( charMap.size() > 0 )
        return false;
    else
        return true;
}



//int main()
int is_anagram_main()
{
    string input1;
    string input2;

    getline( cin, input1 );
    getline( cin, input2 );

    cout << is_anagram( input1, input2 ) << endl;

    return 0;
}

