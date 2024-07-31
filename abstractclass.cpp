#include<iostream>
using namespace std;

class smartphone{
    int id;
    public:
    smartphone(int id){
        this->id=id;
    }
    int getid(){
        return id;
    }
    virtual void call()=0;
    virtual void sms()=0;
    virtual void camera()=0;

};

class android:public smartphone{
    public:
    android(int id):smartphone(id){}
    void call(){
        cout<<"calling from android"<<getid()<<endl;
    }
    void sms(){
        cout<<"sms from android"<<getid()<<endl;
    }
    void camera(){
        cout<<"camera from android"<<getid()<<endl;
    }
};

class ios:public smartphone{
    public:
    ios(int id):smartphone(id){}
    void call(){
        cout<<"calling from ios"<<getid()<<endl;
    }
    void sms(){
        cout<<"sms from ios"<<getid()<<endl;
    }
    void camera(){
        cout<<"camera from ios"<<getid()<<endl;
    }
};



int main(int argc, char const *argv[])
{
    smartphone *p=new android(123);
    p->call();
    p->sms();
    p->camera();

    
    return 0;
}
