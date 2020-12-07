#pragma once
#ifndef PROJECT3_H
#define PROJECT3_H

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
char * getVertexList(string fil_name);


#endif