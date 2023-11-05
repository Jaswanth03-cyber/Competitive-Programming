#include <bits/stdc++.h>
using namespace std ;


bool isvalid(char item){
    if(item == 'a' || item == 'e' || item == 'i' || item == 'o' || item == 'u' || item == 'A' || item == 'E' || item == 'I' || item == 'O' || item == 'U'){
        return true ;
    }
    return false ;
}

void solve(){
    string s ;
    cin>>s ;
    int k = 0 ;
    cin>>k ;

    int ans = 0 ;
    int count = 0 ;
    int n = s.length() ;
    for(int i =0 ; i < k ; i++){
        if(isvalid(s[i])){
            count++ ;
        }
    }

    for(int i = k ; i < n ; i++){
        ans = max(ans, count) ;
        if(isvalid(s[i-k])){
            count-- ;
        }
        if(isvalid(s[i])){
            count++ ;
        }
    } 

    ans = max(ans, count) ;

    cout<<ans<<endl ;
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    solve() ;
    return 0 ;
}