#include <bits/stdc++.h>
using namespace std ;


void solve(){

    string s = "" ;
    cin>>s ;

    int n = s.length() ;

    int minindex = n ;
    for(int i = 0 ; i < n ; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            minindex = min(minindex, i) ;
        }
    } 
    int count = 0 ;
    for(int i = minindex+1 ; i < n ; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            count++ ;
        }
    }

    cout<<count<<endl ;
}
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    solve() ;
    return 0 ;
}