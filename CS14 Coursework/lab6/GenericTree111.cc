#include <vector>
#include <algorithm>

using namespace std;


template <typename Comparable>
class GenericTree
{
private:
struct TreeNode
    {
        Comparable element;
        TreeNode * firstChild;
        TreeNode * nextSibling;
        int height;
        explicit TreeNode(const Comparable &newVal = Comparable{}): element{newVal}, firstChild{nullptr}, nextSibling{nullptr}, height{-1} {}
};
TreeNode* root = new TreeNode;
bool contains (const Comparable & key_val, TreeNode *rt, TreeNode * & key_loc){
    if(rt == nullptr){
        return false;
    }
    else if(rt->element == key_val){
        key_loc = rt;
        return true;
    }
    else if(rt->nextSibling || rt->firstChild){
    return contains (key_val, rt->firstChild, key_loc);
    return contains(key_val, rt->nextSibling, key_loc);
    }
}
void print_Tree(){
        {
            TreeNode *tracker = nullptr; //TRACKER TO GET TO THE FIRST CHILD AND CHECK IF ALREADY HAS AN ASSIGNED HEIGHT

            if (rt-> firstChild != nullptr)
            {
                set_height(rt-> firstChild); //RECURSIVE CALL. PRIORITIZE CHILDREN (POSTFIX TRANSVERSAL)
                tracker = rt-> firstChild; 
                int maxHeight = tracker-> height; 
                TreeNode *i = tracker; 
                bool x = true;
                while (x)
                {
                    if (i-> height > maxHeight)//UPDATE MAX HEIGHT 
                    {
                        maxHeight = i-> height;
                    }
                    if (i-> nextSibling == nullptr) //IF POINTING TO LAST SIBLING, BREAK. 
                    {
                        break;
                    }
                    if (i-> nextSibling != nullptr)
                    {
                        i = i-> nextSibling;
                    }
                }
                    rt-> height = maxHeight + 1;//ASSIGN HEIGHT TO PARENT
            }
            else if (rt-> firstChild == nullptr) //BASE CASE
            {
                rt-> height = 0; 
            }
            if (rt -> nextSibling != nullptr) //RECURSIVE CALL
            {
                set_height(rt-> nextSibling);
            }
    }
}
public:
GenericTree(Comparable root_val){
    root->element = root_val;
    root->firstChild = nullptr;
    root->nextSibling = nullptr;
    root->height = -1;
}
GenericTree & operator =(const TreeNode * &rhs){
    this->element = rhs->element;
    this->firstChild = rhs->firstChild;
    this->nextSibling = rhs->nextSibling;
    this->height = rhs->height;
}
int insert ( Comparable new_val, Comparable parent_val ){
    TreeNode * key_loc;
    if(contains(new_val, root, key_loc) == true){
        return -1;
    }
    else if(contains(parent_val, root, key_loc) == false){
        return -2;
    }
    else{
        TreeNode * temp;
        temp->element = new_val;
        temp->firstChild = nullptr;
        temp->nextSibling = nullptr;
        temp->height = -1;
        return 1;
    }
}
void print_Tree(){
            vector<int> nodeLabel; 
            nodeLabel.push_back(1);
            print_Tree(root, nodeLabel);
}


};