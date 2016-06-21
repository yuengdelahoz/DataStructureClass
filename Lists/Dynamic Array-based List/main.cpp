#include "DAlist.h"
#include<algorithm>
#include<vector>

int main(){
    DAlist<char> Dlist;
    DAlist< vector<double> > D2list;
    cout << "List empty? "<< (Dlist.isEmpty()?"Yes":"No")<< endl;
    int pos = 0;
    Dlist.insert('z');
    Dlist.printList();
    Dlist.insert(0,'a');
    Dlist.printList();
    Dlist.insert(1,'b');
    Dlist.printList();
    Dlist.insert(2,'c');
    Dlist.printList();

    Dlist.insert(-1,'c');// Position does not exist in the array.

    Dlist.insert('x');
    Dlist.printList();
    Dlist.insert('b');
    Dlist.printList();
    // vector<double> d;
    // D2list.insert(d);
    Dlist.del('b');
    cout << "List empty? "<< (Dlist.isEmpty()?"Yes":"No")<< endl;
    return 0;
}
