#include<bits/stdc++.h>
using namespace std ;

void solve(long long n){
    vector<long long> a , b ;

    long long ans = n*(n+1)/4 ;

    for(long long i = n ; i >= 1 ; i--){
        if(i <= ans){
            a.push_back(i) ;
            ans = ans - i ;
        }
        else{
            b.push_back(i) ;
        }
    }

    cout<<a.size()<<endl ;
    for(auto it = a.begin() ; it != a.end() ; it++){
        cout<<*it<<" " ;
    }
    cout<<endl ;
    cout<<b.size()<<endl ;
    for(auto it = b.begin() ; it != b.end() ; it++){
        cout<<*it<<" " ;
    }
    cout<<endl ;

    return ;
}


int main(){

    long long n ; 
    cin>>n ; 
    long long sum = (n)*(n+1)/ 2 ;

    if(sum%2 == 0){
        cout<<"YES"<<endl ;
        solve(n) ;
    }
    else{
        cout<<"NO"<<endl ;
    }


    return 0 ;
}