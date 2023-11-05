#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int n = 0 ;
    cin>>n ;
    int k = 0 ;
    cin>>k ;
    vector<int> score(n, 0) ;

    for(int i = 0 ; i < n ; i++){
        cin>>score[i] ;
    }

    vector<int> minscore(n, INT_MAX) ;
    vector<int> maxscore(n, 0) ;

    minscore[0] = score[0] ;
    for(int i = 1 ; i < n ; i++){
        maxscore[i] = max(score[i], maxscore[i-1]) ;
    }

    minscore[n-1] = score[n-1] ;

    for(int i = n-2 ; i >= 0 ; i--){
        minscore[i] = min(minscore[i+1], score[i]) ;
    }

    int ans = 0 ;
    for(int i = 1 ; i < n ; i++){
        if(maxscore[i-1] + minscore[i] >= k){
            ans++ ;
        }
    }

    cout<<ans<<endl ;
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    solve() ;
    return 0 ;
}