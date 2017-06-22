#include <vector>
#include <algorithm>

using namespace std;

template <typename Comparable>
class GenericTree
{
    private:
        struct TreeNode{
            Comparable element;
            TreeNode *firstChild;
            TreeNode *nextSibling;
            int height;
            explicit TreeNode(const Comparable &newVal = Comparable{}): element{newVal}, firstChild{nullptr}, nextSibling{nullptr}, height{-1} {}
        };
        struct HashEntry{
            Comparable key_val;
            TreeNode *key_loc;
            EntryType info;
            HashEntry( const Comparable & e = Comparable ( ),
                TreeNode * const n = nullptr,
                EntryType i = EMPTY) : key_val( e ), key_loc ( n ), info( i ) { }
        };
        TreeNode* root = new TreeNode;
        int tableSize;
        bool contains (const Comparable & keyVal,TreeNode* rt, TreeNode*& keyLoc){
            if (rt->element == keyVal){
                keyLoc = rt; 
                return true;
            }
                if (rt-> firstChild && rt-> nextSibling){
                  if (contains(keyVal, rt-> firstChild, keyLoc)){
                      return true;
                  }
                  else{
                  return contains(keyVal, rt-> nextSibling, keyLoc);
                  }
                }
                else if (rt-> firstChild || rt-> nextSibling){
                    if (rt-> nextSibling){
                       return contains(keyVal, rt-> nextSibling, keyLoc);
                    }
                    if (rt-> firstChild){
                        return contains(keyVal, rt-> firstChild, keyLoc);
                    }
                }
            return false;
        }
        void print_Tree(const TreeNode *rt, vector<int> &nodeLabel){
                for (int i = 0; i < nodeLabel.size(); ++i){
                    cout << nodeLabel.at(i) << ".";
                }
                cout << "[" << rt-> height << "] " << rt-> element << endl;
            
                if (rt-> firstChild != nullptr){
                        nodeLabel.push_back(1);
                        print_Tree(rt-> firstChild, nodeLabel);
                        nodeLabel.pop_back();
                }
                if (rt-> nextSibling != nullptr){
                        int copy = nodeLabel.at(nodeLabel.size() - 1) + 1;
                        nodeLabel.pop_back();
                        nodeLabel.push_back(copy);
                        print_Tree(rt-> nextSibling, nodeLabel);
                }
                else{
                    return;
                }
            }
            
        void set_height(TreeNode *rt){
            TreeNode *trace = nullptr;
            if (rt-> firstChild != nullptr){
                set_height(rt-> firstChild);
                trace = rt-> firstChild; 
                int maxHeight = trace-> height; 
                TreeNode *i = trace; 
                bool x = true;
                while (x){
                    if (i-> height > maxHeight){
                        maxHeight = i-> height;
                    }
                    if (i-> nextSibling == nullptr) {
                        break;
                    }
                    if (i-> nextSibling != nullptr){
                    i = i-> nextSibling;
                    }
                }
                rt-> height = maxHeight + 1;
                }
                else if (rt-> firstChild == nullptr){
                    rt-> height = 0; 
                }
                if (rt -> nextSibling != nullptr){
                set_height(rt-> nextSibling);
                }
            }
            void dump_hash_table(int tableSize){
                for(int i = 0; i < tableSize - 1; i++){
                    cout << i << ": ";
                }
                cout << i.info << " ";
                if(i.info == "ACTIVE"){
                    cout << "\"" << i.keyVal << "\" ";
                    cout << hash(key_val, tableSize) << " ";
                    cout << "->";
                    out <<"\"" << *key_loc << "\"" << endl;
                }
            }
public:
GenericTree ( Comparable root_val ){
    root->element = root_val;
    root->firstChild = nullptr;
    root->nextSibling = nullptr;
    root->height = -1;
}
TreeNode & operator=(const TreeNode * &rhs){
    this->element = rhs->element;
    this->firstChild = rhs->firstChild;
    this->nextSibling = rhs->nextSibling;
    this->height = rhs->height;
    return *this;
}
int insert ( Comparable new_val, Comparable parent_val ){
    TreeNode *Parent = nullptr;
    TreeNode *valCheck = nullptr;
            if (contains(new_val, root, valCheck)){
                cout << "Insert failed. newVal has been found." << endl;
                return -1;
            }
            else if(!contains(parent_val, root, Parent)){
            cout << "Insert failed. parentVal not found." << endl;
            return -2;
        }
        else if (contains(parent_val, root, pParent)){
                TreeNode *newTreeNode = new TreeNode(new_val);
                TreeNode *track = pParent;
                if (pParent-> firstChild != nullptr){
                track = pParent-> firstChild;
                while (track-> nextSibling != nullptr){
                track = track->nextSibling; 
            }
            track-> nextSibling = newTreeNode; 
            newTreeNode->nextSibling = nullptr;
            newTreeNode->firstChild = nullptr;
        }
        else{
        pParent-> firstChild = newTreeNode; 
        newTreeNode-> nextSibling = nullptr;
        newTreeNode->firstChild = nullptr;
    }
    return 1;
    }
}
void print_Tree(){
    vector<int> nodeLabel; 
    nodeLabel.push_back(1);
    print_Tree(root, nodeLabel);
}
int set_height(){
    set_height(root);
    return(root->height);
}
unsigned int hash( const string & key, int tableSize ){
    unsigned int hashVal = 0;
    for( char ch : key )
        hashVal = 37 * hashVal + ch;
        return hashVal % tableSize;
}
unsigned int hash( const double & key, int tableSize ){
    unsigned int hashVal = 0;
    for( double i : key )
        int x = floor(key);
        double y = key - x
        int z = floor(7919 * y);
        hashVal = ((28411 + (x + z) ∗ 8121) % 134456);
        return hashVal % tableSize;
}
void dump_hash_table(){
     
}
};