#include<bits/stdc++.h>
using namespace std ;


int find(vector<int> &arr){

    set<int> result ;

    int n = arr.size() ;    

    for(int i = 0 ; i < n ; i++){
        if(result.count(arr[i]) == 0){
            result.insert(arr[i]) ;
        }
        else{
            continue ;
        }
    }

    int final = result.size() ;

    return final ;
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

    int result = find(arr) ;

    cout<<result<<endl ;

    return 0 ;
}