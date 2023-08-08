#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/increasing-order-search-tree/
*/

class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans){
        if(root == nullptr){
            return ;
        }
        inorder(root->left, ans) ;
        ans.push_back(root->val) ;
        inorder(root->right, ans) ;
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> ans ;
        inorder(root, ans) ;
        TreeNode *temp = root ;
        temp->val = ans[0] ;
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
        return root ;
    }
};