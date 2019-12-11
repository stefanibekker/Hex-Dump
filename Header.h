/*
 Stefani Bekker
 cssc0424
 CS530 Spring 2019
 Assignment 1, Binary and Hex Dump
 Header.h
*/

#ifndef Header_h
#define Header_h

# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <ctime>

using namespace std;

int main ( int argc, char *argv[] );
void hexDump ( char fileToDump[] );
void binaryDump (char fileToDump[]);


#endif /* Header_h */
