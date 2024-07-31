
//#include "listArr1.cpp"
#include "listLL1.cpp"


int main(int argc, char const *argv[])
{
      int func_num,par,test;
    L.init();
   
   
  
       
   
    cin>>func_num;
    
    if(func_num==0){
        return 1;
    }
    else if(func_num==1 || func_num == 9){
        
        cin>>par;
    }
   
    L.display();
    int z;
    switch (func_num)
    {
    case 1:
        z=L.insert(par);
        L.display();
        cout<<z;
        break;
    case 2:
        z=L.remove();
        L.display();
        cout<<z;
        break;
    case 3:
        z=L.moveToStart();
        L.display();
        cout<<z;
        break;
    case 4:
         z=L.moveToEnd();
        L.display();
        cout<< z;
        break;
    case 5:
        z=L.prev();
        L.display();
       cout<< z;
        break;
    case 6:
        z = L.Next();
        L.display();
        cout<<z;
        break;

    case 7:
        L.display();
        
        cout<<L.length();
        break;

    case 8:
        L.display();
        cout<<L.currPos();
        break;
    case 9:
        z=L.moveToPos(par);
        L.display();
        cout<<z;
        break;
    
    case 10:
        L.display();
        cout<<L.getValue();
        break;

    default:
        cout<<"invalid input";
        break;
    }
    
    return 0;
}
