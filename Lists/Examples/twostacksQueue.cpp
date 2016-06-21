#include "../Queue/mQueue.h"
mQueue<int> Q1;
mQueue<int> Q2;

void push(int data){
    Q1.enqueue(data);
    // cout << "pushing " << data << endl;
    // cout << "size " << Q1.size() << endl;
}

int pop(){ // pop is O(n) now
    while(Q1.size()>1){
        int data = Q1.dequeue();
        Q2.enqueue(data);
    }
    int data = Q1.dequeue();
    mQueue<int> tmp = Q1;
    //Swapping
    Q1 = Q2;
    Q2 = tmp;
    return data;
}

int main(){
    push(1);
    push(2);
    push(3);
    cout << "pop last element " << pop() << endl;
    push(4);
    push(5);
    // push(3);
    cout << "pop last element " << pop() << endl;
    return 0;
}
