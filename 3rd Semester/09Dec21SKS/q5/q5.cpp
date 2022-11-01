#include<bits/stdc++.h>
using namespace std;


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
    // priority_queue<student, vector<student>, less<student>> s;
    map<int,student> s;
    public:
    studentList(){
        // this->s.reserve(100);
    };
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
        s.insert(pair<int,student>(roll,{roll,name,score}));
    }
    void display(){
        // priority_queue<student, vector<student>, less<student>> st = s;
        // map<int,student> st = s;
        for(auto i=s.begin(); i!=s.end(); i++){
            cout<<"Roll= "<<i->second.getRoll()<<endl;
            cout<<"Name= "<<i->second.getName()<<endl;
            cout<<"Score= "<<i->second.getScore()<<endl;
            cout<<endl;
        }
    }
    auto end(){
        return s.end();
    }
    auto retrieveByRoll(int roll){
        return this->s.find(roll);
    }
    int totalStudents(){
        return this->s.size();
    }

};
void call(studentList& sList){
    int roll;
    cout<<"Enter roll= ";
    cin>>roll;
    auto rec = sList.retrieveByRoll(roll);
    if(rec!=sList.end()){
    cout<<"Roll= "<<rec->second.getRoll()<<endl;
    cout<<"Name= "<<rec->second.getName()<<endl;
    cout<<"Score= "<<rec->second.getScore()<<endl;
    cout<<endl;
    }else{
        cout<<"Not found!"<<endl;
    }
}
int main(){
    system("cls");
    int ch;
    studentList sList;
    cout<<"OPTIONS:\n1. Add Student\n2. Display\n3. Retrieve by Roll";
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
            case 3:
                cout<<"Retrieve by Roll"<<endl;
                call(sList);
                
                break;
            default:
                cout<<"WRONG!!! CHOICE"<<endl;
                // break;
        }
    }
    return 0;
}