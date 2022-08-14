#include<bits/stdc++.h>
using namespace std ;

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    long long n ;
    cin>>n ;
    long long arr[n] ;
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i] ;
    }
    long long int changes = 0 ;
    for(long long int i = 0 ; i < n - 1; i++){
        if(arr[i+1] < arr[i]){
            changes = changes + arr[i] - arr[i+1] ;
            arr[i+1] = arr[i] ;
        }
    }
    cout<<changes<<endl ;
    return 0 ;
}