#include <bits/stdc++.h>
using namespace std;
#define __line__ cout << "\n-------------------------------------------------\n"

class TIME
{
    string time_inp;
    int flag = 0;
    static int compare(const string &s)
    {
        int len = (int)s.length();
        const char *test = &s[len - 2];
        if (len == 8)
        {
            int h, m, sec;
            h = ((int)s[0] - 48) * 10 + ((int)s[1] - 48);
            m = ((int)s[3] - 48) * 10 + ((int)s[4] - 48);
            sec = ((int)s[6] - 48) * 10 + ((int)s[7] - 48);
            if ((h >= 0 && h <= 23) && (m >= 0 && m <= 59) && (sec >= 0 && sec <= 59))
                return 1;
        }
        else if (len == 10)
        {
            int h, m, sec;
            h = ((int)s[0] - 48) * 10 + ((int)s[1] - 48);
            m = ((int)s[3] - 48) * 10 + ((int)s[4] - 48);
            sec = ((int)s[6] - 48) * 10 + ((int)s[7] - 48);
            if ((h >= 1 && h <= 12) && (m >= 0 && m <= 59) && (sec >= 0 && sec <= 59))
                return 2;
        }
        return -1;
    }
    void convert()
    {
        char *temp = &(this->time_inp[0]);
        int t, len = (int)this->time_inp.length();
        if (this->flag == 1)
        {
            t = ((int)temp[0] - 48) * 10 + ((int)temp[1] - 48);
            if (t == 0)
            {
                this->time_inp[0] = '1';
                this->time_inp[1] = '2';
                this->time_inp = this->time_inp + "AM";
            }
            else if (t >= 1 && t <= 11)
            {
                this->time_inp = this->time_inp + "AM";
            }
            else if (t == 12)
            {
                this->time_inp = this->time_inp + "PM";
            }
            else if (t > 12 && t <= 23)
            {
                int u = t % 10 - 2;
                t = t / 10 - 1;
                this->time_inp[0] = (char)(t + 48);
                this->time_inp[1] = (char)(u + 48);
                this->time_inp = this->time_inp + "PM";
            }
            this->flag = 2;
        }
        else
        {
            t = ((int)temp[0] - 48) * 10 + ((int)temp[1] - 48);
            if ((temp[len - 2] == 'a' || temp[len - 2] == 'A') && (temp[len - 1] == 'm' || temp[len - 1] == 'M'))
            {
                if (t == 12)
                {
                    this->time_inp[0] = '0';
                    this->time_inp[1] = '0';
                    this->time_inp = this->time_inp.substr(0, len - 2);
                }
                else if (t >= 1 && t <= 11)
                {
                    this->time_inp = this->time_inp.substr(0, len - 2);
                }
            }
            else if ((temp[len - 2] == 'p' || temp[len - 2] == 'P') &&
                     (temp[len - 1] == 'm' || temp[len - 1] == 'M'))
            {
                if (t == 12)
                {
                    this->time_inp = this->time_inp.substr(0, len - 2);
                }
                else if (t >= 1 && t <= 11)
                {
                    int u = t % 10 + 2;
                    t = t / 10 + 1;
                    this->time_inp[0] = (char)(t + 48);
                    this->time_inp[1] = (char)(u + 48);
                    this->time_inp = this->time_inp.substr(0, len - 2);
                }
            }
            this->flag = 1;
        }
    }

public:
    void input()
    {
        cout << "Enter time in any format(24hr or 12hr): ";
        cin >> this->time_inp;
        this->flag = compare(this->time_inp);
        switch (flag)
        {
        case -1:
            cerr << "Wrong input format!!!" << endl;
            __line__;
            break;
        case 1:
            cout << "You have entered a 24-hr format " << endl;
            __line__;
            break;
        case 2:
            cout << "You have entered a 12-hr format " << endl;
            __line__;
            break;
        }
    }
    void output()
    {
        switch (this->flag)
        {
        case 1:
            cout << "24-hr format - " << time_inp << endl;
            __line__;
            convert();
            cout << "12-hr format - " << time_inp << endl;
            __line__;
            break;
        case 2:
            cout << "12-hr format - " << time_inp << endl;
            __line__;
            convert();
            cout << "24-hr format - " << time_inp << endl;
            __line__;
            break;
        default:
            cout << "Try entering again" << endl;
        }
    }
    void addMinutes(int mins = 0)
    {
        int h, m;
        m = mins % 60;
        h = mins / 60;
        if (this->flag == -1)
        {
            cout << "Entered format does not meet the conditions!!!" << endl;
            return;
        }
        else if (this->flag == 1)
        {
            string temp = this->time_inp;
            int tt = ((int)temp[3] - 48) * 10 + ((int)temp[4] - 48);
            tt = tt + m;
            int var = tt / 60;
            tt = tt % 60;
            int hh = ((int)temp[0] - 48) * 10 + ((int)temp[1] - 48);
            hh = hh + h + var;
            if (hh > 23)
                hh = hh % 24;
            temp[0] = (char)(hh / 10 + 48);
            temp[1] = (char)(hh % 10 + 48);
            temp[3] = (char)(tt / 10 + 48);
            temp[4] = (char)(tt % 10 + 48);
            this->time_inp = temp;
        }
        else if (this->flag == 2)
        {
            string temp = this->time_inp;
            int tt = ((int)temp[3] - 48) * 10 + ((int)temp[4] - 48);
            tt = tt + m;
            int var = tt / 60;
            tt = tt % 60;
            int hh = ((int)temp[0] - 48) * 10 + ((int)temp[1] - 48);
            int new_hh = hh + h + var;
            if (new_hh >= 12 && hh < 12 && temp[8] == 'A')
                temp[8] = 'P';
            else if (new_hh >= 12 && hh < 12 && temp[8] == 'P')
                temp[8] = 'A';
            if (new_hh > 12)
                hh = new_hh % 12;
            else
                hh = new_hh;
            temp[0] = (char)(hh / 10 + 48);
            temp[1] = (char)(hh % 10 + 48);
            temp[3] = (char)(tt / 10 + 48);
            temp[4] = (char)(tt % 10 + 48);
            this->time_inp = temp;
        }
    }
};

int main()
{
    TIME t;
    int mins;
    t.input();
    t.output();
    cout << "Enter the minutes to add= ";
    cin >> mins;
    cout << "Time after adding minutes:";
    __line__;
    t.addMinutes(mins);
    t.output();
    return 0;
}
