/*
Ishika got stuck on an island. There is only one shop on this island and it is open on all days of the week except for Sunday. Consider following constraints:

N – The maximum unit of food you can buy each day.
S – Number of days you are required to survive.
M – Unit of food required each day to survive.
Currently, it’s Monday, and she needs to survive for the next S days.
Find the minimum number of days on which you need to buy food from the shop so that she can survive the next S days, or determine that it isn’t possible to survive.*/
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int maxFoodPerDay,daysToSurvive,foodRequiredPerDay;
    cin>>maxFoodPerDay>>daysToSurvive>>foodRequiredPerDay;
    int sundays = daysToSurvive/7;
    int remainingDays = daysToSurvive - sundays;

    int totalFood = daysToSurvive*foodRequiredPerDay;
    int ans = 0;
    if(totalFood%maxFoodPerDay==0){
        ans = totalFood/maxFoodPerDay;
    }
    else{
        ans = totalFood/maxFoodPerDay+1;
    }

    if(ans <= remainingDays){
        cout<<ans<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    
    return 0;
}
