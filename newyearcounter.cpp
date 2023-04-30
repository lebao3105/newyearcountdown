#include <iostream>
#include <math.h>
#include <stdbool.h>
#include "newyearcounter.hpp"

using namespace std;

int checkLeapYear(int year)
{
    return (year % 4 == 0 && year % 100) || (year % 400 == 0);
}

int dayinYear(date_now dt)
{
    int s = dt.day;

    for (int i = 1; i < dt.month; i++)
    {
        switch (i)
        {
        case 4:
        case 6:
        case 9:
        case 11:
            s += 30;
            break;
        case 2:
            s += 28 + checkLeapYear(dt.year);
            break;
        default:
            s += 31;
        }
    }
    return s;
}

double get_year_progress(int today, int daysofyear)
{
    double per = (double) today / daysofyear * 100;
    return per;
}

int main()
{
    newyear_time j;
    date_now dt;
    time_now tm2;

    int s = dayinYear(dt);
    int daysofyear = 365 + checkLeapYear(dt.year);
    int daysremaining = daysofyear - s;
    int monthsremaining = (daysremaining % daysofyear) / 30;
    double year_progress = get_year_progress(s, daysofyear);

    if (j.sc > 0)
        j.mn--;

    if (j.mn > 0)
        j.hr--;

    // Our current location
    cout << "This program started on : " << asctime(ltm);
    cout << "This year " << dt.year << " is " << year_progress << "%"
         << " complete." << endl;

    // Date & Time remaining
    cout << "Next year " << dt.year + 1 << " starts after totally "
        << daysremaining << " day(s), and about "
        << j.hr << " hour(s) " << j.mn << " minute(s) " << j.sc << " second(s)."
        << endl;
    return 0;
}
