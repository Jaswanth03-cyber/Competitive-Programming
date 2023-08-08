#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/path-sum-ii/
*/

class Solution {
public:
    void bfs(TreeNode* node, int target, vector<int> temp, vector<vector<int>> &ans, int sum){
        if(node == nullptr){
            return ;
        }
        sum = sum + node->val ;
        temp.push_back(node->val) ;
        if(node->right == nullptr && node->left == nullptr){
            if(sum == target){
                ans.push_back(temp) ;
            }
        }
        bfs(node->left, target, temp, ans, sum) ;
        bfs(node->right, target, temp, ans, sum) ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp ;
        vector<vector<int>> ans ;
        int sum = 0 ;
        bfs(root, targetSum, temp, ans, sum) ;
        return ans ;   
    }
};