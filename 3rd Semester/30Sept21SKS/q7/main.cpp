/*Define functions f(int, int) and f (char, int). Call the functions with arguments
of type (int, char), (char,char) and (float, float).*/

#include "C:\Users\rohit\Desktop\shorthands\cpp\headers_1.h"
// #include<bits/stdc++.h>
// using namespace std;
// using namespace std::chrono;

// #define __dline__ cout << "\n-------------------------------------------------\n"
// #define _clr_ system("cls");

void f(int a, int b)
{
    cout << "Hello I'm function 1" << endl;
    __dline__;
}
void f(char a, int b)
{
    cout << "Hello I'm function 2" << endl;
    __dline__;
}

int main(int argc, char *argv[])
{
    _clr_;
    int a = 5;
    char b = 'B', b2 = 'Z';
    float c = 5.5, d = 15.51;
    f(a, b);
    f(b, b2);
    // f(c, d); // --> ambiguous as promotion of float possible to both char and int
    return 0;
}
