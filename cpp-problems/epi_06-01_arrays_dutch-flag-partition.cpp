
#include <iostream>
using namespace std;

#include <vector>


/* The Dutch National Flag Problem :

    * Proposed by Dijstra (who was dutch)

    * Given balls of 3 colours arranged randomly in a line (array),
      arrange them such that all balls of the same colour are together
      and their collective colour groups are in the correct order (stable)

    * Suppose each of the possible elements could be classified into exactly 
      one of three categories (bottom, middle, and top).

    * The problem is then to produce an array such that all "bottom" elements 
      come before "middle" elements, which come before all "top" elements.

    * Useful for variants of the quicksort algorithm that must be robust to 
      repeated elements need a three-way partitioning function that groups 
      items less than a given key (red), equal to the key (white) and greater 
      than the key (blue).
*/

template<typename T>
void dutch_flag_partition( vector<T> &A, const int &pivot_index )
{
    T pivot = A[pivot_index];

    int smaller = 0;
    int equal = 0;
    int larger = A.size() - 1;

    while ( equal <= larger )
    {
        if ( A[equal] < pivot )
        {
            swap( A[smaller], A[equal] );
            smaller++;
            equal++;
        }
        else if( A[equal] == pivot )
        {
            equal++;
        }
        else
        {
            swap( A[equal], A[larger] );
            larger--;
        }
    }
}


void partition( int arr[], int length, int i )
{
    int pivot = arr[i];
    int iL = 0;
    int iR = length - 1;

    while ( iL < iR )
    {
        if ( arr[iL] >= pivot && arr[iR] <= pivot )
        {
            int temp = arr[iL];
            arr[iL] = arr[iR];
            arr[iR] = temp;
        }

        if ( arr[iL] <= pivot )
            iL++;

        if ( arr[iR] > pivot )
            iR--;
    }
}


int main()
{
    vector<int> input = { 1, 5, 6, 4, 4, 2 };

    dutch_flag_partition( input, 3 );

    for ( size_t i = 0; i < 6; i++ )
    {
        cout << input[i] << " ";
    }

    return 0;
}

