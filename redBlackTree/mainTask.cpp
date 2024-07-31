#include"map.hpp"


int main(int argc, char const *argv[])
{
    freopen("rbtinputfile.txt","r",stdin);
    //freopen("rbtoutputfile.txt","w",stdout);
    Map m;
    while(true){
        string mode,value;
        int key;
        cin>>mode;
        if(mode=="I"){
            cin>>key>>value;
            m.insert(key,value);
        }
        else if(mode=="F"){
            cin>>key;
            m.find(key);
        }
        else if(mode=="S"){
            m.size();
        }
        else if(mode=="E"){
            cin>>key;
            m.erase(key);
        }
        else if(mode=="Em"){
            m.empty();
        }
        else if(mode == "Itr"){
            m.iteration();
        }
        else if(mode=="Clr"){
            m.clear();
        }
    }
    return 0;
}
