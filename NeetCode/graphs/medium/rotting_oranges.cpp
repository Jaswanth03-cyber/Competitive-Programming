#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/rotting-oranges/
*/
/*
Logic 
so given that in one minute oranges that are adjacent to a rotten orange will be rotten so we have to find the minimum time such that all the oranges
are rotted, if not return -1 i.e if there exists an orrange which can not be rotten what so ever.
so now I am doing a bfs when there is a rotten orange every time and taking the minimum time possible for a good orange among all dfs 
of the rotten orangeswhich visited over there, this we do with sequential dfs and take the minimum timer always.

so lets say we are having a rotten orange we will start the dfs all the oranges which are good which can be visited will have an update in the time[x][y]
here see update is done when time[x][y] < counter and the cell has good orange, if not we already have a minimum time possible than that so here 
time[x][y] = counter and counter++ is done(if you see in the argument counter is not referenced so when a dfs is done for all its 4 adjacent vertices counter will have same value as change is not reflected as not referenced)
and also in the base cases when grid[x][y] is empty have to return, also when gird[x][y] == 2 need not process, but be carefull that this will cause 
an infinite recursion call if there are no good oranges as time[x][y] will be keep on updating so except in the first case whenever again if we
get back to a rotten orange then counter willl not be 0 so thats why when grid[x][y] is 2 and counter != 0 need not process that rotten orange.
note also we are not changing the grid that is when a good becomes rotten no need to change the grid because then we will end up with the wrong answers

effectively at all the positions which have rotten oranges we are doing dfs over here at once and at all the cells which have good and can reach 
we are taking the minimum of the all possible timers. note after timers are calculated we have to check if all good oranges can be converted to rotten 
if not return -1, if yes then lets say z is the maximum time among all then for integers >= z after this time all oranges will be rotten so minimum one 
will be z and also if not good oranges return 0.
*/
class Solution {
public:
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &time, int counter, int x, int y, int n, int m){
        if(grid[x][y] == 0 || (grid[x][y] == 2 && counter != 0)){
            return ;
        }
        if(grid[x][y] == 1 && time[x][y] < counter){
            return ;
        }
        time[x][y] = counter ;
        counter++ ;
        if(x != 0){
            dfs(grid, time, counter, x-1, y, n, m) ;
        }
        if(x != n-1){
            dfs(grid, time, counter, x+1, y, n, m) ;
        }
        if(y != 0){
            dfs(grid, time, counter, x, y-1, n, m) ;
        } 
        if(y != m-1){
            dfs(grid, time, counter, x, y+1, n, m) ;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>> time(n, vector<int>(m, INT_MAX)) ;
        cout<<0<<endl ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                int counter = 0 ;
                if(grid[i][j] == 2 ){
                    dfs(grid, time, counter, i, j, n, m) ;
                }
            }
        }
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){ 
                if(grid[i][j] == 1){
                    if(time[i][j] == INT_MAX){
                        return -1 ;
                    }
                    ans = max(ans, time[i][j]) ;
                }
            }
        } 
        return ans ;    
    }
};