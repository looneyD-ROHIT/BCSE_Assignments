/*Write a function to find the product of two numbers. Call it number of times. 
Make the functions inline. [check the time of execution and size of object code]*/

#include "C:\Users\rohit\Desktop\shorthands\cpp\headers_1.h"
// #include<bits/stdc++.h>
// using namespace std;
// using namespace std::chrono;

// #define __dline__ cout << "\n-------------------------------------------------\n"
// #define _clr_ system("cls");
#define N 1e9

// #pragma inline product

__forceinline float product(float a, float b) // function to calculate product of two nos.
{
    return a * b;
}

int main(int argc, char *argv[])
{
    // system("cls");

    float a, b, p;
    cout << "Enter two nos. = ";
    cin >> a >> b;

    auto beg = high_resolution_clock::now();
    for (int i = 0; i < N; i++)
    {
        p = product(a, b);
    }
    auto end = high_resolution_clock::now();
    cout << "Product = " << p << endl;
    auto calc = duration_cast<milliseconds>(end - beg);
    cout << "Duration = " << calc.count() << " ms" << endl;
    __dline__;

    system("g++ -c main.cpp");
    FILE *f = fopen("main.o", "rb");
    fseek(f, 0L, 2);
    cout << "Size of object file = " << ftell(f) << " bytes" << endl;
    __dline__;

    return 0;
}