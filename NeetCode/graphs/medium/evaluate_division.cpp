#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/evaluate-division/
*/
typedef pair<int, double> pi ;
class graph{
    int vertices ;
    vector<vector<pi>> adjlist ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
    }

    void add(int src, int dest, double value){
        adjlist[src].push_back({dest, value}) ;
        adjlist[dest].push_back({src, 1.0/value}) ;
    }

    double query(int src, int dest){
        vector<double> ans(vertices, -1.00) ;
        ans[src] = 1.0 ;
        vector<int> visited(vertices, false) ;
        queue<int> pq ;
        pq.push(src) ;

        while(!pq.empty()){
            int top = pq.top() ;
            pq.pop() ;
            int size = adjlist[top].size() ;
            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top][i].first ;
                double value = adjlist[top][i].second ;
                if(!visited[node]){
                    visited[node] = true ;
                    ans[node] = value*ans[top] ;
                    pq.push(node) ;
                }
            }
        }
        return ans[dest] ;
    }
};
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, int> mp ;
        int count = 0 ;
        int size = equations.size() ;
        for(int i = 0 ; i < size ; i++){
            if(mp.find(equations[i][0]) == mp.end()){
                mp[equations[i][0]] = count++ ;
            }
            if(mp.find(equations[i][1]) == mp.end()){
                mp[equations[i][1]] = count++ ;
            }          
        }
        graph g(count) ;

        for(int i = 0 ; i < size ; i++){
            g.add(mp[equations[i][0]], mp[equations[i][1]], values[i]) ;
        }

        vector<double> ans ;
        int m = queries.size() ;
        double value ;
        double neg = -1.0 ;
        for(int i = 0 ; i < m ; i++){
            if(mp.find(queries[i][0]) == mp.end() || mp.find(queries[i][1]) == mp.end()){
                value = neg ;
            }
            else{
                value = g.query(mp[queries[i][0]], mp[queries[i][1]]) ;
            }
            ans.push_back(value) ;
        }
        return ans ;
    }
};

/*

I have just created a graph with nodes as the variables for which I have given a naming from 0 to n-1 where n is the number of different
variables given in the equations so a edge from a to b has value of a/b also I have added the edge b/a with value 1/value also I have maintained 
the map of variales to the integre representation of the node, if a variable does not exists value is -1 else value is computed using bfs do not
forget we have to multiply the values as 
a/b*b/c*c/d = a/d so this gives the answer.
*/