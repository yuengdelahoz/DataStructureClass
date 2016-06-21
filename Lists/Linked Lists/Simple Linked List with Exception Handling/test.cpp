#include "SLinkedList.h"

int main(){
    SLinkedList<char> lst;
    cout << "Is list empty ? "<< (lst.isEmpty()?"Yes":"No") << endl;
    lst.insert('y');
    lst.insert('u');
    lst.insert('e');
    lst.insert('n');
    lst.insert('g');
    cout << "Is list empty ? "<< (lst.isEmpty()?"Yes":"No") << endl;
    lst.printList();
    lst.insert('D',-1);
    lst.printList();
    cout << "List size " << lst.getSize() << endl;
    lst.insert('Z',100);
    lst.printList();
    lst.insert('O',3);
    lst.insert('O',0);
    lst.insert('O',100);
    lst.printList();
    lst.del('O');
    lst.printList();
    lst.del('D');
    lst.del('Z');
    lst.printList();
    return 0;
}
