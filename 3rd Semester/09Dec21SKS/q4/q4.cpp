/*
Maintain a container of students where they are kept in the descending order of
their scores. Take the help of suitable STL class.
*/
#include<bits/stdc++.h>
using namespace std;

// student class
class student{
    protected:
    int roll;
    string name;
    float score;
    public:
    student(int roll=0, string name="null", float score=0){
        this->roll=roll;
        this->name=name;
        this->score=score;
    }
    int getRoll(){
        return roll;
    }
    string getName(){
        return name;
    }
    float getScore(){
        return score;
    }
    bool operator<( const student& s) const {return (score<s.score);}
    // friend class studentList;

};

class studentList{
    // vector<student> s;
    
    // using min heap to reorder student according to scores
    priority_queue<student, vector<student>, less<student>> s;
    public:
    studentList(){
        // this->s.reserve(100);
    };
    // adding student
    void add(){
        int roll;
        string name;
        float score;
        cout<<"Enter roll= ";
        cin>>roll;
        cout<<"Enter name= ";
        cin>>name;
        cout<<"Enter score= ";
        cin>>score;
        // student st(roll,name,score);
        // s.push_back(st);
        s.push({roll,name,score});
    }
    // displaying student
    void display(){
        priority_queue<student, vector<student>, less<student>> st = s;
        while(!st.empty()){
            student temp = st.top();
            cout<<"Roll= "<<temp.getRoll()<<endl;
            cout<<"Name= "<<temp.getName()<<endl;
            cout<<"Score= "<<temp.getScore()<<endl;
            st.pop();
            cout<<endl;
        }
    }
    // returning total studentss
    int totalStudents(){
        return this->s.size();
    }

};

// driver code
int main(){
    system("cls");
    int ch;
    studentList sList;
    cout<<"OPTIONS:\n1. Add Student\n2. Display\n";
    while(1){
        cout<<"Enter option: ";
        cin>>ch;
        switch(ch){
            case 0:
                cout<<"Exitting!"<<endl;
                exit(0);
                break;
            case 1:
                cout<<"Add"<<endl;
                sList.add();
                break;
            case 2:
                cout<<"Display"<<endl;
                sList.display();
                break;
            default:
                cout<<"WRONG!!! CHOICE"<<endl;
                // break;
        }
    }
    return 0;
}