/********************************************************************

    On a positive integer, you can perform any one of the 
    following 3 steps. 

    1.) Subtract 1 from it. ( n = n - 1 )
    2.) If its divisible by 2, divide by 2 
    3.) If its divisible by 3, divide by 3
    
    Now the question is, given a positive integer n, 
    find the minimum number of steps that takes n to 1

    eg: 
    1.) For n = 1 , output: 0
    2.) For n = 4 , output: 2  (4/2=2 /2=1)
    3.) For n = 7 , output: 3  (7-1=6 /3=2 /2=1)

    /// Thinking

    4
        -1 
            3  -1 
                    [2]
               %3
        %2
            [2]  -1
               %2
                    end

    2  -1
       %2
       %3

    3  -1 + 
       %2
       %3

lookup in n array



*********************************************************************/






#include <iostream>
using namespace std;

#include <algorithm>

class min_steps
{
public:
    min_steps( int n )
    {
        mem[ n + 1 ] = { -1 };
    }

    int min_steps_to_one( int n )
    {
        if( n == 0 || n == 1 )
            return 0;
        else if( n % 2 == 0 )
            mem[n] = 1 + std::min( n - 1, n / 2 );
        else if( n % 3 == 0 )
            mem[ n ] = 1 + std::min( n - 1, n / 3 );

        return mem[ n ];
    }

private:
    int mem[];

};





int min_steps_to_one( int n )
{



    return 0;
}

int main()
//int min_steps()
{

    return 0;
}
