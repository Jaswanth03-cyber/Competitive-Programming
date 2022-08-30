#include<bits/stdc++.h>
using namespace std ;


vector<int> solve(vector<int> &coins, int n){

    vector<int> new_coins(n+1) ;

    new_coins[0] = -1 ;
    int total = 0 ;
    for(int i = 0 ; i < n ; i++){
        new_coins[i+1] = coins[i] ;
        total = total + coins[i] ;
    }



    vector<vector<bool>> check ; 

    check.resize(n+1) ;
    for(int i = 0 ; i <= n ; i++){
        check[i].resize(total + 1) ;
    }

    check[0][0] = true ;

    for(int i = 1 ; i <= total ; i++){
        check[0][i] = false ;
    }
    for(int i = 0 ; i <= n ; i++){
        check[i][0] = true ;
    }

    for(int i = 1 ; i <= n ; i++){
        check[i][new_coins[i]] = true ;
        for(int j = 1 ; j <= total ; j++){

            if(check[i-1][j]){
                check[i][j] = true ;
                check[i][j+ new_coins[i]] = true ;
            }
        }
    }

    vector<int> result ; 

    for(int i = 1 ; i <= total ; i++){
        if(check[n][i]){
            result.push_back(i) ;
        }
    }

    return result ;
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n ; 
    cin>>n ; 

    vector<int> coins(n) ;
    for(int i = 0 ; i < n ; i++){
        cin>>coins[i] ;
    }

    vector<int> result = solve(coins, n) ;

    cout<<result.size()<<endl ;
    for(unsigned int i = 0 ; i < result.size() ; i++){
        cout<<result[i]<<" " ;
    }
    cout<<endl ; 

    return 0 ;
}