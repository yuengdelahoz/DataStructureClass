#include "Node.h"
#include<iostream>
using namespace std;

int main(){
    Node<char> n1;
    Node<double> n2(2.4);
    Node<double> n3(3.4, &n2);
    cout << n1.data << endl;
    cout << n1.ID << endl;
    cout << n2.ID << endl;
    cout << n3.ID << endl;
    cout << n2.data << endl;
    cout << n3.data << endl;
    cout << n3.next << endl;
    cout << &n2 << endl;
    cout << "Done " << endl;
    return 0;
}
