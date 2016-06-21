#include <iostream>
using namespace std;
#include "../../Lists/Queue/mQueue.h"
template<class type>
class BinNode{
private:
    type data;
    int key;
    BinNode<type> * parent;
    BinNode<type> * left;
    BinNode<type> * right;
    template<class U> friend class BinTree;
    template<class U> friend class BinSTree;
    void visit(){
        cout << data <<", " << key << endl;;
    }
public:
    BinNode(const type & data):key(0),parent(0),left(0),right(0){
        this->data = data;
    }
    void preorder(){
        this->visit();
        if(left!=nullptr) left->preorder();
        if(right != nullptr) right->preorder();
    }
    void inorder(){
        if(left!=nullptr) left->inorder();
        this->visit();
        if(right != nullptr) right->inorder();
    }
    void postorder(){
        if(left!=nullptr) left->postorder();
        if(right != nullptr) right->postorder();
        this->visit();
    }
    void levelorder(){
        if (this==nullptr) return;
        mQueue< BinNode<type>* > Q;
        Q.enqueue(this);
        while(!Q.isEmpty()){
            BinNode<type> *n = Q.dequeue();
            n->visit();
            if(n->left != nullptr) Q.enqueue(n->left);
            if(n->right != nullptr) Q.enqueue(n->right);
        }
    }
};
