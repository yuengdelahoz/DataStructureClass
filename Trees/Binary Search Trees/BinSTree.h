#include "../Binary Trees/BinTree.h"
template<class type>
class BinSTree:public BinTree<type>{
private:
    int size;
public:
    BinSTree():size(0){
    }
    void insert(int key, const type & data){
        if (BinTree<type>::root==nullptr){
            BinNode<type> *n = new BinNode<type>(data);
            n->key = key;
            BinTree<type>::root = n;
            size++;

        }
        else{
            BinNode<type> *n = new BinNode<type>(data);
            n->key = key;
            size++;
            BinNode<type> *ptr = BinTree<type>::root;
            BinNode<type> *prev = nullptr;
            int ind = 0;
            while (ptr!=nullptr){
                if(key <= ptr->key){
                    prev = ptr;
                    ptr = ptr->left;
                    ind =0;
                }
                else if (key > ptr->key){
                    prev = ptr;
                    ptr = ptr->right;
                    ind =1;
                }
            }
            n->parent = prev;
            if (ind==0) prev->left = n;
            else prev->right=n;

        }
    }

    BinNode<type> * find(int key){
        if (BinTree<type>::root==nullptr) return nullptr;
        else{
            BinNode<type> * node = BinTree<type>::root;
            while(node != nullptr){
                if (key < node->key) node = node->left;
                else if (key > node->key) node = node->right;
                else return node;
            }
        }
        return nullptr;
    }

    void buildTree(){
        string line;
        ifstream myfile ("tree.txt");
        int cnt = 0;
        if (myfile.is_open())
        {
            string data;
            int key;
            while(getline(myfile,line)){
                BinTree<type>::parseLine(line,key,data);
                if (key ==-1) continue;
                insert(key,data);
            }
            myfile.close();
        }
        else cout << "Unable to open file";
    }
};
