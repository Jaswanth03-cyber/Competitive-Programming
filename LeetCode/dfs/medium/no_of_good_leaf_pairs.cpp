#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
*/


class Solution {
public:
    void findleaves(TreeNode* node, vector<TreeNode*> &leaf, unordered_map<TreeNode*, TreeNode*> &mp){
        if(node->left == nullptr && node->right == nullptr){
            leaf.push_back(node) ;
        }
        if(node->left != nullptr){
            mp.insert({node->left, node}) ;
            findleaves(node->left, leaf, mp) ;
        }
        if(node->right != nullptr){
            mp.insert({node->right, node}) ;
            findleaves(node->right, leaf, mp) ;
        }
    }
    void dfs(TreeNode* node, int currdistance, unordered_map<TreeNode*, int> &visited,unordered_map<TreeNode*, TreeNode*> &mp, int &ans, int maxdistance){
        if(node == nullptr || visited[node] == 1){
            return ;
        }
        visited[node] = 1 ;
        if(currdistance > maxdistance){
            return ;
        }
        if(currdistance != 0 && node->left == nullptr && node->right == nullptr){
            ans++ ;
        }
        dfs(node->left, currdistance + 1, visited, mp, ans, maxdistance) ;
        dfs(node->right, currdistance + 1, visited, mp, ans, maxdistance) ;
        dfs(mp[node], currdistance + 1, visited, mp, ans, maxdistance) ;
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, TreeNode*> mp ;
        mp.insert({root, root}) ;
        vector<TreeNode*> leaf ;
        findleaves(root, leaf, mp) ; 
        int n = leaf.size() ;
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            unordered_map<TreeNode*, int> visited ;
            dfs(leaf[i], 0, visited, mp, ans, distance) ;
        } 
        int res = ans/2 ;
        return res ; 
    }
};

/*
type of brute force worked for this doing dfs for all the leaves
*/