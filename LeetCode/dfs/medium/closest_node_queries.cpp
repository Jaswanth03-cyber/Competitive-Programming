#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/description/
*/
class Solution {
public:
    void inorder(TreeNode* node, vector<int> &ans){
        if(node == nullptr){
            return ;
        }
        inorder(node->left, ans) ;
        ans.push_back(node->val) ;
        inorder(node->right, ans) ;
    }
    int search(vector<int> &ans, int val){
        int n = ans.size() ;
        int l = 0, r = n - 1 ;
        int res = 0 ;
        while(l <= r){
            int mid = (l+r)/2 ;
            if(ans[mid] > val){
                r = mid - 1 ;
            }
            else{
                l = mid + 1 ;
                res = max(res, ans[mid]) ;
            }
        }
        return res ;
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> ans ;
        inorder(root, ans) ;
        int n = queries.size() ;
        vector<vector<int>> res(n, vector<int>(2, 0)) ;
        for(int i = 0 ; i < n ; i++){
            int val = queries[i] ;
            int index = -1 ;
            index = search(ans, val) ;
            if(index != 0){
                res[i][0] = index ;
            }
            else{
                res[i][0] = -1 ;
            }
            auto it = lower_bound(ans.begin(), ans.end(), val) ;
            if(it != ans.end()){
                index = it - ans.begin() ;
                res[i][1] = ans[index] ;  
            }
            else{
                res[i][1] = -1 ;
            }
        }
        return res ; 
    }
};

/*
searching in inorder traversal will help us to find the required things we can use binary search and upper_bound functions 
*/