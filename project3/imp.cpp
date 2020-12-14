/********************************************************
File: imp.cpp
Programmer: Kylie Outlaw
Purpose: Serves as mplementation of functions
declared in project3.h
********************************************************/
#include "project3.h"

#if defined NETWORK1
string NetworkVertices[] { "s", "v1", "v2", "v3", "v4", "t" }; 
#else
string NetworkVertices[] { "s", "a", "b", "c", "d", "e", "f", "t" };
#endif

/********************************************************
Pre: fil_name must be valid
Post: arr is filled with valid data from fil_name and 
the vertices&edges are output to networkx.out
********************************************************/
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
        out<<src<<" "<<dst<<" "<<len<<endl;
        /* Set adjacency matrix value to weight */
        arr[ (map1[ src ]) ][ (map1[ dst ]) ] = len;
        }

    return;
    } /* setup() */

/********************************************************
Pre: arr[] is filled with valid data
Post: r_arr[] contains the residual paths for max flow &
returns the total max flow of the network
********************************************************/
int FF(int arr[][arrSZ], int r_arr[][arrSZ])
    {
    int path[arrSZ] = { 0 }; /* store the path */
    int max_flow = 0; /* max flow */
    int flow = 9999999; /* set total flow to "infinity" */
    int u; /* temp variable */

    copy(arr, r_arr); /* copy adjacency matrix to residual */

    /* keep running dijkastra() until the sink has been touched */
    while(djikstra(r_arr, path))
        {
        flow = 99999999; /* set up flow to be infinity */
        /* for each vertice in the path, update the flow 
        to be the lowest of the current & residual path */
        for(int i = arrSZ - 1; i != 0; i = path[i])
            {
            u = path[i];
            if( flow > r_arr[u][i]) { flow = r_arr[u][i]; }
            }

        /* for each edge in the path, update the residual array */
        for(int i = arrSZ - 1; i != 0; i = path[i])
            {
            u = path[i];
            r_arr[i][u]+=flow;
            r_arr[u][i]-=flow;
            }

        /* update the max flow to include the new path's flow */
        max_flow += flow;
        }

    return max_flow;
    } /* FF() */

/********************************************************
Pre: r_arr is filled with valid residual path data
Post: returns T/F if the sink has been touched yet
********************************************************/
bool djikstra(int r_arr[][arrSZ], int path[])
    {
    bool touched[arrSZ] = {false};

    queue <int> pq; /* create priority queue */
    pq.push(0); /* push src to pq*/
    touched[0] = true; /* start with src */
    path[0] = -1; 

    while(!pq.empty())
        {
        int u = pq.front(); //set u to the idx of vertice
        pq.pop(); //pop the current vertice

        /* for each vertice in the graph, if there is an edge
        from the current vertice u and it hasn't been touched yet,
        push that onto the priority queue and add it to the path */
        for(int i = 0; i < arrSZ; i++)
            {
            if(touched[i] == false && r_arr[u][i] > 0)
                {
                pq.push(i);
                path[i] = u;
                touched[i] = true;
                }
            }
        }
        return (touched[arrSZ-1]==true);
    } /* dijkstra() */

/********************************************************
Pre: arr is filled with valid data
Post: prints arr to the console
********************************************************/
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
    } /* print */

/********************************************************
Pre: arr, r_arr have valid data with out to a valid file
Post: outputs the flow in proper format to networkx.out
********************************************************/
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
                out<< arr[i][j]-r_arr[i][j] << "/" << arr[i][j] << "\n";
                }
            }
        }
    return;
    } /* output() */

/********************************************************
Pre: src is filled with valid data
Post: copies data from src array to dst array
********************************************************/
void copy(int src[][arrSZ], int dst[][arrSZ])
    {
    for(int i = 0; i < arrSZ; i++)
        {
        for(int j = 0; j < arrSZ; j++)
            {
            dst[i][j] = src[i][j];
            }
        }
    } /* copy() */