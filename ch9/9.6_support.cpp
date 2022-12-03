// support.cpp -- use external variable
// compile with external.cpp
#include<iostream>
extern double warming;  // use warming from another file

using std::cout;
void update(double dt){
    extern double warming;
    warming += dt;
    cout << "Updating global warming to " << warming;
    cout << " degrees.\n";
}

void local(){
    double warming = 0.8;   // new variable hides external one
    cout << "Local warming = " << warming << " degrees.\n";
    cout << "But global warming = " << ::warming;
    cout << " degrees.\n";
}