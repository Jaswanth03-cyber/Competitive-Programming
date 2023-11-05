#include <bits/stdc++.h>
using namespace std ;

/*
https://www.thejoboverflow.com/p/p2137/
*/

struct sortbysec{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)const{
        return a.second < b.second ;
    }
};

void solve(){
    int n = 0 ;
    cin>>n ; 
    vector<int> start(n, 0) ;

    for(int i = 0 ; i < n ;  i++){
        cin>>start[i] ;
    }
    vector<int> end(n, 0) ;

    for(int i = 0 ; i < n ; i++){
        cin>>end[i] ;
    }

    vector<pair<int, int>> intervals ;
    for(int i = 0 ; i < n ; i++){
        intervals.push_back({start[i], end[i]}) ;
    }

    sort(intervals.begin(), intervals.end(), sortbysec()) ;
    int ans = 0 ;
    int endtime = 0 ;

    for(int i = 0 ; i < n ; i++){
        if(intervals[i].first >= endtime){
            ans++ ;
            endtime = intervals[i].second ;
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