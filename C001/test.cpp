#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<stack>
#include<queue>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int val){ // constructor
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// string serialize(TreeNode* root) {
        
//     if(root == NULL) return "";
//     return to_string(root->val) + "(" + serialize(root->left) + ")" + "(" + serialize(root->right) + ")";  
// }

void serial(TreeNode* root, string &str){

    if(root == NULL){
        // str.pop_back();
        return;
    }

    str += to_string(root->val);

    str += "(";
    serial(root->left, str);
    str += ")";

    str += "(";
    serial(root->right, str);
    str += ")";
}

string serialize(TreeNode* root) {
    
    if(root == NULL) return "";
    string str;
    serial(root, str);
    // cout<<str<<endl;
    return str;
}

int main(){
    
    TreeNode *a = new TreeNode(4);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(1);
    TreeNode *e = new TreeNode(6);
    TreeNode *f = new TreeNode(5);

    a->left = b;
    b->left = c;
    b->right = d;
    a->right = e;
    e->right = f;

    cout<<serialize(a)<<endl;
}