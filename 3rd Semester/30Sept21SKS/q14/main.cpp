/*
Design the class(es) for the following scenario:
• An item list contains item code, name, rate, and quantity for several 
items.
• Whenever a new item is added in the list uniqueness of item code is to be 
checked. 
• Time to time rate of the items may change. 
• Whenever an item is issued or received existence of the item is checked 
and quantity is updated. 
• In case of issue, availability of quantity is also to be checked.
• User may also like to know price/quantity available for an item.
*/

#include <bits/stdc++.h>
using namespace std;
#define __dline__ cout << "\n-------------------------------------------------\n"

class ITEM
{
    string code;
    string name;
    float rate;
    int quantity;

public:
    ITEM *next;
    ITEM(string code = "", string name = "", float rate = 0, int quantity = 0)
    {
        this->code = code;
        this->name = name;
        this->rate = rate;
        this->quantity = quantity;
        this->next = NULL;
    }
    static void initITEM(ITEM *&head, ITEM *&ptr)
    {
        string code, name;
        float rate;
        int quantity;
        cout << "Enter code= ";
        cin >> code;
        int flag = searchLIST(head, code);
        if (flag == -1)
        {
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter rate= ";
            cin >> rate;
            cout << "Enter quantity= ";
            cin >> quantity;
            ptr = new ITEM(code, name, rate, quantity);
        }
        else
        {
            cout << "ITEM with same code already exists, so we update quantity(-1 for no change)"; // to update the item quantity/price press y/Y: ";
            __dline__;
            cout << "Enter quantity= ";
            cin >> quantity;
            if (quantity == -1)
                return;
            ITEM *temp = head;
            while (flag--)
            {
                temp = temp->next;
            }
            temp->quantity = quantity;
        }
        // return (new ITEM(code, name, rate, quantity));
    }
    static void addITEM(ITEM *&head)
    {
        if (head == NULL)
        {
            cout << "List is empty";
            __dline__;
            initITEM(head, head);
            return;
        }
        ITEM *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        initITEM(head, temp->next);
    }
    static void deleteITEM(ITEM *&head, int pos = -1)
    {
        if (head == NULL)
        {
            cout << "List is empty";
            __dline__;
            return;
        }
        ITEM *temp = head;
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
            ITEM *temp2 = temp->next;
            temp->next = temp2->next;
            delete (temp2);
        }
        cout << "Deleted successfully";
        __dline__;
    }
    static void modifyITEM(ITEM *&head, int pos = -1)
    {
        if (head == NULL)
        {
            cout << "List is empty";
            __dline__;
            return;
        }
        ITEM *temp = head;
        if (pos == -1)
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
        }
        else
        {
            while (pos--)
            {
                temp = temp->next;
            }
        }
        cout << "Enter new code= ";
        cin >> temp->code;
        cout << "Enter new name: ";
        cin >> temp->name;
        cout << "Enter new rate= ";
        cin >> temp->rate;
        cout << "Enter new quantity= ";
        cin >> temp->quantity;
        __dline__;
    }
    static int searchLIST(ITEM *&head, string code)
    {
        if (head == NULL)
        {
            return -1;
        }
        int pos = 0;
        ITEM *temp = head;
        while (temp != NULL)
        {
            if (temp->code == code)
                return pos;
            pos++;
            temp = temp->next;
        }
        return -1;
    }
    static void displayITEM(ITEM *&head, string code)
    {
        if (head == NULL)
        {
            cout << "List is empty";
            __dline__;
            return;
        }
        ITEM *temp = head;
        while (temp != NULL)
        {
            if (temp->code == code)
                break;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "The details for this item does not exist";
            __dline__;
            return;
        }
        cout << "The details of the code as entered is below:" << endl;
        cout << "Code= " << temp->code << ", "
             << "Name: " << temp->name << ", "
             << "Rate= " << temp->rate << " INR, "
             << "Quantity= " << temp->quantity << " |";
        __dline__;
    }
    static void issueITEM(ITEM *&head, string code)
    {
        if (head == NULL)
        {
            cout << "List is empty";
            __dline__;
            return;
        }
        ITEM *temp = head;
        while (temp != NULL)
        {
            if (temp->code == code)
                break;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "The item does not exist in the list";
            __dline__;
            return;
        }
        int quantity;
        cout << "Enter the no. of items to issue= " << endl;
        cin >> quantity;
        temp->quantity = temp->quantity - quantity;
        __dline__;
    }
    static void displayLIST(ITEM *&head)
    {
        if (head == NULL)
        {
            cout << "List is empty";
            __dline__;
            return;
        }
        ITEM *temp = head;
        while (temp != NULL)
        {
            cout << "Code= " << temp->code << ", "
                 << "Name: " << temp->name << ", "
                 << "Rate= " << temp->rate << " INR, "
                 << "Quantity= " << temp->quantity << " |";
            __dline__;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    system("cls");
    int ch, input;
    string code;
    ITEM *head = NULL;
    cout << "OPTIONS\n"
         << "0. Exit\n"
         << "1. Add an item\n"
         << "2. Delete an ITEM\n"
         << "3. Update an ITEM\n"
         << "4. Show price and quantity of ITEM\n"
         << "5. Issue an item\n"
         << "6. Show full LIST";
    __dline__;
    while (1)
    {
        cout << "Enter choice= ";
        cin >> ch;
        __dline__;
        switch (ch)
        {
        case 0:
            cout << "Exitting";
            __dline__;
            while (head != NULL)
            {
                ITEM *temp = head;
                head = head->next;
                free(temp);
            }
            exit(0);
        case 1:
            cout << "Adding an item";
            __dline__;
            ITEM::addITEM(head);
            __dline__;
            break;
        case 2:
            cout << "Deleting an item";
            __dline__;
            cout << "Enter the position of the item to delete= ";
            cin >> input;
            if (input == -1)
                ITEM::deleteITEM(head);
            else
                ITEM::deleteITEM(head, input);
            break;
        case 3:
            cout << "Modifying an item";
            __dline__;
            cout << "Enter the position of the item to modify= ";
            cin >> input;
            if (input == -1)
                ITEM::modifyITEM(head);
            else
                ITEM::modifyITEM(head, input);
            break;
        case 4:
            cout << "Enter the code of the item= ";
            cin >> code;
            ITEM::displayITEM(head, code);
            break;
        case 5:
            cout << "Issuing an ITEM";
            __dline__;
            cout << "Enter the code of the item= ";
            cin >> code;
            ITEM::issueITEM(head, code);
            break;
        case 6:
            cout << "The ITEM LIST is as follows:";
            __dline__;
            ITEM::displayLIST(head);
            break;
        default:
            cout << "U have entered wrong choice!!!";
            __dline__;
            break;
        }
    }
    return 0;
}