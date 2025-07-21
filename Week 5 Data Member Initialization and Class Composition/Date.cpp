#include <iostream>
#include "Date.h" // include user defined header file - Date class definition
using namespace std;

// constructor confirms proper value for month; calls utility function checkDay to confirm proper value for Day
Date::Date(int mn, int dy, int yr){
    if(mn > 0 && mn <= monthsPerYear) // validate the month mn
        month = mn;
    else {
        month = 1; // invalid month set to 1
        cout << "Invalid Month (" << mn << ") set to 1." << endl;
    }
    year = yr; // could validate year
    day = checkDay(dy); // validate the day

    // output Date object to show when its constructor is called
    cout << "Date object constructor for date ";
    print();
    cout << endl;
}

// Print Date object in the form of Month/Date/Year Format
void Date::print() const{
    cout << month << '/' << day << '/' << year;
}

// Output Date to show when it's Destructor is called
Date::~Date(){
    cout << "Date object destructor for date ";
    print();
    cout << endl;
}

// Utility function to confirm proper Day value based on the month and year; Handles Leap Years too
int Date::checkDay(int testDay)const{
    static const int daysPerMonth[monthsPerYear + 1] = {0 , 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Determine whether testDay is valid for specified month
    if(testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;

    //Feb 29, check for leap year
    if(month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        return testDay;

    cout << "Invalid day (" << testDay << ") set to 1.\n";
    return 1; // leave object in consistent state if bad value
}
bool Date::beforeDate(const Date & xDate) const
{
    if(this->year < xDate.year){
        return true;
    }
    else if(this->year == xDate.year){
        if(this->month < xDate.month){
            return true;
        }
        else if(this->month == xDate.month){
            if(this->day < xDate.day){
                return true;
            }
            else if(this->day == xDate.day){
                return true;
            }
        }
    }
    else
        return false;
}
bool Date::afterDate(const Date & xDate) const
{
    if(this->year > xDate.year){
        return true;
    }
    else if(this->year == xDate.year){
        if(this->month > xDate.month){
            return true;
        }
        else if(this->month == xDate.month){
            if(this->day > xDate.day){
                return true;
            }
            else if(this->day == xDate.day){
                return true;
            }
        }
    }
    else
        return false;
}
