#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root->val == p->val || root->val == q->val){
            return root ;
        }
        else if(root->val > q->val && root->val > p->val){
            return lowestCommonAncestor(root->left, p, q) ;
        }
        else if(root->val < q->val && root->val < p->val){
            return lowestCommonAncestor(root->right, p, q) ;
        }
        else if((root->val < p->val && root->val > q->val) || (root->val > p->val && root->val < q->val)){
            return root ;
        }
        return nullptr ;
    }
};