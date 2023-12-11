#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/
*/

class FindElements {
public:
    set<int> st ;
    FindElements(TreeNode* root) {
        queue<pair<int, TreeNode*>> pq ;
        pq.push({0, root}) ;
        root->val = 0 ;
        st.insert(0) ;
        while(!pq.empty()){
            int size = pq.size() ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front().second ;
                int index = pq.front().first ;
                pq.pop() ;
                if(node->left != nullptr){
                    node->left->val = 2*index + 1 ;
                    pq.push({2*index+1, node->left}) ;
                    st.insert(2*index+1) ;
                }
                if(node->right != nullptr){
                    node->right->val = 2*index + 2 ;
                    pq.push({2*index+2, node->right}) ;
                    st.insert(2*index+2) ;
                }               
            }
        }
    }
    
    bool find(int target) {
        if(st.find(target) != st.end()){
            return true ;
        }
        return false ;
    }
};