#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/house-robber-iii/
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// this resulted in tle so used dp
class Solution {
public:
    int find(TreeNode* node){
        if(node == nullptr){
            return 0 ;
        }
        int ans = 0 ;
        int sum1 = node->val  ;
        if(node->left != nullptr){
            sum1 += find(node->left->left) + find(node->left->right) ;
        }
        if(node->right != nullptr){
            sum1 += find(node->right->left) + find(node->right->right) ;
        }
        int sum2 = find(node->left) + find(node->right) ;
        int temp = max(sum1, sum2) ;
        ans = max(ans, temp) ;
        return ans ;
    }
    int rob(TreeNode* root) {
        TreeNode* node = root ;
        int res = find(node) ;
        return res ; 
    }
};


class Solution {
public:
    void dfs(TreeNode* node, unordered_map<TreeNode*, int> &mp){
        if(node == nullptr){
            return ;
        }
        if(node->left == nullptr && node->right == nullptr){
            mp.insert({node, node->val}) ;
            return ;
        }

        int sum1 = node->val ;
        int sum2 = 0 ;
        if(node->left != nullptr && mp.find(node->left) == mp.end()){
            dfs(node->left, mp) ;
            sum2 += mp[node->left] ;
            if(node->left->left != nullptr){
                sum1 += mp[node->left->left] ;
            }
            if(node->left->right != nullptr){
                sum1 += mp[node->left->right] ;
            }
        }
        if(node->right != nullptr && mp.find(node->right) == mp.end()){
            dfs(node->right, mp) ;
            sum2 += mp[node->right] ;
            if(node->right->left != nullptr){
                sum1 += mp[node->right->left] ;
            }
            if(node->right->right != nullptr){
                sum1 += mp[node->right->right] ;
            }
        }
        mp[node] = max(sum1, sum2) ;
    }
    int rob(TreeNode* root) {
        TreeNode* node = root ;
        unordered_map<TreeNode*, int> mp ;
        dfs(node, mp) ;
        int res = mp[root] ;
        return res ; 
    }
};