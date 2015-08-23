/********************************************************************

    Given an array of n integers where n > 1, nums, return an array 
    output such that output[i] is equal to the product of all the 
    elements of nums except nums[i].
    
    For example, given[1, 2, 3, 4], return[24, 12, 8, 6].


    Follow up :
    Solve it without division and in O( n ).

    Follow up :
    Could you solve it with constant space complexity ? 
    ( Note : The output array does not count as extra space for 
      the purpose of space complexity analysis. )

*********************************************************************/

#include <iostream>
using namespace std;

#include <vector>

vector<int> product_except_self( vector<int>& nums )
{
    vector<int> output;

    int zeros   = 0;
    int product = 1;

    for ( auto it = nums.begin( ); it != nums.end( ); it++ )
    {
        if ( *it != 0 )
            product *= *it;
        else
            zeros++;
    }

    for ( auto it = nums.begin( ); it != nums.end( ); it++ )
    {
        if ( zeros > 1 || ( *it != 0 && zeros == 1 ) )
            output.push_back( 0 );
        else if ( *it == 0 )
            output.push_back( product );
        else
            output.push_back( product / *it );
    }

    return output;
}


//int main()
int product_except_self()
{
    vector<int> nums = { 1, 2, 3, 4 };
    vector<int> result = product_except_self( nums );

    for ( auto i : result )
        cout << i << " ";

    return 0;
}

