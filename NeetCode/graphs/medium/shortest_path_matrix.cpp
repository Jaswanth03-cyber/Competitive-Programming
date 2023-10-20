#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/shortest-path-in-binary-matrix/
*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() ;
        if(grid[0][0] || grid[n-1][n-1]){
            return -1 ;
        }
        queue<pair<int, int>> pq ;
        pq.push({0, 0}) ;
        vector<vector<bool>>  visited(n, vector<bool>(n, false)) ;
        vector<vector<int>> distance(n, vector<int>(n, -1)) ;
        distance[0][0] = 1 ;
        visited[0][0] = true ;

        while(!pq.empty()){
            int x = pq.top().first ;
            int y = pq.top().second ;
            pq.pop() ;
            if(x == n-1 && y == n-1){
                return distance[n-1][n-1] ;
            }

            if(x != 0){
                if(!visited[x-1][y] && grid[x-1][y] != 1){
                    distance[x-1][y] = distance[x][y] + 1 ;
                    visited[x-1][y] = true ;
                    pq.push({x-1, y}) ;
                }

                if(y != 0 && !visited[x-1][y-1] && grid[x-1][y-1] != 1){
                    distance[x-1][y-1] = distance[x][y] + 1 ;
                    visited[x-1][y-1] = true ;
                    pq.push({x-1, y-1}) ;
                }

                if(y != n-1 && !visited[x-1][y+1] && grid[x-1][y+1] != 1){
                    distance[x-1][y+1] = distance[x][y] + 1 ;
                    visited[x-1][y+1] = true ;
                    pq.push({x-1, y+1}) ;
                }
            }

            if(y != 0){
                if(!visited[x][y-1] && grid[x][y-1] != 1){
                    distance[x][y-1] = distance[x][y] + 1 ;
                    visited[x][y-1] = true ;
                    pq.push({x, y-1}) ;
                }

                if(x != n-1 && !visited[x+1][y-1] && grid[x+1][y-1] != 1){
                    distance[x+1][y-1] = distance[x][y] + 1 ;
                    visited[x+1][y-1] = true ;
                    pq.push({x+1, y-1}) ;
                }
            }

            if(y != n-1){
                if(!visited[x][y+1] && grid[x][y+1] != 1){
                    distance[x][y+1] = distance[x][y] + 1 ;
                    visited[x][y+1] = true ;
                    pq.push({x, y+1}) ;
                }
                if(x != n-1 && !visited[x+1][y+1] && grid[x+1][y+1] != 1){
                    distance[x+1][y+1] = distance[x][y] + 1 ;
                    visited[x+1][y+1] = true ;
                    pq.push({x+1, y+1}) ;
                }
            }

            if(x != n-1){
                if(!visited[x+1][y] && grid[x+1][y] != 1){
                    distance[x+1][y] = distance[x][y] + 1 ;
                    visited[x+1][y] = true ;
                    pq.push({x+1, y}) ;
                }
            }
        }
        return distance[n-1][n-1] ;
    }
};

/*
bfs be careful with the index out of bounds 
*/