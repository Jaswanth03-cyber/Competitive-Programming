#include<bits/stdc++.h>
using namespace std ;

int solve(vector<int> &arr, int n){

    vector<int> length(n,1) ;

    int maximum = 1 ;
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < i ;j++){
            if(arr[j] < arr[i]){
                length[i] = max(length[i], length[j] + 1) ;
            }
        }
        maximum = max(length[i], maximum) ;
    }
    return maximum ;
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n ; 
    cin>>n ;

    vector<int> arr(n) ;

    for(int i = 0 ; i < n ; i++){
        cin>>arr[i] ;
    }

    int length = solve(arr, n) ;
    cout<<length<<endl ;
    return 0 ;
}