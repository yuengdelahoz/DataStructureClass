#include "BinSTree.h"
#include<string>
using namespace std;
int main(){
    BinSTree<string> BT;
    BT.buildTree();
    cout << "Size " << BT.getSize() << endl;
    cout << "Height " << BT.height() << endl;
    cout << "Level Order Traversal " << endl;
    BT.getRoot()->levelorder();
    cout << "InOrder Traversal " << endl;
    BT.getRoot()->inorder();
    cout << "Depth " << BT.depth(BT.find(14)) <<endl;
    return 0;
}
