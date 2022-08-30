#include<bits/stdc++.h>
using namespace std ; 




int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n ;
    cin>>n ; 
    long long value = 1 ; 
    long long max_value = 1e9 + 7 ;
    for(int i = 1 ; i <=n ; i++){
        value = (value%max_value)*(2%max_value)%max_value ;
    }

    cout<<value<<endl ;
    return 0 ;
}