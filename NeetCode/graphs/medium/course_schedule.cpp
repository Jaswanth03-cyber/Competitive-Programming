#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/course-schedule/
*/

class graph{
    private:
    vector<vector<int>> adjlist ;
    int vertices ;
    int edges ;
    vector<char> color ; 
    vector<int> parent ;
    int cycle_end ;
    int cycle_start ;
    public:
    graph(int n){
        this->vertices = n ;
        adjlist.resize(n) ;
        this->edges = 0 ;
        color.resize(this->vertices) ;
        fill(color.begin(), color.end(), 'W') ;
        this->cycle_start = -1 ;
        this->cycle_end = -1 ;
    }
    void addedge(int a, int b){
        adjlist[a].push_back(b) ;
    }
    bool dfs(int source){
        if(color[source] == 'W'){
            color[source] = 'G' ;
            for(int i = 0 ; i < adjlist[source].size() ; i++){
                if(color[adjlist[source][i]] == 'W'){
                    if(dfs(adjlist[source][i])){
                        return true ;
                    }
                }
                else if(color[adjlist[source][i]] == 'G'){
                    cycle_start = adjlist[source][i] ;
                    cycle_end = source ;
                    return true ;
                }
            }
        }
        color[source] = 'B' ;
        return false ;
    }
    bool find_cycle(){
        for(int i = 0 ; i < this->vertices ; i++){
            if((color[i] == 'W') && (dfs(i))){
                return true ;
            }
        }
        return false ;
    }
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size() ;
        graph g(numCourses) ;

        for(int i = 0 ; i < n ; i++){
            g.addedge(prerequisites[i][1], prerequisites[i][0]) ;
        }

        bool res = g.find_cycle() ;
        return !res ;
    }
};