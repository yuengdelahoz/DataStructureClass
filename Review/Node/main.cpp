#include<iostream>
#include "Node.h"
using namespace std;

int main (){
    Node<int> obj1;
    Node<double> tmp1;
    Node<double> obj2(4.0, &tmp1);
    Node<char> tmp2;
    Node<char> * obj3 = new Node<char>('d',&tmp2);
    Node<char> & obj4 = tmp2;
    cout << "ID " << obj1.getID() << " Data " <<  obj1.getData() << " Next " << obj1.getNext() << endl;
    cout << "ID " << obj2.getID() << " Data " <<  obj2.getData() << " Next " << obj2.getNext() << endl;
    cout << "ID " << obj3->getID() << " Data " <<  obj3->getData() << " Next " << obj3->getNext() << endl;
    cout << obj2.getNext()->getID() << endl;
    return 0;
}
