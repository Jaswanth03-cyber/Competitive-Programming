#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/most-frequent-subtree-sum/
*/
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        queue<TreeNode*> pq ;
        pq.push(root) ;
        stack<pair<TreeNode*, TreeNode*>> st ;
        unordered_map<TreeNode*, int> mp ;
        int size = 0 ;
        unordered_map<int, int> freq ;

        while(!pq.empty()){
            size = pq.size();
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front() ;
                pq.pop() ;
                mp.insert({node, 0}) ;
                if(node->left != nullptr){
                    pq.push(node->left) ;
                    st.push({node->left, node}) ;
                }
                if(node->right != nullptr){
                    pq.push(node->right) ;
                    st.push({node->right, node}) ;
                }
            }
        }

        while(!st.empty()){
            mp[st.top().second] += mp[st.top().first] + st.top().first->val ;
            st.pop() ;
        }
        int maxfreq = 0 ;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            int subtreenodesum = it->second + it->first->val  ;
            freq[subtreenodesum]++ ;
            maxfreq = max(maxfreq, freq[subtreenodesum]) ;
        }
        vector<int> ans ;
        for(auto it = freq.begin() ; it != freq.end() ; it++){
            if(it->second == maxfreq){
                ans.push_back(it->first) ;
            }
        }
        return ans ;
    }
};