/*
In a library, for each book book-id, serial number (denotes copy number of a book),
title, author, publisher and price are stored. Book-id and serial number together will
be unique identifier for a book. Members are either student or faculty. Each member has
unique member-id. Name, e-mail, address are also to be stored. For any transaction
(book issue or return), members are supposed to place transactions slip. User will submit
member-id, book-id, and serial number (only for book return). While processing a
transaction, check the validity of the member. While issuing, availability of a copy
of the book is to be checked. While returning a book, it is to be checked whether this
copy was issued to the member or not. A student member can have 2 books issued at a point
of time. For faculty members it is 10. Transaction information is to be stored like date
of transaction, member-id, book-id, serial number, returned or not. An entry is made when
book is issued and updated when the book is returned.
Design the classes and implement. For list consider memory data structure.
*/

/*
LIBRARY MANAGEMENT SYSTEM:
book = [id & s.no], title, author, publisher, price
members (student/faculty) = id, name, email
return = memberid, bookid, s.no
*/

// linked list implementation
#include <bits/stdc++.h>
using namespace std;

class member;

// BOOK class
class BOOK
{
    friend class member;
    static int cnt;

protected:
    int book_id;
    int sNo;

public:
    int total;
    char title[60];
    char author[30];
    char publisher[100];
    float price;
    BOOK *next;
    char *transactionTime;
    // constructor
    BOOK(int id = 1000, int total = 0, string title = "NULL", string author = "NULL", string pub = "NULL", float price = 0)
    {
        this->book_id = id;
        this->total = total;
        this->sNo = total;
        strcpy(this->title, &title[0]);
        strcpy(this->author, &author[0]);
        strcpy(this->publisher, &pub[0]);
        this->price = price;
        next = NULL;
        // cnt++;
    }
    // destructor
    ~BOOK()
    {
        cout << "BOOK instance destroyed" << endl;
    }
    // function to search book list
    static BOOK *searchBOOK(BOOK *&head, int id = 0)
    {
        if (head == NULL)
        {
            cout << "BOOK list is empty!" << endl;
            return NULL;
        }
        BOOK *temp = head;
        while (temp != NULL)
        {
            if (id == temp->book_id)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }
    // function to show book details
    static void showBOOK(BOOK *&head)
    {
        if (head == NULL)
        {
            cout << "BOOK list is empty!" << endl;
            return;
        }
        BOOK *temp = head;
        while (temp != NULL)
        {
            cout << "BOOK id: " << temp->book_id << endl;
            cout << "BOOK serial no.: ";
            if (temp->sNo <= 0)
                cout << "OUT OF STOCK" << endl;
            else
                cout << 1 << " to " << temp->sNo << endl;
            cout << "TITLE: " << temp->title << endl;
            cout << "AUTHOR: " << temp->author << endl;
            cout << "PUBLISHER: " << temp->publisher << endl;
            cout << "PRICE: " << temp->price << endl;
            cout << "LAST TRANSACTION TIME: " << temp->transactionTime << endl;
            cout << "---------------------------------------------------------\n";
            temp = temp->next;
        }
    }
    friend bool returnBOOK(BOOK *&, member *&, int);
};
// function to return transaction time
char *getTransactionTIME()
{
    time_t t = time(0);
    struct tm *gt = localtime(&t);
    return asctime(gt);
}

int BOOK::cnt = 0;
// bool validate(const char *str)
//     {
//         return (strcmpi(prefix, str) == 0);
//     };

// member class
class member
{
    friend bool returnBOOK(BOOK *&head, member *&top, int);

protected:
    char member_id[30];
    char name[30];
    char email_id[100];
    int *issuedIds;
    int onPossession;
    int limit;
    char prefix[4];

public:
    member *next;
    // constructor
    member(string id = "NULL", string name = "NULL", string email = "NULL")
    {
        strcpy(this->member_id, &id[0]);
        strcpy(this->name, &name[0]);
        strcpy(this->email_id, &email[0]);
        issuedIds = NULL;
        onPossession = 0;
        next = NULL;
    }
    // function to construct member id
    void construct()
    {
        prefix[0] = member_id[0];
        prefix[1] = member_id[1];
        prefix[2] = member_id[2];
        prefix[3] = '\0';

        if (strcmpi(prefix, "STU") == 0)
        {
            limit = 2;
            issuedIds = new int[limit];
            memset(issuedIds, -1, sizeof(int) * limit);
        }
        else if (strcmpi(prefix, "FAC") == 0)
        {
            limit = 10;
            issuedIds = new int[limit];
            memset(issuedIds, -1, sizeof(int) * limit);
        }
    }
    // function to validate a book
    bool validate(const char *str)
    {
        return strcmpi(prefix, str) == 0;
    }
    // function to issue a book
    bool issue(BOOK *&head, int id = 0)
    {
        if (!id)
        {
            cout << "Enter a valid book id!" << endl;
            return false;
        }

        BOOK *temp = BOOK::searchBOOK(head, id);
        int &av = temp->sNo;
        if (temp == NULL)
        {
            cout << "BOOK doesn't exist!" << endl;
            return false;
        }
        if (av <= 0)
        {
            cout << "BOOK is out of stock, Please come few days later!" << endl;
            return false;
        }

        if (validate("STU"))
        {
            if (onPossession >= 2)
            {
                cout << "The student already possesses the maximum no. of books. :(" << endl;
                return false;
            }
            int i = 0;
            while (issuedIds[i] != -1)
                i++;

            issuedIds[i] = id;
            av--;
            onPossession++;
            temp->transactionTime = getTransactionTIME();
            return true;
        }
        else if (validate("FAC"))
        {
            if (onPossession >= 10)
            {
                cout << "The faculty already possesses the maximum no. of books. :(" << endl;
                return false;
            }
            int i = 0;
            while (issuedIds[i] != -1)
                i++;

            issuedIds[i] = id;
            av--;
            onPossession++;
            temp->transactionTime = getTransactionTIME();
            return true;
        }
        else
        {
            cout << "This member id seems to be invalid!" << endl;
        }
        return false;
    }

