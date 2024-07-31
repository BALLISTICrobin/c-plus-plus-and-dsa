#include<iostream>
#include<algorithm>

using namespace std;

int TotalValue(int n, vector<int> weight, vector<int> price, vector<double> pricePerWeight,int capacity){
  int p = pricePerWeight[0];
  int ans = price[0];
  int remaining_weight = capacity - weight[0];
    for(int i=1; i<n; i++){
        if(remaining_weight >= weight[i]){
            ans += price[i];
            remaining_weight -= weight[i];
        }
        else{
            ans += pricePerWeight[i]*remaining_weight;
            break;
        }
    }

} 

int main(int argc, char const *argv[])
{
    int n;
    vector<int> weight;
    vector<int> price;
    vector<double> pricePerWeight;
    cin>>n;
    for(int i=0; i<n; i++){
        int w,p;
        cin>>w>>p;
        weight.push_back(w);
        price.push_back(p);
        pricePerWeight.push_back(double(p)/double(w));
    }
    int capacity;
    cin>>capacity;
    sort(pricePerWeight.begin(),pricePerWeight.end(),greater<double>());
    cout<<TotalValue(n,weight,price,pricePerWeight,capacity)<<endl;
    


    return 0;
}
