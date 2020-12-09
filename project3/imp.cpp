#include "project3.h"

#if defined NETWORK1
string NetworkVertices[] { "s", "v1", "v2", "v3", "v4", "t" }; ]
#else
string NetworkVertices[] { "s", "a", "b", "c", "d", "e", "f", "t" };
#endif

void setup(string fil_name, int arr[][arrSZ], ofstream & out)
    {
/* Define the name of vertices for networks 1 and 2 */

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
        if( file.eof() )
            {
            return; //check for end of file
            }
        stringstream convert( length );
        convert >> len;
        out<<src<<" "<<dst<<" "<<len<<endl;
        /* Set adjacency matrix value to weight */
        arr[ (map1[ src ]) ][ (map1[ dst ]) ] = len;
        }

    return;
    }

int FF(int arr[][arrSZ], int r_arr[][arrSZ])
    {
    int path[arrSZ] = { 0 }; /* store the path */
    int max_flow = 0; /* max flow */
    int flow = 9999999; /* set total flow to infinity */
    int u; /* temp variable */

    copy(arr, r_arr); /* copy adjacency matrix to residual */

    while(djikstra(r_arr, path))
        {
        flow = 99999999;/* set up flow to be infinity */
        for(int i = arrSZ - 1; i != 0; i = path[i])
            {
            u = path[i];
            if( flow > r_arr[u][i]) { flow = r_arr[u][i]; }
            }


        for(int i = arrSZ - 1; i != 0; i = path[i])
            {
            u = path[i];
            r_arr[i][u]+=flow;
            r_arr[u][i]-=flow;
            }

        max_flow += flow;
        }

    return max_flow;
    }


bool djikstra(int r_arr[][arrSZ], int path[])
    {
    bool touched[arrSZ] = {false};

    queue <int> pq; /* create priority queue */
    pq.push(0);
    touched[0] = true;
    path[0] = -1;

    while(!pq.empty())
        {
        int u = pq.front();
        pq.pop();

        for(int v = 0; v < arrSZ; v++)
            {
            if(touched[v] == false && r_arr[u][v] > 0)
                {
                pq.push(v);
                path[v] = u;
                touched[v] = true;
                }
            }
        }
        return (touched[arrSZ-1]==true);
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

void output(int arr[][arrSZ], int r_arr[][arrSZ], ofstream& out)
    {
    out << "\n" << "Output: " << "\n";
    for(int i = 0; i < arrSZ; i++)
        {
        for(int j = 0; j < arrSZ; j++)
            {
            if(arr[i][j] != 0)
                {
                out << NetworkVertices[i] << " " << NetworkVertices[j] << " ";
                out<< r_arr[i][j] << "/" << arr[i][j] << "\n";
                }
            }
        }
    return;
    }


void copy(int src[][arrSZ], int dst[][arrSZ])
    {
    for(int i = 0; i < arrSZ; i++)
        {
        for(int j = 0; j < arrSZ; j++)
            {
            dst[i][j] = src[i][j];
            }
        }
    }