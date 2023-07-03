/*
Range Sum of BST 
Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a 
value in the inclusive range [low, high].

https://leetcode.com/problems/range-sum-of-bst/
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
    int rangeSumBST(TreeNode* root, int low, int high) {

        vector<int> ans ; 
        inorder(root, ans) ;
        int sum = 0 ;
        for(size_t i = 0 ; i < ans.size() ; i++){
            if((ans[i] >= low) && (ans[i] <= high)){
                sum = sum + ans[i] ;
            }
        }  
        return sum ;   
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;


    return 0 ;
}