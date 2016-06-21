#include<iostream>
#include<cassert>
using namespace std;

template <class D>
class DAlist{
private:
    D * Darray;
    int size;
    int arr_sz;
public:
    DAlist():size(0),arr_sz(1024){
        Darray = new D[arr_sz];
    }
    DAlist(int sz):size(0){
        arr_sz = sz;
        Darray = new D[arr_sz];
    }
    ~DAlist(){
        delete []Darray;
    }
    D getData(int pos) const{
        if (pos < size) return Darray[pos];
        else{
            cerr << "Position does not exist in the array" << endl;
            return -1;
        }
    }
    int getSize() const {
        return size;
    }
    void insert(int pos, const D& data){
        if (size == 0){
            DAlist::insert (data);
        }
        else if (pos >=0 and pos <=size){
            assert(size < arr_sz);
            cout << "Adding element to the list in position " << pos << endl;
            size++;
            for (int i=0;i<size;i++){
                if (i==pos){
                    for(int j=size;j>pos;j--){
                        Darray[j]=Darray[j-1];// shifting to the right, staring in the last element of the array.
                    }
                    Darray[pos]=data;// inserting data in the array.
                    break;
                }
            }
        }
        else cerr << "Element cannot be added in that position. Next position available is " << ((size -1)>0?size:0) << endl;
    }
    void insert(const D& data){// insert 'data' to last available place in the array
        assert(size < arr_sz);
        cout << "Adding element to the list" << endl;
        Darray[size] = data;
        size++;
    }
    bool isEmpty(){
        return size == 0;
    }

    void del(const D & ele){ // delete element 'ele' from list
        bool flag = false;
        for (int i=0;i<size;i++){// iterate over the array and remove all instances of 'ele'
            if (Darray[i]==ele){ // find the element 'ele' in the array
                cout << "Element found in position " << i << ". Deleting " << endl;
                for(int j=i;j<size;j++){
                    Darray[j]=Darray[j+1]; // shift to the left. Remove 'ele' from the array
                }
                size--;
                DAlist::printList();
            }
        }
    }

    void printList(){
        for (int i=0;i<size;i++)
            cout << "Pos[" << i << "]='" << Darray[i] << "'-> ";
        cout << "end" << endl;
    }
};
