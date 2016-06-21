#include "SLinkedList.h"

template<class type1, class type2>
class HashTable{
private:
    int sz;
    SLinkedList<type2> * Arr;
    int cap;
    /* Returns index to a bucket in the hash table*/
    int getIndex(const type1 & key){
        int hash = ((int) key) % 127;
        int idx = hash%cap;
        // cout << endl <<"index->" << idx << endl;
        return idx;
    }


public:
    HashTable():sz(0),cap(31){
        Arr = new SLinkedList<type2>[cap];
    }
    HashTable(int cap):sz(0){
        this->cap = cap;
        Arr = new SLinkedList<type2>[cap];
    }
    bool isEmpty() const{
        return sz==0;
    }

    int getSize() const{
        return sz;
    }
    void insert(const type1 & key, const type2 & value){
        int idx = HashTable::getIndex(key);
        if (HashTable::isEmpty(key)){
            Arr[idx].insert(value);
        }
        else{
            cerr << "Collision. Value cannot be inserted." << endl;
        }
    }
    void delValue(const type1 & key){
        int idx = HashTable::getIndex(key);
        if (!HashTable::isEmpty(key)){
            Arr[idx].clear();
        }
        else{
            cerr << "Position is already empty"<<endl;
        }
    }

    type2 getValue(const type1 & key){
        int idx = HashTable::getIndex(key);
        if (!HashTable::isEmpty(key)){
            return Arr[idx].getHeadValue();
        }
        else{
            cerr << "Position is empty";
            return 0;
        }

    }

    bool isEmpty(const type1 & key){
        int idx = HashTable::getIndex(key);
        return Arr[idx].isEmpty();
    }

    void printTable() const{
        for (int i=0;i<cap;i++) Arr[i].printLst();
    }

};
template<>
int HashTable<string,string>::getIndex(const string & key){
    // cout << "Hello my friends" << endl;
    int hash = key[0] % 127;
    int idx = hash%cap;
    // cout << endl <<"index->" << idx << endl;
    return idx;
}
