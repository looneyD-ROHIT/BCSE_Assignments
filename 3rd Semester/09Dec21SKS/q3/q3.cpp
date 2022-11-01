/*
Students come to mark sheet collection desk and are served in first come first
served basis. Implement the scenario. Take the help of suitable STL class.
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
// student list class to handle various operations
class studentList{
    vector<student> s;
    public:
    studentList(){
        this->s.reserve(100);
    };
    // function to add student
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
    // function to remove student
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
    // function to get details
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
    // function to get highest score
    void highestScore(){
        int i;
        float max = 0;
        for(i=1; i<this->totalStudents(); i++){
            if(this->s[i].getScore()>this->s[max].getScore())
            max = i;
        }
        getData(max);
    }
    // function to display details
    void display(){
        for(int i=0; i<this->totalStudents(); i++){
            this->getData(i);
        }
    }
    // function to return total students
    int totalStudents(){
        return this->s.size();
    }
    // function to match substring
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
    // function to match not present substring
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

// marksheet class to view the results
class markSheet{
    private:
        // using queue to queue the students who come to collect marksheet
        queue<student> marksDist;
    public:
        markSheet(){};
        // add student
        void add(student s){
            marksDist.push(s);
        }
        // issue marksheet
        void issue(){
            if(!marksDist.empty()){
                cout<<"Marksheet issue to student:"<<endl;
                student temp = marksDist.front();
                cout<<"Roll= "<<temp.getRoll()<<endl;
                cout<<"Name= "<<temp.getName()<<endl;
                cout<<"Roll= "<<temp.getScore()<<endl;
                cout<<endl;
                marksDist.pop();
                return;
            }
            cout << "MarkSheet List empty!" << endl;
        }
        
};



int main(){
    system("cls");
    int ch;
    // studentList sList;
    markSheet m;
    // hardcoded these values, operation results will be based on these
    m.add({100,"rohit",98});
    m.add({200,"rohan",99});
    m.add({300,"rik",97});
    m.issue();
    m.issue();
    m.issue();
    m.issue();
    return 0;
}