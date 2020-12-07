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
const string NET1 = "network1.txt";
const string NET2 = "network2.txt";

/********************************************************
Processes
********************************************************/
char * setup(string fil_name);


#endif