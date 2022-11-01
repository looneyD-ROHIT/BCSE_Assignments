/*
 Create a class for linked list. Consider a separate class NODE for basic node 
activities and use it in class for linked list.
*/
#include <bits/stdc++.h>
using namespace std;
#define __dline__ "\n-------------------------------------------------\n"

class LIST
{
    friend class NODE;
    int val;

public:
    LIST *next;
    static int count;
    LIST(int val = 0)
    {
        this->val = val;
        this->next = NULL;
        count++;
    }
};
class NODE
{
public:
    LIST *element;
    static void initNODE(LIST *item)
    {
        cout << "Enter the value to be inserted in node = ";
        cin >> item->val;
    }
    static void insertNODE(LIST *&head, int pos = -1)
    {
        if (pos > LIST::count)
        {
            cout << "Position index too high";
            cout << __dline__;
            return;
        }
        if (head == NULL)
        {
            cout << "LIST was empty";
            cout << __dline__;
            head = new LIST(0);
            initNODE(head);
            return;
        }
        LIST *temp = head;
        if (pos == -1)
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new LIST(0);
            initNODE(temp->next);
        }
        else if (pos == 0)
        {
            head = new LIST(0);
            initNODE(head);
            head->next = temp;
        }
        else
        {
            while (pos > 1)
            {
                temp = temp->next;
                pos--;
            }
            LIST *temp2 = temp->next;
            temp->next = new LIST(0);
            initNODE(temp->next);
            temp->next->next = temp2;
        }
    }
    static void deleteNODE(LIST *&head, int pos = -1)
    {
        if (pos >= LIST::count)
        {
            cout << "Position index too high";
            cout << __dline__;
            return;
        }
        if (head == NULL)
        {
            cout << "LIST is empty";
            cout << __dline__;
            return;
        }
        LIST *temp = head;
        if (pos == 0)
        {
            head = head->next;
            delete (temp);
        }
        else if (pos == -1)
        {
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete (temp->next);
            temp->next = NULL;
        }
        else
        {
            while (pos > 1)
            {
                temp = temp->next;
                pos--;
            }
            LIST *temp2 = temp->next;
            temp->next = temp2->next;
            delete (temp2);
        }
    }
    static void totalcountLIST()
    {
        cout << "The total no. of elements in the list is = " << LIST::count;
        cout << __dline__;
    }
    static void updateNODE(LIST *&head, int pos)
    {
        if (pos > LIST::count)
        {
            cout << "Position index too high";
            cout << __dline__;
            return;
        }
        if (head == NULL)
        {
            cout << "LIST was empty";
            cout << __dline__;
            return;
        }
        LIST *temp = head;
        if (pos == -1)
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            cout << "Enter new value to be updated= ";
            cin >> temp->val;
        }
        else
        {
            while (pos--)
            {
                temp = temp->next;
            }
            cout << "Enter new value to be updated= ";
            cin >> temp->val;
        }
        cout << __dline__;
    }
    static void traverseLIST(LIST *&head)
    {
        if (head == NULL)
        {
            cout << "LIST is empty!!!";
            cout << __dline__;
            return;
        }
        LIST *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
        cout << __dline__;
    }
    static void searchLIST(LIST *&head, int e)
    {
        if (head == NULL)
        {
            cout << "LIST is empty!!!";
            cout << __dline__;
            return;
        }
        LIST *temp = head;
        int pos = 0;
        while (temp != NULL)
        {
            if (temp->val == e)
            {
                cout << "Element found at pos " << pos << " in the list" << endl;
                cout << __dline__;
                return;
            }
            pos++;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Item not found in the list";
            cout << __dline__;
        }
    }
};
int LIST::count = 0;

int main()
{
    system("cls");
    LIST *head = NULL;
    int ch, input;
    cout << "OPTIONS:\n0. Exit\n1. Add a node\n2. Delete a node\n3. Search for a val\n4. Traverse and Display\n5. Update a position\n6. Total count of nodes\n";
    while (1)
    {
        cout << "Enter choice= ";
        cin >> ch;
        cout << __dline__;
        switch (ch)
        {
        case 0:
            cout << "Exitting";
            cout << __dline__;
            while (head != NULL)
            {
                LIST *temp = head;
                head = head->next;
                free(temp);
            }
            exit(0);
        case 1:
            cout << "Adding a node";
            cout << __dline__;
            cout << "Enter position of insertion= ";
            cin >> input;
            if (input != -1)
                NODE::insertNODE(head, input);
            else
                NODE::insertNODE(head);
            cout << __dline__;
            break;
        case 2:
            cout << "Deleting a node";
            cout << __dline__;
            cout << "Enter position of deletion= ";
            cin >> input;
            if (input != -1)
                NODE::deleteNODE(head, input);
            else
                NODE::deleteNODE(head);
            cout << __dline__;
            break;
        case 3:
            cout << "Searching for a val";
            cout << __dline__;
            cout << "Enter the value to be searched= ";
            cin >> input;
            NODE::searchLIST(head, input);
            break;
        case 4:
            cout << "Traverse and Display";
            NODE::traverseLIST(head);
            break;
        case 5:
            cout << "Updating a val at a specified position";
            cout << __dline__;
            cout << "Enter position of updation= ";
            cin >> input;
            NODE::updateNODE(head, input);
            break;
        case 6:
            NODE::totalcountLIST();
            break;
        default:
            cout << "You have entered a wrong choice";
            cout << __dline__;
            break;
        }
        cout << __dline__;
    }
    return 0;
}