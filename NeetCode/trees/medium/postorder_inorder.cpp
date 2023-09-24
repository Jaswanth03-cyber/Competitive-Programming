#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
*/

/*
Logic 
basically in the postorder last index will be the root, now we search this value in the inorder we will get index 
from instart to index-1 will be the left of the root and index +1 to inend will be the right side of the root
if instart == indend then we will get a leaf we will return it, if instart > inend then return nullptr which will be left or right of a node 
here 
node->right = build() this is written before node->left as see postindex-- is done in the recursion call in the post order 
first left next right then parent so lets assume only three nodes in the binary tree for simple example
if postindex is the root then postindex-- will be the value of right child of the node and postindex-2 will be
the node of the left child in the postorder so thats the reason why this recursion call is written first.
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
    int search(vector<int> &inorder, int start, int end, int val){
        int ans = 0 ;
        for(int i = start ; i <= end ; i++){
            if(inorder[i] == val){
                ans = i ;
                break ;
            }
        }
        return ans ; 
    }
    TreeNode* build(vector<int> &inorder, vector<int> &postorder, int instart, int inend, int &postindex){
        if(instart > inend){
            return nullptr ;
        }

        TreeNode* node = new TreeNode(postorder[postindex]) ;
        postindex-- ;

        if(instart == inend){
            return node ;
        }

        int index = search(inorder, instart, inend, node->val) ;
        node->right = build(inorder, postorder, index+1, inend, postindex) ;
        node->left = build(inorder, postorder, instart, index-1, postindex) ;

        return node ;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root ;
        int n = inorder.size() ;
        int postindex = n-1 ;
        root = build(inorder, postorder, 0, n-1, postindex) ;   
        return root ; 
    }
};