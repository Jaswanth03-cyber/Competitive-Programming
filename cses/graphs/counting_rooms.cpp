#include <bits/stdc++.h>
using namespace std ;

/*
iterating up down, left and right flood fill algorithm.
*/
void solve(int x, int y, int n, int m, vector<vector<char>> &grid, vector<vector<bool>> &visited){

    stack<pair<int, int>> st; 
    st.push({x, y}) ;

    while(!st.empty()){
        int i = st.top().first ;
        int j = st.top().second ;
        st.pop() ;
        if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] == '#'){ // visited and grid checking later because if i and j not bound so first those conditions
            continue ;
        }

        visited[i][j] = true ;
        st.push({i+1, j}) ; st.push({i-1, j}) ; st.push({i, j+1}) ; st.push({i, j-1}) ;
    }
}

/*
Recursion algorithm
*/
void dfs(int x, int y, int n, int m, vector<vector<char>> &grid, vector<vector<bool>> &visited){
    if(visited[x][y] || grid[x][y] == '#'){
        return ;
    }
    visited[x][y] = true ;

    if(x != 0){
        dfs(x-1, y, n, m, grid, visited) ;
    }
    if(x != n-1){
        dfs(x+1, y, n, m, grid, visited) ;
    }
    if(y != 0){
        dfs(x, y-1, n, m, grid, visited) ;
    }
    if(y != m-1){
        dfs(x, y+1, n, m, grid, visited) ;
    }
}
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0, m = 0 ;
    cin>>n>>m ;
    vector<vector<char>> grid(n, vector<char>(m, 'a')) ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin>>grid[i][j] ;
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false)) ;
    int count = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!visited[i][j] && grid[i][j] == '.'){
                solve(i, j, n, m, grid, visited) ; // dfs(i, j, n, m, grid, visited) ;
                count++ ;
            }
        }
    }

    cout<<count<<endl ;
    return 0 ;
}