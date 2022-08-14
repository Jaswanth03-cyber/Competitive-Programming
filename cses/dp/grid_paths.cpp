#include<bits/stdc++.h>
using namespace std ;

int solve(vector<vector<char>> &grid){
    int value = 1e9 + 7 ;
    vector<vector<int>> paths ;
    int n = grid.size() ;
    paths.resize(n) ;
    for(int i = 0 ; i < n ; i++){
        paths[i].resize(n) ;
    }

    if(grid[0][0] == '.'){
        paths[0][0] = 1 ;
    }
    else{
        return 0 ;
    }

    int index = -1 ; 
    for(int i = 1 ; i < n ; i++){
        if(grid[i][0] == '*'){
            index = i ; 
            break ;
        }
    }

    if(index != -1){
        for(int i = index ; i < n ;i++){
            paths[i][0] = 0 ;
        }
        for(int i = 1 ; i < index ; i++){
            paths[i][0] = 1 ;
        }
    }
    else{
        for(int i = 1 ; i < n ; i++){
            paths[i][0] = 1 ;
        }
    }

    int index_1 = - 1 ;

    for(int i = 1 ; i < n ; i++){
        if(grid[0][i] == '*'){
            index_1 = i ; 
            break ;
        }
    }

    if(index_1 != -1){
        for(int i = index_1 ; i < n ;i++){
            paths[0][i] = 0 ;
        }
        for(int i = 1 ; i < index_1 ; i++){
            paths[0][i] = 1 ;
        }
    }
    else{
        for(int i = 1 ; i < n ; i++){
            paths[0][i] = 1 ;
        }
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < n ; j++){
            if(grid[i][j] == '.'){
                paths[i][j] = (paths[i-1][j]%value + paths[i][j-1]%value)%value ;
            }
            else{
                paths[i][j] = 0 ;
            }
        }
    }
    return paths[n-1][n-1] ;
}


/*
dp[i][j] denotes the number of ways we can reach to ij square from to left this is nothing but 
dp[i-1][j] + dp[i][j-1] as we can move only down and right this is only if ij id not * if it is * then 0 
for first row and column base cases we have to be carefull
*/
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n ; 
    cin>>n ; 
    vector<vector<char>> grid ;
    grid.resize(n) ;
    for(int i = 0 ; i < n ;i++){
        grid[i].resize(n) ;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>grid[i][j] ;
        }
    }

    int result = solve(grid) ;
    cout<<result<<endl ;
    return 0 ;
}