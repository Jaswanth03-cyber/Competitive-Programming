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

/*
https://leetcode.com/problems/insert-into-a-binary-search-tree/
*/

class Solution {
public:
    TreeNode *insert(TreeNode* node, int val){
        if(node == nullptr){
            node = new TreeNode(val) ;
            return node ;
        }
        if(node->val > val){
            node->left = insert(node->left, val) ;
        }
        if(node->val < val){
            node->right = insert(node->right, val) ;
        }
        return node ;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            root = new TreeNode(val) ;
        }
        TreeNode *curr = root ; 
        TreeNode *temp = insert(curr, val) ;
        return root ;  
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}