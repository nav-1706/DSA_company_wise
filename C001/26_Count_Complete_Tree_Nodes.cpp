// LEETCODE 222

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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
/*

****************** METHOD: 1 (O(n)) *********************
T.C : O(n)
S.C : O(1)

*/

class Solution {
public:
    int countNodes(TreeNode* root) {

        if(root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

/*

****************** METHOD: 2 (less than O(n)) *********************

https://youtu.be/2XTXL7a6ItI?si=_Tv3t0A8mVB6GJwZ

In perfect binary tree(even full at leaf node) number of nodes = (2^heiht)-1

In this given tree: Last level is not possibly completelet filled only

TC = O( (log(n))^2 ) 
SC = O(log(n)) --> Recursive call stack

*/

class Solution {
public:

    int find_left_height(TreeNode* root){

        int height = 0;
        while(root != NULL){

            height++;
            root = root->left; // not 1+max(find_height(root->left), find_height(root->right));  coz given that it is complete binary tree, max-height will be at left side
        }

        return height;
    }

    int find_right_height(TreeNode* root){

        int height = 0;
        while(root != NULL){

            height++;
            root = root->right; // not 1+max(find_height(root->left), find_height(root->right));  coz given that it is complete binary tree, if it will be perfect binary tree, right heigh will be equal to left height
        }

        return height;
    }

    int countNodes(TreeNode* root) { // TC = O(log(n))
        
        if(root == NULL) return 0;

        int left_height = find_left_height(root); // TC = O(log(n))
        int right_height = find_right_height(root);

        if(left_height == right_height) return pow(2,left_height)-1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};