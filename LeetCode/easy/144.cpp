#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/binary-tree-preorder-traversal/
*/

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
    void preorder(TreeNode* root, vector<int> &ans){
        if(root == nullptr){
            return ;
        }
        ans.push_back(root->val) ;
        preorder(root->left, ans) ;
        preorder(root->right, ans) ;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans ; 
        preorder(root, ans) ;
        return ans ; 
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;


    return 0 ;
}