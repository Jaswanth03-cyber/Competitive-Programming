#include<bits/stdc++.h>
using namespace std ;

/*
This isBadVersion is a dummy function it was provided before 
https://leetcode.com/problems/first-bad-version/
*/

bool isBadVersion(int i){
    if(i%2 == 0){
        return false ;
    }
    return true ;
}

// came from back as to reduce time 
class Solution {
public:
    int firstBadVersion(int n) {
        for(int i = n ; i >= 0 ; i--){
            if(!isBadVersion(i)){
                return i +1 ;
            }
        } 
        return n ;  
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ; 
    cin>>n ; 

    Solution ans ;
    int result = ans.firstBadVersion(n) ;

    cout<<result<<endl ;
    return 0 ;
}