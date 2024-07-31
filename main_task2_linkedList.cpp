#include"listLL1.cpp"
//#include"listArr1.cpp"

int main(int argc, char const *argv[])
{
     int func_num,par;
    L.init();
    
    
  
       
   
    cin>>func_num;
    
    if(func_num==0){
        return 1;
    }
    else if(func_num==2 | func_num==3){
        
        cin>>par;
    }
    else if(func_num>3){
        cout<<"invalid input";
        return 1;
    }
    L.display();
    int z;
    switch(func_num){
        case 1:
        z=L.clear();
        L.display();
        cout<<z;
        break;

        case 2:
        z = L.append(par);
        L.display();
        cout<<z;
        break;
        case 3:
        
        L.display();
        cout<< L.search(par);;
        break;
        default:
        cout<<"invalid input"<<endl;
        break;
    }
    
    return 0;
}
