/*
Define a structure student with roll and score as attributes and with two member
functions to take input and to show the data. Use the member functions to take
data for a structure variable and to show. Write global function i) to modify score
and ii) to show the data again.
*/
#include "C:\Users\rohit\Desktop\shorthands\cpp\headers_1.h"

// #include <bits/stdc++.h>
// #include <chrono>
// using namespace std;
// using namespace std::chrono;
// #define __dline__ cout << "\n-------------------------------------------------\n"

struct student
{
    int roll;
    float score;
    void input_Data()
    {
        cout << "Enter roll no. of the student = ";
        cin >> this->roll;
        cout << "Enter score = ";
        cin >> this->score;
    }
    void output_Data()
    {
        cout << "Roll no. = " << this->roll << " and Score = " << this->score << endl;
    }
};

void modify_Data(student *s, int pos)
{
    cout << "Enter new score = ";
    cin >> (s + pos)->score;
}

void global_output_Data(const student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Roll no. = " << (s + i)->roll << " and Score = " << (s + i)->score << endl;
    }
}

int main()
{
    system("cls");
    int ch, i, n;
    char ans = 'N';
    cout << "Enter no. of students = ";
    cin >> n;
    student *s = new student[n];
    cout << "OPTIONS:\n1. Input Data\n2. Output Data\n3. Modify Data\n4. Output Data (Global)\n\n";
    do
    {
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "^^^^INPUT^^^^" << endl;
            for (i = 0; i < n; i++)
            {
                s[i].input_Data();
            }
            __dline__;
            break;
        case 2:
            cout << "^^^^OUTPUT(local)^^^^" << endl;
            for (i = 0; i < n; i++)
            {
                s[i].output_Data();
            }
            __dline__;
            break;
        case 3:
            cout << "^^^^MODIFY^^^^" << endl;
            int roll;
            cout << "Enter roll for which u want to change score = ";
            cin >> roll;
            for (i = 0; i < n; i++)
            {
                if ((s + i)->roll == roll)
                {
                    roll = i;
                    break;
                }
            }
            if (i == n)
            {
                cout << "Roll does not exist!!!\n";
                break;
            }
            modify_Data(s, roll);
            __dline__;
            break;
        case 4:
            cout << "^^^^OUTPUT(global)^^^^" << endl;
            global_output_Data(s, n);
            __dline__;
            break;
        default:
            cout << "U have entered wrong option!!!" << endl;
            __dline__;
            break;
        }
        cout << "Answer: ";
        cin >> ans;
    } while (ans == 'Y' || ans == 'y');
    delete[] s;
    return 0;
}
