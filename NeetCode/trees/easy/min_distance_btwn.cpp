#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/minimum-distance-between-bst-nodes/
*/

class Solution {
public:
    void inorder(TreeNode * root, vector<int> &ans){
        if(root == nullptr){
            return ;
        }
        inorder(root->left, ans) ;
        ans.push_back(root->val) ;
        inorder(root->right, ans) ;
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> ans ;
        inorder(root, ans) ;

        sort(ans.begin(), ans.end()) ;
        int minimum = 1e9 ; 
        for(int i = 1 ; i < ans.size() ; i++){
            minimum = min(minimum, abs(ans[i] - ans[i-1])) ;
        }
        return minimum ;
    }
};