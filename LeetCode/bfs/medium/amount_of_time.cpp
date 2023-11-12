#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
*/

class Solution {
public:
    TreeNode* mapparents(TreeNode* Node, unordered_map<TreeNode*, TreeNode*> &mp, unordered_map<TreeNode*, int> &visited, int start){
        queue<TreeNode*> pq ;
        pq.push(Node) ;
        mp.insert({Node, Node}) ;
        TreeNode* startnode ;
        int size = 0 ;
        while(!pq.empty()){
            size = pq.size() ;
            for(int i = 0; i < size ; i++){
                TreeNode* node = pq.front() ;
                pq.pop() ;
                if(node->val == start){
                    startnode = node ;
                }
                visited.insert({node, 0}) ;
                if(node->left != nullptr){
                    mp.insert({node->left, node}) ;
                    pq.push(node->left) ;
                }
                if(node->right != nullptr){
                    mp.insert({node->right, node}) ;
                    pq.push(node->right) ;
                }
            }
        }
        return startnode ;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> mp ;
        TreeNode* Node = root ;
        TreeNode* startnode ;
        unordered_map<TreeNode*, int> visited ;
        startnode = mapparents(Node, mp, visited, start) ;
        int distance = 0 ;
        queue<TreeNode*> pq ;
        pq.push(startnode) ;
        visited[startnode] = 1 ;
        int size = 0 ;
        while(!pq.empty()){
            size = pq.size() ;
            distance++ ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front() ;
                pq.pop() ;
                cout<<node->val<<" "<<distance<<endl ;
                if(visited[mp[node]] == 0){
                    pq.push(mp[node]) ;
                    visited[mp[node]] = 1 ;
                }
                if(node->left != nullptr && visited[node->left] == 0){
                    pq.push(node->left) ;
                    visited[node->left] = 1 ;
                }
                if(node->right != nullptr && visited[node->right] == 0){
                    pq.push(node->right) ;
                    visited[node->right] = 1 ;
                }
            }
        }
        int ans = distance - 1 ;
        return ans ;
    }
};

/*
I have done two dfs to find it first bfs I have mapped the parents and their children and also found the start node and also 
created a visited map and parent map in it now in the second bfs I have started bfs from the starting node and the maximum distance we can reach from this
is the time taken to be infected to all the vertices 
*/