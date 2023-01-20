// frnd2tmp.cpp -- template class with non-template friends

#include <ctime>
#include<iostream>
using std::cout;
using std::endl;

template<typename T>
class HasFriend{
private:
    T item;
    static int ct;
public:
    HasFriend(const T & i) : item(i) { ct++; }
    ~HasFriend() { ct--; }
    friend void counts();
    friend void report(HasFriend<T> &); // template parameter
};

// each specialization has its own static data member
template<typename T>
int HasFriend<T>::ct = 0;

// non-template friend to all HasFriend<T> classes
void counts(){
    cout << "int count: " << HasFriend<int>::ct << "; ";
    cout << "double count: " << HasFriend<double>::ct << endl;
}

// non-template friend to the HasFriend<int> class
void report(HasFriend<int> & hf){
    cout << "HasFriend<int>: " << hf.item << endl;
}

// non-template friend to the HasFriend<double class
void report(HasFriend<double> & hf){
    cout << "HasFriend<double>: " << hf.item << endl;
}

int main(){
    cout << "No objects declared: ";
    counts();
    HasFriend<int>hfil(10);
    cout <<"After hfil declared: ";
    counts();
    HasFriend<int>hfil2(20);
    cout << "After hfil2 declared: ";
    counts();
    HasFriend<double>hfdb(10.5);
    cout << "After hfdb declared: ";
    counts();
    report(hfil);
    report(hfil2);
    report(hfdb);

    return 0;

}
