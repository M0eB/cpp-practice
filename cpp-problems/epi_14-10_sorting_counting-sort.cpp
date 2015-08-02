#include <iostream>
using namespace std;

#include <vector>
#include <unordered_map>


/* Implement Counting Sort

    Problem : 
        You are given an array of objects. Each object has a field that is to be 
        treated as a key.Rearrange the elements of the array so that objects with 
        equal keys appear together. The order in which distinct keys appear is
        not important.

    Hint :
        Partition the array into subarrays which hold objects with equal keys.

    Discussion :
        Brute-Force is to sort the array, but this is inefficient as it does 
        more than required.
        Equal elements must be adjacent but do not have to be in order.
        Counting sort cannot be applied directly since we need to write objects, 
        not integers - two objects may have the same key, but other fields may
        be different.

*/


struct Person
{
    int age;
    string name;
};

void epi_group_by_age( vector<Person>* person_array )
{
    // Use two maps - one for count of each type, one for starting offset of each type
    // Take first item in offset map, use as index to pull from input array, lookup it's correct offset
    // Swap the item from the offset it was found with the offset it should be
    // Decremented count and remove offset if 0, otherwise increment offset and repeat

    //Get the size of each group
    unordered_map<int, int> age_to_count;
    for( const auto& p : *person_array )
    {
        ++age_to_count[ p.age ];
    }

    //Get the offsets of each group
    unordered_map<int, int> age_to_offset;
    int offset = 0;
    for( const auto& p : age_to_count )
    {
        age_to_offset[ p.first ] = offset;
        offset += p.second;
    }

    //Swap each item intp it's target subarray
    while( age_to_offset.size() )
    {
        auto from_offset = age_to_offset.begin();
        auto from_age = ( *person_array )[ from_offset->second ].age;
        auto to_offset = age_to_offset.find( from_age );

        // We swap the item we found to it's to a position in it's subarray

        swap( ( *person_array )[ from_offset->second ], 
              ( *person_array )[ to_offset->second ] );

        // Use age_to_count to see when we are finished with a particular age

        --age_to_count[ to_offset->first ];

        if( age_to_count[ to_offset->first ] > 0 )
        {
            ++to_offset->second;  //incrememnt to next position for this subbarray
        }
        else
        {
            age_to_offset.erase( to_offset );  //subarray complete
        }
    }

}


int main()
{
    vector<Person> people = { Person( { 20, "foo" } ), 
                              Person( { 10, "bar" } ), 
                              Person( { 20, "widget" } ), 
                              Person( { 20, "something" } ),
                              Person( { 10, "another" } ),
                              Person( { 30, "alpha" } ),
                              Person( { 30, "beta" } ),
                              Person( { 20, "omega" } ) };
    
    epi_group_by_age( &people );

    return 0;
}
