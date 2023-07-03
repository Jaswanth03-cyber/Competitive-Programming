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
maximum depth is similar to height itself but in the definition of depth we have to consider number of nodes in the path from root node to the 
a particular node depth of root node is 1 so if a node is nullptr we are returning 0 instead of -1 unlike in height definition 
*/
class Solution {
public:
    int maxDepth(TreeNode* root){
        if(root == nullptr){
            return 0 ;
        } 
        int height = max(maxDepth(root->left) + 1, maxDepth(root->right) + 1) ;

        return height ; 
    }
};


int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}