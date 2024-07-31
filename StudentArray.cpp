#include<iostream>
using namespace std;

class Student{
    int id;
    static int count;
    
    public:
    Student(){
        count++;
        this->id = count;
    }

    int getId(){
        return id;
    }
    

};
int Student::count =0;


int main(int argc, char const *argv[])
{
    Student *arr = new Student[120];//creating 120 objects of student class, 
    //count is the property of class

    for(int i=0; i<120; i++){
        cout<<arr[i].getId()<<endl;
    }

    return 0;
}

