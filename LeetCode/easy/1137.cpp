#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0){
            return 0 ;
        }
        else if(n == 1 || n == 2){
            return 1 ;
        }
        vector<int> arr(n+1,0) ; 
        arr[1] = 1 ;
        arr[2] = 1 ;

        for(int i = 3 ; i <= n ; i++){
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3] ;
        }  

        return arr[n] ;  
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    Solution ans ;
    int result = ans.tribonacci(n) ;
    cout<<result<<endl ;
    return 0 ;
}