/********************************************************
File: project3.h
Programmer: Kylie Outlaw
Purpose: Stores includes for project, global vriables,
and function declaratins
********************************************************/
#ifndef PROJECT3_H
#define PROJECT3_H

/********************************************************
Define which network will be used in the following #define
********************************************************/
#define NETWORK2 //NETWORK1 or NETWORK2

/********************************************************
Includes
********************************************************/
#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>
#include <array>
#include <sstream>
#include <map>
#include <queue>
using namespace std;

/********************************************************
Variables & Constants
********************************************************/
# if defined NETWORK1
const int arrSZ = 6;
const string NET = "network1.txt";
const string OUT = "network1.out";

# endif
#if defined NETWORK2
const int arrSZ = 8;
const string NET = "network2.txt";
const string OUT = "network2.out";
#endif

/********************************************************
Processes
********************************************************/
void setup(string fil_name, int arr[][arrSZ], ofstream & out);
void print(int arr[][arrSZ]);
void output(int arr[][arrSZ], int r_arr[][arrSZ], ofstream & out);
int FF(int arr[][arrSZ], int r_arr[][arrSZ]);
void copy(int src[][arrSZ], int dst[][arrSZ]);
bool djikstra( int r_arr[][arrSZ], int path[]);
void get_total(int arr[][arrSZ], int & s, int & t);


#endif