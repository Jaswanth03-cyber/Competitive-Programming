#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/binary-tree-tilt/description/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int dfs(TreeNode* node, int &sum){
        if(node == nullptr){
            return 0 ; 
        }
        int sum1 = node->val + dfs(node->left, sum) ;
        int sum2 = node->val + dfs(node->right, sum) ;
        sum = sum + abs(sum1 - sum2) ;
        return sum1 + sum2 - node->val ;
    }
    int findTilt(TreeNode* root) {
        int ans = 0 ;
        TreeNode* temp = root ;
        int rootval = dfs(root, ans) ;
        return ans ;  
    }
};