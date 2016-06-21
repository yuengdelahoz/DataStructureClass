#include<iostream>
#include "Test.h"
using namespace std;

int main(){
    Test obj1;
    Test obj2(4,&obj1);
    Test * obj3 = new Test(10,&obj2);
    cout << "Obj" << obj1.getID()<<" is in Address " << &obj1 << " And its next neighbor is " << obj1.getNext() << endl;
    cout << "Obj" << obj2.getID()<<" is in Address " << &obj2 << " And its next neighbor is " << obj2.getNext() << endl;
    cout << "Obj" << obj3->getID()<<" is in Address " << obj3 << " And its next neighbor is " << obj3->getNext() << endl;
    return 0;
}
