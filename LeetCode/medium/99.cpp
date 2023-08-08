#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/recover-binary-search-tree/
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
    void solve(TreeNode* node, vector<int> &ans, int &index){
        if(node == nullptr){
            return ;
        }
        solve(node->left, ans, index) ;
        node->val = ans[index++] ;
        solve(node->right, ans, index) ;
    }
    void recoverTree(TreeNode* root) {
        vector<int> ans ;
        inorder(root, ans) ;
        sort(ans.begin(), ans.end()) ;
        int index = 0 ;
        solve(root, ans, index) ;
    }
};