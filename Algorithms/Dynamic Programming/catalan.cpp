#include <bits/stdc++.h>
using namespace std ;

/*
C[0] =1 
C[n+1] = sum of (C[i]*C[n-i]) for all n >= 0                              
*/

int solve(int n){
    vector<long> catalan(n+1, 0) ;
    catalan[0] = 1 ;
    catalan[1] = 1 ;
    for(int i = 2 ; i <= n ; i++){
        for(int j = 0 ; j < i ; j++){
            catalan[i] += catalan[j]*catalan[n-j-1] ;
        }
    }
    return catalan[n] ;
}
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 
    int ans = solve(n) ;
    cout<<ans<<endl ;
    return 0 ;
}