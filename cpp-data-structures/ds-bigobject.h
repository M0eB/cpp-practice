
#include <iostream>
using namespace std;


/* Dummy object for demonstration purposes. */

class bigobject
{
public:
    bigobject( string string1 ) : m_string( string1 ){}
    bigobject( int num, string string ) : m_num( num ), m_string( string ){}
    int GetNum() { return m_num; }
    string GetString() { return m_string; }
    ~bigobject(){}
private:
    bigobject();   //disable default constructor
    int    m_num;
    string m_string;
};


class compare_bigobject
{
public:
    bool operator()( bigobject obj1, bigobject obj2 )
    {
        if ( obj1.GetNum() < obj2.GetNum() )
            return true;
        else
            return false;
    }
};
