#include "mQueue.h"

int main(){
    mQueue<char> Q;
    cout << "Is Queue empty " << (Q.isEmpty()?"yes":"no") << endl;
    Q.enqueue('Y');
    Q.enqueue('U');
    Q.enqueue('E');
    Q.enqueue('N');
    Q.enqueue('G');
    // Q.display();
    mQueue<char>::display(Q);
    try{
        cout << "Front is: " << Q.front()<< endl;
        cout << "Back is: " << Q.back()<< endl;
    }catch (const exception &e){
        cerr << "error-->" << e.what()<<endl;
    }
    cout << "Is Queue empty " << (Q.isEmpty()?"yes":"no") << endl;
    try{
        cout << "Dequeueing: " << Q.dequeue() << endl;
    }catch (const exception &e){
        cerr << "error-->" << e.what()<<endl;
    }
    mQueue<char>::display(Q);
    return 0;
}
