/*
Create an array of student objects (containing roll, name, name and score)
whose size may vary dynamically once objects are added or removed, randomly
elements may be accessed, one can find number of objects in the list, one can
find the student with highest score, find the students with a substring in their
name and also without a substring in the name. Take the help of suitable STL
classes.
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
    // friend class studentList;

};

// student list to handle the operations
class studentList{
    vector<student> s;
    public:
    studentList(){
        this->s.reserve(100);
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
        s.push_back({roll,name,score});
    }
    void remove(int i){
        if(this->totalStudents()>i && i>=0){
            auto it = s.begin();
            while(i--)
            it++;
            s.erase(it);
        }else{
            cout<<"index not valid!"<<endl;
        }
    }
    void getData(int i){
        if(this->totalStudents()>i && i>=0){
            cout<<"Roll= "<<this->s[i].getRoll()<<endl;
            cout<<"Name= "<<this->s[i].getName()<<endl;
            cout<<"Roll= "<<this->s[i].getScore()<<endl;
            cout<<endl;
        }else{
            cout<<"index not valid!"<<endl;
        }
    }
    void highestScore(){
        int i;
        float max = 0;
        for(i=1; i<this->totalStudents(); i++){
            if(this->s[i].getScore()>this->s[max].getScore())
            max = i;
        }
        getData(max);
    }
    void display(){
        for(int i=0; i<this->totalStudents(); i++){
            this->getData(i);
        }
    }
    int totalStudents(){
        return this->s.size();
    }
    void withSubstr(){
        string str;
        cout<<"Enter ur string value: ";
        cin>>str;
        for(int i=0,c=0; i<this->totalStudents(); i++){
            if(this->s[i].getName().find(str)!=string::npos){
                c++;
                cout<<"Found "<<c<<endl;
                getData(i);
                cout<<endl;
            }
        }
    }
    void withoutSubstr(){
        string str;
        cout<<"Enter ur string value: ";
        cin>>str;
        for(int i=0,c=0; i<this->totalStudents(); i++){
            if(!(this->s[i].getName().find(str)!=string::npos)){
                c++;
                cout<<"Found "<<c<<endl;
                getData(i);
                cout<<endl;
            }
        }
    }

};

// driver code
int main(){
    system("cls");
    int ch;
    studentList sList;
    cout<<"OPTIONS:\n1. Add Student\n2. Remove Student\n3. Display\n4. Highest Score\n5. Total students\n6. Find by string match\n";
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
                cout<<"Remove"<<endl;
                int index;
                cout<<"Enter index= ";
                cin>>index;
                sList.remove(index);
                break;
            case 3:
                cout<<"Display"<<endl;
                sList.display();
                break;
            case 4:
                cout<<"Highest Score"<<endl;
                sList.highestScore();
                break;
            case 5:
                cout<<"Total Students"<<endl;
                cout<<"count= "<<sList.totalStudents()<<endl;
                break;
            case 6:
                cout<<"String Matching"<<endl;
                sList.withSubstr();
                break;
            default:
                cout<<"WRONG!!! CHOICE"<<endl;
                // break;
        }
    }
    return 0;
}