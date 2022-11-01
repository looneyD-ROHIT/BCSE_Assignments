/*
Write a macro to find the maximum of two numbers. Call the macro with 
i) two integers as the arguments and 
ii) two char * as the arguments.
Observe the outcomes.
*/

#include "C:\Users\rohit\Desktop\shorthands\cpp\headers_1.h"
// #include<bits/stdc++.h>
// using namespace std;
// using namespace std::chrono;

// #define __dline__ cout << "\n-------------------------------------------------\n"
// #define _clr_ system("cls");

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main(int argc, char *argv[])
{
    int a = 4, b = 5;
    // cout << "Enter two nos. = ";
    // cin >> a >> b;
    cout << "Maximum of the two = " << max(a, b) << endl; // using integers as arguments

    char s1[] = "Rohit", s2[] = "Sadhu";
    char t2[] = "Sadhu";
    char t1[] = "Rohit";
    cout << "Max = " << max(s1, s2) << endl; // using char* as arguments
    cout << "Max = " << max(t1, t2) << endl; // using char* as arguments
    return 0;
}