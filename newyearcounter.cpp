#include <iostream>
#include "newyearcounter.hpp"

using namespace std;

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
                s += 28 + (dt.year % 4 == 0 && dt.year % 100) || (dt.year % 400 == 0);
                break;
            default:
                s += 31;
        }
    }
    return s;
}


int main() {
    newyear_time j;
    date_now dt;
    time_now tm2;

    int s = dayinYear(dt);
    int daysremaining = 365 - s;
    int monthsremaining = (daysremaining%365)/30;
    float year_progress = s / 3.65;

    // cout << s;
    // cout << daysremaining;
    cout << "The current local time is: " << asctime(ltm);
    cout << "This year " << dt.year << " is " << year_progress << "%" << " complete." << endl;
    cout << "Next year " << dt.year + 1 << " starts after totally " << \
        daysremaining << " day(s)." << endl;
    return 0;
}