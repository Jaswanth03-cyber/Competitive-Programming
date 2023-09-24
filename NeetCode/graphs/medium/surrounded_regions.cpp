#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/surrounded-regions/
*/

/*
Logic :-
as border 'O's should not be changed and also those which are connected to those so take dfs of all 'O's which are on the border 
after it is done now remaining all 'O's which are not visited can be changed to 'X's so thats what is done.
*/



class Solution {
public:
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int x, int y, int n, int m){
        if(visited[x][y] || board[x][y] == 'X'){
            return ;
        }
        visited[x][y] = true ;
        if(x != 0){
            dfs(board, visited, x-1, y, n, m) ;
        }
        if(x != n-1){
            dfs(board, visited, x+1, y, n, m) ;
        }
        if(y != 0){
            dfs(board, visited, x, y-1, n, m) ;
        }
        if(y != m-1){
            dfs(board, visited, x, y+1, n, m) ;
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size() ;
        int m = board[0].size() ;
        vector<vector<bool>> visited(n, vector<bool>(m, false)) ;
        vector<pair<int, int>> ans ;
        for(int i = 0 ; i < m ; i++){
            if(!visited[0][i] && board[0][i] == 'O'){
                dfs(board, visited, 0, i, n, m) ;
            }
        }
        for(int i = 0 ; i < m ; i++){
            if(!visited[n-1][i] && board[n-1][i] == 'O'){
                dfs(board, visited, n-1, i, n, m) ;
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(!visited[i][0] && board[i][0] == 'O'){
                dfs(board, visited, i, 0, n, m) ;
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(!visited[i][m-1] && board[i][m-1] == 'O'){
                dfs(board, visited, i, m-1, n, m) ;
            }
        }

        for(int i = 1 ; i < n-1 ; i++){
            for(int j = 1 ; j < m -1 ; j++){
                if(!visited[i][j] && board[i][j]== 'O'){
                    board[i][j] = 'X' ;
                }
            }
        }
    }
};