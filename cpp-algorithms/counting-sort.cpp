
#include <iostream>
using namespace std;

#include <vector>


/* COUNTING SORT :

    Description

    [DSA]
    * Not a comparison sort Algorithm
    * Gives O(n) complexity for sorting
    * Assumes that each of the elements is an integer in the range 1 to K
    * Basic idea is to determine for each input element X the number of elements less than X
    * This information is used to place directly into its correct position
    * EG - If 10 elements are less than X then X belongs int the 11th position
    * Requires two additional arrays :
        One for counting
        one for the result

    * Complexity :
        Time  : O(K) + O(n) + O(K) + O(n) = O(n) if K = O(n)
        Space : O(n) if K = O(n)


    [EPI]
    * Supposed you need to reorder the elements of a ery large array so that equal elements
      appear together EG. <b,a,c,b,d,a,b,d> to <a,a,b,b,b,c,d,d> or <d,d,c,a,a,b,b,b>
    * If the number of distinct integers is very small relative to the size of the array
      Then it is efficient to count the number of occurerences of each distinct integer 
      and write the appropriate number of ecah integer in sorted order, to the array

*/


vector<int> counting_sort( vector<int> input )
{
    int max = 0;

    //Find max to determins size of count array
    for( auto val : input )
    {
        if( max < val )
            max = val;
    }

    //Create count to hold number of elements =i
    vector<int> count( max + 1 );
    for( auto val : input )
    {
        count[ val ] = count[ val ] + 1;
    }

    //Update count to hold number of elements <i
    for( size_t i = 1; i < count.size(); i++ )
    {
        count[ i ] = count[ i ] + count[ i - 1 ];
    }

    vector<int> result( input.size() + 1 );
    for( auto val : input )
    {
        result[ count[ val ] ] = val;
        count[ val ] = count[ val ] - 1;
    }

    return result;
}


int NOT_main()
{

    vector<int> input = { 7, 1, 5, 2, 2 };

    vector<int> result = counting_sort( input );

    return 0;
}

