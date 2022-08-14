#include<bits/stdc++.h>
using namespace std ;


int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    long long n ; 
    cin>>n ;

    long long solve[n + 1] ;
    long long v = 1e9 + 7 ;

    long long arr[6] ;
    for(int i = 0 ; i < 6 ; i++){
        arr[i] = i + 1 ;
    }

    solve[0] = 1 ;
    for(long long i =1 ; i <= n ; i++){
        solve[i] = 0 ;
    }
    for(long long i = 1 ; i <= n ; i++){
        for(long long j = 0 ;  j < 6 ; j++){
            if(i >= arr[j]){
                solve[i] = solve[i]%v + solve[i-arr[j]]%v ;
            }
        }
    }
    long long result = solve[n]%(v) ;
    cout<<result<<endl ;


}