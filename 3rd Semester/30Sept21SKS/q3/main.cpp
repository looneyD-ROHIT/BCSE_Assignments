/*Write a function swap (a, b) to interchange the values of two variables. Do not 
use pointers.*/

#include "C:\Users\rohit\Desktop\shorthands\cpp\headers_1.h"
// #include<bits/stdc++.h>
// using namespace std;
// using namespace std::chrono;

// #define __dline__ cout << "\n-------------------------------------------------\n"
// #define _clr_ system("cls");

template <typename T, T>
void swap(T &a, T &b) // swapping using reference
{
    T temp = a;
    a = b;
    b = temp;
}

int main(int argc, char *argv[])
{
    system("cls");
    int a, b;
    cout << "Enter two integers = ";
    cin >> a >> b;
    swap(a, b);
    cout << "Swapped integers = " << a << " " << b << endl;
    __dline__;

    float c, d;
    cout << "Enter two floats = ";
    cin >> c >> d;
    swap(c, d);
    cout << "Swapped floats = " << c << " " << d << endl;
    __dline__;

    string s1, s2;
    cout << "Enter two strings = ";
    cin >> s1 >> s2;
    swap(s1, s2);
    cout << "Swapped strings = " << s1 << " " << s2 << endl;
    __dline__;

    return 0;
}