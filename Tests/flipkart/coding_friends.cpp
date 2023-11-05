#include <bits/stdc++.h>
using namespace std ;


void solve(){
    int n = 0 ;
    cin>>n ;
    int m = 0 ;
    cin>>m ;
    int difference = 0 ;
    cin>>difference ;

    if(difference > 0 && n >= m){
        cout<<-1<<endl ;
        return ;
    }

    int ans = (difference)/(m-n) + 1 ;

    int days = 0 ;

    while(difference >= 0){
        difference += n ;
        difference -= m ;
        days++ ;
    }

    cout<<ans<<" "<<days<<endl ;
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    solve() ;
    return 0 ;
}

/*
second approach is preferable 
*/