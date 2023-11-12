#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/count-nodes-with-the-highest-score/description/
*/
class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<int> dp ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        dp.resize(n, 0) ;
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
        adjlist[dest].push_back(src) ;
    }

    void dfs(int src, int parent){
        dp[src] = 1 ;
        int size = adjlist[src].size() ;
        for(int i = 0; i < size ; i++){
            int node = adjlist[src][i] ;
            if(node == parent){
                continue ;
            }
            dfs(node, src) ;
            dp[src] += dp[node] ;
        }
    }

    int solve(vector<int> &parents){
        dfs(0, 0) ;
        vector<long long> score(vertices, 1) ;
        long long maximum = 0 ;
        for(int i = 0 ; i < vertices ; i++){
            int size = adjlist[i].size() ;
            int child = 0 ;
            vector<int> count(4, 0) ;
            count[3] = 1 ;
            for(int j = 0; j < size ; j++){
                int node = adjlist[i][j] ;
                if(node != parents[i] && child == 0){
                    count[0] =  dp[node] ;
                    child++ ;
                }
                else if(node != parents[i]){
                    count[1] = dp[node] ;
                }
            }
            count[2] = vertices - 1 - count[0] - count[1] ;
            for(int j = 0 ; j < 4 ; j++){
                if(count[j] != 0){
                    score[i] = score[i]*(long long)count[j] ;
                }
            }
            maximum = max(maximum, score[i]) ;
        }
        int ans = 0 ;
        for(int i = 0 ; i < vertices ; i++){
            cout<<score[i]<<" "<<i<<endl ;
            if(score[i] == maximum){
                ans++ ;
            }
        }
        return ans ;
    }
};
class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size() ;
        graph g(n) ;
        for(int i = 1 ; i < n ; i++){
            g.add(parents[i], i) ;
        }
        int ans = g.solve(parents) ;
        return ans ;
    }
};

/*
creating a graph and checking for each edge removing its connected ones and whil calculating no of nodes in left and right 
subtree we maintain a count vector for each node as each node can create 4 components with 0th value corresponding to 
no of components in its left subtree, 1 corresponding to right subtree, 2 correspond to its parent, and 3rd correspond to the node itself 
*/