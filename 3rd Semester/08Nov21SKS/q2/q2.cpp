/*
Consider a class Student with roll, name and score as attributes. Support to 
take and display data is also there.  One wants to works with array of Student 
objects. May collect data for array elements, display those. In case index goes 
out of bounds, exception is to be raised with suitable message.
*/
#include<bits/stdc++.h>
using namespace std;

class STUDENT{
    public:
    int roll;
    string name;
    float score;
    STUDENT(){};
    ~STUDENT(){};
};
class studentArray{
    STUDENT s[3];
    public:
    int len=3;
    // STUDENT()
    void input(){
        for(int i=0; i<len; i++){
        cout<<"Enter data:";
        cin>>s[i].roll;
        cin>>s[i].name;
        cin>>s[i].score;
        cout<<endl;
        }
    }
    void output(){

        for(int i=0;; i++){
            try{
                if(i>=len)
                throw "index getting too large!";
                
        cout<<"Data:"<<endl;
        cout<<s[i].roll<<" ";
        cout<<s[i].name<<" ";
        cout<<s[i].score<<" "<<endl;
            }catch(const char* msg){
                cout<<"msg: "<<msg<<endl;
                return;
            }
        }
    }
};

int main(){
    system("cls");
    studentArray sr;
    sr.input();
    sr.output();

    return 0;
}