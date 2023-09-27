#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
*/

/*
Logic 
Starting dfs at 0, now we first assume that the given tree is undirected and also we maintain the directed edges in a set so that finding 
if a node goes to a particular node or not in the original tree.
so now first a neighbour of 0 is taken now it checks if this neighbour has a edge to the 0 in the set if not we have to reverse this so count++
now dfs on this neighbor, now neighbors of this node whose edges do not point to this neigbor has to be changed so that is checked, so everything is
normal dfs 

here in the for loop if(visited[]){} this is checked because for example take the first example in the question when dfs of 2 is done now 3 
is actually visited before itself, as there as an edge between  2 and 3 in the undirected graph and also if we see there is no edge between 3 and 2
here adjlist[src][i] is 3 and src is 2 which says there is no edge between 3 and 2 so this is added extra, but actually that is not true.
so we are not processing the nodes which have been visited. as we need minimum changes

Note here visited is true in the sense we can reach 0 from that node. at the end all will be true.
*/
class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<bool> visited ;
    set<pair<int, int>> st ;
    public :
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        visited.resize(n, false) ;
    }
    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
        adjlist[dest].push_back(src) ;
        st.insert({src, dest}) ;
    }

    void dfs(int src, int &count){
        if(visited[src]){
            return ;
        }
        visited[src] = true ;
        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            if(visited[adjlist[src][i]]){
                continue ;
            }
            if(st.find({adjlist[src][i], src}) == st.end()){
                count++ ;
            }
            dfs(adjlist[src][i], count) ;
        }
    }

    int solve(){
        int count = 0 ;
        dfs(0, count) ;
        return count ;
    }
};
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        graph g(n) ;
        int m = connections.size() ;
        for(int i = 0 ; i < m ; i++){
            g.add(connections[i][0], connections[i][1]) ;
        }
        int ans = g.solve() ;
        return ans ;
    }
};