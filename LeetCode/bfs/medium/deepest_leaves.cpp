#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/deepest-leaves-sum/description/
*/
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> pq ;
        pq.push(root) ;

        int size = 0 ;
        int ans = 0 ;
        while(!pq.empty()){
            ans = 0 ;
            size = pq.size() ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front() ;
                pq.pop() ;
                ans += node->val ;
                if(node->left != nullptr){
                    pq.push(node->left) ;
                }
                if(node->right != nullptr){
                    pq.push(node->right) ;
                }
            }
        }  
        return ans ;
    }
};