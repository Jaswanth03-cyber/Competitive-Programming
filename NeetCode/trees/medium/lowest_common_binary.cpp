#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ancestor(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == nullptr){
            return node ;
        }
        if(node->val == p->val || node->val == q->val){
            return node ;
        }
        TreeNode* left = lowestCommonAncestor(node->left, p, q) ;
        TreeNode* right = lowestCommonAncestor(node->right, p, q) ;

        if(left != nullptr && right != nullptr){
            return node ;
        }
        if(left != nullptr){
            return left ;
        }
        if(right != nullptr){
            return right ;
        }
        return nullptr ;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = ancestor(root, p, q) ;
        return ans ; 
    }
};