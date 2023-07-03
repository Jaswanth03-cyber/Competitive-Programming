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
    void inorder(TreeNode * root, vector<int> &ans){
        if(root == nullptr){
            return ;
        }
        inorder(root->left, ans) ;
        ans.push_back(root->val) ;
        inorder(root->right, ans) ;
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> ans ;
        inorder(root, ans) ;

        sort(ans.begin(), ans.end()) ;
        int minimum = 1e9 ; 
        for(int i = 1 ; i < ans.size() ; i++){
            minimum = min(minimum, abs(ans[i] - ans[i-1])) ;
        }
        return minimum ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}