Hello !

Welcome to my final project for CS2500 (Algorithms). 

If you would like to change which network is being tested, please open PROJECT3.h and edit LINE 13 to define which network is being used. The possibilities I set up for are
#define NETWORK1 
#define NETWORK2

If you would like to add a new network other than those given as part of the assignment, two other areas will need to be updated:

First, a new #if defined NETWORK# will need to be added in PROJECT3.h after LINE 41. Within this definition, the arrSZ must be defined as the number of vertices, the string NET must be defined as the input file name, and the string OUT must be defined as the output file name.

Second, the string of each vertice name as listed in the input file must be added to a new #if defined in IMP.cpp after LINE 14. This is listed as an array of the vertice names with the source first, then the other vertices in any order, followed by the sink last. 

Thank you for looking at this project and I hope you hve a great day!

Cheers,
Kylie