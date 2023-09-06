#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/merge-two-binary-trees/description/
*/

/*
Logic is that we are reccursively adding, so if we can see the base cases you will get an idea 

if both the pointers are null pointers then return nullptr, if one is nullptr give that argument as nullptr but for other provide the pointer
as the argument 
*/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* merge(TreeNode* root1, TreeNode* root2){
        TreeNode* root = new TreeNode(0) ;
        if(root1 == nullptr && root2 == nullptr){
            return nullptr ;
        }
        else if(root1 == nullptr){
            root->val = root2->val ;
            root->left = merge(nullptr, root2->left) ;
            root->right = merge(nullptr, root2->right) ;
        }
        else if(root2 == nullptr){
            root->val = root1->val ;
            root->left = merge(root1->left, nullptr) ;
            root->right = merge(root1->right, nullptr) ;
        }
        else{
            root->val = root1->val + root2->val ;
            root->left = merge(root1->left, root2->left) ;
            root->right = merge(root1->right, root2->right) ;
        }
        return root ;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root = new TreeNode(0) ;
        root = merge(root1, root2) ;  
        return root ; 
    }
};