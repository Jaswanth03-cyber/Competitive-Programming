#include<bits/stdc++.h>
using namespace std ;


int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    long long n ;
    cin>>n ;

    long long arr[n-1] ;
    for(long long int i = 0 ; i < n-1 ; i++){
        cin>>arr[i] ;
    }
    long long int sum = (n)*(n+1)/2 ;
    for(long long int i = 0 ; i < n-1 ; i++){
        sum = sum - arr[i] ;
    }
    cout<<sum<<endl ;

    return 0 ;
}