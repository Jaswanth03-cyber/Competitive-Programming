#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/sum-root-to-leaf-numbers/
*/

// Definition for a binary tree node.
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
    void bfs(TreeNode *root, string sum, vector<string> &ans){
        if(root == nullptr){
            return ;
        }
        char temp = 48 + root->val ;
        sum = sum + temp ;
        if((root->left == nullptr) && (root->right == nullptr)){
            ans.push_back(sum) ;
        }
        bfs(root->left, sum, ans) ;
        bfs(root->right, sum, ans) ;
    }
    int sumNumbers(TreeNode* root) {
        vector<string> ans ;
        string sum = "" ;
        bfs(root, sum, ans) ; 
        int res = 0 ;
        int temp = 0 ;
        for(int i = 0 ; i < ans.size() ; i++){
            temp = stoi(ans[i]) ;
            res = res + temp ;
        }
        return res ; 
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;


    return 0 ;
}