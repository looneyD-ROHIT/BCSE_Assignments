/*
Modify the STRING class so that assigning/initializing a string by another will not 
copy it physically but will keep a reference count, which will be incremented. 
Reference value 0 means the space can be released.
*/

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
#define __dline__ cout << "\n-----------------------------------------------------\n";

// modified class STRING
class STRING
{
    char *str = NULL;
    int len = 0;
    static int count;

public:
    friend istream &operator>>(istream &, STRING &);
    // constructor
    STRING(int len = 1024)
    {
        this->str = new char[len];
        this->len = 1024;
    }
    // destructor
    STRING(const char *ch_arr)
    {
        cout << "const char* constructor called!!!" << endl;
        int len = 0;
        for (; ch_arr[len] != '\0'; len++)
            ;
        this->str = new char[len + 1];
        int i;
        for (i = 0; i < len; i++)
        {
            this->str[i] = ch_arr[i];
        }
        this->str[i] = '\0';
        this->len = len;
    }
    // copy constructor
    STRING(STRING &str_2)
    {
        cout << "Copy constructor called!!!" << endl;
        this->str = &(str_2[0]);
        this->len = str_2.length();
        count++;
    }
    // destructor
    ~STRING()
    {
        cout << "Destructor called!!!" << endl;
    }
    // function to clear string
    auto clear()
    {
        cout << "Clear called!!!" << endl;
        delete[](this->str);
    }
    // overloading + operator to concatenate strings
    void operator=(STRING &str_2)
    {
        cout << "Assignment operator called!!!" << endl;
        this->str = &(str_2[0]);
        this->len = str_2.length();
        // *this = str_2;
        count++;
    }
    // function to keep ref count
    static int refcount()
    {
        return STRING::count;
    }
    // function to return length of string
    int length()
    {
        return this->len;
    }
    // overloading [] operator
    char &operator[](int i)
    {
        return this->str[i];
    }
    // char* operator &(int i){
    //     return (this->str + i);
    // }
};
int STRING::count = 0;
// overloading stream extraction operator
istream &operator>>(istream &console, STRING &s)
{
    cout << "Stream extraction operator overloaded!!!" << endl;
    int i = 0;
    char ch;
    console.get(ch);
    while (ch != '\n')
    {
        s.str[i] = ch;
        cin.get(ch);
        i++;
    }
    s.str[i] = '\0';
    return console;
}
// overloading stream insertion operator
ostream &operator<<(ostream &console, STRING &s)
{
    console << "The string is as follows:" << endl;
    int i = 0;
    while (s[i] != '\0')
    {
        cout << s[i];
        i++;
    }
    cout << endl;
    return console;
}
// driver code
int main()
{
    STRING str1("My name is Rohit Sadhu.");
    STRING str2 = str1;
    STRING str3;
    str3 = str1;
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << "Reference count= " << STRING::refcount() << endl;
    __dline__;
    // cout << "Enter new str1:";
    cin >> str1;
    cout << "new str1= " << str1 << endl;
    cout << "new str2= " << str2 << endl;
    cout << "new str3= " << str3 << endl;
    cout << "Reference count= " << STRING::refcount() << endl;
    if (STRING::refcount() == 0)
    {
        cout << "space can be freed as there is no reference" << endl;
        str1.clear();
    }
    else
    {
        cout << "space cannot be freed as there is one/more reference" << endl;
    }

    return 0;
}