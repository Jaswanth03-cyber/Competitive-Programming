#include<bits/stdc++.h>
using namespace std ; 

long long solve(int n, long long total){
    long long half = total/2 ;
    int max_value = 1e9 + 7 ;

    vector<long long> possibilities(half +1,0) ; 

    possibilities[0] = 1 ; 

    for(int i = 1 ; i <= n ; i++){
        for(int j = half ; j >= i ; j--){
            possibilities[j] = (possibilities[j] + possibilities[j - i])%max_value ;
        }
    }

    if(possibilities[half]%2 == 1){
        possibilities[half] = possibilities[half] + max_value ;
    }
    return possibilities[half]/2 ; 
}



int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;


    int n ; 
    cin>>n ; 

    long long total  ;

    total = n*(n+1)/2 ;
    if(total%2 == 1){
        cout<<0<<endl ;
    }
    else{
        long long result = solve(n, total) ;
        cout<<result<<endl ;
    }

    return 0 ;
}