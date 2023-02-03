#include <iostream>
#include <math.h>
#include <stdbool.h>
#include "newyearcounter.hpp"

using namespace std;
  
bool checkLeapYear(int year) 
{ 
    if (year % 400 == 0) 
        return true; 
  
    if (year % 4 == 0 && year % 100 != 0) 
        return true;
 
    return false; 
} 

int dayinYear(date_now dt) {
    int s; // result
    for (int i = 1; i < dt.month; i++) {
        switch (i) {
            case 4:
            case 6:
            case 9:
            case 11:
                s += 30;
                break;
            case 2:
                if (checkLeapYear(dt.year) == true)
                    s += 29;
                else
                    s += 28;
                break;
            default:
                s += 31;
        }
    }
    return s;
}

float get_year_progress(int today, int daysofyear) {
    float onepercent = daysofyear / 100;
    return (float) today / onepercent;
}

int main() {
    newyear_time j;
    date_now dt;
    time_now tm2;

    int s = dayinYear(dt);
    int daysofyear = 365;

    if (checkLeapYear(dt.year) == true)
        daysofyear = 366;

    int daysremaining = daysofyear - s;
    int monthsremaining = (daysremaining%daysofyear)/30;
    float year_progress = roundf(get_year_progress(s, daysofyear) * 100) / 100;
    
    if (j.sc > 0)
        j.mn --;

    if (j.mn > 0)
        j.hr --;
    
    if (j.sc && j.mn > 0)
        daysremaining --;

    // Our current location
    cout << "The current local time is: " << asctime(ltm);
    cout << "This year " << dt.year << " is " << year_progress << "%" << " complete." << endl;

    // Date / Time remaining
    cout << "Next year " << dt.year + 1 << " starts after totally " << \
        daysremaining << " day(s), and about " << \
        j.hr << " hour(s) " << j.mn << " minute(s) " << j.sc << " second(s)." << endl;

    return 0;
}