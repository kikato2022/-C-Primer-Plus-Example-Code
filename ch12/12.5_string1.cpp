// string1.cpp -- String class methods
#include<cstring>
#include"12.4_string1.h"
using std::cin;
using std::cout;

int String1::num_strings = 0;

int String1::HowMany(){
    return num_strings;
}

// class methods
String1::String1(const char * s){
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str,s);
    num_strings++;
}

String1::String1(){
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String1::String1(const String1 & st){
    len = st.len;
    str = new char[len+1];
    std::strcpy(str,st.str);
    num_strings++;
}

String1::~String1(){
    --num_strings;
    delete [] str;
}

String1 & String1::operator=(const String1 & st){
    if(this == &st){
        return *this;
    }
    delete [] str;
    len = st.len;
    str = new char[len+1];
    std::strcpy(str,st.str);
    return *this;
}

String1 & String1::operator=(const char * s){
    delete [] str;
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str,s);
    return *this;
}


char & String1::operator[](int i){
    return str[i];
}

const char & String1::operator[](int i) const{
    return str[i];
}

bool operator<(const String1 & st1, const String1 & st2){
    return (std::strcmp(st1.str, st2.str)<0);
}

bool operator>(const String1 & st1, const String1 & st2){
    return (std::strcmp(st1.str, st2.str)>0);
}

bool operator==(const String1 & st1, const String1 & st2){
    return (std::strcmp(st1.str, st2.str)==0);
}

ostream & operator<<(ostream & os, const String1 & st){
    os << st.str;
    return os;
}

istream & operator>>(istream  & is, String1 & st){
    char temp[String1::CINLIM];
    is.get(temp, String1::CINLIM);
    if(is){
        st = temp;
    }
    while(is&&is.get()!='\n') continue;
    return is;
}


