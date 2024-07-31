#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int test;
    cin>>test;
    while(test--){
        vector<vector<char>> v;
        for(int i=0; i<8; i++){
            vector<char> v1;
            for(int j=0; j<8; j++){
                char c;
                cin>>c;
                v1.push_back(c);
                
            }
            v.push_back(v1);
        }

        for(int i =0; i<8; i++){
            for(int j=0; j<8; j++){
                if(v[i][j]!='.'){
                    cout<<v[i][j];
                }
            }
        }
        cout<<endl;
    }
    
    return 0;
}
