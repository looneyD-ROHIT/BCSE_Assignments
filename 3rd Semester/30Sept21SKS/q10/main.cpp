/*Create a STACK class with operation for initialization, push and pop. Support
for checking underflow and overflow condition are also to be provided.*/

#include <bits/stdc++.h>
using namespace std;
#define __line__ cout << "\n-------------------------------------------------\n"

class STACK
{
    int element;
    STACK *next = NULL;

public:
    STACK()
    {
        this->element = 0;
        this->next = NULL;
    }
    static STACK *init()
    {
        STACK *n = new STACK;
        cout << "Enter element value = ";
        cin >> n->element;
        return n;
    }
    static void push(STACK *&head)
    {
        if (head == NULL)
        {
            cout << "STACK was empty" << endl;
        }
        STACK *temp = init();
        STACK *x = head;
        head = temp;
        temp->next = x;
    }
    static void pop(STACK *&head)
    {
        if (head == NULL)
        {
            cout << "STACK underflow!!!" << endl;
            return;
        }
        STACK *temp;
        temp = head;
        head = head->next;
        delete (temp);
        cout << "Popped successfully" << endl;
        __line__;
    }
    static void display(STACK *head)
    {
        if (head == NULL)
        {
            cout << "STACK underflow!!!" << endl;
            return;
        }
        while (head != NULL)
        {
            cout << "element = " << head->element << endl;
            __line__;
            head = head->next;
        }
    }
};

int main()
{
    system("cls");
    STACK *head = NULL;
    int ch;
    while (1)
    {
        cout << "OPTIONS:\n1. PUSH\n2. POP\n3. DISPLAY\n";
        __line__;
        cout << "Enter choice = ";
        cin >> ch;
        __line__;
        switch (ch)
        {
        case 1:
            STACK::push(head);
            break;
        case 2:
            STACK::pop(head);
            break;
        case 3:
            STACK::display(head);
            break;
        case 0:
            exit(0);
        default:
            cout << "Wrong choice" << endl;
            __line__;
        }
    }
    return 0;
}
