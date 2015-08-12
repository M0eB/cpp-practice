#include <iostream>
using namespace std;

/********************************************************************

Problem :

    Given a parent and child class, what is the expected output
    for the provided code.

    ( Code in main should create objects, destroy objects, 
      call methods, throw exceptions, etc. to test understanding )

*********************************************************************/

class parent
{
public:

    parent()
    {
        cout << "Parent Constructor" << endl;
    }

    ~parent()
    {
        cout << "Parent Destructor" << endl;
    }

    virtual void foo()
    {
        cout << "Parent foo" << endl;
    }

};

class child : parent
{
public:

    child()
    {
        cout << "Child Constructor" << endl;
    }

    ~child()
    {
        cout << "Child Destructor" << endl;
    }

    virtual void foo()
    {
        cout << "Child foo" << endl;
    }
};


//int main()
int output_order_main()
{
    try
    {
        child* p = new child();
        p->foo();

        //etc

        throw "Exception";

        delete p;
    }
    catch( exception e )
    {
    
    }

    return 0;
}






