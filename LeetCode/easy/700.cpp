#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/search-in-a-binary-search-tree/
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr){
            return nullptr ;
        }
        else if(root->val == val){
            return root ;
        }
        else if(root->val > val){
            return searchBST(root->left, val) ;
        }
        return searchBST(root->right, val) ;
    }
};