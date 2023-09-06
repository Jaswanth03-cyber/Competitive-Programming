#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/construct-string-from-binary-tree/description/
*/

/*
we need to add the brackets if left child is not present but right child is present, so thats why even though left child is null and right child
is existing we are having a reccursive call for that, if none of the childs are there no need to add anything.
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
    string ans = "" ;
    void preorder(TreeNode* node){
        if(node == nullptr){
            return ;
        }
        ans = ans + to_string(node->val) ;
        if(node->left != nullptr || node->right != nullptr){
            ans = ans + '(' ;
            preorder(node->left) ;
            ans = ans + ')' ;
        }
        if(node->right != nullptr){
            ans = ans + '(' ;
            preorder(node->right) ;
            ans = ans + ')' ;
        }
    }
    string tree2str(TreeNode* root) {   
        preorder(root) ;
        return ans ;
    }
};