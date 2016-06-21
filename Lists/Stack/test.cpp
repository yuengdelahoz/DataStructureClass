#include "mStack.h"

int main(){
    mStack<char> stck;
    cout << "Is stack empty? "<< (stck.isEmpty()?"yes":"no")<< endl;
    stck.push('Y');
    stck.push('U');
    stck.push('E');
    stck.push('N');
    stck.push('G');
    stck.display();
    cout << "Is stack empty? "<< (stck.isEmpty()?"yes":"no")<< endl;
    try{
        cout << "Top is-->" << stck.top()<< endl;
    }catch(const underflow_error& ex){
        cerr << "error: " << ex.what() << endl;
    }

    try {
        cout << "Popping from stack-->" << stck.pop()<< endl;
    }catch(const underflow_error& ex){
        cerr << "error: " << ex.what() << endl;
    }
    stck.display();
    return 0;
}
