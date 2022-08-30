#include<bits/stdc++.h>
using namespace std ;


int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n ; 
    cin>>n ; 

    int b = 0 ;

    int i = 5 ;

    while(n/i > 0){
        b = b + n/i ;
        i = i*5 ;
    }

    cout<<b<<endl ;
    return 0 ;
}