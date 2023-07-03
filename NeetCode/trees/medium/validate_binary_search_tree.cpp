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
just check whether inorder traversal is in ascending order or not 
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
    bool isValidBST(TreeNode* root) {

        bool result = true ;    
        vector<int> ans ;
        inorder(root, ans) ;
        int n = ans.size() ;
        for(int i = 1 ; i < ans.size() ; i++){
            if(ans[i] <= ans[i-1]){
                result = false ;
                break ;
            }
        }
        return result ;

    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}
