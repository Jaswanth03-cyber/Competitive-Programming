#include<bits/stdc++.h>
using namespace std ;

long long solve(long long i){
    long long result ; 
    result = ((i-1)*(i+4)*(i*i - 3*i + 4))/2 ;
    return result ;
}


int main(){
    int n ; 
    cin>>n ; 

    for(long long i = 1 ; i <= n ; i++){
        long long result = solve(i) ;
        cout<<result<<endl ;
    }
}