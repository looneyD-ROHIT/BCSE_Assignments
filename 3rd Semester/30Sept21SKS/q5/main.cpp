/*Write a function that will have income and tax rate as arguments and will return 
tax amount. In case tax rate is not provided it will be automatically taken as 10%.
Call it with and without tax rate.*/

#include "C:\Users\rohit\Desktop\shorthands\cpp\headers_1.h"
// #include<bits/stdc++.h>
// using namespace std;
// using namespace std::chrono;

// #define __dline__ cout << "\n-------------------------------------------------\n"
// #define _clr_ system("cls");

auto calc_tax(float &income, float rate = 10.0)
{
    return (rate * income / 100);
}

int main(int argc, char *argv[])
{
    _clr_;
    float income, rate;
    cout << "Enter income = ";
    cin >> income;
    cout << "Enter rate = ";
    cin >> rate;
    cout << "Tax to be paid = " << calc_tax(income, rate);
    __dline__;
    cout << "Tax to be paid (without passing actual parameter) = " << calc_tax(income);
    __dline__;

    return 0;
}
