/*
Design the class(es) for the following. Each account has account number and 
balance amount. A list of account is to be maintained where one can add and find 
account, display information of all accounts. While adding, account number must 
be unique. Withdraw object has account number (must exist) and amount (will not 
exceed balance amount of corresponding account). Withdraw object will update 
the balance of corresponding account in the list. Implement your design. Use 
friend function wherever required and again, modify your implementation to 
avoid friend function.
*/

// code completed without the help of friend functions
#include <bits/stdc++.h>
#define M ((unsigned long long int)1e9 + 7)
#define __dline__ \
    cout << "------------------------------------------------------------\n";
using namespace std;
class Account;
class AccountOperations;

// account class
class Account
{
protected:
    unsigned long long int acno;
    double bal;

public:
    Account()
    {
        cout << "Constructor Called!!!" << endl;
        this->acno = 0;
        this->bal = 0;
    }
    ~Account()
    {
        cout << "Destructor Called!!!" << endl;
    }
};

// transaction class
// account operation class to manipulate all operations
class AccountOperations : private Account
{
    static int count;
    AccountOperations *next;

public:
    AccountOperations()
    {
        this->count++;
        this->next = NULL;
    }
    static void createNewAccount(AccountOperations *&head);
    static AccountOperations *findAccount(AccountOperations *&head, unsigned long long int acno);
    static void showDetails(AccountOperations *&head);
    static void deposit(AccountOperations *&head);
    static void withdraw(AccountOperations *&head);
    static void showCount();
};

int AccountOperations::count = 0;

// function to create new account
void AccountOperations::createNewAccount(AccountOperations *&head)
{
    if (head == NULL)
    {
        head = new AccountOperations();
        cout << "Enter account no.= ";
        cin >> head->acno;
        cout << "Enter balance to deposit on account creation= ";
        cin >> head->bal;
        head->next = NULL;
        return;
    }
    AccountOperations *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    unsigned long long int var;
    cout << "Enter account no.= ";
    // time_t today = time(0);
    // temp->next->acno = (unsigned long long int)(today) % M;
    cin >> var;
    if (AccountOperations::findAccount(head, var) != NULL)
    {
        cout << "Entered acno already exists!!!" << endl;
        return;
    }
    temp->next = new AccountOperations();
    temp->next->acno = var;
    cout << "Enter balance to deposit on account creation= ";
    cin >> temp->next->bal;
    temp->next->next = NULL;
}

// function to find account
AccountOperations *AccountOperations::findAccount(AccountOperations *&head, unsigned long long int acno)
{
    if (head == NULL)
    {
        cout << "AccountList is empty" << endl;
        return NULL;
    }
    AccountOperations *temp = head;
    while (temp != NULL)
    {
        if (temp->acno == acno)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// function to show details of accounts
void AccountOperations::showDetails(AccountOperations *&head)
{
    AccountOperations *temp = head;
    while (temp != NULL)
    {
        cout << "Account no. = " << temp->acno << endl;
        cout << "Account balance = " << temp->bal << endl;
        __dline__;
        temp = temp->next;
    }
}

// function to handle deposits
void AccountOperations::deposit(AccountOperations *&head)
{
    float amt;
    unsigned long long int acno;
    cout << "Enter the account no.= ";
    cin >> acno;
    AccountOperations *temp;
    if ((temp = AccountOperations::findAccount(head, acno)) == NULL)
    {
        cout << "Account no. does not exist" << endl;
        return;
    }
    cout << "Account found!!!" << endl;
    cout << "Enter the amount you want to deposit= ";
    cin >> amt;
    temp->bal -= -amt;
}

// function to handle withdrawals
void AccountOperations::withdraw(AccountOperations *&head)
{
    float amt;
    unsigned long long int acno;
    cout << "Enter the account no.= ";
    cin >> acno;
    AccountOperations *temp;
    if ((temp = AccountOperations::findAccount(head, acno)) == NULL)
    {
        cout << "Account no. does not exist" << endl;
        return;
    }
    cout << "Account found!!!" << endl;
    cout << "Enter the amount you want to deposit= ";
    cin >> amt;
    if (amt <= temp->bal)
        temp->bal -= amt;
    else
        cout << "Withdraw amount cannot exceed available balance" << endl;
}

// function to show count of all accounts
void AccountOperations::showCount()
{
    cout << "Total no. of accounts= " << AccountOperations::count << endl;
}

// driver code
int main()
{
    system("cls");
    AccountOperations *head = NULL;
    unsigned long long int temp_acno;

    int ch;
    while (1)
    {
        cout << "OPTIONS:\n1. Add\n2. Show All Accounts\n3. Find\n4. Withdraw\n5. Deposit\n6. No. of accounts\n";
        cin >> ch;
        __dline__;
        switch (ch)
        {
        case 0:
            cout << "Exiting" << endl;
            __dline__;
            exit(0);
            break;
        case 1:
            cout << "Creating new account" << endl;
            AccountOperations::createNewAccount(head);
            __dline__;
            break;
        case 3:
            cout << "Finding an account" << endl;
            cout << "Enter acno to find= ";
            cin >> temp_acno;
            if (AccountOperations::findAccount(head, temp_acno) != NULL)
                cout << "Account found" << endl;
            else
                cout << "Account not found" << endl;
            __dline__;
            break;
        case 2:
            cout << "Show details of a account" << endl;
            AccountOperations::showDetails(head);
            break;
        case 4:
            cout << "Withdrawing money" << endl;
            AccountOperations::withdraw(head);
            __dline__;
            break;
        case 5:
            cout << "Deposit money" << endl;
            AccountOperations::deposit(head);
            __dline__;
            break;
        case 6:
            AccountOperations::showCount();
            __dline__;
            break;
        default:
            cout << "Enter valid option!!!" << endl;
            __dline__;
        }
    }
    return 0;
}