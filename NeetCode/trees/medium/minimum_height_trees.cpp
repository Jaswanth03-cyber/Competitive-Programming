#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/minimum-height-trees/
*/
class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<int> height1 ;
    vector<int> height2 ;
    vector<int> paththrough ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        height1.resize(n, 0) ;
        height2.resize(n, 0) ;
        paththrough.resize(n, 0) ;
    }
    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
        adjlist[dest].push_back(src) ;
    }

    void dfs1(int src, int parent){
        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            if(node == parent){
                continue ;
            }
            dfs1(node, src) ;

            if(height1[node] + 1 > height1[src]){
                height2[src] = height1[src] ;
                height1[src] = height1[node] + 1 ;
                paththrough[src] = node ;
            }
            else if(height1[node] + 1 > height2[src]){
                height2[src] = height1[node] + 1 ;
            }
        }
    }

    void dfs2(int src, int parent){
        int size = adjlist[src].size() ;

        for(int i  = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            if(node == parent){
                continue ;
            }

            if(paththrough[src] == node){
                if(height2[src] + 1 > height1[node]){
                    height2[node] = height1[node] ;
                    height1[node] = height2[src] + 1 ;
                    paththrough[node] = src ;
                }
                else if(height2[src] + 1 > height2[node]){
                    height2[node] = height2[src] + 1 ;
                }
            }
            else{
                height2[node] = height1[node] ;
                height1[node] = height1[src] + 1 ;
                paththrough[node] = src ;
            }

            dfs2(node, src) ;
        }
    }

    vector<int> solve(){
        dfs1(0, 0) ;
        dfs2(0, 0) ;
        vector<int> ans ;
        int minheight = *min_element(height1.begin(), height1.end()) ;
        for(int i = 0 ; i < vertices ; i++){
            if(height1[i] == minheight){
                ans.push_back(i) ;
            }
        }
        return ans ;
    }
};
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        graph g(n) ;
        int m = edges.size() ;
        for(int i = 0 ; i < m ; i++){
            g.add(edges[i][0], edges[i][1]) ;
        } 
        vector<int> ans = g.solve() ;
        return ans ;
    }
};