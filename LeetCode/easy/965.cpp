#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/univalued-binary-tree/
*/

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        set<int> st ;
        queue<TreeNode*> pq ;
        pq.push(root) ;
        bool ans = true ;
        int size = 0 ; 
        st.insert(root->val) ;
        int level = 0 ;
        while(!pq.empty()){
            size = pq.size() ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front() ;
                pq.pop() ;
                if(level != 0){
                    if(st.find(node->val) == st.end()){
                        return false ;
                    }
                }
                if(node->left != nullptr){
                    pq.push(node->left) ;
                }
                if(node->right != nullptr){
                    pq.push(node->right) ;
                }
            }
            level++ ;
        } 
        return true ; 
    }
};