#include<iostream>
#include<map>


using namespace std;

class A{
    int id;
    string name;
    float cg;


    public:

    A(int id, string name, float cg){
        this->id = id;
        this->name = name;
        this->cg = cg;
    }
};


int main(int argc, char const *argv[])
{
    map<int, A> m;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int id;
        string name;
        float cg;
        cin>>id>>name>>cg;
        A a(id, name, cg);
        m.insert(make_pair(id,a));
    }
    return 0;
}
