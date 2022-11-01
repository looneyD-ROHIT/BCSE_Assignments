/*
 Design a BALANCE class with account number, balance and date of last update. 
Consider a TRANSACTION class with account number, date of transaction, 
amount and transaction type (W for withdrawal and D for deposit). If it is a 
withdrawal check whether the amount is available or not. Transaction object will 
make necessary update in the BALANCE class.
*/
#include <bits/stdc++.h>
using namespace std;
#define __dline__ cout << "\n-------------------------------------------------\n"

class BALANCE
{
    friend class TRANSACTION;
    double balance;
    string last_date;
    static int count;

public:
    int acno;
    BALANCE(int acno = 1000, double balance = 0, string last_date = "")
    {
        this->acno = acno + count;
        this->balance = balance;
        this->last_date = last_date;
        count++;
    }
    void initAC()
    {
        cout << "Your account no. assigned is= " << this->acno << endl;
        cout << "Enter the balance u want to keep on opening ac(min. 3000)= ";
        cin >> this->balance;
        time_t t;
        struct tm *t_input;
        time(&t);
        t_input = localtime(&t);
        this->last_date = string(asctime(t_input));
    }
    void displaydetails()
    {
        cout << "DETAILS:" << endl;
        cout << "Yout acno is= " << this->acno << endl;
        cout << "Balance= " << this->balance << endl;
        cout << "Last date of transaction- " << this->last_date;
        __dline__;
    }
};

int BALANCE::count = 0;

class TRANSACTION
{
public:
    int acno;
    char type;
    TRANSACTION(int acno = 0, char type = 'W')
    {
        this->acno = acno;
        this->type = type;
    }
    void transactionBALANCE(BALANCE &obj)
    {
        double amount = 0;
        if (this->type == 'W')
        {
            cout << "Enter amount to withdraw= ";
            cin >> amount;
            if (amount + 3000 <= obj.balance)
                obj.balance = obj.balance - amount;
            else
                cout << "Not enough balance!!!";
            __dline__;
        }
        else if (this->type == 'D')
        {
            cout << "Enter amount to deposit= ";
            cin >> amount;
            obj.balance += amount;
            __dline__;
        }
        time_t t;
        struct tm *t_input;
        time(&t);
        t_input = localtime(&t);
        obj.last_date = string(asctime(t_input));
    }
};
int main()
{
    system("cls");
    BALANCE test_user;
    TRANSACTION test_transaction;
    cout << "Initializing user";
    __dline__;
    test_user.initAC();
    test_user.displaydetails();
    test_transaction.acno = test_user.acno;
    cout << "Enter type of transaction: ";
    cin >> test_transaction.type;
    test_transaction.transactionBALANCE(test_user);
    test_user.displaydetails();
    return 0;
}