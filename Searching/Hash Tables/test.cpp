#include "HashTable.h"
int main(){
    HashTable<string,string> table(5);
    HashTable<int,string> tb2(14);
    table.printTable();
    table.insert("hello","world");
    cout << "value is " << table.getValue("hello")<< endl;
    table.printTable();
    cout << endl;
    return 0;
}
