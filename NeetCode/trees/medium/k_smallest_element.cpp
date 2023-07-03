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
in bst inorder traversal gives node values in ascending order 
*/
class Solution {
public:
    void inorder(TreeNode *root, vector<int> &ans){
        if(root == nullptr){
            return ;
        }
        inorder(root->left, ans) ;
        ans.push_back(root->val) ;
        inorder(root->right, ans) ;
    }
    int kthSmallest(TreeNode* root, int k) {

        vector<int> ans ;
        inorder(root, ans) ;
        int result = ans[k-1] ;

        return result ;    
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;


    return 0 ;
}