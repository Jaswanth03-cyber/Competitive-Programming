#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/happy-number/
*/
class Solution {
public:
    int squares(int n){
        int total = 0 ;
        while(n != 0){
            total = total + (n%10)*(n%10) ;
            n = n/10 ;
        }
        return total ;
    }
    bool isHappy(int n) {
        if(n == 1){
            return true ;
        }
        set<int> st ;
        while((n > 1) && (st.count(n) == 0)){
            st.insert(n) ;
            n = squares(n) ;
        }
        return n == 1 || st.count(n) == 0 ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}