    // function to show member details
    static void showMember(member *&top)
    {
        if (top == NULL)
        {
            cout << "Member list is empty!" << endl;
            return;
        }
        member *temp = top;
        while (temp != NULL)
        {
            cout << "Member id: " << temp->member_id << endl;
            cout << "NAME: " << temp->name << endl;
            cout << "EMAIL ID: " << temp->email_id << endl;
            cout << "issuedIDS: ";
            for (int i = 0; i < temp->onPossession; i++)
                cout << temp->issuedIds[i] << ", ";
            cout << endl;
            cout << "LIMIT: " << temp->limit << endl;
            cout << "PREFIX: " << temp->prefix << endl;
            cout << "---------------------------------------------------------\n";
            temp = temp->next;
        }
    }
};

// function to return a book
bool returnBOOK(BOOK *&head, member *&top, int id = 0)
{
    if (top == NULL)
    {
        cout << "Member list is empty!" << endl;
        return false;
    }
    // if (member::validate("STU") || member::validate("FAC"))
    // {

    BOOK *book = BOOK::searchBOOK(head, id);
    int flag = book->total > book->sNo;
    if (book->total == book->sNo)
    {
        cout << "Sorry our records show that this book was not issued!" << endl;
        return false;
    }
    cout << "This book was last issued on - " << book->transactionTime << endl;

    int *temp = top->issuedIds;
    int i;
    for (i = 0; i < top->limit; i++)
        if (temp[i] == id)
            break;

    if (i == top->limit)
    {
        cout << "This is not a valid member having issued this book!" << endl;
        return false;
    }
    // }
    for (int i = 0; i < top->limit; i++)
    {
        if (id == top->issuedIds[i])
        {
            top->issuedIds[i] = top->issuedIds[top->onPossession - 1];
            top->issuedIds[top->onPossession - 1] = -1;
            top->onPossession--;
            head->sNo++;
            cout << "BOOK successfully returned!" << endl;
            book->transactionTime = getTransactionTIME();
            return true;
        }
    }
    return false;
}
// driver code
int main()
{
    // book list
    BOOK *head = NULL;
    BOOK *b1 = new BOOK(1069, 10, "hello world1", "noob coder1", "springer1", 1100);
    head = b1;
    BOOK *b2 = new BOOK(1070, 7, "hello world2", "noob coder2", "springer2", 1200);
    b1->next = b2;
    BOOK *b3 = new BOOK(1071, 4, "hello world3", "noob coder3", "springer3", 1300);
    b2->next = b3;

    // member list
    member *top = NULL;
    member *m1 = new member("STU1069", "a b", "1@gmail.com");
    m1->construct();
    top = m1;
    member *m2 = new member("STU1070", "c d", "2@gmail.com");
    m2->construct();
    m1->next = m2;
    member *m3 = new member("FAC1069", "e f", "3@gmail.com");
    m3->construct();
    m2->next = m3;

    // issuing books
    m1->issue(head, 1070);
    m1->issue(head, 1069);
    // m1->issue(head, 1071);
    // m1->issue(head, 1069);

    m2->issue(head, 1071);

    m3->issue(head, 1071);
    // m3->issue(head, 1071);
    // m3->issue(head, 1071);
    // m3->issue(head, 1071);
    // m3->issue(head, 1071);

    // returning books
    returnBOOK(head, m1, 1069);
    cout << "[MEMBERS]:-\n\n";
    member::showMember(top);
    cout << "[BOOKS]:-\n\n";
    BOOK::showBOOK(head);

    return 0;
}