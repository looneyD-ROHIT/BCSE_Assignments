/*
Design an ARRAY class with the following features:
a. Array object may be declared for a specific size and a value for initializing
all the elements. If this it is to be assumed as a 0.
b. An array object may be declared and initialized with another object.
c. An array object may be declared and initialized with another array (not the
object, standard array as in C language).
Let a and b are two objects:
i. a+b will add corresponding elements.
ii. a=b will do the assignment.
iii. a[I] will return the ith element of the object.
iv. a*5 or 5*a will multiply the element with 5.
*/

#include <bits/stdc++.h>
using namespace std;
#define __dline__ cout << "\n-----------------------------------------------------\n";

// implemented this code using template class with default typenames
template <typename T = int, int size = 1, T val = 0>
class ARRAY
{
    T *arr = new T[size];

public:
    typedef T default_type;
    int len = size;
    T default_val = val;
    // default constructor
    ARRAY()
    {
        cout << "Default Constructor called!!!" << endl;
        for (int i = 0; i < size; i++)
            arr[i] = val;
    }
    // destructor
    ~ARRAY()
    {
        cout << "Destructor called!!!" << endl;
        free(this->arr);
    }

    // copy constructor for object of same type
    template <typename T_, int size_, T val_>
    ARRAY(ARRAY<T_, size_, val_> &a)
    {
        if (this->length() != a.length())
        {
            cout << "Size was not matching so size equated!!!" << endl;
            free(this->arr);
            this->arr = new T_[size_];
            this->len = size_;
        }
        cout << "Copy Constructor called!!!" << endl;
        for (int i = 0; i < a.length(); i++)
            this->arr[i] = a[i];
    }
    // length function
    auto length()
    {
        return len;
    }
    // assignment operator overloading for array object of same type
    template <typename T_, int size_, T val_>
    auto operator=(ARRAY<T_, size_, val_> &a)
    {
        cout << "Assignment Operator called!!!" << endl;
        for (int i = 0; i < a.length(); i++)
            (*this).arr[i] = a[i];
    }
    // copy constructor overloading for C style array
    template <typename A, size_t N>
    ARRAY(const A (&a)[N])
    {
        cout << "Copy constructor called for C style array!!!" << endl;
        stringstream ss;
        ss << a[0];
        if (!(ss >> this->arr[0]))
        {
            cout << "Type mismatch!!!" << endl;
            return;
        }
        if (N != this->length())
        {
            free(this->arr);
            this->arr = new A[N];
            this->len = N;
        }
        for (int i = 0; i < N; i++)
            (*this).arr[i] = a[i];
    }
    // assignment operator overloading for C style array
    template <typename A, size_t N>
    auto operator=(const A (&a)[N])
    {
        cout << "Assignment Operator called for C style array!!!" << endl;
        stringstream ss;
        ss << a[0];
        if (!(ss >> this->arr[0]))
        {
            cout << "Type mismatch!!!" << endl;
            return;
        }
        if (N != this->length())
        {
            free(this->arr);
            this->arr = new A[N];
            this->len = N;
        }
        for (int i = 0; i < N; i++)
            (*this).arr[i] = a[i];
    }

    // + operator overloading
    template <typename T_, int size_, T val_>
    auto operator+(ARRAY<T_, size_, val_> &a)
    {
        cout << "+ Operator called!!!" << endl;
        for (int i = 0; i < a.length(); i++)
        {
            this->arr[i] = this->arr[i] + a[i];
        }
        return this;
    }
    // * operator overloading - 1
    auto operator*(int n)
    {
        cout << "* Operator1 called!!!" << endl;
        for (int i = 0; i < this->length(); i++)
        {
            this->arr[i] = this->arr[i] * n;
        }
        return this;
    }
    // [] operator overloading
    auto operator[](int i)
    {
        return (this->arr)[i];
    }
    // getting the address of index i
    auto value(int i)
    {
        return (this->arr + i);
    }
    // operator=(ARRAY &x, const ARRAY arr)
    // {
    //     x = arr;
    // }
    // ARRAY& operator ARRAY&(){
    //     return *this;
    // }
};

// * operator overloading - 2
template <typename T_, int size_, T_ val_>
auto operator*(int n, ARRAY<T_, size_, val_> &a)
{
    cout << "* Operator2 called!!!" << endl;
    for (int i = 0; i < a.length(); i++)
    {
        *(a.value(i)) = a[i] * n;
    }
    // return a;
}

// template function to overload stream insertion operator
template <typename T, int size, T val>
ostream &operator<<(ostream &console, ARRAY<T, size, val> &arr)
{
    console << "The array is as follows:\n";
    for (int i = 0; i < arr.length(); i++)
    {
        console << arr[i] << " ";
    }
    return console;
}

// driver code
int main()
{
    system("cls");
    // (a)
    __dline__
            // initialising the array:
            cout
        << "(a)" << endl;
    ARRAY<int, 5, 1>
        a;
    cout << a;
    cout << endl;
    // (b)
    __dline__
            // initialising the array with another object: (copy constructor)
            cout
        << "(b)" << endl;
    ARRAY<int, 5, 0>
        b = a;
    cout << b << endl;

    __dline__
            // initialising the array with another different size object: (copy constructor)
            cout
        << "(b)" << endl;
    ARRAY<int, 2, 1> c_ = a;
    cout << c_ << endl;

    // (c)
    __dline__
            // initialising the array with a C style array: (assignment operator)
            cout
        << "(c)" << endl;
    ARRAY<int, 3, 0>
        d;
    int b_arr[5] = {00, 01, 02, 03, 04};
    d = b_arr;
    cout << d << endl;

    __dline__
            // initialising the array with a C style array: (copy constructor)
            cout
        << "(c)" << endl;
    int int_arr[5] = {1, 2, 3, 4, 5};
    ARRAY<int, 3, 0>
        d_ = int_arr;
    cout << d_ << endl;

    // (i)
    __dline__
            // + operator overloading function call
            cout
        << "(i)" << endl;
    ARRAY<int, 6, 1> aa;
    ARRAY<int, 6, 2> bb;
    cout << *(aa + bb) << endl;

    // (ii)
    __dline__
            // initialising the array with another same object: (assignment operator)
            cout
        << "(ii)" << endl;
    ARRAY<int, 5, 0>
        c;
    c = a;
    cout << c << endl;

    // (iii)
    __dline__
            // overloading the [] operator
            cout
        << "(iii)" << endl;
    cout << d_[2] << "\t|\t" << d_[3] << endl;

    // (iv)
    __dline__
            // overloading the * operator
            cout
        << "(iv)" << endl;

    ARRAY<int, 6, 1> xx;
    cout << *(xx * 5) << endl;
    (5 * xx);
    cout << xx << endl;

    // __dline__
    //     // initialising the array with a C style array:
    //     int sec_arr[4] = {1, 2, 3, 4};
    // ARRAY d;

    return 0;
}