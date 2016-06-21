#include "../Linked Lists/Library/SLinkedList.h"

template<class type>
class mStack: public SLinkedList<type>{
public:
    mStack(){}
    bool isEmpty() const{
        return SLinkedList<type>::isEmpty();
    }
    void push(const type& data){
        SLinkedList<type>::insert(data,0);
    }
    type top() const{
        if (this->isEmpty()) throw underflow_error("empty stack");
        return SLinkedList<type>::head->data;
    }
    type pop(){
        if (this->isEmpty()) throw underflow_error("empty stack");
        type dat = SLinkedList<type>::head->data;
        Node<type> *ptr = SLinkedList<type>::head;
        SLinkedList<type>::head = SLinkedList<type>::head->next;
        delete ptr;
        SLinkedList<type>::sz--;
        return dat;
    }
    int size(){
        return SLinkedList<type>::sz;
    }
    void display() const{
        Node<type> *ptr = SLinkedList<type>::head;
        while(ptr!=nullptr){
            cout << ptr->data << endl;
            ptr=ptr->next;
        }
        cout << "bottom" << endl;
    }
};
