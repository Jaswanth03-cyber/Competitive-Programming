#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/
*/

class Solution {
public:
    pair<TreeNode*, TreeNode*> mapparents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mp, int start, int dest){
        pair<TreeNode*, TreeNode*> ans ;
        queue<TreeNode*> pq ;
        pq.push(root) ;
        int size = 0 ;
        mp.insert({root, root}) ;
        while(!pq.empty()){
            size = pq.size() ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front() ;
                pq.pop() ;
                if(node->val == start){
                    ans.first = node ;
                }
                if(node->val == dest){
                    ans.second = node ;
                }
                if(node->left != nullptr){
                    pq.push(node->left) ;
                    mp.insert({node->left, node}) ;
                }
                if(node->right != nullptr){
                    pq.push(node->right) ;
                    mp.insert({node->right, node}) ;
                }
            }
        }
        return ans ;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* Node = root ;
        unordered_map<TreeNode*, char> direction ;
        unordered_map<TreeNode*, TreeNode*> mp ;
        unordered_map<TreeNode*, int> visited ;
        unordered_map<TreeNode*, TreeNode*> parents ;
        pair<TreeNode*, TreeNode*> nodes = mapparents(Node, mp, startValue, destValue) ; 
        queue<TreeNode*> pq ; 
        pq.push(nodes.first) ;
        int size = 0 ;
        visited[nodes.first] = 1 ;
        while(!pq.empty()){
            size = pq.size() ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front() ;
                pq.pop() ;
                if(visited[mp[node]] == 0){
                    pq.push(mp[node]) ;
                    direction[mp[node]] = 'U' ;
                    visited[mp[node]] = 1 ;
                    parents[mp[node]] = node ;
                }
                if(node->left != nullptr && visited[node->left] == 0){
                    pq.push(node->left) ;
                    direction[node->left] = 'L' ;
                    visited[node->left] = 1 ;
                    parents[node->left] = node ;
                }
                if(node->right != nullptr && visited[node->right] == 0){
                    pq.push(node->right) ;
                    direction[node->right] = 'R' ;
                    visited[node->right] = 1 ;
                    parents[node->right] = node ;
                }
            }
        }
        string res = "" ;
        TreeNode* node = nodes.second ;
        while(node != nodes.first){
            res.push_back(direction[node]) ;
            node = parents[node] ;
        }
        reverse(res.begin(), res.end()) ;
        return res ;         
    }
};

/*
first bfs maps the parents and its child nodes and also tells us the start and end nodes, next one starts bfs from the starting node
and maintains a visited map, direction map in what direction it came from and also we will have a parent from where it came from
now using these two we finally build the array.
*/