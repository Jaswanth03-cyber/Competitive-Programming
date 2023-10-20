#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
*/
class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<bool> hasapple ;
    public:
    graph(int n, vector<bool> &arr){
        vertices = n ;
        adjlist.resize(n) ;
        hasapple = arr ;
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
        adjlist[dest].push_back(src) ;
    }

    int dfs(int src, int parent){
        int size = adjlist[src].size() ;
        int ans = 0 ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            if(node == parent){
                continue ;
            }
            int res = dfs(node, src) ;
            if(hasapple[node] || res){
                ans = ans + res + 2 ;
            }
        }
        return ans ;
    }

    int solve(){
        int ans = dfs(0, 0) ;
        return ans ;
    }
};
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        graph g(n, hasApple) ;
        for(int i = 0 ; i < n-1 ; i++){
            g.add(edges[i][0], edges[i][1]) ;
        } 
        int ans = g.solve() ;
        return ans ;
    }
};

/*
logic
so the thought is that we recursively calculate the distance

for each subtree what is the distance it takes to travel as to the answer we are adding the distance or if node has a apple so 
in the res at every iteration it stores what is the distance travelled if that vertex is the node and if we consider that subtree if it has any 
apples then how much time it takes to collect the apples so basically if we see the first example 

we start dfs at 0 so now 1 does not have any apples, its child 4 and 5 have apples so in the dfs its child 4,5 dfs is called and also 
as no child for 4 and 5 returns 0 but as both have apples we have to add 2 to that so either a node has apples or it sub ordinates have apple 
we need to add 2 if in case subordinates returns a positive value that is also added 2 is anyway for sure if there is an apple over there 
so next we go to 2 it has apple but it subordinates does not have any apple so they return 0 but at as 2 has apple we add 2 anyway res is 0
from 3,6  so no effect, this way we recursively calculate the value. note 2 because once going forward and coming backward.
*/