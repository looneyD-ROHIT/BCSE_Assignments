/*Write a function void f(int) that prints “inside f(int)”. Call the function with
actual argument of type:
i) int,
ii) char,
iii) float and
iv) double.
Add one more function f(float) that prints “inside f(float)”. Repeat the calls again
and observe the outcomes.*/

#include "C:\Users\rohit\Desktop\shorthands\cpp\headers_1.h"
// #include<bits/stdc++.h>
// using namespace std;
// using namespace std::chrono;

// #define __dline__ cout << "\n-------------------------------------------------\n"
// #define _clr_ system("cls");

// void f(int x)
// {
//     cout << "inside f(int)" << endl;
// }

void f(float x)
{
    cout << "inside f(float)" << endl;
}

int main(int argc, char *argv[])
{
    _clr_;
    int a = 5;
    char b = 'B';
    float c = 10.1;
    double d = 15.15;
    f(a);
    f(b);
    f(c);
    f(d);
    return 0;
}
