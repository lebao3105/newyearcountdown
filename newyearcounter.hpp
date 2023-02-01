#pragma "once"

#include <ctime>

time_t now = time(0);
tm *ltm = localtime(&now);

struct date_now
{
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
};

struct time_now {
    int hour = ltm->tm_hour;
    int min = ltm->tm_min;
    int sec = ltm->tm_sec;
};

struct newyear_time
{
    time_now currtm;
    int hr = 24-currtm.hour;
    int mn = 60-currtm.min;
    int sc = 60-currtm.sec;
};