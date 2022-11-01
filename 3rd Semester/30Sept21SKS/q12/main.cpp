/*
Design a STUDENT class to store roll, name, course, admission date and marks in 
5 subjects. Provide methods corresponding to admission (marks are not available 
then), receiving marks and preparing mark sheet. Support must be there to show 
the number of students who have taken admission.
*/

#include <bits/stdc++.h>
using namespace std;
#define __dline__ cout << "\n-------------------------------------------------\n"

class STUDENT
{
    int roll_no;
    string name;
    string course;
    string adm_date;
    float marks[5];
    STUDENT *next = NULL;
    static int count;

public:
    STUDENT(int roll_no = 0, string name = "", string course = "NIL", string adm_date = "NIL") : roll_no(1000 + count), name(name), course(course), adm_date(adm_date)
    {
        count++;
    }
    void admission()
    {
        cout << "Admission Date: ";
        cin >> this->adm_date;
        __dline__;
        cout << "Enter name of STUDENT: ";
        cin >> this->name;
        __dline__;
        cout << "Course enrolled: ";
        cin >> this->course;
        __dline__;
    }
    void receive_marks()
    {
        cout << "Enter the marks obtained in 5 subjects:" << endl;
        for (int i = 0; i < 5; i++)
        {
            cin >> this->marks[i];
        }
    }
    void show_Data()
    {
        cout << "Admission date = " << this->adm_date << endl;
        __dline__;
        cout << "STUDENT roll no. = " << this->roll_no << endl;
        __dline__;
        cout << "Name: " << this->name << endl;
        __dline__;
        cout << "Course = " << this->course << endl;
        __dline__;
    }
    void marks_sheet(int roll)
    {

        cout << "Marksheet of the student with roll no. " << this->roll_no << endl
             << endl;
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            cout << this->marks[i] << endl;
            __dline__;
            sum += this->marks[i];
        }
        cout << "Total marks = " << sum << endl;
        __dline__;
        cout << "Percentage = " << sum / 5 << endl;
        __dline__;
    }
    static void init(STUDENT *&head)
    {
        if (head == NULL)
        {
            cout << "STUDENT list is empty" << endl;
            __dline__;
            head = new STUDENT;
            head->admission();
            return;
        }
        STUDENT *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new STUDENT;
        temp->next->admission();
    }
    static void init_marks(STUDENT *head, int roll)
    {
        if (head == NULL)
        {
            cout << "Student list is empty" << endl;
            __dline__;
        }
        STUDENT *temp = head;

        while (temp->next != NULL)
        {
            if (temp->roll_no == roll)
                break;
            temp = temp->next;
        }
        temp->receive_marks();
    }
    static void display(STUDENT *head)
    {
        if (head == NULL)
        {
            cout << "Empty list" << endl;
            __dline__;
            return;
        }
        while (head != NULL)
        {
            head->show_Data();
            head = head->next;
        }
    }
    static void show_marks_sheet(STUDENT *head, int roll)
    {
        if (head == NULL)
        {
            cout << "Empty list" << endl;
            __dline__;
            return;
        }
        while (head->next != NULL)
        {
            if (head->roll_no == roll)
                break;
            head = head->next;
        }
        if (head == NULL)
        {
            cout << "Roll no. does not exist in list" << endl;
            return;
        }
        head->marks_sheet(roll);
    }
    static void n_p()
    {
        cout << "Total no. of partcipants are = " << STUDENT::count << endl;
        __dline__;
    }
};

int STUDENT::count = 0;

int main(int argc, char *argv[])
{
    system("cls");
    int ch;
    STUDENT *head = NULL;
    while (true)
    {
        cout << "OPTIONS:\n1. ADMISSION\n2. ADD MARKS\n3. SHOW DATA\n4. SHOW MARKSHEET\n5. NO. OF PARTICIPANTS\n";
        cout << "Enter choice = ";
        cin >> ch;
        __dline__;
        switch (ch)
        {
        case 0:
            exit(0);
        case 1:
            STUDENT::init(head);
            break;
        case 2:
            cout << "Enter roll for marks = ";
            int roll;
            cin >> roll;
            __dline__;
            STUDENT::init_marks(head, roll);
            break;
        case 3:
            STUDENT::display(head);
            break;
        case 4:
            cout << "Enter roll to see marksheet = ";
            cin >> roll;
            STUDENT::show_marks_sheet(head, roll);
            break;
        case 5:
            STUDENT::n_p();
            break;
        default:
            cout << "Wrong Choice" << endl;
            __dline__;
        }
    }

    return 0;
}
