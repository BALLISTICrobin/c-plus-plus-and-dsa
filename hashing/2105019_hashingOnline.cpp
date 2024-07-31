#include"doubleHashing.hpp"
#include<algorithm>

bool isPrime(ll num)
{
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;

    for (long long i = 5; i * i <= num; i += 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return false;

    return true;
}

long long nextPrime(ll num)
{
    while (true)
    {
        if (isPrime(num))
            return num;
        num++;
    }
}

string reverseComplement(string s){
    // std::cout<<"hi";
    int len = s.length();
    string rc="";
    int j=0;
    for(int i=len-1; i>=0 ; i--){
        if(s.at(i)=='A'){
            rc+= 'T';
        }
        else if(s.at(i)=='T'){
            rc+= 'A';
        }
        else if(s.at(i) == 'G'){
            rc+= 'C';
        }
        else if(s.at(i)=='C'){
            rc+= 'G';
        }
        j++;
        
    }
    return rc;
}

int main(int argc, char const *argv[])
{
    int n,l;
    std::cin>>n>>l;
    Doublehashing table1(n,2);
    vector<string> revCompl;
    Doublehashing table2(n,2);
    for(int i=0; i<n; i++){
        string seq;
        std::cin>>seq;
        // cout<<"hi";
        string revComple = reverseComplement(seq);
        revCompl.push_back(revComple);
        table1.insert(seq,table1.size+1);
        //table2.insert(revComple,table2.size+1);
    }

    for(auto i: revCompl){
        string s =reverseComplement(i);
        string s2 ="";
        pair<string,ll> p = table1.find(i);
        if(p.second!=-1 ){
            s2 = p.first;
            if(s!=s2)
            cout<<s<<" "<<s2<<endl;
        }
    }

    return 0;
}
