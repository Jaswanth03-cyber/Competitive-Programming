#include <bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/validate-binary-tree-nodes/
*/


class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0) ;
        vector<int> outdegree(n, 0) ;
        for(int i = 0 ; i < n ; i++){
            if(leftChild[i] != -1){
                indegree[leftChild[i]]++ ;
            }
            if(rightChild[i] != -1){
                indegree[rightChild[i]]++ ;
            }
        }  
        int root = -1 ;
        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0 && root == -1){
                root = i ;
            }
            else if(indegree[i] == 0){
                return false ;
            }
        }
        if(root == -1){
            return false ;
        }
        vector<int> visited(n, 0) ;
        queue<int> pq ;
        pq.push(root) ;

        while(!pq.empty()){
            int top = pq.front() ;
            pq.pop() ;
            if(visited[top]){
                return false ;
            }
            visited[top] = 1 ;
            if(leftChild[top] != -1){
                pq.push(leftChild[top]) ;
            }
            if(rightChild[top] != -1){
                pq.push(rightChild[top]) ;
            }
        }
        int sum = accumulate(visited.begin(), visited.end(), 0) ;
        if(sum != n){
            return false ;
        }
        return true ;
    }
};

/*
just checking the indegrees, indegree 0 will be the root node if more are there then return false after finding the root do bfs 
if so a node is twise visited then return false and also if atleast one vertex is not visited from the node then not a tree so return false 
*/