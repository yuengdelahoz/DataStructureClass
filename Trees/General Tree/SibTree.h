#include "TreeNode.h"
#include "../../Lists/Queue/mQueue.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template<class type>
class SibTree{
private:
    TreeNode<type> * root;
    int size;
    void insert(const type & data, TreeNode<type> *parent,int node_pos){
        cout << "Inserting " << data <<" in position "<<node_pos<<  ", parent is " << (parent==nullptr?"NULL, this is the root.":parent->data) << endl;
        TreeNode<type> *n = new TreeNode<type>(data);
        if (parent==nullptr){
            root = n;
            size++;
        }
        else{
            if (parent->first_child==nullptr){
                n->parent = parent;
                parent->first_child = n;
                size++;
            }
            else{
                TreeNode<type> *ptr = parent->first_child;
                while(ptr->next_sibling!=nullptr) ptr = ptr->next_sibling;
                n->parent = parent;
                ptr->next_sibling=n;
                size++;
            }
        }
    }

    TreeNode<type> * findParent(string str){
        int level = 0;
        for (int i=str.size()-1;i>=0;i--){
            if (str[i]=='.') level++;
        }
        if (level<1) return root;
        else{
            int last_dot = str.find_last_of('.');
            int cur_level = 0;
            str = str.substr(last_dot+1); // 0.#.#.par_pos
            string::size_type sz;
            int par_pos = stoi(str,&sz);
            TreeNode<type> * ptr = root;
            while (ptr !=nullptr && cur_level!=level){
                ptr= ptr->first_child;
                cur_level++;
            }
            for(int i=0;i<par_pos;i++){
                ptr = ptr->next_sibling;
            }
            return ptr;
        }
    }

    void build_tree(string path){
        string line;
        ifstream myfile (path);
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                int pos = line.find(' ');
                string data = line.substr(0,pos);
                string str = line.substr(pos+1);
                pos = str.find_last_of('.');
                string str2 = str.substr(pos+1);
                string::size_type sz;
                int node_pos = stoi(str2,&sz);
                str = str.substr(0,pos);
                TreeNode<type> *ptr = findParent(str);
                // cout << "parent for " << data << " is "<< (ptr==nullptr?"nullptr":ptr->data)<<endl;
                insert(data,ptr,node_pos);
            }
            myfile.close();
        }
        else cout << "Unable to open file";
    }

    void visit(TreeNode<type> *ptr){
        cout << ptr->data << endl;
    }
public:
    SibTree():root(0),size(0){
        build_tree("tree.txt");
    }

    bool isEmpty() const{
        return root == nullptr;
    }

    TreeNode<type> * getRoot() const {
        return root;
    }
    int getSize() const {
        return size;
    }
    void preorder(TreeNode<type> *ptr){
        //
        this->visit(ptr);
        if(ptr->first_child!=nullptr){
            preorder(ptr->first_child);
        }
        if(ptr->next_sibling!=nullptr){
            preorder(ptr->next_sibling);
        }
    }
    void postorder(TreeNode<type> *ptr){
        if(ptr->first_child!=nullptr){
            postorder(ptr->first_child);
        }
        this->visit(ptr);
        if(ptr->next_sibling!=nullptr){
            postorder(ptr->next_sibling);
        }
    }

    void levelorder(TreeNode<type> *ptr){
        mQueue< TreeNode<type>* > Q;
        Q.enqueue(ptr);
        while(!Q.isEmpty()){
            TreeNode<type> *n = Q.dequeue();
            this->visit(n);
            TreeNode<type> *sib =nullptr;
            if(n->first_child != nullptr){
                Q.enqueue(n->first_child);
                sib= n->first_child->next_sibling;
            }
            while (sib!=nullptr){
                Q.enqueue(sib);
                sib = sib->next_sibling;
            }
        }
    }
};
