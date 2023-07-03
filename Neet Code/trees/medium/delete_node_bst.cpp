#include<bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/delete-node-in-a-bst/
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
    TreeNode* inorder_sucessor(TreeNode *n){
        TreeNode *current = n->right ;
        while((current->left != nullptr) && (current != nullptr)){
            current = current->left ;
        }
        return current ;
    }
    TreeNode* Delete(TreeNode *n, int a){
        if(n == nullptr){
            return n ;
        } 
        else if(n->val > a){
            n->left = Delete(n->left,a) ;
        }
        else if(n->val < a){
            n->right = Delete(n->right,a) ;
        }
        else{ 
            if((n->right == nullptr) && (n->left == nullptr)){
                return nullptr ;
            }
            else if(n->right == nullptr){
                TreeNode *temp = n->left ;
                delete n ;
                return temp ;
            }
            else if(n->left == nullptr){
                TreeNode *temp = n->right ;
                delete n ;
                return temp ;
            }
            else{
                TreeNode *temp = inorder_sucessor(n) ;
                n->val = temp->val ;
                n->right = Delete(n->right, temp->val);
            }
        }
        return n ;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *curr = root ;
        root = Delete(curr, key) ;
        return root ;  
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;

}