#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
*/
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0 ;
        queue<TreeNode*> pq ;
        stack<pair<TreeNode*, TreeNode*>> st ;
        unordered_map<TreeNode*, pair<int, int>> mp ;
        pq.push(root) ;
        int size = 0 ;

        while(!pq.empty()){
            size = pq.size() ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front() ;
                pq.pop() ;
                mp.insert({node, {0, 1}}) ;
                if(node->left != nullptr){
                    st.push({node->left, node}) ;
                    pq.push(node->left) ;
                }
                if(node->right != nullptr){
                    st.push({node->right, node}) ;
                    pq.push(node->right) ;
                }
            }
        }

        while(!st.empty()){
            mp[st.top().second].first += mp[st.top().first].first + st.top().first->val ;
            mp[st.top().second].second += mp[st.top().first].second ;
            st.pop() ;
        }

        for(auto it = mp.begin() ; it != mp.end() ; it++){
            int val = (it->second.first + it->first->val)/(it->second.second) ;
            if(val == it->first->val){
                ans++ ;
            }
        }
        return ans ;
    }
};

/*
be carefull while calculating number of nodes in the subtree
*/