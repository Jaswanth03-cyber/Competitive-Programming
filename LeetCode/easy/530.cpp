#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/minimum-absolute-difference-in-bst/
*/

class Solution {
public:
    void inorder(TreeNode* node, vector<int> &ans){
        if(node == nullptr){
            return ;
        }
        inorder(node->left, ans) ;
        ans.push_back(node->val) ;
        inorder(node->right, ans) ;
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> ans ;
        inorder(root, ans) ;
        sort(ans.begin(), ans.end()) ;

        int res = INT_MAX ;
        int size = ans.size() ;
        for(int i = 1 ; i < size ; i++){
            res = min(res, abs(ans[i] - ans[i-1])) ;
        }
        return res ; 
    }
};
