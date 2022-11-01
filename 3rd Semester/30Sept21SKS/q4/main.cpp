/*Write a function max (a, b) that will return the reference of larger value.
Store the returned information to x where x is a 
i) variable of type a or b,
ii) variable referring to type of a or b.
In both the cases modify x. Check also the values of a and b.*/

#include "C:\Users\rohit\Desktop\shorthands\cpp\headers_1.h"
// #include<bits/stdc++.h>
// using namespace std;
// using namespace std::chrono;

// #define __dline__ cout << "\n-------------------------------------------------\n"
// #define _clr_ system("cls");

int &max(int &a, int &b)
{
    return ((a > b) ? a : b);
}

int main(int argc, char *argv[])
{
    system("cls");
    int a, b;
    cout << "Enter two integers = ";
    cin >> a >> b;

    int m = max(a, b);
    cout << "Max from m = " << m << endl;
    cout << "Values of a = " << a << " b = " << b << endl;
    m = 0;
    cout << "Max from m = " << m << endl;
    cout << "Values of a = " << a << " b = " << b << endl;
    __dline__;

    int &mm = max(a, b);
    cout << "Max from mm = " << mm << endl;
    cout << "Values of a = " << a << " b = " << b << endl;
    mm = 0;
    cout << "Max from m = " << mm << endl;
    cout << "Values of a = " << a << " b = " << b << endl;
    __dline__;
    return 0;
}