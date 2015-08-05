// 1234 -> 1,234
// 1234567 -> 1,234,567
// 100 -> 100

#include <iostream>
#include <string>
using namespace std;

std::string formatNumber( int number )
{
    std::string result;
    int nDigits = 0;
    int digit;

    while ( number > 0 )
    {
        digit = number % 10;
        result = (char)( digit + '0' ) + result;
        nDigits++;

        if ( nDigits == 3 && number >= 10 )
        {
            result = ',' + result;
            nDigits = 0;
        }

        number = number / 10;
    }

    return result;
}

//int main()
int format_number_main( )
{
    std::string result = formatNumber( 10000 );

    cout << result << endl;

    return 0;
}