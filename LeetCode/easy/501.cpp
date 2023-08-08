#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-mode-in-binary-search-tree/
*/

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        map<int, int> mp ;
        int maximum = INT_MIN ;

        queue<TreeNode*> pq; 
        pq.push(root) ;

        int size = 0 ;

        while(!pq.empty()){
            size = pq.size() ;

            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front() ;
                pq.pop() ;
                if(mp.find(node->val) != mp.end()){
                    mp[node->val]++ ;
                }
                else{
                    mp.insert({node->val, 1}) ;
                }
                if(node->left != nullptr){
                    pq.push(node->left) ;
                }
                if(node->right != nullptr){
                    pq.push(node->right) ;
                }
            }
        }

        for(auto it = mp.begin() ; it != mp.end() ; it++){
            maximum = max(it->second, maximum) ;
        }
        vector<int> ans ;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            if(it->second == maximum){
                ans.push_back(it->first) ;
            }
        }
        return ans ; 
    }
};