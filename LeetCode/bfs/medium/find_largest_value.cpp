#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-largest-value-in-each-tree-row/
*/
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> pq ;
        vector<int> ans ;
        if(root == nullptr){
            return ans ;
        }
        pq.push(root) ;
        int size = 0 ;
        while(!pq.empty()){
            size = pq.size() ;
            int maximum = INT_MIN ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front() ;
                pq.pop() ;
                maximum = max(maximum, node->val) ;
                if(node->left != nullptr){
                    pq.push(node->left) ;
                }
                if(node->right != nullptr){
                    pq.push(node->right) ;
                }
            }
            ans.push_back(maximum) ;
        }
        return ans ;
    }
};