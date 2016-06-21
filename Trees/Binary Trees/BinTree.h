#include "BinNode.h"
#include <string>
#include <fstream>
using namespace std;

template<class type>
class BinTree{
protected:
    BinNode<type> * root;
    int size;
    mQueue< BinNode<type>* > Q;
    BinNode<type> * find(const type & data, BinNode<type> * ptr){
        if (ptr->data==data){
            // cout << "Found" << endl;
            return ptr;
        }
        BinNode<type> * tmp1=nullptr;
        BinNode<type> * tmp2=nullptr;

        if(ptr->left!=nullptr){
            tmp1= find(data,ptr->left);
        }
        if(ptr->right!=nullptr){
            tmp2= find(data,ptr->right);
        }
        return tmp1!=nullptr?tmp1:tmp2;
    }

public:
    BinTree():root(0),size(0){}
    bool isEmpty() const{
        return root==nullptr;
    }
    int getSize() const{
        return size;
    }
    BinNode<type> * getRoot(){
        return root;
    }
    int depth(BinNode<type> * node){
        if (node == nullptr || node == root) return 0;
        else return 1 + depth(node->parent);
    }

    int height(BinNode<type> * node){
        if (node==nullptr) return 0;
        int l = 0;
        int r = 0;
        if (node->left!=nullptr) l = 1 + height(node->left);
        if (node->right!=nullptr) r = 1 + height(node->right);
        return l>r?l:r;
    }

    int height(){
        return height(root);
    }

    BinNode<type> * find(const type & data){
        if (root==nullptr) return nullptr;
        else{
            return find(data,root);
        }
    }

    void buildTree(){
        string line;
        ifstream myfile ("tree.txt");
        int cnt = 0;
        if (myfile.is_open())
        {
            int key;
            string data;
            while (!myfile.eof()){
                if (cnt==0){
                    if (!getline (myfile,line)) break;
                    parseLine(line,key,data);
                    // cout << data << ", " << key<< endl;
                    if (key==-1) continue;
                    root = new BinNode<type>(data);
                    root->key=key;
                    Q.enqueue(root);
                    size++;
                }
                else{
                    if (!getline (myfile,line)) break;
                    parseLine(line,key,data);
                    BinNode<type> *ptr = Q.dequeue();
                    if (key!=-1){
                        BinNode<type> *n = new BinNode<type>(data);
                        n->key=key;
                        n->parent = ptr;
                        ptr->left = n;
                        Q.enqueue(n);
                        size++;
                    }
                    if (!getline (myfile,line)) break;
                    parseLine(line,key,data);
                    if (key!=-1){
                        BinNode<type> *n = new BinNode<type>(data);
                        n->key=key;
                        n->parent = ptr;
                        ptr->right = n;
                        Q.enqueue(n);
                        size++;
                    }
                }
                cnt++;
            }
            myfile.close();
        }
        else cout << "Unable to open file";
    }
    void parseLine(string line, int & key, string & data){
        string::size_type sz;
        int pos = line.find(' ');
        string k = line.substr(0,pos);
        data = line.substr(pos+1);
        key = stoi(k,&sz);
    }
};
