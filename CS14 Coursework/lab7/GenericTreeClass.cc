#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

enum EntryType { ACTIVE, EMPTY, DELETED };
unsigned int hashFunc( const string & key, int tableSize ){
    unsigned int hashVal = 0;
    for( char ch : key )
        hashVal = 37 * hashVal + ch;
        return hashVal % tableSize;
}
unsigned int hashFunc( const double & key, int tableSize ){
    unsigned int hashVal = 0;
        int x = floor(key);
        int y = floor(7919 *(key - floor(key)));
        hashVal = (28411 + (x + y) * 8121) % 134456;
        return hashVal % tableSize;
}
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
            HashEntry( const Comparable & e = Comparable (), TreeNode * const n = nullptr, EntryType i = EMPTY) : key_val( e ), key_loc ( n ), info( i ) { }
        };
        TreeNode* root = new TreeNode;
        int tableSize = 101;
        vector<HashEntry> array = vector<HashEntry> (tableSize);
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
                    if (rt-> firstChild){
                        return contains(keyVal, rt-> firstChild, keyLoc);
                    }
                    if (rt-> nextSibling){
                       return contains(keyVal, rt-> nextSibling, keyLoc);
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
                TreeNode *iterator = rt-> firstChild;
                bool tracing = true;
                while (tracing){
                    if (iterator-> height > maxHeight){
                        maxHeight = iterator-> height;
                    }
                    if (iterator-> nextSibling == nullptr) {
                        break;
                    }
                    if (iterator-> nextSibling != nullptr){
                    iterator = iterator-> nextSibling;
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
            void hang_left( TreeNode *rt ){
                priority_queue <pair <int, TreeNode*>> childQ;
            if (rt-> firstChild != nullptr){
                bool tracing = true;
                TreeNode* i = rt->firstChild;
                rt->firstChild = nullptr;
                while(tracing){
                    childQ.push(make_pair(i->height, i));
                    if(i->nextSibling == nullptr){
                        break;
                    }
                    i = i->nextSibling;
                }
                while(!childQ.empty()){
                    pair<int,TreeNode*> p = childQ.top();
                    if(rt->firstChild == nullptr){
                        rt->firstChild = p.second;
                        TreeNode* tempDelete = p.second;
                        tempDelete->nextSibling = nullptr;
                        childQ.pop();
                    }
                    else if(rt->firstChild != nullptr){
                        TreeNode* trace = rt->firstChild;
                        while(trace->nextSibling != nullptr){
                            trace = trace-> nextSibling;
                        }
                        trace->nextSibling = p.second;
                        TreeNode* nextChild = p.second;
                        nextChild->nextSibling = nullptr;
                        childQ.pop();
                    }
                }
            }
            if (rt -> nextSibling != nullptr){
                return hang_left(rt ->nextSibling);
            }
            if (rt-> firstChild == nullptr){
                return hang_left(rt->firstChild);
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
        else if (contains(parent_val, root, Parent)){
            TreeNode *newTreeNode = new TreeNode(new_val);
            TreeNode *trace = Parent;
            if (Parent-> firstChild != nullptr){
                trace = Parent-> firstChild;
                while (trace-> nextSibling != nullptr){
                    trace = trace->nextSibling; 
            }
            trace-> nextSibling = newTreeNode; 
            newTreeNode->nextSibling = nullptr;
            newTreeNode->firstChild = nullptr;
            unsigned int hashPos = hashFunc(new_val, array.size());
            array.at(hashPos) = HashEntry(new_val, newTreeNode, ACTIVE);
            }
            else{
                Parent-> firstChild = newTreeNode; 
                newTreeNode-> nextSibling = nullptr;
                newTreeNode->firstChild = nullptr;
                unsigned int hashPos = hashFunc(new_val, array.size());
                array.at(hashPos) = HashEntry(new_val, newTreeNode, ACTIVE);
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
void dump_hash_table(){
    for(int i = 0; i < tableSize; i++){
        cout << i << ": ";
        if(array.at(i).info == 0){
            cout << "ACTIVE"  << " \" "  << array.at(i).key_val << " \" ";
            cout << i << " ";
            cout << "->";
            cout <<" \" " << array.at(i).key_loc->element << " \" " << endl;
        }
    }
}
void hang_left(){
    return hang_left(root);
}
};