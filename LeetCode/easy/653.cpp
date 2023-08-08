#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
*/
class Solution {
public:
    void traverse(TreeNode* node, set<int> &ans){
        if(node == nullptr){
            return ;
        }
        traverse(node->left, ans) ;
        ans.insert(node->val) ;
        traverse(node->right, ans) ;
    }
    bool findTarget(TreeNode* root, int k) {
        bool ans = false ;
        set<int> st ;
        traverse(root, st) ;
        for(auto it = st.begin() ; it != st.end() ; it++){
            if((st.find(k - *it) != st.end()) && (k - *it != *it)){ // second condition as we took set so every value will be only once, if k is 2 times *it then it will be a problem so checking that also
                ans = true ; 
                break ;
            }
        }
        return ans ;
    }
};
