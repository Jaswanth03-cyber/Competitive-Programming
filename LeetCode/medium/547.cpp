#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/number-of-provinces/
*/
class Solution {
public:
    void bfs(int src, vector<vector<int>> &arr, vector<bool> &visited){
        if(visited[src]){
            return ;
        }
        visited[src] = true ;
        int size = arr.size() ;
        for(int i = 0 ; i < size ; i++){
            if( i != src && arr[src][i]){
                bfs(i, arr, visited) ;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) { 
        int size = isConnected.size() ;
        vector<bool> visited(size, false) ;
        int count = 0 ;
        for(int i = 0 ; i < size ; i++){
            if(!visited[i]){
                bfs(i, isConnected, visited) ;
                count++ ;
            }
        }
        return count ;
    }
};