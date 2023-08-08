#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
*/

class Solution {
public:
    void preorder(TreeNode *node, vector<int> &ans){
        if(node == nullptr){
            return ;
        }
        ans.push_back(node->val) ;
        preorder(node->left, ans) ;
        preorder(node->right, ans) ;
    }
    void flatten(TreeNode* root) {
        if(root == nullptr || (root->right == nullptr && root->left == nullptr)){
            return ;
        }

        vector<int> ans ;
        TreeNode *node = root ;
        preorder(node, ans) ;
        TreeNode *temp = root ;
        int size = ans.size() ;
        for(int i = 1 ; i < size ; i++){
            temp->left = nullptr ;
            if(temp->right == nullptr){
                temp->right = new TreeNode(ans[i]) ;
            }
            else{
                temp->right->val = ans[i] ;
            }
            temp = temp->right ;
        }
    }
};