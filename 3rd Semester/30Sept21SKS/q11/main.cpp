/*Create an APPLICANT class with application id (auto generated as last id +1), 
name and score. Support must be there to receive applicant data, show applicant 
details and to find out number of applicants.*/

#include <bits/stdc++.h>
using namespace std;
#define __dline__ cout << "\n-------------------------------------------------\n"

class APPLICANT
{
    int a_id;
    string name;
    float score;
    APPLICANT *next = NULL;
    static int count;

public:
    APPLICANT(string name = "", float score = 0.0) : a_id(1000 + count), name(name), score(score)
    {
        count++;
    }
    void get_Data()
    {
        cout << "Enter name of applicant: ";
        cin >> this->name;
        __dline__;
        cout << "Enter score of applicant = ";
        cin >> this->score;
        __dline__;
    }
    void show_Data()
    {
        cout << "Applicant id = " << this->a_id << endl;
        __dline__;
        cout << "Name: " << this->name << endl;
        __dline__;
        cout << "Score = " << this->score << endl;
        __dline__;
    }
    static void init(APPLICANT *&head)
    {
        if (head == NULL)
        {
            cout << "Applicant list is empty" << endl;
            __dline__;
            head = new APPLICANT;
            head->get_Data();
            return;
        }
        APPLICANT *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new APPLICANT;
        temp->next->get_Data();
    }
    static void display(APPLICANT *head)
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
    static void n_p()
    {
        cout << "Total no. of partcipants are = " << APPLICANT::count << endl;
        __dline__;
    }
};

int APPLICANT::count = 0;

int main(int argc, char *argv[])
{
    system("cls");
    int ch;
    APPLICANT *head = NULL;
    while (true)
    {
        cout << "OPTIONS:\n1. ADD\n2. SHOW DATA\n3. NO. OF PARTICIPANTS\n";
        cout << "Enter choice = ";
        cin >> ch;
        __dline__;
        switch (ch)
        {
        case 0:
            exit(0);
        case 1:
            APPLICANT::init(head);
            break;
        case 2:
            APPLICANT::display(head);
            break;
        case 3:
            APPLICANT::n_p();
            break;
        default:
            cout << "Wrong Choice" << endl;
            __dline__;
        }
    }

    return 0;
}