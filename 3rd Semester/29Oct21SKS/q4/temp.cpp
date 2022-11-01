#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    virtual void f(int y)
    {
        cout << "a" << endl;
    }
};
class B : virtual public A
{
public:
    void f(int y)
    {
        cout << "b" << endl;
    }
    void f2(int z)
    {

        cout << "b2" << endl;
    }
};
class C : virtual public A
{
public:
    void f(int y)
    {
        cout << "c" << endl;
    }
    void f2(int z)
    {

        cout << "c2" << endl;
    }
};
class D : public B, public C
{
public:
    void f(int y)
    {
        cout << "d" << endl;
    }
};
int main()
{
    system("cls");
    // B objb;
    // A *ptr = &objb;
    // // ptr->A::f(69);
    // ptr->f2(69);
    // D d;
    // A *ptr = &d;
    // ptr->f(69);
    // char s[100];
    // cin.getline(s, 50);
    // cout << s;
    // const char *c = "rohit";
    // cout << c;
    // char *p = c;
    // c[0] = 'm';
    // cout << c;
    char ch;
    cin.get(ch);
    cout << ch;
    // cout << sizeof('') << endl;
    return 0;
}