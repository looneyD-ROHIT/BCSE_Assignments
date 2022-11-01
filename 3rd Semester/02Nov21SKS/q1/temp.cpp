#include <bits/stdc++.h>
using namespace std;

class subjects
{
    string subCode;
    string subName;
    static int subjectCount;

public:
    subjects()
    {
        this->subCode = "xxxx";
        this->subName = "xxxx";
    }
    void setData(string subCode = "", string subName = "")
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

int main()
{
    int i = 0;
    ifstream inputfile("input.txt", ios::in);
    subjects sub_input[2];
    while (!inputfile.eof())
    {
        string t1, t2;
        cout << "hello" << endl;
        getline(inputfile, t1);
        cout << "t1= " << t1 << endl;
        getline(inputfile, t2);
        cout << "t2= " << t2 << endl;
        cout << "subCount= " << subjects::sub_Count() << endl;
        sub_input[subjects::sub_Count()].setData(t1, t2);
        cout << "subCount= " << subjects::sub_Count() << endl;
    }
    // inputfile.close();
    int j = 0;
    while (j < sub_input->sub_Count())
    {
        (sub_input + j)->showData();
        j++;
    }
    return 0;
}