/*
Design a STRING class, which will have the initialization facility similar to array
class. Provide support for
• Assigning one object for another,
• Two string can be concatenated using + operator,
• Two strings can be compared using the relational operators.
*/

#include <bits/stdc++.h>
using namespace std;
#define __dline__ cout << "\n-----------------------------------------------------\n";

// user defined STRING class
class STRING
{
    char *str = NULL;
    int len = 0;

public:
    friend istream &operator>>(istream &, STRING &);
    // default constructor
    STRING(int len = 1024)
    {
        this->str = new char[len];
        this->len = 1024;
    }
    // constructor for creating instance via c style array
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
        free(this->str);
        this->str = new char[str_2.length()];
        this->len = str_2.length();
        int i;
        for (i = 0; str_2[i] != '\0'; i++)
        {
            this->str[i] = str_2[i];
        }
        this->str[i] = '\0';
    }
    // function to return length of string
    int length()
    {
        return this->len;
    }
    // overloading - operator
    auto operator=(STRING &str_2)
    {
        cout << "Assignment operator called!!!" << endl;
        free(this->str);
        this->str = new char[str_2.length() + 1];
        this->len = str_2.length();
        int i;
        for (i = 0; str_2[i] != '\0'; i++)
        {
            this->str[i] = str_2[i];
        }
        this->str[i] = '\0';
    }
    // overloading + operator
    auto operator+(STRING &str_2)
    {
        cout << "Concatenation of two strings" << endl;
        char *buffer = new char[this->length() + str_2.length()];
        int i, j;
        for (i = 0; this->str[i] != '\0'; i++)
        {
            buffer[i] = this->str[i];
        }
        for (j = 0; str_2[j] != '\0'; j++, i++)
        {
            buffer[i] = str_2[j];
        }
        buffer[i] = '\0';
        return new STRING((const char *)buffer);
    }
    // overloading == operator
    auto operator==(STRING &str_2)
    {
        cout << "== operator overloaded!!!" << endl;
        if (this->length() == str_2.length())
        {
            // int flag=0;
            // cout << "hhhh" << endl;
            for (int i = 0; i < this->length(); i++)
            {
                // cout << this->str[i] << " " << str_2[i] << endl;
                if ((int)this->str[i] != (int)str_2[i])
                    return false;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    // overloading != operator
    auto operator!=(STRING &str_2)
    {
        cout << "!= operator overloaded!!!" << endl;
        if (this->length() == str_2.length())
        {
            // int flag=0;
            // cout << "hhhh" << endl;
            for (int i = 0; i < this->length(); i++)
            {
                // cout << this->str[i] << " " << str_2[i] << endl;
                if ((int)this->str[i] != (int)str_2[i])
                    return true;
            }
            return false;
        }
        else
        {
            return true;
        }
    }
    // overloading > operator
    auto operator>(STRING &str_2)
    {
        cout << "> operator overloaded!!!" << endl;
        int i;
        for (i = 0; this->str[i] != '\0' && str_2[i] != '\0'; i++)
        {
            // cout << this->str[i] << " " << str_2[i] << endl;
            if ((int)this->str[i] == (int)str_2[i])
            {
                continue;
            }
            else if ((int)this->str[i] < (int)str_2[i])
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        if (this->str[i] != '\0')
            return true;
        else
            return false;
    }
    // overloading < operator
    auto operator<(STRING &str_2)
    {
        cout << "< operator overloaded!!!" << endl;
        int i;
        for (i = 0; this->str[i] != '\0' && str_2[i] != '\0'; i++)
        {
            // cout << this->str[i] << " " << str_2[i] << endl;
            if ((int)this->str[i] == (int)str_2[i])
            {
                continue;
            }
            else if ((int)this->str[i] < (int)str_2[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if (str_2[i] != '\0')
            return true;
        else
            return false;
    }
    // overloading >= operator
    auto operator>=(STRING &str_2)
    {
        cout << ">= operator overloaded!!!" << endl;
        int flag = 0;
        for (int i = 0; this->str[i] != '\0' && str_2[i] != '\0'; i++)
        {
            // cout << this->str[i] << " " << str_2[i] << endl;
            if ((int)this->str[i] == (int)str_2[i])
            {
                flag++;
            }
            else if ((int)this->str[i] < (int)str_2[i])
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        if (flag == str_2.length())
            return true;
        else
            return false;
    }
    // overloading <= operator
    auto operator<=(STRING &str_2)
    {
        cout << "<= operator overloaded!!!" << endl;
        int flag = 0;
        for (int i = 0; this->str[i] != '\0' && str_2[i] != '\0'; i++)
        {
            // cout << this->str[i] << " " << str_2[i] << endl;
            if ((int)this->str[i] == (int)str_2[i])
            {
                flag++;
            }
            else if ((int)this->str[i] > (int)str_2[i])
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        if (flag == this->length())
            return true;
        else
            return false;
    }
    // overloading the [] operator
    char operator[](int i)
    {
        return this->str[i];
    }
};
// overloading the stream extraction operator
istream &operator>>(istream &console, STRING &s)
{
    cout << "Stream extraction operator overloaded!!!" << endl;
    int i = 0;
    int in_len = 1024;
    char *str = (char *)malloc(in_len * sizeof(char));
    char ch;
    cin.get(ch);
    while (ch != '\n')
    {
        str[i] = ch;
        cin.get(ch);
        i++;
        if (i >= in_len)
        {
            str = (char *)realloc(str, in_len * 2);
            in_len *= 2;
        }
    }
    str[i] = '\0';
    str = (char *)realloc(str, i + 1);
    s.str = str;
    return console;
}
// overloading the stream insertion operator
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
    STRING s("hello guys!!!"); // const char* initialisation
    cout << s;
    __dline__;
    STRING s2 = s; // copy constructor
    cout << s2;
    __dline__;
    STRING s3;
    s3 = s; // assignment operator initialisation
    cout << s3;
    __dline__;
    STRING s4;
    cin >> s4;
    cout << s4;
    __dline__;
    STRING str1("rohitafaf"), str2("sadhuafa"), *str3;
    str3 = str1 + str2; // string concatenation
    cout << *str3;
    __dline__;
    cout << "relational operators start here:" << endl;
    {
        STRING ss1("roh"), ss2("rohit");
        if ((ss1 == ss2) == true) // == operator overloaded
        {
            cout << "ss1 is same as ss2" << endl;
        }
        else
        {
            cout << "ss1 and ss2 are different" << endl;
        }
        __dline__;
        if ((ss1 != ss2) == true) // != operator overloaded
        {
            cout << "ss1 and ss2 are different" << endl;
        }
        else
        {
            cout << "ss1 is same as ss2" << endl;
        }
        __dline__;
        if ((ss1 > ss2) == true) // > operator overloaded
        {
            cout << "ss1 is greater than ss2" << endl;
        }
        else
        {
            cout << "ss1 is not greater than ss2" << endl;
        }
        __dline__;
        if ((ss1 < ss2) == true) // < operator overloaded
        {
            cout << "ss1 is smaller than ss2" << endl;
        }
        else
        {
            cout << "ss1 is not smaller than ss2" << endl;
        }
        __dline__;
        if ((ss1 >= ss2) == true) // >= operator overloaded
        {
            cout << "ss1 is greater than or equal to ss2" << endl;
        }
        else
        {
            cout << "ss1 is smaller than ss2" << endl;
        }
        __dline__;
        if ((ss1 <= ss2) == true) // <= operator overloaded
        {
            cout << "ss1 is smaller than or equal to ss2" << endl;
        }
        else
        {
            cout << "ss1 is greater than ss2" << endl;
        }
        __dline__;
    }
    return 0;
}