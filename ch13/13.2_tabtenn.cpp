// tabtenn.cpp -- simple base-class methods
#include "13.1_tabtenn.h"
#include<iostream>

TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool ht) : 
        firstname(fn), lastname(ln), hasTable(ht){

}

void TableTennisPlayer::Name() const{
    std::cout << lastname << ", " << firstname;
}
