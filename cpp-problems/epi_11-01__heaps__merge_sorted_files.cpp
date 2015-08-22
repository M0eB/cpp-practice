/********************************************************************

Problem :

    You are given 500 files, each containing stock trade information.
    Each trade is encoded by a line as : 1232111,AAPL,30,456.12
    <time in ms, stock, shares, price> ordered by time.
    You are to create a single file containing the trades files, 
    sorted in order of increaseing trade times.

    The individual file s are of the order of 5-100 MB, 
    the combined file will be of the order of 5 GB.
    
    Design an algorithm that takes a set of files containing stock 
    trades sorted by increasing trade times, and writes a single 
    file containing the trades appearing in the individual files 
    sorted in the same order. 
    
    The algorithm should use very little ram, 
    ideally of the order of a few KB.

*********************************************************************/

#include <iostream>
using namespace std;

#include <vector>
#include <queue>





class CompareStock
{
public:
    bool operator()( string stock1, string stock2 )
    {
        if( stock1 < stock2 )
            return true;
        else
            return false;
    }
};


class MergeFiles
{
public:
    void merge_files( vector<string> fileList )
    {
        files = fileList;
        lines = get_next_set();

        while( !lines.empty() )
        {
            pq.push( lines.front() );
            lines.pop();

            if( lines.empty() )
            { 
                //write items in pq to file
                pq.top();  //write to file;
                pq.pop();
                lines = get_next_set();
            }
        }
    }

private:
    int lineIndex;
    vector<string> files;
    queue<string> lines;
    priority_queue<string, vector<string>, CompareStock> pq;

    string get_file_line( string file, int index )
    {
        //open file
        //read line at index
        //if no file has less lines than index, return empty
        //else close file, return string at index
    
    }

    queue<string> get_next_set()
    {
        queue<string> set;

        for( auto it = files.begin(); it != files.end(); it++ )
        {
            string line = get_file_line( *it, lineIndex );

            if( line.empty() )
                files.erase( it );
            else
                set.push( line );
        }

        lineIndex++;

        return set;
    }
};

string getFileLine( string file )
{

    return "";
}




string sort_files()
{

    priority_queue<string, vector<string>, CompareStock> pq;

    vector<string> files;
    int lineIndex;

    for( auto it = files.begin(); it != files.end(); it++ )
    {
        pq.push( getFileLine( *it ) );
    }


}





int main()
{




    return 0;
}

