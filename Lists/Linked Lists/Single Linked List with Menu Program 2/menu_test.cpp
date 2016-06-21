#include "SLinkedList.h"

int main(){
    int op = 0;
    bool flag = false;
    SLinkedList<char> lst;
    while(true){
        cout << "******Menu Program******" << endl;
        cout << "Please select an option." << endl;
        cout << "1. Create List." << endl;
        cout << "2. Insert Element." << endl;
        cout << "3. Delete Element." << endl;
        cout << "4. Print List." << endl;
        cout << "5. Exit." << endl;
        cout << "--> ";
        cin >> op;
        if (op==5) break;
        else if (op==1){
            flag = true;
            cout << endl << "List created." << endl;
        }
        else if (op==2){
            if (!flag) {
                cerr << endl << "Cannot insert element. List has not been created yet." << endl;
            }
            else {
                char data;
                cout << "Enter value to be inserted" << endl;
                cin >> data;
                int op_i;
                cout << "Do you want insert element in a specific postions ?(1.Yes, 2.No)\n-->";
                cin >> op_i;
                if (op_i==1){
                    int pos;
                    cout << "Enter Position\n-->";
                    cin >> pos;
                    lst.insertBefore(data,pos);
                }
                else lst.insert(data);
            }
        }
        else if (op==3){
            char data;
            cout << "Enter value to delete\n-->";
            cin >> data;
            lst.del(data);
        }

        else if (op==4){
            cout << endl;
            lst.printLst();
        }
    cout << endl << endl;
    }
    cout << " Bye bye" << endl;
}
