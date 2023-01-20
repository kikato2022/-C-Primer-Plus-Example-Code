// stacktem.cpp -- testing the template stack class
#include<iostream>
#include<string>
#include<cctype>

#include"14.13_stacktp.h"

using std::cin;
using std::cout;


int main(){
    Stack<std::string> st;      // create an empty stack
    char ch;
    std::string po;
    cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
    while(cin>>ch && std::toupper(ch)!='Q'){
        while ( cin.get() != '\n' )
            continue;
        if (!std::isalpha(ch)){
            cout << '\a';
            continue;
        }
        switch(ch){
            case 'A':
            case'a':    cout << "Enter a PO number to add: ";
                        cin >> po;
                        if (!st.push(po)){
                            cout << "stack already full\n";
                        }
                        break;
            case 'P':
            case 'p':   if (!st.pop(po)){
                            cout << "stack already empty\n";
                        }
                        else{
                            cout << "P0 #" << po << " popped\n";
                        }
                        break;
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}