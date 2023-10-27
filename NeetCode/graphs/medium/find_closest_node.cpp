#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
*/
class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<int> dis1 ;
    vector<int> dis2 ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        dis1.resize(n, -1) ;
        dis2.resize(n, -1) ;
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
    }

    void dfs(int src, int count){
        vector<bool> visited(vertices, false) ;
        visited[src] = true ;
        if(count == 0){
            dis1[src] = 0 ;
        }
        else{
            dis2[src] = 0 ;
        }
        queue<int> pq ;
        pq.push(src) ;

        while(!pq.empty()){
            int top = pq.front() ;
            pq.pop() ;
            int size = adjlist[top].size() ;
            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top][i] ;
                if(!visited[node]){
                    visited[node] = true ;
                    pq.push(node) ;
                    if(count == 0){
                        dis1[node] = dis1[top] + 1 ;
                    }
                    else{
                        dis2[node] = dis2[top] + 1 ;
                    }
                }
            }
        }
    }

    int solve(int node1, int node2){
        int count = 0 ;
        dfs(node1, count) ;
        count++ ;
        dfs(node2, count) ;
        int ans = vertices ;
        int distance = INT_MAX ;
        for(int i = 0 ; i < vertices ; i++){
            if(dis1[i] != -1 && dis2[i] != -1 && distance > max(dis1[i], dis2[i])){
                distance = max(dis1[i], dis2[i]) ;
                ans = i ;
            }
            else if(dis1[i] != -1 && dis2[i] != -1 && distance == max(dis1[i], dis2[i])){
                ans = min(ans, i) ;
            }
        } 
        if(ans == vertices){
            return -1 ;
        }
        return ans ;
    }
};

/*
read the question carefully
*/