template<class type>
class TreeNode{
private:
    type data;
    bool valid;
    TreeNode<type> * parent;
    TreeNode<type> * first_child;
    TreeNode<type> * next_sibling;
    template<class U> friend class SibTree;
public:
    TreeNode():valid(false),parent(0),first_child(0),next_sibling(0){
    }
    TreeNode(const type & data):valid(true),parent(0),first_child(0),next_sibling(0){
        this->data = data;
    }
};
