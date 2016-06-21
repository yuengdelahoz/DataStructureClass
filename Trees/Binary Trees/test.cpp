#include "BinTree.h"

int main(){
    BinTree<string> T;
    T.buildTree();
    cout << "Height of the tree is " << T.height(T.getRoot()) << endl;
    return 0;
}
