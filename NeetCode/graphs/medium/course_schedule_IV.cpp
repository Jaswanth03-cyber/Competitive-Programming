#include <bits/stdc++.h>
using namespace std ;

/*
maintaing a boolean array n*n such that 
check[i][j] dentes whether i is prereq of j or not

no need to run dfs for every time query is called do dfs for n times where n is number of vertices and we are storing the result
*/


/*
https://leetcode.com/problems/course-schedule-iv/
*/

class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<bool> visited ;
    vector<vector<bool>> check ;
    public:
    graph(int n){
        vertices = n ;
        visited.resize(n, false) ;
        adjlist.resize(n) ;
        check.resize(n) ;
        for(int i = 0 ; i < n ; i++){
            check[i].resize(n, false) ;
        }
    }
    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
    }

// in one dfs run we are checking for what all courses is ith course(top over here) a pre req if in case for some course i is pre req we are setting
// check[top][src] = true ;
// if in case already visited return as not cycles we can just do it like normal directed graph bfs no need to check for cycle ;
    void dfs(int src, int top){
        if(visited[src]){
            return ;
        }
        check[top][src] = true ; 
        visited[src] = true ;
        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ; 
            dfs(node, top) ;
        }
    }

    vector<bool> solve(vector<vector<int>>& queries){
        for(int i = 0 ; i < vertices ; i++){
            dfs(i, i) ;
            fill(visited.begin(), visited.end(), false) ;
        }
        int n = queries.size() ;
        vector<bool> ans(n, false) ;
        for(int i = 0 ; i < n ; i++){
            int one = queries[i][0] ;
            int two = queries[i][1] ;
            ans[i] = check[one][two] ;
        }
        return ans ;
    }
};

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        graph g(numCourses) ;
        int m = prerequisites.size() ;

        for(int i = 0 ; i < m ; i++){
            g.add(prerequisites[i][0], prerequisites[i][1]) ;
        } 
        vector<bool> ans = g.solve(queries) ;
        return ans ; 
    }
};