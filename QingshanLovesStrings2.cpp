#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
    /* code */
    ll test;
    cin>>test;
    while(test--){
        int len;
        string s;
        cin>>len>>s;
        if(len%2!=0){
            cout<<-1<<endl;
            continue;
        }
        
        deque<char> q;
        for(auto i:s){
            q.push_back(i);
        }
        int a = q.front();
        int b = q.back();
        int operation = 0;
        int front_pos =0;
        int rear_pos = len;
        vector<ll> pos;
        while(!q.empty()){
            if(a==b){
                if(a=='0'){
                    q.push_back('0');
                    q.push_back('1');
                    pos.push_back(rear_pos);
                    rear_pos+=2;
                }else{
                    q.push_front('1');
                    q.push_front('0');
                    pos.push_back(front_pos);
                    
                }
                a = q.front();
                b = q.back();
                operation++;
            }
            else{
                front_pos++;
                rear_pos--;
                q.pop_front();
                q.pop_back();
                a = q.front();
                b = q.back();
            }
            if(operation>300){
                cout<<-1<<endl;
                break;
            }
        }
        if(operation<=300){
            cout<<operation<<endl;
            for(auto i:pos){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    
    return 0;
}

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
// typedef long long ll;

// int main() {
//     ll test;
//     cin >> test;
//     while (test--) {
//         int len;
//         string s;
//         cin >> len >> s;
//         if (len % 2 != 0) {
//             cout << -1 << endl;
//             continue;
//         }
//         int count = 0;
//         vector<ll> pos;
//         for (int i = 0; i < len / 2; ++i) {
//             if (s[i] == s[len - i - 1]) {
//                 if (s[i] == '0') {
//                     s.insert(i * 2 + 1, "01");
//                     pos.push_back(i * 2 + 1);
//                 } else {
//                     s.insert(i * 2, "01");
//                     pos.push_back(i * 2);
//                 }
//                 count++;
//             }
//             if (count > 300) {
//                 cout << -1 << endl;
//                 break;
//             }
//         }
//         if (count <= 300) {
//             cout << count << endl;
//             for (auto i : pos) {
//                 cout << i << " ";
//             }
//             cout << endl;
//         }
//     }

//     return 0;
// }
