#include<bits/stdc++.h>
using namespace std ;

void solve(){
    int n = 0 ;
    cin>>n ;
    int k = 0 ;
    cin>>k ;
    int m = 0 ;
    cin>>m ;

    vector<vector<int>> matrix(n, vector<int>(n, 0)) ;
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>matrix[i][j] ;
        }
    }
    vector<vector<int>> rows(n, vector<int>(n-k+1, 0)) ;
    for(int i = 0 ; i < n ; i++){
        map<int, int, greater<int>> mp ;
        for(int j = 0 ; j < k ; j++){
            mp[matrix[i][j]]++ ;
        }
        int index = 0 ;
        for(int j = k ; j < n ; j++){
            rows[i][index] = mp.begin()->first ;
            index++ ;
            if(mp[matrix[i][j-k]] > 1){
                mp[matrix[i][j-k]]-- ;
            }
            else{
                mp.erase(mp.find(matrix[i][j-k])) ;
            }
            mp[matrix[i][j]]++ ;
        }
        rows[i][index] = mp.begin()->first ;
    }

    vector<int> ans ;

    for(int i = 0 ; i < n-k+1 ; i++){
        map<int, int, greater<int>> mp ;
        for(int j = 0 ; j < k ; j++){
            mp[rows[j][i]]++ ;
        }
        for(int j = k ; j < n ; j++){
            ans.push_back(mp.begin()->first) ;
            if(mp[rows[j-k][i]] > 1){
                mp[rows[j-k][i]]-- ;
            }
            else{
                mp.erase(mp.find(rows[j-k][i])) ;
            }
            mp[rows[j][i]]++ ;
        }
        ans.push_back(mp.begin()->first) ;
    }
    sort(ans.begin(), ans.end()) ;
    int size = ans.size() ;
    int l = 0, r = size-1 ;
    int res = size ;
    while(l <= r){
        int mid = (l+r)/2 ;
        if(ans[mid] < m){
            l = mid + 1 ;
        }
        else if(ans[mid] >= m){
            r = mid -1 ;
            res = min(res, mid) ;
        }
    }
    cout<<size-res<<" "<<ans[res]<<" "<<ans[size-1]<<endl ;
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    
    int t = 0 ;
    while(t--){
      solve() ;
    }
    return 0 ;
}

/*
sliding window on rows then on columns 
*/