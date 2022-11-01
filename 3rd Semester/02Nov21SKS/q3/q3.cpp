#include <bits/stdc++.h>
using namespace std;

class employee
{
protected:
    int emp_id;
    string name;
    string designation;
    float basic_pay;

public:
    virtual void salary() = 0;
    virtual void showData() = 0;
    virtual ~employee()
    {
        cout << "~EMPLOYEE destructor!" << endl;
    }
};

class permanent : public employee
{
    float net_pay;

public:
    permanent(int id = 1000, string n = "NULL", string d = "NULL", float pay = 0)
    {
        emp_id = id;
        name = n;
        designation = d;
        basic_pay = pay;
        net_pay = basic_pay;
    }
    void salary()
    {
        net_pay = basic_pay * (1 + 0.3 + 0.8);
    }
    void showData()
    {
        cout << "ID: " << this->emp_id << endl;
        cout << "NAME: " << this->name << endl;
        cout << "DESIGNATION: " << this->designation << endl;
        cout << "NET SALARY: " << this->net_pay << endl;
        cout << "---------------------------------------------------------------\n";
    }
    ~permanent()
    {
        cout << "~PERMANENT destructor!" << endl;
    }
};
class contractual : public employee
{
    float net_pay;

public:
    contractual(int id = 1000, string n = "NULL", string d = "NULL", float pay = 0)
    {
        emp_id = id;
        name = n;
        designation = d;
        basic_pay = pay;
        net_pay = basic_pay;
    }
    void salary()
    {
        float temp;
        cout << "Enter your allowance= ";
        cin >> temp;
        net_pay = basic_pay + temp;
    }
    void showData()
    {
        cout << "ID: " << this->emp_id << endl;
        cout << "NAME: " << this->name << endl;
        cout << "DESIGNATION: " << this->designation << endl;
        cout << "NET SALARY: " << this->net_pay << endl;
        cout << "---------------------------------------------------------------\n";
    }
    ~contractual()
    {
        cout << "~CONTRACTUAL destructor!" << endl;
    }
};
int main()
{
    employee *e1 = new permanent(1000, "abcd", "senior technician", 50000);
    e1->salary();

    employee *e2 = new contractual(2000, "efgh", "junior technician", 40000);
    e2->salary();

    e1->showData();
    e2->showData();

    delete e1;
    delete e2;
    return 0;
}