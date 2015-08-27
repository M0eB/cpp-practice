//
//
//
//
//#include <iostream>
//using namespace std;
//
//#include <vector>
//#include <math.h>
//
//bool containsNearbyAlmostDuplicate( vector<int>& nums, int k, int t )
//{
//    for ( int i = 0; i < nums.size( ); i++ )
//    {
//        for ( int j = i + 1; j < nums.size( ); j++ )
//        {
//            if ( ( j - i <= k ) && ( abs( nums[j] - nums[i] ) <= t ) )
//                return true;
//        }
//    }
//}
//
//#include <set>
//
//bool containsNearbyAlmostDuplicate( vector<int>& nums, int k, int t ) 
//{
//    set<int> window; // set is ordered automatically 
//
//    for ( int i = 0; i < nums.size( ); i++ ) 
//    {
//        if ( i > k ) 
//            window.erase( nums[i - k - 1] );       // keep the set contains nums i j at most k
//                                                            // -t <= x - nums[i] <= t;
//        auto pos = window.lower_bound( nums[i] - t );       // x >= nums[i] - t
//        if ( pos != window.end( ) && *pos - nums[i] <= t )  // x <= nums[i] + t
//            return true;
//
//        window.insert( nums[i] );
//    }
//
//    return false;
//}
//
//
//
////int main()
//int contains_duplicate_3()
//{
//
//
//
//    return 0;
//}


