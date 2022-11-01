/*
Create an array of student objects where along with the support mentioned in
Q.1, one can remove an object with specific roll, sort the collection in the
descending order and show the same; two student collections can also be
combined. Take the help of suitable STL class.
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
// compare function
bool compFun(student& s1, student& s2){
    return (s1.getScore() > s2.getScore());
}
// student list to handle operations
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
    void remove(int roll){
        if(this->s.empty()){
            cout<<"List is empty!"<<endl;
            return;
        }
        for(int i=0; i<this->totalStudents(); i++){
            if(this->s[i].getRoll()==roll){
                cout<<"Roll found at index= "<<i<<endl;
                auto it = this->s.begin();
                // getData(i);
                this->s.erase(it+i);
            }
        }
        display();
    }
    // function to get details
    void getData(int i){
        if(this->s.empty()){
            cout<<"List is empty!"<<endl;
            return;
        }
        if(this->totalStudents()>i && i>=0){
            cout<<"Roll= "<<this->s[i].getRoll()<<endl;
            cout<<"Name= "<<this->s[i].getName()<<endl;
            cout<<"Roll= "<<this->s[i].getScore()<<endl;
            cout<<endl;
        }else{
            cout<<"index not valid!"<<endl;
        }
    }
    // function to print highest score
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
        if(this->s.empty()){
            cout<<"List is empty!"<<endl;
            return;
        }
        for(int i=0; i<this->totalStudents(); i++){
            this->getData(i);
        }
    }
    // function to sort by score
    void sortListByScore(){
        if(this->s.empty()){
            cout<<"List is empty!"<<endl;
            return;
        }
        sort(s.begin(),s.end(),compFun);
        display();
    }
    // function to combine two students as a pair
    void combine(int r1, int r2, pair<student,student> &temp){
        int i,j;
        for( i=0; i<this->totalStudents(); i++){
            if(r1==this->s[i].getRoll())
            break;
        }
        for(j=0; j<this->totalStudents(); j++){
            if(r2==this->s[j].getRoll())
            break;
        }
        if(i==this->totalStudents() || j==this->totalStudents()){
            cout<<"Cannot find any of the roll nos."<<endl;
            return;
        }
        temp = {s[i],s[j]};
        // temp = make_pair(s[i],s[j]);
    }
    int totalStudents(){
        return this->s.size();
    }
    

};

// driver code
int main(){
    system("cls");
    int ch;
    studentList sList;
    pair<student,student> temp;
    cout<<"OPTIONS:\n1. Add Student\n2. Remove Student by roll\n3. Display\n4. Highest Score\n5. Total students\n6. Sort\n7. Combine i and j\n";
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
                int roll;
                cout<<"Enter roll= ";
                cin>>roll;
                sList.remove(roll);
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
                cout<<"Sorting"<<endl;
                sList.sortListByScore();
                break;
            case 7:
                cout<<"Combine"<<endl;
                int r1, r2;
                cout<<"Enter roll= ";
                cin>>r1>>r2;
                sList.combine(r1,r2,temp);
                cout<<"first= "<<temp.first.getName()<<endl; 
                cout<<"second= "<<temp.second.getName()<<endl; 
                break;
            default:
                cout<<"WRONG!!! CHOICE"<<endl;
                // break;
        }
    }
    return 0;
}