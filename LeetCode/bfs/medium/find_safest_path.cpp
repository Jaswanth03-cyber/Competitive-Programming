#include <bits/stdc++.h>
using namespace std ;

typedef pair<int, int> pi ;
typedef pair<int, pi> pii ;
class Solution {
public:
    void process(vector<vector<int>> &dis, int x, int y){
        int n = dis.size() ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                dis[i][j] = min(dis[i][j], abs(i-x) + abs(j-y)) ;
            }
        }
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size() ;
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX)) ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]){
                    process(dis, i, j) ;
                }
            }
        }  

        priority_queue<pii> pq ;
        pq.push({dis[0][0], {0, 0}}) ;
        vector<vector<bool>> visited(n, vector<bool>(n, false)) ;
        while(!pq.empty()){
            int curr = pq.top().first ;
            int x = pq.top().second.first ;
            int y = pq.top().second.second ;
            pq.pop() ;
            if((x == n-1 && y == n-1) || curr == 0){
                return curr ;
            }

            if(visited[x][y]){
                continue ;
            }
            visited[x][y] = true ;
            if(x != 0 && !visited[x-1][y]){
                int currdis = min(curr, dis[x-1][y]) ;
                pq.push({currdis, {x-1, y}}) ;
            }
            if(x != n-1 && !visited[x+1][y]){
                int currdis = min(curr, dis[x+1][y]) ;
                pq.push({currdis, {x+1, y}}) ;
            }
            if(y != 0 && !visited[x][y-1]){
                int currdis = min(curr, dis[x][y-1]) ;
                pq.push({currdis, {x, y-1}}) ;
            }
            if(y != n-1 && !visited[x][y+1]){
                int currdis = min(curr, dis[x][y+1]) ;
                pq.push({currdis, {x, y+1}}) ;
            }
        }
        return 0 ;
    }
};