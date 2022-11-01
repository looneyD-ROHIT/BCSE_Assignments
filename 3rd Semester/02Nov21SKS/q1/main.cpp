/*
 For each student roll, name and phone number are to be maintained. For each
subject store subject code, name. A student may choose number of subjects from a
list of subjects. A subject may be chosen by number of students. Given a roll
number system must able to display the subjects chosen by the student and also
be able to display the students corresponding to a subject code. Design the classes
and implement the system.
*/

#include <bits/stdc++.h>
using namespace std;
#define __dline__ cout << "--------------------------------------------------------\n";
class STUDENT;
// basic details class
class basicDetails
{
public:
    string roll;
    string name;
    long long int phno;
    basicDetails(string roll = "", string name = "", long long int phno = 0)
    {
        this->roll = roll;
        this->name = name;
        this->phno = phno;
    }
};

// subjects class to keep track of list of subjects
class subjects
{

public:
    string subCode;
    string subName;
    static int subjectCount;
    // friend static void STUDENT::displayStudentbySub(STUDENT *&head, subjects *sub, string temp_subCode);
    subjects()
    {
        this->subCode = "xxxx";
        this->subName = "xxxx";
    }
    auto setData(string subCode = "", string subName = "", int count = 0)
    {
        this->subCode = subCode;
        this->subName = subName;
        subjectCount++;
    }
    static int sub_Count()
    {
        return subjectCount;
    }
    void showData()
    {
        cout << "subCode= " << this->subCode << " "
             << "subName= " << this->subName << endl;
    }
};
int subjects::subjectCount = 0;

// student class publicly inhereting basicDetails class
class STUDENT : public basicDetails
{
    int *sub_arr_index = NULL;
    int sub_arr_count;
    static int studentCount;
    STUDENT *next = NULL;

public:
    // constructor
    STUDENT(string roll = "", string name = "", long long int phno = 0) : basicDetails(roll, name, phno)
    {
        this->sub_arr_index = NULL;
        studentCount++;
        next = NULL;
    }
    // function to add student
    static void addStudent(STUDENT *&head)
    {
        if (head == NULL)
        {
            string roll, name;
            long long int phno;
            cout << "List was empty" << endl;
            cout << "Roll= ";
            cin >> roll;
            cout << "Name= ";
            cin >> name;
            cout << "Phno= ";
            cin >> phno;
            head = new STUDENT(roll, name, phno);
            return;
        }
        STUDENT *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        string roll, name;
        long long int phno;
        cout << "List was empty" << endl;
        cout << "Roll= ";
        cin >> roll;
        cout << "Name= ";
        cin >> name;
        cout << "Phno= ";
        cin >> phno;
        temp->next = new STUDENT(roll, name, phno);
    }
    // function to assign subject to a roll no.
    static void inputSubjectindices(STUDENT *&head)
    {
        STUDENT *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        cout << "Enter the indices of the subjects= ";
        temp->sub_arr_index = new int[subjects::sub_Count()];
        int i = 0, t;
        string st;
        fflush(stdin);
        getline(cin, st);
        fflush(stdin);
        stringstream ss(st);
        while (ss >> t)
        {
            temp->sub_arr_index[i] = t;
            i++;
        }
        temp->sub_arr_count = i;
    }
    // function to display students by roll
    static void displayStudent(STUDENT *&head, subjects *sub, string roll)
    {
        STUDENT *temp = head;
        while (temp != NULL)
        {
            if (temp->roll == roll)
            {
                break;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Roll doesn't exist!!!" << endl;
            return;
        }
        __dline__;
        cout << "Roll= " << temp->roll << " "
             << "Name: " << temp->name << endl;
        cout << "Phno.= " << temp->phno << endl;
        __dline__;
        cout << "Subjects:" << endl;
        for (int i = 0; i < temp->sub_arr_count; i++)
        {
            sub[temp->sub_arr_index[i]].showData();
        }
        __dline__;
    }
    // function to display student by subjects
    static void displayStudentbySub(STUDENT *&head, subjects *sub, string temp_subCode)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        STUDENT *temp = head;
        bool flag = false;
        while (temp != NULL)
        {
            for (int i = 0; i < temp->sub_arr_count; i++)
            {
                if (sub[temp->sub_arr_index[i]].subCode == temp_subCode)
                {
                    cout << "Roll= " << temp->roll << endl;
                    flag = true;
                }
            }
            temp = temp->next;
        }
        if (flag == false)
        {
            cout << "NO student found with this subject!" << endl;
        }
    }
    // auto allocate subjects()
};
int STUDENT::studentCount = 0;
// driver code
int main()
{
    system("cls");
    // cout << "hello" << endl;
    int i = 0, j;
    ifstream inputfile("input.txt", ios::in);
    subjects sub_input[8];
    // taking input of subjects data from an already existing file
    while (!inputfile.eof())
    {
        string t1, t2;
        inputfile >> t1;
        getline(inputfile, t2);
        sub_input[subjects::sub_Count()].setData(t1, t2);
    }

    // STUDENT s1("1000A", "Rohit", 9876543210);
    int ch;
    string temp_roll, temp_subCode;
    STUDENT *head = NULL;
    while (1)
    {
        cout << "OPTIONS:\n1. Add Student\n2. Show Subject List\n3. Search details for a student\n4. Search students with a particular subject\n";
        cout << "Enter option: ";
        cin >> ch;
        switch (ch)
        {
        case 0:
            cout << "Exitting" << endl;
            exit(0);
            break;
        case 1:
            cout << "Adding a student:-" << endl;
            STUDENT::addStudent(head);
            STUDENT::inputSubjectindices(head);
            break;
        case 2:
            cout << "List of subjects:-" << endl;
            j = 0;
            __dline__;
            while (j < sub_input->sub_Count())
            {
                cout << j << ". ";
                (sub_input + j)->showData();
                j++;
            }
            __dline__;
            break;
        case 3:
            cout << "Search details for a student" << endl;
            cout << "Enter roll no. of the student= ";
            cin >> temp_roll;
            STUDENT::displayStudent(head, sub_input, temp_roll);
            break;
        case 4:
            cout << "Search details for a subject" << endl;
            cout << "Enter subCode= ";
            cin >> temp_subCode;
            STUDENT::displayStudentbySub(head, sub_input, temp_subCode);
            break;
        }
    }
    return 0;
}