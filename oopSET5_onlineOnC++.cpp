#include <iostream>
#include <cmath>
#include <string>
#include<stdbool.h>
using namespace std;
// typedef long long int ll;

class Date
{
    int day, month, year;

public:
    Date()
    {
    }
    Date(int a, int b, int c)
    {
        day = a;
        month = b;
        year = c;
    }
    ~Date() {}
    void printDate()
    {
        cout << day << "-" << month << "-" << year << endl;
    }
    int compareDays(Date d)
    {
        int totalDays1 = day + (month - 1) * 30 + year * 365;
        int totalDays2 = d.day + (d.month - 1) * 30 + d.year * 365;
        if (totalDays1 == totalDays2)
            return 0;
        else if (totalDays1 > totalDays2)
            return -1;
        else
            return 1;
    }

    int numOfDays(Date d)
    {
        int totalDays1 = day + (month - 1) * 30 + year * 365;
        int totalDays2 = d.day + (d.month - 1) * 30 + d.year * 365;
        return abs(totalDays1 - totalDays2);
    }
};

class Event
{
    string eventName;
    Date start;
    Date end;

public:
    Event()
    {
        string temp;
        cout<<"event name:"<<endl;
        cin >> temp;
        eventName = temp;
        int day1, month1, year1;
        cout<<"starting date:"<<endl;
        cin >> day1 >> month1 >> year1;
        start = Date(day1, month1, year1);
        cout<<"ending date: "<<endl;
        cin >> day1 >> month1 >> year1;
        end = Date(day1, month1, year1);
    }

    ~Event(){}
    int duration(){
       int temp = start.numOfDays(end);
       return temp;
    }

    bool doesConflict(Event E){
        if(start.compareDays(E.end)==1||start.compareDays(E.end)==0)
        return true;
        else if(end.compareDays(E.start)==-1||end.compareDays(E.start)==0)
        return true;

        return false;
    }


};

// class EventList{
//     Event *event_arr;
//     int n;

//     public:
//     EventList(){
//         int value;
//         cin>>value;
//         n = value;
//         event_arr = new Event[n];
//     }
//     ~EventList(){
//         delete []event_arr;
//     }
    
// };

int main(int argc, char const *argv[])
{
    // int day1, month1, year1;
    // cin >> day1 >> month1 >> year1;
    // Date d1(day1, month1, year1);
    // cin >> day1 >> month1 >> year1;
    // Date d2(day1, month1, year1);
    // d1.printDate();
    // d2.printDate();
    // cout << d1.compareDays(d2) << endl;
    // cout << d1.numOfDays(d2) << endl;

    Event E1;
    Event E2;
    cout<<"duration "<<E1.duration()<<"days"<<endl;
    cout<<"conflict "<<E1.doesConflict(E2)<<endl;
    return 0;
}
