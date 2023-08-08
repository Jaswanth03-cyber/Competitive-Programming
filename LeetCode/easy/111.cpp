#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/minimum-depth-of-binary-tree/
*/

class Solution {
public:
    void pathcount(TreeNode* node, priority_queue<int, vector<int>, greater<int>> &pq, int count){
        if(node == nullptr){
            return ;
        }
        count++ ;
        if(node->left == nullptr && node->right == nullptr){
            pq.push(count) ;
        }
        pathcount(node->left, pq, count) ;
        pathcount(node->right, pq, count) ;
    }
    int minDepth(TreeNode* root) {

        if(root == nullptr){
            return 0 ;
        }
        int count = 0 ;
        priority_queue<int, vector<int>, greater<int>> pq ;
        pathcount(root, pq, count) ;
        return pq.top() ;  
    }
};