#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
*/
class Solution {
public:
    bool isvalid(unordered_map<int, int> &mp){
        int countodd = 0 ;
        int counteven = 0 ;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            if(it->second%2 == 1){
                countodd++ ;
            }
            else{
                counteven++ ;
            }
        }
        if(countodd > 1){
            return false ;
        }
        return true ;
    }
    void dfs(TreeNode* node, unordered_map<int, int> &mp, int &ans){
        if(node == nullptr){
            return ;
        }
        mp[node->val]++ ;
        if(node->left == nullptr && node->right == nullptr){
            if(isvalid(mp)){
                ans++ ;
            }
        }
        dfs(node->left, mp, ans) ;
        dfs(node->right, mp, ans) ;
        mp[node->val]-- ;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int> mp ;
        int ans = 0 ;
        dfs(root, mp, ans) ;  
        return ans ;
    }
};

/*
instead of stirng you can directly maintain a map that will be easy even though with string you might get MLE if not properly referenced 
*/