#include <iostream>
using namespace std;

/********************************************************************

Problem :

    Fill in the code below to track URL hisotry for unique URLs
    entered by the user. Only the last 10 unique urls should be
    displayed ordered by most recent.

    Entered URL :           History List :         Display : 
    6 www.cnn.com            ( ignored )           www.cnn.com
    5 www.bbc.com            www.bbc.com           www.bbc.com
    4 www.google.com         ( ignored )           www.google.com
    3 www.cnn.com            www.cnn.com           www.bing.com
    2 www.bing.com           www.bing.com
    1 www.google.com         www.google.com
    
    Provided Template : 

    class urlhistory
    {
    public:
    void enterURL( const std::string& url );
    void displayURLS();
    };

    void urlhistory::enterURL( const std::string& url )
    {
    }

    void urlhistory::displayURLS( )
    {
    }

*********************************************************************/


class urlhistory
{
public:
    void enterURL( const std::string& url );
    void displayURLS();
};

void urlhistory::enterURL( const std::string& url )
{
}

void urlhistory::displayURLS( )
{
}

int main()
{


    return 0;
}
