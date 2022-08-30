#include<bits/stdc++.h>
using namespace std ;

void towerofhanoi(int n, int a, int b, int c, vector<pair<int, int>> &result){
    if(n == 0){
        return  ;
    }
    towerofhanoi(n-1, a, c, b, result) ;
    result.push_back(make_pair(a,b)) ;
    towerofhanoi(n-1, c, b, a, result) ;
}
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    int n  ; 
    cin>>n ;

    int a = 1 ;
    int b = 2 ;
    int c = 3 ; 

    vector<pair<int, int>> result  ;
    towerofhanoi(n, a, c, b, result) ;

    cout<<result.size()<<endl ;

    for(auto it = result.begin() ; it != result.end() ; it++){
        cout<<it->first<<" "<<it->second<<endl ;
    }

    return 0 ;
}