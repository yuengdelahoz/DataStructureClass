#include "SLinkedList.h"

int main(){
    SLinkedList<double> lst; // List created
    // Example number 1. Using a dummy function. Function returns an integer.
    try{
        int a = lst.dummyfunc(0);// function is supposed to throw an underflow exception because of the parameter being passed. See dummyfunc implementation in the SLinkedList.h file
    }catch(const underflow_error& e){}

    //Example Number 2. Using the del function in list. Function returns nothing (void).
    try{
        lst.del(4.3);// Attempting to delete. You can't, the list is empty. Function is supposed to throw an underflow exception. See implementation in the SLinkedList.h file
    }
    catch(const underflow_error& e){
        cout << "caught " << e.what() << '\n';
    }
    cout << "bye" << endl;
    return 0;
}
