#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
*/
/*
Logic 
basically in the preorderr first index will be the root, now we search this value in the inorder we will get index 
from instart to index-1 will be the left of the root and index +1 to inend will be the right side of the root
if instart == indend then we will get a leaf we will return it, if instart > inend then return nullptr 
node->left = build() this is written before node->right as see preindex++ is done in the recursion call in the pre order 
first parent left and right so lets assume only three nodes in the binary tree for simple example
if preindex is the root then preindex++ will be the value of left child of the node and preindex+2 will be
the node of the right child in the preorder so thats the reason why this recursion call is written first.
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
    int search(vector<int> &inorder, int instart, int inend, int val){
        int ans = 0 ;
        for(int i = instart ; i <= inend ; i++){
            if(inorder[i] == val){
                ans = i ;
                break ;
            }
        }
        return ans ;
    }
    TreeNode* build(vector<int> &inorder, vector<int> &preorder, int instart, int inend, int &preindex){
        if(instart > inend){
            return nullptr ;
        }

        TreeNode* node = new TreeNode(preorder[preindex]) ;
        preindex++ ;

        if(instart == inend){
            return node ;
        }

        int index = search(inorder, instart, inend, node->val) ;
        node->left = build(inorder, preorder, instart, index-1, preindex) ;
        node->right = build(inorder, preorder, index+1, inend, preindex) ;
        return node ;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size() ;
        int preindex = 0 ;
        TreeNode* root = build(inorder, preorder, 0, n-1, preindex) ;
        return root ;
    }
};