// error5.cpp -- unwinding the stack

#include<iostream>
#include<cmath> // or math.h, unix users may need -lm flag
#include<string>

#include"15.10_exc_mean.h"

class Demo{
private:
    std::string word;
public:
    Demo(const std::string & str){
        word = str;
        std::cout << "Demo " << word << " created\n";
    }
    ~Demo(){
        std::cout << "Demo " << word << " destroyed\n";
    }
    void show() const{
        std::cout << "Demo " << word << " lives!\n";
    }
};

// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main(){
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    {
        Demo d1("found in block in main()");
        cout << "Enter two numbers: ";
        while(cin>>x>>y){
            try{    // start of try block
                z = means(x, y);
                cout << "The mean mean of " << x << " and " << y
                     << " is " << z << endl;
            }   // end of try block
            catch (bad_hmean & bh){  // start of catch block
                bh.mesg();
                cout << "Try again.\n";
                continue;
            } 
            catch (bad_gmean & bg){ 
                cout << bg.mesg();
                cout << "Values used: " << bg.v1 << ", "
                     << bg.v2 << endl;
                cout << "Sorry, you don't get to play any more.\n";
                break;
            }   // end of catch block
        }
        d1.show();
    }
    cout << "Bye!\n";
    cin.get();
    cin.get();
    return 0;
}

double hmean(double a, double b){
    if (a==-b)
        throw bad_hmean(a,b);
    return 2.0 * a * b / ( a + b);
}

double gmean(double a, double b){
    if (a<0||b<0){ 
        throw bad_gmean(a,b);
    }
    return std::sqrt(a * b);
}

double means(double a, double b){
    double am, hm, gm;
    Demo d2("found in means()");
    am = (a+b)/2.0;     // arithmetic mean
    try{
        hm = hmean(a,b);
        gm = gmean(a,b);
    }
    catch (bad_hmean & bh){
        bh.mesg();
        std::cout << "Caught in means()\n";
        throw;      // rethrow the exception
    }
    d2.show();
    return (am+hm+gm)/3.0;
}