#include <bits/stdc++.h>
using namespace std ;

string formatrange(int low, int high){
    if(low == high){
        return to_string(low) ;
    }
    string ans = to_string(low) + "->" + to_string(high) ;
    return ans ;
}

void solve(){

    int n = 0 ;
    cin>>n ;
    vector<int> marks(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>marks[i] ;
    }
    sort(marks.begin(), marks.end()) ;
    int low = 0 ;
    cin>>low ;
    int high = 0 ;
    cin>>high ;

    int currlow = low ; 
    int i = 0 ; 
    vector<string> ans ;

    while(i < n){
        if(marks[i] == currlow){
            i++ ;
            currlow++ ;
        }
        else{
            string range = formatrange(currlow, marks[j]-1) ;
            ans.push_back(range) ;
            currlow = marks[j++] + 1 ;
        }
    }

    if(currlow <= high){
        ans.push_back(formatrange(currlow, high)) ;
    }

    int size = ans.size() ;
    for(int i = 0 ; i < size ; i++){
        cout<<ans[i]<<" " ;
    }
    cout<<endl ;
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    solve() ;

    return 0 ;
}