#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/convert-bst-to-greater-tree/
*/
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans){
        if(root == nullptr){
            return ;
        }
        inorder(root->left, ans) ;
        ans.push_back(root->val) ;
        inorder(root->right, ans) ;
    }
    TreeNode* convertBST(TreeNode* root) {
        if((root == nullptr) || (root->left == nullptr && root->right == nullptr)){
            return root;
        }
        vector<int> ans ;
        inorder(root, ans) ;
        map<int, int> mp ;
        int size = ans.size() ;
        int sum = 0 ;
        for(int i = 0 ; i < size ; i++){
            for(int j = i + 1 ; j < size ; j++){
                sum = sum + ans[j] ;
            }
            mp.insert({ans[i], sum}) ;
            sum = 0 ;
        }

        queue<TreeNode*> pq ;
        pq.push(root) ;

        while(!pq.empty()){
            size = pq.size() ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front() ;
                pq.pop() ;
                node->val = node->val + mp[node->val] ;
                if(node->left != nullptr){
                    pq.push(node->left) ;
                }
                if(node->right != nullptr){
                    pq.push(node->right) ;
                }
            }
        }

        return root ;
    }
};

