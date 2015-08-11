/********************************************************************

Problem :

    Given a sentence strings, reverse the words in the sentence.
    eg. - "the sky is blue" --> "blue is sky the"
    eg. - "Hello, how are you" --> "you are how Hello,"

*********************************************************************/

#include <iostream>
using namespace std;

#include <string>
#include <sstream>

string reverse_sentence( string input )
{
    stringstream reverse;

    auto wordStart = input.begin();
    for ( auto it = input.begin(); it != input.end(); it++ )
    {
        if ( *it == ' ' )
        {
            reverse << " " << string( wordStart, it - 1 ) << reverse.str();
            wordStart = it++;
        }
        else if ( it == input.end() )
        {
            reverse << string( wordStart, it );
        }
    }

    return reverse.str();
}

string reverse( string input )
{
    string reverse;

    auto wordStart = input.begin();
    
    for ( auto it = input.begin(); it != input.end(); it++ )
    {
        if ( *it == ' ' )
        {
            reverse = string( wordStart, it - 1 ) + " " + reverse;
            wordStart = it + 1;
        }
        else if ( it == input.end() )
        {
            reverse = string( wordStart, it );
        }
    }

    return reverse;
}



//int main()
int rever_sentence_main()
{
    string input;
    getline( cin, input );

    cout << reverse( input ) << endl;
    //cout << reverse_sentence( input ) << endl;

    return 0;
}





















