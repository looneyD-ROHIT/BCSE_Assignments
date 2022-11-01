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

#include <bits/stdc++.h>
using namespace std;

class BOOK{
    static int cnt;
    protected:
    int book_id;
    int sNo;
    public:
    char title[60];
    char author[30];
    char publisher[100];
    float price;
    BOOK(int id=0, int sNo=0, string title="NULL", string author="NULL", string pub="NULL", float price=0F){
        this->book_id = id + cnt;
        this->sNo = sNo + cnt;
        strcpy(this->title,&title[0]);
        strcpy(this->author,&author[0]);
        strcpy(this->publisher,&pub[0]);
        this->price=price;
    }
    ~BOOK(){
        cout<<"BOOK instance destroyed"<<endl;
    }
};
int BOOK::cnt=0;

class member{
    protected:
    char member_id[30];
    char name[30];
    char email_id[100];
    char prefix[4];
    public:
    void construct(){
        prefix[0]=member_id[0];
        prefix[1]=member_id[1];
        prefix[2]=member_id[2];
    }
    virtual bool validate()=0;
    virtual int limit()=0;
    // member(string id = "NULL",string name="NULL",string email = "NULL"){
    //     strcpy(this->member_id,&id[0]);
    //     strcpy(this->name,&name[0]);
    //     strcpy(this->email_id,&email[0]);
    // }
};
class student:public member{
    public:
    student(string id = "NULL",string name="NULL",string email = "NULL"){
        strcpy(this->member_id,&id[0]);
        strcpy(this->name,&name[0]);
        strcpy(this->email_id,&email[0]);
    }
    bool validate(){
        if(strcmpi(prefix,"STU")==0)
        return true;
        return false;
    }
    int limit(){
        return 2;
    }
};
class faculty:public member{
    public:
    faculty(string id = "NULL",string name="NULL",string email = "NULL"){
        strcpy(this->member_id,&id[0]);
        strcpy(this->name,&name[0]);
        strcpy(this->email_id,&email[0]);
    }
    bool validate(){
        if(strcmpi(prefix,"FAC")==0)
        return true;
        return false;
    }
    int limit(){
        return 10;
    }
};
int main()
{

    return 0;
}