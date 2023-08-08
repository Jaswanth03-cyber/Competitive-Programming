#include <bits/dtc++.h>
using namespace std ;

/*
https://leetcode.com/problems/sum-of-left-leaves/
*/
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> pq; 
        pq.push(root) ;

        int size = 0 ;
        int sum = 0 ;
        while(!pq.empty()){
            size = pq.size() ;

            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front() ;
                pq.pop() ;

                if(node->left != nullptr){
                    if(node->left->left == nullptr && node->left->right == nullptr){
                        sum = sum + node->left->val ;
                    }
                    // sum = sum + node->left->val ;
                    pq.push(node->left) ;
                }
                if(node->right != nullptr){
                    pq.push(node->right) ;
                }
            }
        }
        return sum ;
    }
};