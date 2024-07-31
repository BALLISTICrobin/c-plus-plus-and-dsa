/*
In a candy store, there are N different types of candies available and the prices of all the N different types of candies are provided to you.
You are now provided with an attractive offer.
For every candy you buy from the store and get at most K other candies ( all are different types ) for free.
Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have to spend to buy all the N different candies. Secondly, you have to find what is the maximum amount of money you have to spend to buy all the N different candies.
In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.*/
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int typesOfCandies,free;
    cin>>typesOfCandies>>free;
    vector<int> candies;
    for(int i=0; i<typesOfCandies; i++){
        int price;
        cin>>price;
        candies.push_back(price);
    }

    int minAmountOfMoney=0,maxAmountOfMoney=0;
    sort(candies.begin(),candies.end());
    
    int startIndex = 0;
    int endIndex = candies.size()-1;
    while(startIndex<=endIndex){
        minAmountOfMoney += candies.at(startIndex);
        int k=0;
        while(endIndex>startIndex && k<free){
            
            endIndex--;
            k++;
        }
        startIndex++;
    }  
    endIndex = 0;
     startIndex = candies.size()-1;
    while(startIndex>=endIndex){
        maxAmountOfMoney += candies.at(startIndex);
        int k=0;
        while(endIndex<startIndex  && k<free){
            
            endIndex++;
            k++;
        }
        startIndex--;
    }  
    cout<<"min amount of money: "<<minAmountOfMoney<<endl;
    cout<<"max amount of money: "<<maxAmountOfMoney<<endl;

    return 0;
}
