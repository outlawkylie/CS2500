// LCS.cpp : This file contains the 'main' function. Program execution begins and ends there.
/* Author: Kylie Outlaw on 10/20/2020.
The purpose of this program is to generate the number of characters in the LCS of two
strings. The program will also print out the LCS characters. In order to adjust the strings 
used in this program, please edit lines22 and 23 to adjust the strings, then lines 13 and 14
to match the length of strings s1 and s2 respectively.
I referenced geeksforgeeks.org for help in printing the LCS from the already-created LCSArray.
*/

#include <iostream>
#include <cstring>
#include <assert.h>
using namespace std;
#define rowlength    28
#define columnlength 29

void LCS(char s1[], char s2[]);

int main()
{
    //Setup strings to find LCS of: S1 and S2
    char s1[] = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";  //relating to rowlength
    char s2[] = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA"; //relating to columnlength

    //Output some UI formatting & info
    cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * "<<endl;
    cout<<"String 1 is: "<<s1<<endl;
    cout<<"String 2 is: "<<s2<<endl<<endl;

    //Find & Print the LCS of S1 and S2
    LCS(s1, s2);
}

void LCS(char s1[], char s2[])
    {
    //double check that x is rowlength and y is columnlength
    int x = (int)strlen(s1);
    int y = (int)strlen(s2);

    //double check that x is rowlength and y is columnlength
    //if you hit this assert, then update rowlength and columnlength to the proper numbers
    assert(x == rowlength);
    assert(y == columnlength);

    /* Setup LCS Array */
    int LCSArray[rowlength+1][columnlength+1];

    for (int i = 0; i <= x; i++) // go through every row 
        {
        for (int j = 0; j <= y; j++) // and column combination
            {
            if (i == 0 || j == 0) //check if in first column or row full of all 0s
                {
                LCSArray[i][j] = 0; //set the value to 0
                }
            else if (s1[i - 1] == s2[j - 1]) // check if the row/column is the same
                {
                //if they are the same, set the value in that spot
                //to be the previous (diagonal) value +1
                LCSArray[i][j] = LCSArray[i-1][j-1] + 1;
                }
            else //otherwise set it to the highest value from [i-1][j] or [i][j-1]
                {
                if(LCSArray[i-1][j] > LCSArray[i][j-1]){ LCSArray[i][j] = LCSArray[i-1][j]; }
                else {LCSArray[i][j] = LCSArray[i][j-1]; }
                }
            }
        }

    //figure out how many characters are in LCS
    int num_char = LCSArray[rowlength][columnlength];
   
    //set up character array for characters in LCS
    char* LCS;
    const int NUM_LCS = num_char+1; //find length of NTCA needed
    LCS = new char[NUM_LCS];
    LCS[num_char] = '\0';//set up NTCA terminating character

    //set up while loop counters 
    int i = x; 
    int j = y;

    while (i > 0 && j > 0) //loop until reaching either the 0th row or 0th column
        {
        if (s1[i-1] == s2[j-1]) //if row and column are same
            {
            LCS[num_char-1] = s1[i-1];
            i--; //check next row
            j--; //check next column
            num_char--; //set the next-to-last character value for LCS char array
            }
        else if (LCSArray[i - 1][j] > LCSArray[i][j - 1])
            {
            i--; //decrement the row if row side is larger *check next row
            }
        else{ j--; } //decrement the column if column side is larger *check next column
        }
    //output information to console
    cout<<"LCS has a length of "<<NUM_LCS-1<<"."<<endl;
    cout<<"The LCS is: ";
    for (int i = 0; i < NUM_LCS-1; i++)
        {
        cout<<LCS[i]<<" ";
        }
    cout<<".\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n\n";
    return;
    }