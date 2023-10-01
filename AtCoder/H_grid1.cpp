#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int n = 0 ;
    cin>>n ;
    int m = 0 ;
    cin>>m ;

    vector<vector<char>> grid(n, vector<char>(m, '.'));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin>>grid[i][j] ;
        }
    }
    int mod = 1e9 + 7 ;
    vector<vector<int>> paths(n, vector<int>(m, 0)) ;

    if(grid[0][0] == '#' || grid[n-1][m-1] == '#'){
        cout<<0<<endl ;
        return  ;
    }

    int index = m ;
    for(int i = 0 ; i < m ; i++){
        if(grid[0][i] == '#'){
            index =  i ;
            break ;
        }
    }

    for(int i = 0 ; i < m ; i++){
        if(i < index){
            paths[0][i] = 1 ;
        }
        else{
            paths[0][i] = 0 ;
        }
    }
    index = n ;
    for(int i = 0 ; i < n ; i++){
        if(grid[i][0] == '#'){
            index =  i ;
            break ;
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(i < index){
            paths[i][0] = 1 ;
        }
        else{
            paths[i][0] = 0 ;
        }
    }

    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < m ; j++){
            if(grid[i][j] == '.'){
                paths[i][j] = (paths[i-1][j]%mod + paths[i][j-1]%mod)%mod ;
            }
        }
    }
    cout<<paths[n-1][m-1]<<endl ;
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    solve() ;
    return 0 ;
}