#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0 ;
        if((low%2 == 0) && (high%2 == 0)){
            ans = (high - low)/(2) ;
        }
        else{
            ans = (high - low)/(2) +1 ; 
        }
        return ans ; 
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int low = 0 ;
    int high = 0 ;

    cin>>low>>high ;

    Solution ans ; 
    int result = ans.countOdds(low, high) ;
    return 0 ;
}


