#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> pq ;
        vector<vector<int>> ans ; 
        if(root == nullptr){
            return ans ;
        } 
        pq.push(root) ;
        vector<int> group ;
        char dir = 'r' ;
        int n = 0 ;
        while(!pq.empty()){
            n = pq.size() ;
            for(int i = 0 ; i < n ; i++){
                TreeNode* current = pq.front() ;
                pq.pop() ;
                group.push_back(current->val) ;
                if(dir == 'l'){
                    if(current->left != nullptr){
                        pq.push(current->left) ;
                    }
                    if(current->right != nullptr){
                        pq.push(current->right) ;
                    }
                }
                if(dir == 'r'){
                    if(current->right != nullptr){
                        pq.push(current->right) ;
                    }
                    if(current->left != nullptr){
                        pq.push(current->left) ;
                    }
                }
            }
            if(dir == 'r'){
                dir = 'l' ;
            }
            else{
                dir = 'r' ;
            }
            ans.push_back(group) ;
            group.clear() ;
        }
        return ans ;
    }
};