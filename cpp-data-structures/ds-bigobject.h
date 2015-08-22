
#include <iostream>
using namespace std;


/* Dummy object for demonstration purposes. */

class bigobject
{
public:
    bigobject( string string1 ) : m_string( string1 ){}
    bigobject( int num, string string ) : m_num( num ), m_string( string ){}
    ~bigobject(){}
private:
    bigobject();   //disable default constructor
    int    m_num;
    string m_string;
};

