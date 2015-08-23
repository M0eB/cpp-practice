


//https://leetcode.com/problems/max-points-on-a-line/

/*
    Problem :
        Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/



/**
* Definition for a point.
* struct Point {
*     int x;
*     int y;
*     Point() : x(0), y(0) {}
*     Point(int a, int b) : x(a), y(b) {}
* };
*/

#include <iostream>
using namespace std;

#include <vector>

struct Point 
{
    int x;
    int y;
    Point( ) : x( 0 ), y( 0 ) {}
    Point( int a, int b ) : x( a ), y( b ) {}
};


int maxPoints( vector<Point>& points ) 
{


    return 0;
}


//int main()
int main_max_points_on_line()
{
    vector<Point> points;
    points.emplace_back( 1, 2 );
    points.emplace_back( 1, 2 );
    points.emplace_back( 1, 2 );
    points.emplace_back( 1, 2 );
    points.emplace_back( 1, 2 );

    maxPoints( points );

    return 0;
}


