#include<bits/stdc++.h>
using namespace std ;


int solve(vector<int> &coins, int value, int n){
    int mod = 1e9 + 7 ;

    vector<int> possibilities(value+1, 0) ;

    sort(coins.begin(), coins.end()) ;

    possibilities[0] = 1  ;

    for(int i = 0 ; i < n ; i++){
        for(int j = coins[i] ; j <= value ; j++){
            possibilities[j] = (possibilities[j] + possibilities[j-coins[i]])%mod  ;
        }
    }

    return possibilities[value] ;
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n ; 
    int value ;
    cin>>n>>value ;

    vector<int> coins(n) ;
    for(int i = 0 ; i < n ; i++){
        cin>>coins[i] ;
    }

    int result = solve(coins, value, n) ;
    cout<<result<<endl ;
    return 0 ;
}