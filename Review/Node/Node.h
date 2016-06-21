#include<iostream>
using namespace std;
static int num = 0;
template<class Type>
class Node {
private:
    int id;
    Type data;
    Node * next;
public:
    Node():id(num++),data(0),next(0){};
    Node(const Type& data, Node * next){
        this->id = num++;
        this->data = data;
        this->next = next;
    }
    int getID(){ return this->id;}
    Type getData(){return this->data;}
    Node * getNext(){return this->next;}
};
