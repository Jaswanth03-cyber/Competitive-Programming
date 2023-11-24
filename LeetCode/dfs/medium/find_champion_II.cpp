#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-champion-ii/description/
*/
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0) ;
        int m = edges.size() ;
        for(int i = 0 ; i < m ; i++){
            indegree[edges[i][1]]++ ;
        } 
        int ans = -1 ;
        int count = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0 && count == 0){
                ans = i ;
                count++ ;
            }
            else if(indegree[i] == 0){
                return -1 ;
            }
        }
        return ans ;
    }
};

/*
return the node which has indegree 0 if more nodes with indegree 0 then return -1 as many champions can be present if none of the nodes have indegree 0 then
also -1
*/