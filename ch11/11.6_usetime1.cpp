// usetime1.cpp -- using the second draft of the Time class
// compile usetime1.cpp and mytime1.cpp together
#include<iostream>
#include"11.4_mytime1.h"

int main(){
    using std::cout;
    using std::endl;

    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = " ;
    planning.Show();

    cout << "coding time = ";
    coding.Show();

    cout << "fixing time = ";
    fixing.Show();

    total = coding + fixing;

    cout << "coding + fixing = ";
    total.Show();

    Time morefixing(3, 28);
    cout << "more fixing time = ";
    morefixing.Show();

    total = morefixing.operator+(total);
    // function notation
    cout << "morefixing.operator+(total) = ";
    total.Show();

    return 0;
}