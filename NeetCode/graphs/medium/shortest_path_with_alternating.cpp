#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/shortest-path-with-alternating-colors/description/
*/
class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<int> distance1 ;
    vector<int> distance2 ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(2*n) ;
        distance1.resize(2*n, -1) ;
        distance2.resize(2*n, -1) ;
    }

    void add(int src, int dest, char color){
        if(color == 'r'){
            adjlist[src].push_back(dest+vertices) ;
        }
        else{
            adjlist[src+vertices].push_back(dest) ;
        }
    }

    void bfsr(){
        vector<bool> visited(2*vertices, false) ;
        queue<int> pq ;
        pq.push(0) ;
        distance1[0] = 0 ;
        while(!pq.empty()){
            int top = pq.front() ;
            pq.pop() ;
            int size = adjlist[top].size() ;
            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top][i] ;
                if(!visited[node]){
                    visited[node] = true ;
                    distance1[node] = distance1[top] + 1 ;
                    pq.push(node) ;
                }
            }
        }
    }

    void bfsb(){
        vector<bool> visited(2*vertices, false) ;
        queue<int> pq ;
        int n = vertices ;
        pq.push(n) ;
        distance2[n] = 0 ;
        while(!pq.empty()){
            int top = pq.front() ;
            pq.pop() ;
            int size = adjlist[top].size() ;
            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top][i] ;
                if(!visited[node]){
                    visited[node] = true ;
                    distance2[node] = distance2[top] + 1 ;
                    pq.push(node) ;
                }
            }
        }
    }

    vector<int> solve(){
        vector<int> ans(vertices, -1) ;
        ans[0] = 0 ;
        bfsr() ;
        bfsb() ;
        int n = vertices ;
        for(int i = 1 ; i < vertices ; i++){
            int minimum = INT_MAX ;
            if(distance1[i] != -1){
                minimum = min(minimum, distance1[i]) ;
            }
            if(distance1[i+n] != -1){
                minimum = min(minimum, distance1[i+n]) ;
            }
            if(distance2[i] != -1){
                minimum = min(minimum, distance2[i]) ;
            }
            if(distance2[i+n] != -1){
                minimum = min(minimum, distance2[i+n]) ;
            }
            if(minimum != INT_MAX){
                ans[i] = minimum ;
            }
        }
        return ans ;
    }
};
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        graph g(n) ;
        int m = redEdges.size() ;
        for(int i = 0 ; i < m ;  i++){
            g.add(redEdges[i][0], redEdges[i][1], 'r') ;
        }
        m = blueEdges.size() ;
        for(int i = 0 ; i < m ;  i++){
            g.add(blueEdges[i][0], blueEdges[i][1], 'b') ;
        }
        vector<int> ans = g.solve() ;
        return ans ;
    }
};

/*
so this logic I got from cp-algorithms.com bfs applications there he will ask about what is the minimum odd and even distances if exists
so there we will create a new graph with nodes having parity as odd or even 

so here also I have maintained 2*n vertices where 0 to n-1 correspond to red vertices and n to 2*n-1 correspond to blue vertices 
so rededges go from red node to blue node and blue edges go from blue node to red node 
so the thing is that in the red edge if given vertex from a to b
then we will add it as a to b+n and in the blue edge if it is given that edge is from a to b we upadte it as a+n to b

so now I do bfs from 0 and also from 0 + n as src can start from either blue or red and can end at red or blue vertex 
but note that in our graph edges will be from blue to red or red to blue indicating alternating colors of paths as given in the question
so at the end we have to take minimum of all the 4 distances here 4 because 2 from 0 and 2 from n 2 because red and blue vertex if 
none of them has path ans is anyway -1.
*/