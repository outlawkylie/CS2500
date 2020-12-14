/********************************************************
File:
Programmer:
Purpose:
********************************************************/
#include "project3.h"

int main()
    {
    int arr[arrSZ][arrSZ] = { 0 };   /* create adjacency matrix */
    int r_arr[arrSZ][arrSZ] = { 0 }; /* create resudial matrix  */
    int max_flow = 0; /* set max flow to 0 */
    ofstream out(OUT); /* create output stream to file */


    out<<"Kylie Outlaw\nInput file:  "<<NET<<"\n\nInput:"<<endl;
    setup( NET, arr, out); /* get data from file */
    max_flow = FF(arr, r_arr); /* get max flow with ford-fulkerson implementation */

    /* output max flow network data to networkx.out */
    output(arr, r_arr, out); 
    out<<"Max flow in this network is "<<max_flow;
    }