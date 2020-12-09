#pragma once
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
using namespace std;

/********************************************************
Variables & Constants
********************************************************/
# if defined NETWORK1
const int arrSZ = 6;
const string NET = "network1.txt";
const string OUT = "network1.out";

# else
const int arrSZ = 8;
const string NET = "network2.txt";
const string OUT = "network2.out";
#endif

/********************************************************
Processes
********************************************************/
void setup(string fil_name, int arr[][arrSZ], ofstream & out);
void print(int arr[][arrSZ]);
void output(int arr[][arrSZ], ofstream & out);



#endif