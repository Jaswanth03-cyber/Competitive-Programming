#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/symmetric-tree/
*/

class Solution {
public:
 
bool isMirror(TreeNode* root1, TreeNode* root2){
    if (root1 == nullptr && root2 == nullptr){
        return true;
    }
    if ((root1 != nullptr) && (root2 != nullptr) && (root1->val == root2->val)){
        if((isMirror(root1->left, root2->right)) && (isMirror(root1->right, root2->left))){
            return true ;
        }
    }
    return false;
}
    bool isSymmetric(TreeNode* root) { 
        bool result = isMirror(root, root) ;
        return result ;
    }
};