#include "project3.h"

char * setup(string fil_name)
    {
    string src, dst, length;
    int len;
    bool inVerticesList = false;

    # if defined NETWORK1
        string NetworkVertices[] { "s", "v1", "v2", "v3", "v4", "t" };
        const int arrSZ = 6;
    # else
        string NetworkVertices[] { "s", "a", "b", "c", "d", "e", "f", "t" };
        const int arrSZ = 8;
    #endif

    map<string, int>map1;

    for (int i = 0; i < sizeof(NetworkVertices)/sizeof(NetworkVertices[0]); i++)
        {
        map1.insert(make_pair(NetworkVertices[i], i));
        }

    int arr[ arrSZ ][ arrSZ ] = { 0 };

    map<string, int>::iterator it = map1.begin();
    while (it != map1.end())
        {
        cout << it->first << " :: " << it->second << std::endl;
        it++;
        }

    ifstream file(fil_name); //create file stream for network
    assert(file.is_open()); //if asserting, file did not open correctly

    while( !file.eof() ) //while not at end of file, process file data
        {
        getline( file, src, ',' );
        getline( file, dst, ',' );
        getline( file, length, '\n' );
        stringstream convert( length );
        convert >> len;

        arr[ (map1[ src ]) ][ (map1[ dst ]) ] = len;
        }
    
    for( int i = 0; i < arrSZ; i++ )
        {
        for( int j = 0; j < arrSZ; j++ )
            {
            cout << arr[ i ][ j ] << " ";
            }
        cout << endl;
        }
        return NULL;
    }
