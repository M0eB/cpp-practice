// Given an array of integers. Write a function “countDuplicates” which will
// count the total number of distinct integers that occur more than once in
// the array. Write a main() function and demonstrate the correct behavior
// for the following sample arrays.
//
// {5,2,2,4} -->  1  (2 occurs more than once)
// {8,33,7,8,7,7} -->  2  (7, 8 occur more than once)
// {1,2,3} --> 0 (no duplicates)


#include <iostream>
#include <map>

using namespace std;

int getDuplicates( int input[], int size )
{
    std::map<int, int> counts;

    for ( int i = 0; i < size; i++ )
    {
        if ( counts.find( input[i] ) == counts.end( ) )
        {
            counts.insert( std::pair<int, int>( input[i], 1 ) );
        }
        else
            counts[input[i]]++;
    }

    int dups = 0;
    for ( auto it = counts.begin( ); it != counts.end( ); it++ )
    {
        if ( ( *it ).second >= 2 )
            dups++;
    }

    return dups;
}


//int main( )
int count_duplicates_main()
{
    //int input[] = { 5, 2, 2, 4 };
    int input[] = { 8, 33, 7, 1, 9, 2 };

    cout << getDuplicates( input, sizeof( input ) / sizeof( input[0] ) ) << endl;

    return 0;
}