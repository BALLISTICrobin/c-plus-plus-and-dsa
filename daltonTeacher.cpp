#include<iostream>
#include<map>

using namespace std;

int main()
{
    

    int test;
    cin>>test;
    while(test--){
        map<int,int> m;
        int n;
        cin>>n;
        int i=0;
        while(n--){
            int value;
            cin>>value;
            i++;
            m[i] = value;
        }
        
        int count=0;
        for(auto it1=m.begin(); it1!=m.end();it1++){
            if(it1->first == it1->second){
                
                count++;
            }
        }
        if(count%2==0){
            cout<<count/2<<endl;
        }
        else
        {
            cout<<(count/2)+1<<endl;
        }


    }
    return 0;
}
