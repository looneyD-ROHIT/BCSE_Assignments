#include <bits/stdc++.h>
using namespace std;

// class member;
void stringCopy(char *a, const char *b)
{
    int i;
    for (i = 0; b[i] != '\0'; i++)
    {
        cout << b[i] << endl;
        a[i] = b[i];
    }
    a[i] = '\0';
}
class BOOK
{
    // friend class member;
    static int cnt;

protected:
    int book_id;
    int sNo;

public:
    int total;
    // char title[60];
    // char author[30];
    // char publisher[100];
    float price;
    BOOK *next;
    char *transactionTime;
    BOOK(int id, int total, float price)
    {
        cout << "hello" << endl;
        this->book_id = id;
        this->total = total;
        this->sNo = total;
        // strcpy(title, &t[0]);
        // strcpy(author, &a[0]);
        // strcpy(publisher, &pub[0]);
        // stringCopy(this->title, &title[0]);
        // stringCopy(this->author, &author[0]);
        // stringCopy(this->publisher, &pub[0]);
        this->price = price;
        next = NULL;
        // cnt++;
    }
    ~BOOK()
    {
        cout << "BOOK instance destroyed" << endl;
    }
    // static BOOK *searchBOOK(BOOK *&head, int id = 0)
    // {
    //     if (head == NULL)
    //     {
    //         cout << "BOOK list is empty!" << endl;
    //         return NULL;
    //     }
    //     BOOK *temp = head;
    //     while (temp != NULL)
    //     {
    //         if (id == temp->book_id)
    //             return temp;
    //         temp = temp->next;
    //     }
    //     return NULL;
    // }
    static void showBOOK(BOOK *&head)
    {
        cout << "show function!" << endl;
        if (head == NULL)
        {
            cout << "BOOK list is empty!" << endl;
            return;
        }
        BOOK *temp = head;
        while (temp != NULL)
        {
            cout << "BOOK id: " << temp->book_id << endl;
            cout << "BOOK serial no.: " << 0 << " to " << temp->sNo - 1 << endl;
            // cout << "TITLE: " << temp->title << endl;
            // cout << "AUTHOR: " << temp->author << endl;
            // cout << "PUBLISHER: " << temp->publisher << endl;
            cout << "PRICE: " << temp->price << endl;
            cout << "---------------------------------------------------------\n";
            temp = temp->next;
        }
    }
    // friend bool returnBOOK(BOOK *&, member *&, int);
};

int main()
{
    // BOOK *head = NULL;
    // BOOK *b1 = new BOOK(1069, 10, "hello world1", "noob coder1", "springer1", 1100);
    // head->next = b1;
    // BOOK *b2 = new BOOK(1069, 10, "hello world2", "noob coder2", "springer2", 1200);
    // b1->next = b2;
    // BOOK *b3 = new BOOK(1069, 10, "hello world3", "noob coder3", "springer3", 1300);
    // b3->next = NULL;
    BOOK *head = NULL;
    // BOOK b1(1069, 10, "hello world1", "noob coder1", "springer1", 1100);
    BOOK b1(1069, 10, 1100);
    head->next = &b1;
    // BOOK b2(10069, 10, "hello world2", "noob coder2", "springer2", 1200);
    BOOK b2(10069, 10, 1200);
    b1.next = &b2;
    // BOOK b3(100069, 10, "hello world3", "noob coder3", "springer3", 1300);
    BOOK b3(100069, 10, 1300);
    b3.next = NULL;

    BOOK::showBOOK(head);
    return 0;
}