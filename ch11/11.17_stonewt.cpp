// stonewt.cpp -- Stonewt methods
#include <iostream>
using std::cout;
#include "11.16_stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs){
    stone = int(lbs) / Lbs_per_stn; // integer division
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs){
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

// default constructor, wt = 0
Stonewt::Stonewt(){
    stone = pounds = pds_left = 0;
}

// destructor
Stonewt::~Stonewt(){

}

// show weight in pounds
void Stonewt::show_lbs() const{
    cout << pounds << " pounds\n";
}

// show weight in stones
void Stonewt::show_stn() const{
    cout << stone << " stone, " << pds_left << " pounds\n";
}