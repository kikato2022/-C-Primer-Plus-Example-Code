// mytime3.cpp -- implementing Time methods

#include"11.10_mytime3.h"


Time::Time(){
    hours = minutes = 0;
}


Time::Time(int h, int m){
    hours = h;
    minutes = m;
}


void Time::AddMin(int m){
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::Reset(int h, int m){
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time &t) const{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time & t) const{
    Time diff;
    int tot1, tot2;
    tot1 = minutes + hours * 60;
    tot2 = t.minutes + t.hours * 60;
    diff.minutes = (tot1 - tot2) % 60;
    diff.hours = (tot1 - tot2) / 60;
    return diff;
}

Time Time::operator*(double mult) const{
    Time result;
    long totalminutes = hours * mult * 60 + minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t){
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}