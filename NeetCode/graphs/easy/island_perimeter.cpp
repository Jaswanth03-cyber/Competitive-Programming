#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/island-perimeter/description/
*/

/*
Idea is simple take all the cells which are land, now just check its surroundings, if surroundings is water then just we will add that if not
we will not add it to the perimeter so thats all having a vector pair where land is present, as n <= 100 O(N^2) this works if not we have to go with bfs
*/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<pair<int, int>> land ;
        int n = grid.size() ;
        int m = grid[0].size() ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]){
                    land.push_back({i, j}) ;
                }
            }
        }

        int size = land.size() ;
        int x = 0 ;
        int y = 0 ;
        int ans = 0 ;
        int count = 0 ;
        for(int i = 0 ; i < size ; i++){
            count = 0 ;
            x = land[i].first ;
            y = land[i].second ;
            if(x != 0 && grid[x-1][y]){
                count++ ;
            }
            if(x != n -1 && grid[x+1][y]){
                count++ ;
            }
            if(y != 0 && grid[x][y-1]){
                count++ ;
            }
            if(y != m -1 && grid[x][y+1]){
                count++ ;
            }
            ans = ans + 4 - count ;
        }
        return ans ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    int m = 0 ;
    vector<vector<int>> grid(n, vector<int>(m, 0)) ;

    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin>>grid[i][j] ;
        }
    }

    Solution ans ;
    int res = ans.islandPerimeter(grid) ;
    cout<<res<<endl ;
    return 0 ;
}