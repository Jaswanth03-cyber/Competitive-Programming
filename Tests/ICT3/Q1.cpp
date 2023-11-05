#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int n = 0 ;
    cin>>n ;
    vector<int> stocks(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>stocks[i] ;
    }
    int ans = 0 ;
    int minstock = stocks[0] ;
    for(int i = 1 ; i , n ; i++){
        if(stocks[i] < minstocks){
            minstocks = stocks[i] ;
        }
        else{
            ans = ans + stocks[i] - minstocks ;
            minstocks = stocks[i] ;
        }
    } 
    cout<<ans<<endl ;
}
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    solve() ;

    return 0 ;
}