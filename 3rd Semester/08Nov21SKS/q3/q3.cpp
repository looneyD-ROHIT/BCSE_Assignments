/*
Implement a class template for 1D array. Elements may be any basic data type. 
Provision to find maximum element, sum of the elements must be there.
*/
#include<bits/stdc++.h>
using namespace std;


template <typename T = int>
class oneDArray{
    T* arr;
    int len;
    public:
    oneDArray(int x=1){ 
        len = x;
        arr = new T[len];
    };
    oneDArray(oneDArray& c){
        this->arr=new T[c.length()];
        for(int i=0; i<c.length(); i++)
        this->arr[i] = c[i];
    }
    int length(){
        return len;
    }
    T operator[](int i){
        return this->arr[i];
    }
    T maxElement(){
        int size = this->length();
        T max = this->arr[0];
        for(int i=0; i<size; i++){
            if(this->arr[i]>max)
            max = this->arr[i];
        }
        return max;
    }
    T sumElements(){
        T sum = 0;
        int size = this->length();
        for(int i=0; i<size; i++){
            sum = sum + this->arr[i];
        }
        return sum;
    }
    void input(){
        cout<<"\nINPUT:\n";
        for(int i=0; i<this->length(); i++){
            cin>>this->arr[i];
        }
        cout<<endl;
    }
    void output(){
        cout<<"\nARRAY:\n";
        for(int i=0; i<this->length(); i++){
            cout<<this->arr[i]<<" ";
        }
        cout<<endl;
    }
    ~oneDArray(){
        cout<<"Destructor!"<<endl;
        delete[] this->arr;
    }
};
template<typename T>
ostream& operator<<(ostream& console, oneDArray<T> &obj ){
    console<<"\nARRAY:\n";
    for(int i=0; i<obj.length(); i++){
        console<<obj[i]<<" ";
    }
    console<<endl;
    return console;
}

int main(){
    system("cls");
    oneDArray<int> A(5);
    cout<<A.length()<<endl;
    A.input();
    // cout<<A;
    cout<<"MAX element=" <<A.maxElement()<<endl;
    cout<<"SUM element=" <<A.sumElements()<<endl;
    cout<<A;
    return 0;
}