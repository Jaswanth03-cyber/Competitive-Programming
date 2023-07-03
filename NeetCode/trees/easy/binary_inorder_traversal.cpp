#include<bits/stdc++.h>
using namespace std ;


 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*
inorder traversal of a tree takes a vector and root of the tree as inputs and gives out inorder traversal into that tree 
*/

class Solution {
public:
    void inorder(TreeNode *root, vector<int> &result){
        if(root == nullptr){
            return ;
        }
        inorder(root->left, result) ;
        result.push_back(root->val) ;
        inorder(root->right, result) ;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> result ;
        
        inorder(root, result) ;
        return result ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}