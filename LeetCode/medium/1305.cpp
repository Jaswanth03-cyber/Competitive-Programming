#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
*/
class Solution {
public:
    void inorder(TreeNode* root,priority_queue<int, vector<int>, greater<int>> &pq){
        if(root == nullptr){
            return ;
        }
        inorder(root->left, pq) ;
        pq.push(root->val) ;
        inorder(root->right, pq) ;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        priority_queue<int, vector<int>, greater<int>> pq ;
        inorder(root1, pq) ;
        inorder(root2, pq) ;

        vector<int> ans ;
        while(!pq.empty()){
            ans.push_back(pq.top()) ;
            pq.pop() ;
        }
        return ans ; 
    }
};
