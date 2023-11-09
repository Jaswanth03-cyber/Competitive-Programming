#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/longest-univalue-path/
*/
class Solution {
public:
    int dfs(TreeNode* node, int &res){
        if(node == nullptr){
            return 0 ;
        }
        int ans = 1 ;
        int ans1 = dfs(node->left, res) ;
        int ans2 = dfs(node->right, res) ;
        if(node->left != nullptr && node->right != nullptr && node->val == node->left->val && node->val == node->right->val){
            res = max(res, 1 + ans1 + ans2) ;     
        }
        if(node->left != nullptr && node->val == node->left->val){
            ans = max(ans, 1 + ans1) ;
        }
        if(node->right != nullptr && node->val == node->right->val){
            ans = max(ans, 1 +ans2) ;
        }
        res = max(res, ans) ;
        return ans ; 
    }
    int longestUnivaluePath(TreeNode* root) {
        TreeNode* node = root ;
        if(root == nullptr){
            return 0 ;
        }
        int res = 0 ;
        int ans = dfs(node, res) ;
        return res - 1 ;   
    }
};

/*
pls note the 16th line it wont be a path if that value is used by the ancestors so thats why took the result maximum of all those 
instead of taking max of ans over there
*/