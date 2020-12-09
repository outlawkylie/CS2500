#include "project3.h"

void setup(string fil_name, int arr[][arrSZ])
    {
/* Define the name of vertices for networks 1 and 2 */
#if defined NETWORK1
    string NetworkVertices[] { "s", "v1", "v2", "v3", "v4", "t" };]
#else
    string NetworkVertices[] { "s", "a", "b", "c", "d", "e", "f", "t" };
#endif

    string src, dst, length;
    int len;
    bool inVerticesList = false;

    /* Set up a map to link vertice name (key) to adjacency matrix index (value) */
    map<string, int>map1;

    /* Add each pair of string and index value to the map */
    for (int i = 0; i < sizeof(NetworkVertices)/sizeof(NetworkVertices[0]); i++)
        {
        map1.insert(make_pair(NetworkVertices[i], i));
        }


    //map<string, int>::iterator it = map1.begin();
    //while (it != map1.end())
    //    {
    //    cout << it->first << " :: " << it->second << std::endl;
    //    it++;
    //    }

    /* Open the file for the chosen network and parse data */
    ifstream file(fil_name); //create file stream for network
    assert(file.is_open()); //if asserting, file did not open correctly

    while( !file.eof() ) //while not at end of file, process file data
        {
        getline( file, src, ',' );
        getline( file, dst, ',' );
        getline( file, length, '\n' );
        stringstream convert( length );
        convert >> len;

        /* Set adjacency matrix value to weight */
        arr[ (map1[ src ]) ][ (map1[ dst ]) ] = len;
        }

    return;
    }

void print(int arr[][arrSZ])
    {
    for(int i = 0; i < arrSZ; i++)
        {
        for(int j = 0; j < arrSZ; j++)
            {
            cout << arr[i][j] << " ";
            }
        cout << endl;
        }
    return;
    }