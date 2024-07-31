#include<iostream>
#include<vector>

using namespace std;

int helpingFindPeak(vector<int> a, int start , int end){
    if(start>=end){
        return a[start];
    }
    int mid = (start+end)/2;
    int p = helpingFindPeak(a,start,mid);
    int q = helpingFindPeak(a,mid+1,end);
    if(p<=q){
        return q;
    }
    else
    return p;
}

int findPeakElement(vector<int> a, int size){

    int start = 0;
    int end = size-1;
    return helpingFindPeak(a, start, end);
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0; i<n; i++){
        int value;
        cin>>value;
        a.push_back(value);
    }

    cout<<"peak element: "<<findPeakElement(a,n)<<endl;
    return 0;
}
