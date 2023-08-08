#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/path-sum-iii/
*/

class Solution {
public:
    void bfs(TreeNode *root, long long sum, int &count, int target){
        if(root == nullptr){
            return ;
        }
        sum = sum + root->val ; // as they do not want our final path should end at leaf
        // if they need path to finally end at leaf this should be the case instead of the bottom one 
        // if(node->right == nullptr && node->left == nullptr){
        //     if(sum == target){
        //         count++ ;
        //     }
        // }
        if(sum == target){
            count++ ;
        }
        bfs(root->left, sum, count, target) ;
        bfs(root->right, sum, count, target) ;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return 0 ;
        }
        queue<TreeNode*> pq ;
        pq.push(root) ;
        int size = 0 ;
        int count = 0 ;
        long long sum = 0 ;
        while(!pq.empty()){
            size = pq.size() ;

            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front() ;
                pq.pop() ;
                bfs(node, sum, count, targetSum) ;
                if(node->left != nullptr){
                    pq.push(node->left) ;
                }
                if(node->right != nullptr){
                    pq.push(node->right) ;
                }
            }
        }
        return count ; 
    }
};