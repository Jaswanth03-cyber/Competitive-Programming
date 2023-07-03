/*
Leaf-Similar Trees

Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

https://leetcode.com/problems/leaf-similar-trees/
*/

#include<bits/stdc++.h>
using namespace std ;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// writing a function inc which while traversing in inorder storing only leaves 

class Solution {
public:
    void inorder_leaf(TreeNode *root, vector<int> &ans){
        if(root == nullptr){
            return ;
        }
        inorder_leaf(root->left, ans) ;
        if((root->left == nullptr) && (root->right == nullptr)){
            ans.push_back(root->val) ;
        }
        inorder_leaf(root->right, ans) ;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2){

        vector<int> ans1 ;
        vector<int> ans2 ;
        inorder_leaf(root1, ans1) ;
        inorder_leaf(root2, ans2) ;

        bool result = true ;
        if(ans1.size() != ans2.size()){
            result = false ;
            return result ;
        }

        for(size_t i = 0 ; i < ans1.size() ; i++){
            if(ans1[i] != ans2[i]){
                result = false ;
                break ;
            }
        }
        return result ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}