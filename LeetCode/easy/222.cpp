#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/count-complete-tree-nodes/
*/

class Solution {
public:
    int countNodes(TreeNode* root) {
        int ans = 0 ;
        if(root == nullptr){
            return ans ;
        }    
        queue<TreeNode*> pq ;
        pq.push(root) ;
        int size = 0 ;

        while(!pq.empty()){
            size = pq.size() ;
            ans = ans + size ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* temp = pq.front() ;
                pq.pop() ;
                if(temp->left != nullptr){
                    pq.push(temp->left) ;
                }
                if(temp->right != nullptr){
                    pq.push(temp->right) ;
                }
            }
        }
        return ans ;
    }
};