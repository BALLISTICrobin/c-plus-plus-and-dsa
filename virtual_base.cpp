#include<iostream>
using namespace std;

class Student{
    protected:
    int roll_num;
    public:
    void set_roll_number(int num){
        roll_num = num;
    }
    void dispalay_number(){
        cout<<roll_num<<endl;
    }
};

class Marks: virtual public Student{
    protected:
    float maths,physics;

    public:
    void set_marks(float a, float b){
        maths = a;
        physics = b;
    }

    void display_marks(){
        cout<<maths<<endl<<physics<<endl;
    }
};

class PT: virtual public Student{
    protected:
    float score;
    
    public:
    void set_score(float v){
        score = v;
    }
    void display_score(){
        cout<<score<<endl;
    }
};

class Result: public Marks, public PT{
    float result;

    public:
    
    void display_result(){
        result = physics + maths + score;
        cout<<result<<endl;
        dispalay_number();
        display_marks();
        display_score();
    }

    
};

int main(int argc, char const *argv[])
{
    Result std1;
    std1.set_roll_number(2105019);
    std1.set_marks(89.6,94.78);
    std1.set_score(9);
    std1.display_result();
    return 0;
}
