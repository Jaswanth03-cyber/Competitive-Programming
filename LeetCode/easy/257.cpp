#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/binary-tree-paths/
*/

class Solution {
public:
    void add(TreeNode* node, vector<string> &ans, string temp){
        if(node == nullptr){
            return ;
        }
        temp = temp + to_string(node->val) ;
        if(node->right == nullptr && node->left == nullptr){
            ans.push_back(temp) ;
        }
        else{
            temp = temp + "->" ;
        }
        add(node->left, ans, temp) ;
        add(node->right, ans, temp) ; 
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans ;
        string temp = "" ;
        add(root, ans, temp) ; 
        return ans ;   
    }
};