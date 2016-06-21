#include "SLinkedList.h"

int main(){
    SLinkedList<char> lst;
    cout << "Is the list empty ? "<< (lst.isEmpty()?"Yes":"No") <<endl;
    lst.insert('Y');
    lst.insert('U');
    lst.insert('E');
    lst.insert('N');
    lst.insert('G');
    cout << "Is the list empty ? "<< (lst.isEmpty()?"Yes":"No") <<endl;
    lst.printLst();
    return 0;

}
