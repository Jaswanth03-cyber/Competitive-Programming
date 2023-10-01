#include <bits/stdc++.h>
using namespace std ;

class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<char> color ;
    public:
    graph(int n){
        vertices = n ;
        color.resize(n, 'w') ;
        adjlist.resize(n) ;
    }
    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
    }

    bool dfs(int src, stack<int> &st){
        color[src] = 'g' ;
        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ; 
            if(color[node] == 'w'){
                if(dfs(node, st)){
                    return true ;
                }
            }
            else if(color[node] == 'g'){
                return true ;
            }
        }
        st.push(src) ;
        color[src] = 'b' ;
        return false ;
    }

    vector<int> solve(){
        stack<int> st ;
        vector<int> ans ;
        for(int i = 0 ; i < vertices ; i++){
            if(color[i] == 'w' && dfs(i, st)){
                return ans ;
            }
        }

        while(!st.empty()){
            ans.push_back(st.top()) ;
            st.pop() ;
        }
        return ans ;
    }
};
class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph g(numCourses) ;
        int m = prerequisites.size() ;

        for(int i = 0 ; i < m ; i++){
            g.add(prerequisites[i][1], prerequisites[i][0]) ;
        } 
        vector<int> ans = g.solve() ;
        return ans ; 
    }
};