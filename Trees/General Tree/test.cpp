#include "SibTree.h"
int main(){
    SibTree<string> T;
    T.levelorder(T.getRoot());
    return 0;
}
