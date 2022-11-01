/*
Design a COMPLEX class, which will behave like normal integer with respect to
• addition,
• subtraction,
• accepting the value and
• Displaying the value.
*/

#include <bits/stdc++.h>
using namespace std;
#define __dline__ \
    cout << "\n------------------------------------------------------------\n";

// creating a new data type name COMPLEX
class COMPLEX
{
    float x;
    float y;

public:
    friend istream &operator>>(istream &, COMPLEX &);
    friend ostream &operator<<(ostream &, const COMPLEX *);
    COMPLEX(float x = 0, float y = 0) : x(x), y(y)
    {
        // cout << "Constructor called!!!" << endl;
    }
    ~COMPLEX()
    {
        cout << "Destructor called!!!" << endl;
    }
    auto operator=(const COMPLEX *c)
    {
        this->x = c->x;
        this->y = c->y;
    }

    // overloading of + operator to handle additions
    auto operator+(const COMPLEX &p)
    {
        COMPLEX *t = new COMPLEX;
        t->x = this->x + p.x;
        t->y = this->y + p.y;
        return t;
    }
    // overloading - operator to handle subtractions
    auto operator-(const COMPLEX &p)
    {
        COMPLEX *t = new COMPLEX;
        t->x = this->x - p.x;
        t->y = this->y - p.y;
        return t;
    }
};
// overloading the stream extraction operator to take input
istream &operator>>(istream &console, COMPLEX &c)
{
    __dline__
        string s;
    cout << "Enter your complex no. (spaces): ";
    getline(cin, s);
    float arr[2] = {0, 0};
    int i = 0;
    stringstream ss(s);
    while (!ss.eof())
    {
        ss >> arr[i];
        i++;
    }
    c.x = arr[0];
    c.y = arr[1];
    return console;
}
// overloading the stream insertion operator to display outputs
ostream &operator<<(ostream &console, const COMPLEX *c)
{
    // __dline__
    cout
        << "[ ";
    if (c->y >= 0)
        cout << c->x << " + " << c->y << "i";
    else
        cout << c->x << " - " << abs(c->y) << "i";
    cout << " ]";
    return console;
}

// driver code
int main()
{
    system("cls");
    int ch;
    float x, y;
    COMPLEX a, b;
    while (true)
    {
        cout << "OPTIONS:\n1. Addition\n2. Subtraction\n";
        cout << "Enter choice= ";
        cin >> ch;
        fflush(stdin);
        __dline__ switch (ch)
        {
        case 0:
            cout << "Exitting\n";
            exit(0);
            break;
        case 1:
            cout << "Addition\n";
            cout << "Enter the first complex no: ";
            fflush(stdin);
            cin >> a;
            cout << "Enter the second complex no: ";
            fflush(stdin);
            cin >> b;
            __dline__
                    cout
                << "The addition of these two nos. result in= " << (a + b) << endl;
            break;
        case 2:
            cout << "Subtraction\n";
            cout << "Enter the first complex no: ";
            fflush(stdin);
            cin >> a;
            cout << "Enter the second complex no: ";
            fflush(stdin);
            cin >> b;
            __dline__
                    cout
                << "The subtraction of these two nos. result in= " << (a - b) << endl;
            break;
        }
    }
    return 0;
}