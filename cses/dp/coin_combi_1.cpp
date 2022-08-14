#include<bits/stdc++.h>
using namespace std ;

int solve(int coins[], int value, int n){
    int mod = 1e9 + 7 ;
    vector<int> possibilities(value+1, 0) ;

    possibilities[0] = 1 ;
    for(int i = 1 ; i <= value ; i++){
        for(int j = 0 ; j < n ; j++){
            if(coins[j] <= i){
                possibilities[i] = (possibilities[i] + possibilities[i-coins[j]])%mod ;
            }
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

    int coins[n] ;
    for(int i = 0 ; i < n ; i++){
        cin>>coins[i] ;
    }
    int result = solve(coins, value, n) ;
    cout<<result<<endl ;
    return 0 ;
}